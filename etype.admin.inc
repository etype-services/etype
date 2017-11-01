<?php

/* admin settings form */
function etype_admin() {

  $form = array();

  $form['message'] = array(
    '#markup' => '<p>This is a dummy form. This module has no settings yet.</p>'
  );


  return system_settings_form($form);
}