<?php

/* BLOCKS */

/**
 * Implements hook_block_info().
 */
function etype_block_info() {
  $blocks = array();

  $blocks['Social'] = array(
    'info' => t('Social'),
  );

  $blocks['Follow'] = array(
    'info' => t('Follow'),
  );

  $blocks['Facebook'] = array(
    'info' => t('Facebook'),
  );

  $blocks['Twitter'] = array(
    'info' => t('Twitter'),
  );

  $blocks['e-Edition'] = array(
    'info' => t('e-Edition'),
  );
  return $blocks;
}

/**
 * Implements hook_block_view().
 */
function etype_block_view($delta = '') {
  $block = array();
  switch ($delta) {

    case 'Social':
      $block['subject'] = '';
      $block['content'] = _etype_social_content();
      break;

    case 'Follow':
      $block['subject'] = 'Follow Us';
      $block['content'] = _etype_follow_content();
      break;

    case 'Facebook':
      $block['subject'] = 'Facebook';
      $block['content'] = _etype_facebook_content();
      break;

    case 'Twitter':
      $block['subject'] = 'Twitter';
      $block['content'] = _etype_twitter_content();
      break;

    case 'e-Edition':
      $block['subject'] = '';
      $block['content'] = _etype_e_edition_content();
      break;
  }
  return $block;
}

/**
 * Social Block for Header
 * @return null
 */
function _etype_social_content() {
  $output = '
  <ul class="social-links">';
  $facebook = theme_get_setting('facebook');
  $twitter = theme_get_setting('twitter');
  $pinterest = theme_get_setting('pinterest');
  $instagram = theme_get_setting('instagram');
  $googleplus = theme_get_setting('googleplus');
  $youtube = theme_get_setting('youtube');
  $rssfeed = theme_get_setting('rssfeed');

  if (empty($facebook)) {
    $facebook = variable_get('etype_facebook_top');
    $twitter = variable_get('etype_twitter_top');
    $instagram = variable_get('etype_instagram_top');
    $youtube = variable_get('etype_youtube_top');
    $pinterest = variable_get('etype_pinterest_top');
    $vimeo = variable_get('etype_vimeo_top');
    $rss = variable_get('etype_rss_top');
  }

  if (!empty($facebook)) {
    $output .= '<li><a class="facebook" href="https://www.facebook.com/' . $facebook . '"></a></li>';
  }
  if (!empty($twitter)) {
    $output .= '<li><a class="twitter" href="https://twitter.com/' . $twitter . '"></a></li>';
  }
  if (!empty($pinterest)) {
    $output .= '<li><a class="pinterest" href="https://www.pinterest.com/' . $pinterest . '"></a></li>';
  }
  if (!empty($instagram)) {
    $output .= '<li><a class="instagram" href="https://instagram.com/' . $instagram . '"></a></li>';
  }
  if (!empty($googleplus)) {
    $output .= '<li><a class="googleplus" href="https://plus.google.com/' . $googleplus . '"></a></li>';
  }
  if (!empty($youtube)) {
    $output .= '<li><a class="youtube" href="' . $youtube . '"></a></li>';
  }
  if (!empty($rssfeed)) {
    $output .= '<li><a class="rss" href="/rss.xml"></a></li>';
  }
  $output .= '</ul>';
  return $output;
}

/**
 * Follow Block in Footer
 * @return null
 */
function _etype_follow_content() {
  $output = '';
  $facebook = theme_get_setting('facebook');
  $twitter = theme_get_setting('twitter');
  $pinterest = theme_get_setting('pinterest');
  $instagram = theme_get_setting('instagram');
  $googleplus = theme_get_setting('googleplus');
  $youtube = theme_get_setting('youtube');
  $rssfeed = theme_get_setting('rssfeed');
  if (!empty($facebook)) {
    $output .= '<div class="facebook"><a href="https://www.facebook.com/' . $facebook . '">Like us on Facebook</a></div>';
  }
  if (!empty($twitter)) {
    $output .= '<div class="twitter"><a href="https://twitter.com/' . $twitter . '">Follow us on Twitter</a></div>';
  }
  if (!empty($pinterest)) {
    $output .= '<div class="pinterest"><a href="https://www.pinterest.com/' . $pinterest . '">Follow us on Pinterest</a></div>';
  }
  if (!empty($instagram)) {
    $output .= '<div class="instagram"><a href="https://instagram.com/' . $instagram . '">Follow us on Instagram</a></div>';
  }
  if (!empty($googleplus)) {
    $output .= '<div class="googleplus"><a href="https://plus.google.com/' . $googleplus . '">Follow us on Google Plus</a></div>';
  }
  if (!empty($youtube)) {
    $output .= '<div class="youtube"><a href="' . $youtube . '">Follow us on YouTube</a></div>';
  }
  if (!empty($rssfeed)) {
    $output .= '<div class="rss"><a href="/rss.xml">RSS Feed</a></div>';
  }
  return $output;
}

/**
 * @return string
 */
function _etype_facebook_content() {
  $output = '';
  $facebook = theme_get_setting('facebook', 'cni');
  if (!empty($facebook)) {
    $output .= '
 <div class="fb-page" data-href="https://www.facebook.com/' . $facebook . '" data-tabs="timeline" data-small-header="true" data-adapt-container-width="true" data-hide-cover="false" data-show-facepile="true"></div>
    ';
  }

  return $output;
}

/**
 * @return string
 */
function _etype_twitter_content() {
  $output = '';
  $twitter = theme_get_setting('twitter');
  if (!empty($twitter)) {
    $output .= '
<a class="twitter-timeline" data-height="300" href="https://twitter.com/' . $twitter . '">Tweets by ' . $twitter . '</a> <script async src="//platform.twitter.com/widgets.js" charset="utf-8"></script>';
  }

  return $output;
}

/**
 * e-Edition block
 */
function _etype_e_edition_content() {
  $e_editions = etype_e_editions();
  $output = '';
  foreach($e_editions as $e_edition) {
    $output .= '
<p class="rtecenter"><a href="' . $e_edition['path'] . '"><img src="' . $e_edition['image'] . '" alt="' . $e_edition['site_name'] . ' e-Edition" /></a></p><h4 class="rtecenter"><a href="' .
      $e_edition['path'] . '">Click here to read ' .
      $e_edition['site_name'] . '</a></h4>
';
  }
  return $output;
}
