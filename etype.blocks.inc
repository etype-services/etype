<?php

/* BLOCKS */

/**
 * Implements hook_block_info().
 */
function etype_block_info() {
  $blocks = [];

  $blocks['e-edition'] = [
    'info' => t('e-Edition'),
  ];

  $blocks['social-search'] = [
    'info' => t('eType Social Search'),
  ];

  $blocks['follow'] = [
    'info' => t('eType Follow'),
  ];

  $blocks['contact-page-follow'] = [
    'info' => t('eType Contact Page Follow'),
  ];

  $blocks['etype-facebook-feed'] = [
    'info' => t('eType Facebook Feed'),
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
    case 'e-edition':
      $block['subject'] = '';
      $block['content'] = _etype_e_edition_content();
      break;

    case 'social-search':
      $block['subject'] = '';
      $block['content'] = _etype_social_search_content();
      break;

    case 'follow':
      $block['subject'] = '';
      $block['content'] = _etype_follow_content();
      break;

    case 'contact-page-follow':
      $block['subject'] = '';
      $block['content'] = _etype_contact_follow_content();
      break;

    case 'etype-facebook-feed':
      $block['subject'] = 'Facebook Feed';
      $block['content'] = _etype_facebook_feed_content();
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
<p><a href="' . $e_edition['path'] . '"><img src="' . $e_edition['image'] . '" alt="' . $e_edition['site_name'] . ' e-Edition"></a></p>
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
      $output .= '<li><a href="' . $url . '" target="_blank"><i class="fab fa-fw fa-2x fa-facebook"></i></a></li>';
    }
  }

  if ($twitter > 0) {
    $url = variable_get('etype_twitter_url');
    if (! empty($url)) {
      $output .= '<li><a href="' . $url . '" target="_blank"><i class="fab fa-fw fa-2x fa-twitter"></i></a></li>';
    }
  }

  if ($googleplus > 0) {
    $url = variable_get('etype_googleplus_url');
    if (! empty($url)) {

    }
    $output .= '<li><a href="' . $url . '" target="_blank"><i class="fab fa-fw fa-2x fa-google-plus"></i></a></li>';
  }

  if ($instagram > 0) {
    $url = variable_get('etype_instagram_url');
    if (! empty($url)) {
      $output .= '<li><a href="' . $url . '" target="_blank"><i class="fab fa-fw fa-2x fa-instagram"></i></a></li>';
    }
  }

  if ($youtube > 0) {
    $url = variable_get('etype_youtube_url');
    if (! empty($url)) {
      $output .= '<li><a href="' . $url . '" target="_blank"><i class="fab fa-fw fa-2x fa-youtube"></i></a></li>';
    }
  }

  if ($pinterest > 0) {
    $url = variable_get('etype_pinterest_url');
    if (! empty($url)) {
      $output .= '<li><a href="' . $url . '" target="_blank"><i class="fab fa-fw fa-2x fa-pinterest"></i></a></li>';
    }
  }

  if ($vimeo > 0) {
    $url = variable_get('etype_vimeo_url');
    if (! empty($url)) {
      $output .= '<li><a href="' . $url . '" target="_blank"><i class="fab fa-fw fa-2x fa-vimeo-square"></i></a></li>';
    }
  }

  if ($rss > 0) {
    $output .= '<li><a href="/rss.xml" target="_blank"><i class="fas fa-fw fa-2x fa-rss-square"></i></a></li>';
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
      $output .= '<li><a href="' . $url . '" target="_blank"><i class="fab fa-fw fa-2x fa-facebook"></i></a></li>';
    }
  }

  if ($twitter > 0) {
    $url = variable_get('etype_twitter_url');
    if (! empty($url)) {
      $output .= '<li><a href="' . $url . '" target="_blank"><i class="fab fa-fw fa-2x fa-twitter"></i></a></li>';
    }
  }

  if ($googleplus > 0) {
    $url = variable_get('etype_googleplus_url');
    if (! empty($url)) {
      $output .= '<li><a href="' . $url . '" target="_blank"><i class="fab fa-fw fa-2x fa-google-plus"></i></a></li>';
    }
  }

  if ($instagram > 0) {
    $url = variable_get('etype_instagram_url');
    if (! empty($url)) {
      $output .= '<li><a href="' . $url . '"><i class="fab fa-fw fa-2x fa-instagram"></i></a></li>';
    }
  }

  if ($youtube > 0) {
    $url = variable_get('etype_youtube_url');
    if (! empty($url)) {
      $output .= '<li><a href="' . $url . '" target="_blank"><i class="fab fa-fw fa-2x fa-youtube"></i></a></li>';
    }
  }

  if ($pinterest > 0) {
    $url = variable_get('etype_pinterest_url');
    if (! empty($url)) {
      $output .= '<li><a href="' . $url . '" target="_blank"><i class="fab fa-fw fa-2x fa-pinterest"></i></a></li>';
    }
  }

  if ($vimeo > 0) {
    $url = variable_get('etype_vimeo_url');
    if (! empty($url)) {
      $output .= '<li><a href="' . $url . '"><i class="fab fa-fw fa-2x fa-vimeo-square"></i></a></li>';
    }
  }

  if ($rss > 0) {
    $output .= '<li><a href="/rss.xml" target="_blank"><i class="fas fa-fw fa-2x fa-rss-square"></i></a></li>';
  }

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
      $output .= '<li><a href="' . $url . '" target="_blank"><i class="fab fa-fw fa-6x fa-facebook"></i></a></li>';
    }
  }

  if ($twitter > 0) {
    $url = variable_get('etype_twitter_url');
    if (! empty($url)) {
      $output .= '<li><a href="' . $url . '" target="_blank"><i class="fab fa-fw fa-6x fa-twitter"></i></a></li>';
    }
  }

  if ($googleplus > 0) {
    $url = variable_get('etype_googleplus_url');
    if (! empty($url)) {
      $output .= '<li><a href="' . $url . '" target="_blank"><i class="fab fa-fw fa-6x fa-google-plus"></i></a></li>';
    }
  }

  if ($instagram > 0) {
    $url = variable_get('etype_instagram_url');
    if (! empty($url)) {
      $output .= '<li><a href="' . $url . '" target="_blank"><i class="fab fa-fw fa-6x fa-instagram"></i></a></li>';
    }
  }

  if ($youtube > 0) {
    $url = variable_get('etype_youtube_url');
    if (! empty($url)) {
      $output .= '<li><a href="' . $url . '" target="_blank"><i class="fab fa-fw fa-6x fa-youtube"></i></a></li>';
    }
  }

  if ($pinterest > 0) {
    $url = variable_get('etype_pinterest_url');
    if (! empty($url)) {
      $output .= '<li><a href="' . $url . '" target="_blank"><i class="fab fa-fw fa-6x fa-pinterest"></i></a></li>';
    }
  }

  if ($vimeo > 0) {
    $url = variable_get('etype_vimeo_url');
    if (! empty($url)) {
      $output .= '<li><a href="' . $url . '" target="_blank"><i class="fab fa-fw fa-6x fa-vimeo-square"></i></a></li>';
    }
  }

  if ($rss > 0) {
    $output .= '<li><a href="/rss.xml" target="_blank"><i class="fas fa-fw fa-6x fa-rss-square"></i></a></li>';
  }

  $output .= '
</ul>';

  return $output;

}

/**
 * @return string
 */
function _etype_facebook_feed_content() {
  $url = variable_get('etype_facebook_url');
  $name = variable_get('site_name');
  $output = "
  <div id=\"fb-root\"></div>
<script>(function(d, s, id) {
  var js, fjs = d.getElementsByTagName(s)[0];
  if (d.getElementById(id)) return;
  js = d.createElement(s); js.id = id;
  js.src = 'https://connect.facebook.net/en_US/sdk.js#xfbml=1&version=v2.12';
  fjs.parentNode.insertBefore(js, fjs);
}(document, 'script', 'facebook-jssdk'));</script>
<div class=\"fb-page\" data-href=\"$url\" data-tabs=\"timeline\" data-width=\"340\" data-height=\"600\" data-small-header=\"true\" data-adapt-container-width=\"true\" data-hide-cover=\"false\" data-show-facepile=\"false\"><blockquote cite=\"$url\" class=\"fb-xfbml-parse-ignore\"><a href=\"$url\">$name</a></blockquote></div>
";
  return $output;
}
