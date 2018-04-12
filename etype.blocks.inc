<?php

/* BLOCKS */

/**
 * Implements hook_block_info().
 */
function etype_block_info() {
  $blocks = [];

  $blocks['e-Edition'] = [
    'info' => t('e-Edition'),
  ];

  $blocks['Social-Search'] = [
    'info' => t('eType Social & Search'),
  ];

  $blocks['Follow'] = [
    'info' => t('eType Follow'),
  ];

  $blocks['Contact-Page-Follow'] = [
    'info' => t('eType Contact Page Follow'),
  ];

  $blocks['eType User Menu'] = [
    'info' => t('eType User Menu'),
  ];

  return $blocks;
}

/**
 * Implements hook_block_view()
 *
 * @param string $delta
 *
 * @return array
 */
function etype_block_view($delta = '') {

  $block = [];
  switch ($delta) {
    case 'e-Edition':
      $block['subject'] = '';
      $block['content'] = _etype_e_edition_content();
      break;

    case 'Social-Search':
      $block['subject'] = '';
      $block['content'] = _etype_social_search_content();
      break;

    case 'Follow':
      $block['subject'] = '';
      $block['content'] = _etype_follow_content();
      break;

    case 'Contact-Page-Follow':
      $block['subject'] = '';
      $block['content'] = _etype_contact_follow_content();
      break;

    case 'eType Menu (Code)':
      $block['subject'] = '';
      $block['content'] = _etype_menu_content();
      break;

  }

  return $block;
}

/**
 * e-Edition block
 */
function _etype_e_edition_content() {
  $e_editions = etype_e_editions();
  $output = '';
  foreach ($e_editions as $e_edition) {
    $output .= '
<p><a href="' . $e_edition['path'] . '"><img src="' . $e_edition['image'] . '"></a></p>
<p><a href="' . $e_edition['path'] . '">Click here to read ' . $e_edition['site_name'] . '</a></p>
';
  }
  return $output;
}

/**
 * Social & Search block for Navigation bar
 */
function _etype_social_search_content() {

  $output = '
<div class="navigation-social-bookmarks">
    <ul class="social-bookmarks">';

  $facebook = variable_get('etype_facebook_top');
  $twitter = variable_get('etype_twitter_top');
  $googleplus = variable_get('etype_googleplus_top');
  $instagram = variable_get('etype_instagram_top');
  $youtube = variable_get('etype_youtube_top');
  $pinterest = variable_get('etype_pinterest_top');
  $vimeo = variable_get('etype_vimeo_top');
  $rss = variable_get('etype_rss_top');

  if ($facebook > 0) {
    $url = variable_get('etype_facebook_url');
    if (! empty($url)) {
      $output .= '<li><a href="' . $url . '" target="_blank"><i class="fab fa-fw fa-lg fa-facebook"></i></a></li>';
    }
  }

  if ($twitter > 0) {
    $url = variable_get('etype_twitter_url');
    if (! empty($url)) {
      $output .= '<li><a href="' . $url . '" target="_blank"><i class="fab fa-fw fa-lg fa-twitter"></i></a></li>';
    }
  }

  if ($googleplus > 0) {
    $url = variable_get('etype_googleplus_url');
    if (! empty($url)) {

    }
    $output .= '<li><a href="' . $url . '" target="_blank"><i class="fab fa-fw fa-lg fa-google-plus"></i></a></li>';
  }

  if ($instagram > 0) {
    $url = variable_get('etype_instagram_url');
    if (! empty($url)) {
      $output .= '<li><a href="' . $url . '" target="_blank"><i class="fab fa-fw fa-lg fa-instagram"></i></a></li>';
    }
  }

  if ($youtube > 0) {
    $url = variable_get('etype_youtube_url');
    if (! empty($url)) {
      $output .= '<li><a href="' . $url . '" target="_blank"><i class="fab fa-fw fa-lg fa-youtube"></i></a></li>';
    }
  }

  if ($pinterest > 0) {
    $url = variable_get('etype_pinterest_url');
    if (! empty($url)) {
      $output .= '<li><a href="' . $url . '" target="_blank"><i class="fab fa-fw fa-lg fa-pinterest"></i></a></li>';
    }
  }

  if ($vimeo > 0) {
    $url = variable_get('etype_vimeo_url');
    if (! empty($url)) {
      $output .= '<li><a href="' . $url . '" target="_blank"><i class="fab fa-fw fa-lg fa-vimeo-square"></i></a></li>';
    }
  }

  if ($rss > 0) {
    $output .= '<li><a href="/rss.xml" target="_blank"><i class="fab fa-fw fa-lg fa-rss-square"></i></a></li>';
  }

  $output .= '
</ul>';

  /* search box is part of this block for News+ theme */
  $etype_add_search_to_social = variable_get('etype_add_search_to_social');
  if ($etype_add_search_to_social === 1) {
    if (module_exists('search')) {
      $output .= '
    <div class="dropdown search-bar block-search">
    <a data-toggle="dropdown" href="#" class="trigger"></a>
    <ul class="dropdown-menu" role="menu" aria-labelledby="dLabel">
    <li>';
      $block = module_invoke('search', 'block_view', 'search');
      $output .= render($block);
      $output .= '</li></ul></div>';
    }
  }

  $output .= '</div>';
  return $output;

}


/**
 * Follow block for Footer region
 */
function _etype_follow_content() {

  $output = '
<ul class="social-bookmarks">';

  $facebook = variable_get('etype_facebook_footer');
  $twitter = variable_get('etype_twitter_footer');
  $googleplus = variable_get('etype_googleplus_footer');
  $instagram = variable_get('etype_instagram_footer');
  $youtube = variable_get('etype_youtube_footer');
  $pinterest = variable_get('etype_pinterest_footer');
  $vimeo = variable_get('etype_vimeo_footer');
  $rss = variable_get('etype_rss_footer');

  if ($facebook > 0) {
    $url = variable_get('etype_facebook_url');
    if (! empty($url)) {
      $output .= '<li><a href="' . $url . '" target="_blank"><i class="fab fa-fw fa-lg fa-facebook"></i></a></li>';
    }
  }

  if ($twitter > 0) {
    $url = variable_get('etype_twitter_url');
    if (! empty($url)) {
      $output .= '<li><a href="' . $url . '" target="_blank"><i class="fab fa-fw fa-lg fa-twitter"></i></a></li>';
    }
  }

  if ($googleplus > 0) {
    $url = variable_get('etype_googleplus_url');
    if (! empty($url)) {
      $output .= '<li><a href="' . $url . '" target="_blank"><i class="fab fa-fw fa-lg fa-google-plus"></i></a></li>';
    }
  }

  if ($instagram > 0) {
    $url = variable_get('etype_instagram_url');
    if (! empty($url)) {
      $output .= '<li><a href="' . $url . '"><i class="fab fa-fw fa-lg fa-instagram"></i></a></li>';
    }
  }

  if ($youtube > 0) {
    $url = variable_get('etype_youtube_url');
    if (! empty($url)) {
      $output .= '<li><a href="' . $url . '" target="_blank"><i class="fab fa-fw fa-lg fa-youtube"></i></a></li>';
    }
  }

  if ($pinterest > 0) {
    $url = variable_get('etype_pinterest_url');
    if (! empty($url)) {
      $output .= '<li><a href="' . $url . '" target="_blank"><i class="fab fa-fw fa-lg fa-pinterest"></i></a></li>';
    }
  }

  if ($vimeo > 0) {
    $url = variable_get('etype_vimeo_url');
    if (! empty($url)) {
      $output .= '<li><a href="' . $url . '"><i class="fab fa-fw fa-lg fa-vimeo-square"></i></a></li>';
    }
  }

  if ($rss > 0) {
    $output .= '<li><a href="/rss.xml" target="_blank"><i class="fab fa-fw fa-lg fa-rss-square"></i></a></li>';
  }

  /* email form
  $output .= '
</ul>';

  $output .= '
<div class="subscribe-form">
    <form action="">
        <div>
            <div class="form-item form-type-textfield">
<input type="text" class="form-text" name="subscribe" value="Your email address" onfocus="if (this.value == \'Your email address\') {this.value = \'\';}" onblur="if (this.value == \'\') {this.value = \'Your email address\';}" />
            </div>
            <div class="form-actions">
<input value="" type="submit" id="edit-submit" name="subscribe" class="form-submit">
            </div>
        </div>
     </form>
</div>
';
  */

  return $output;

}

/**
 * Follow block for Contact page
 */
function _etype_contact_follow_content() {

  $output = '
<ul class="social-bookmarks large">';

  $facebook = variable_get('etype_facebook_contact');
  $twitter = variable_get('etype_twitter_contact');
  $googleplus = variable_get('etype_googleplus_contact');
  $instagram = variable_get('etype_instagram_contact');
  $youtube = variable_get('etype_youtube_contact');
  $pinterest = variable_get('etype_pinterest_contact');
  $vimeo = variable_get('etype_vimeo_contact');
  $rss = variable_get('etype_rss_contact');

  if ($facebook > 0) {
    $url = variable_get('etype_facebook_url');
    if (! empty($url)) {
      $output .= '<li><a href="' . $url . '" target="_blank"><i class="fab fa-fw fa-lg fa-facebook"></i></a></li>';
    }
  }

  if ($twitter > 0) {
    $url = variable_get('etype_twitter_url');
    if (! empty($url)) {
      $output .= '<li><a href="' . $url . '" target="_blank"><i class="fab fa-fw fa-lg fa-twitter"></i></a></li>';
    }
  }

  if ($googleplus > 0) {
    $url = variable_get('etype_googleplus_url');
    if (! empty($url)) {
      $output .= '<li><a href="' . $url . '" target="_blank"><i class="fab fa-fw fa-lg fa-google-plus"></i></a></li>';
    }
  }

  if ($instagram > 0) {
    $url = variable_get('etype_instagram_url');
    if (! empty($url)) {
      $output .= '<li><a href="' . $url . '" target="_blank"><i class="fab fa-fw fa-lg fa-instagram"></i></a></li>';
    }
  }

  if ($youtube > 0) {
    $url = variable_get('etype_youtube_url');
    if (! empty($url)) {
      $output .= '<li><a href="' . $url . '" target="_blank"><i class="fab fa-fw fa-lg fa-youtube"></i></a></li>';
    }
  }

  if ($pinterest > 0) {
    $url = variable_get('etype_pinterest_url');
    if (! empty($url)) {
      $output .= '<li><a href="' . $url . '" target="_blank"><i class="fab fa-fw fa-lg fa-pinterest"></i></a></li>';
    }
  }

  if ($vimeo > 0) {
    $url = variable_get('etype_vimeo_url');
    if (! empty($url)) {
      $output .= '<li><a href="' . $url . '" target="_blank"><i class="fab fa-fw fa-lg fa-vimeo-square"></i></a></li>';
    }
  }

  if ($rss > 0) {
    $output .= '<li><a href="/rss.xml" target="_blank"><i class="fab fa-fw fa-lg fa-rss-square"></i></a></li>';
  }

  $output .= '
</ul>';

  return $output;

}

/**
 * Fake User Menu
 */
function _etype_menu_content() {
  global $user;
  $output = "<ul class=\"user-menu menu\">";
  if($user ->uid != 0) {
    $username= $user ->name;
    $pub_id = variable_get('etype_pub');
    $ptype = variable_get('etype_ptype');
    $output .= "<li><a 
href=\"https://www.etypeservices.com/ReadTheEdition.aspx?Username=$username&Pub=$pub_id&PType=$ptype\"  title=\"\" target=\"_blank\">e-Edition</a></li>";
    $output .= "<li><a href=\"/content/my-account\" title=\"\">My account</a></li>";
    $output .= "<li><a href=\"/user/logout\" title=\"\">Log out</a></li>";
  } else {
    $e_edition =  variable_get('etype_e_edition');
    $output .= "<li><a href=\"/content/custom-login-page\" title=\"\">Login</a></li><li><a 
href=\"https://www.etypeservices.com/$e_edition/\" title=\"\">Subscribe</a></li>";
  }
  $output .= "</ul>";
  return $output;
}