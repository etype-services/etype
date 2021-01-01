<?php

/**
 * @param $form
 * @param $form_state
 * @return mixed
 */
function etype_login_form($form, &$form_state) {

  $uid = user_is_logged_in();
  if ($uid > 0) {

    $user = user_load($uid);
    $string = t("Hello");
    $string .= ' ' . $user->username . ', ';
    $string .= t("you are already logged in");
    $form['help'] = [
      '#type' => 'item',
      '#markup' => $string,
    ];

  } else {

    $form['username'] = [
      '#type' => 'textfield',
      '#title' => t('User Name'),
      '#required' => TRUE,
    ];

    $form['password'] = [
      '#type' => 'password',
      '#title' => t('Password'),
      '#required' => TRUE,
    ];

    $form['help'] = [
      '#type' => 'item',
      '#markup' => t('<a href="/etype-forgot-password">I forgot my password.</a>'),
    ];

    $form['destination'] = [
      '#type' => 'hidden',
      '#value' => $_POST['destination'],
    ];

    $form['submit'] = [
      '#type' => 'submit',
      '#value' => t('Login'),
    ];

  }

  return $form;

}

function etype_login_form_submit($form, &$form_state): bool {

  $username = $form['username']['#value'];
  $password = $form['password']['#value'];
  $destination = $form['destination']['#value'];
  $etype_pub = variable_get('etype_pub');

  $error_message = "We‘re sorry, either your user name or password is incorrect!";
  $expired_message = "We‘re sorry, your subscription has expired.";
  $success_message = "Hello $username, you are now logged in!";
  $auth_message = "We couldn‘t log you in, but we have cleared your data, so please try again. If you still can‘t login, please contact support@etypeservices.com and we will help you.";

  $client = new soapclient('https://publisher.etype.services/webservice.asmx?WSDL');
  $param = [
    'publicationId' => $etype_pub,
    'username' => $username,
    'password' => $password,
  ];
  $response = $client->ValidateSubscriber($param);
  $validateSubscriberResult = $response->ValidateSubscriberResult;
  $responseCode = $validateSubscriberResult->TransactionMessage->Message;

  switch ($responseCode) {
    case "-1":
      drupal_set_message($error_message, 'error');
      break;

    case "-2":
      drupal_set_message($expired_message, 'error');
      break;

    default:
      $subscriberEmail = $validateSubscriberResult->Email;
      /* Check there is already a user */
      $user = user_load_by_mail($subscriberEmail);
      /* If not, make one */
      if ($user == false) {
        $user = array(
          'name' => $username,
          'pass' => $password, // note: do not md5 the password
          'mail' => $subscriberEmail,
          'status' => 1,
          'init' => $subscriberEmail,
          'roles' => [
            DRUPAL_AUTHENTICATED_RID => 'authenticated user',
          ],
        );

        try {
          user_save('', $user);
        } catch (Exception $e) {
          drupal_set_message("Could not save User", 'error');
        }
      }

      if (user_authenticate($username, $password)) {
        $user_obj = user_load_by_name($username);
        $form_state = [];
        $form_state['uid'] = $user_obj->uid;
        user_login_submit([], $form_state);
        drupal_set_message($success_message, 'status');
        drupal_goto($destination);
      } else {
        /*
         * Something went wrong, a mismatched email or password.
         * Changes to V2 don't propagate to Drupal
        */
        watchdog('V2_login', $subscriberEmail, [], WATCHDOG_ERROR);
        /* Clear info and start afresh. */
        user_delete($user->uid);
        $user = array(
          'name' => $username,
          'pass' => $password, // note: do not md5 the password
          'mail' => $subscriberEmail,
          'status' => 1,
          'init' => $subscriberEmail,
          'roles' => [
            DRUPAL_AUTHENTICATED_RID => 'authenticated user',
          ],
        );

        try {
          user_save('', $user);
          $user_obj = user_load_by_name($username);
          $form_state = [];
          $form_state['uid'] = $user_obj->uid;
          user_login_submit([], $form_state);
          drupal_set_message($success_message, 'status');
          drupal_goto($destination);
        } catch (Exception $e) {
          drupal_set_message("Could not save User", 'error');
        }

      }
  }

}

/**
 * @param $form
 * @param $form_state
 * @return mixed
 */
function etype_password_form($form, &$form_state) {
  $form['username'] = [
    '#type' => 'textfield',
    '#title' => t('User Name'),
    '#required' => TRUE,
  ];

  $form['submit'] = [
    '#type' => 'submit',
    '#value' => t('Send me my password'),
  ];

  return $form;
}

/**
 * @param $form
 * @param $form_state
 */
function etype_password_form_submit($form, &$form_state) {

  $username = $form['username']['#value'];
  $etype_pub = variable_get('etype_pub');

  $error_message = "We‘re sorry, we can‘t find an account for that user name at this publication.";
  $success_message = "Your password has been sent to your email address.";

  $client = new soapclient('https://publisher.etype.services/webservice.asmx?WSDL');
  $param = ['publicationId' => $etype_pub];
  $param['username'] = $username;
  $response = $client->ForgetPassword($param);
  $code = $response->ForgetPasswordResult;

  switch ($code) {
    case "-1":
      drupal_set_message($error_message, 'error');
      break;

    default:
      drupal_set_message($success_message, 'status');
      break;
  }
}

/**
 * Not a form, but here because it is to do with the account.
 */
function etype_my_account() {
  global $user;
  $etype_pub = variable_get('etype_pub');
  $markup = <<<EOF
      <script type='text/javascript'>
      window.addEventListener('message', receiveMessage, false);
      function receiveMessage(event) {
        let ifrmAccountUpdateForm = document.getElementById('ifrmAccountUpdateForm');
		    if (event.data.docHeight != undefined && event.data.docHeight != 'undefined') {
		      ifrmAccountUpdateForm.height = event.data.docHeight;
		    }
      }
      </script>
      <iframe id='ifrmAccountUpdateForm'
        src='https://publisher.etype.services/subscriber-account?pubId=$etype_pub&username=$user->name'
        width='100%' height='860' frameborder='0' scrolling='no'></iframe>
EOF;
  return [
    "#markup" => $markup,
  ];
}
