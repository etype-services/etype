<?php

/* Admin Settings */
function etype_admin() {

  $form = [];

  /* e_edition settings */
  $form['e_edition'] = [
    '#type' => 'fieldset',
    '#title' => t('e-Edition/Login'),
  ];

  $form['e_edition']['etype_e_edition'] = [
    '#type' => 'textarea',
    '#title' => t('e-Edition'),
    '#description' => t('For one paper enter the e-Edition like <code>Mitchell%20News-JournalID617</code>, for more than one format like this: <code>Mitchell%20News-JournalID617|Mitchell News Journal,The%20Yorktown%20News-ViewID84|The Yorktown News View</code>'),
    '#size' => 101,
    '#default_value' => variable_get('etype_e_edition'),
  ];

  $etype_pub = variable_get('etype_pub');
  $etype_pub_fixed = preg_replace("/[\s_]/", "", $etype_pub);

  $form['e_edition']['etype_pub'] = [
    '#type' => 'textfield',
    '#title' => t('eType Pub Id'),
    '#description' => t('Separate multiple entries with a comma, in the same order as the e-Editions'),
    '#size' => 55,
    '#default_value' => $etype_pub_fixed,
  ];

  $form['e_edition']['etype_ptype'] = [
    '#type' => 'textfield',
    '#title' => t('eType PType'),
    '#description' => t('Separate multiple entries with a comma, in the same order as the e-Editions'),
    '#size' => 55,
    '#default_value' => variable_get('etype_ptype'),
  ];

  $form['e_edition']['etype_v2'] = [
    '#type' => 'checkbox',
    '#title' => t('Use V2 Login'),
    '#default_value' => variable_get('etype_v2', 0),
  ];

  /* facebook */
  $form['facebook'] = [
    '#type' => 'fieldset',
    '#title' => t('Facebook'),
  ];

  $form['facebook']['etype_facebook_url'] = [
    '#type' => 'textfield',
    '#title' => t('Facebook URL'),
    '#size' => 55,
    '#default_value' => variable_get('etype_facebook_url', 'https://www.facebook.com/'),
  ];

  $form['facebook']['etype_facebook_top'] = [
    '#type' => 'checkbox',
    '#title' => t('Add link to main navigation bar'),
    '#default_value' => variable_get('etype_facebook_top', 0),
  ];

  $form['facebook']['etype_facebook_footer'] = [
    '#type' => 'checkbox',
    '#title' => t('Add link to footer area'),
    '#default_value' => variable_get('etype_facebook_footer', 0),
  ];

  $form['facebook']['etype_facebook_contact'] = [
    '#type' => 'checkbox',
    '#title' => t('Add link to Contact page (News+ theme only)'),
    '#default_value' => variable_get('etype_facebook_contact', 0),
  ];


  /* twitter */
  $form['twitter'] = [
    '#type' => 'fieldset',
    '#title' => t('Twitter'),
  ];

  $form['twitter']['etype_twitter_url'] = [
    '#type' => 'textfield',
    '#title' => t('Twitter'),
    '#description' => t('Twitter URL'),
    '#size' => 55,
    '#default_value' => variable_get('etype_twitter_url', 'https://twitter.com/'),
  ];

  $form['twitter']['etype_twitter_top'] = [
    '#type' => 'checkbox',
    '#title' => t('Add link to main navigation bar'),
    '#default_value' => variable_get('etype_twitter_top', 0),
  ];

  $form['twitter']['etype_twitter_footer'] = [
    '#type' => 'checkbox',
    '#title' => t('Add link to footer area'),
    '#default_value' => variable_get('etype_twitter_footer', 0),
  ];

  $form['twitter']['etype_twitter_contact'] = [
    '#type' => 'checkbox',
    '#title' => t('Add link to Contact page (News+ theme only)'),
    '#default_value' => variable_get('etype_twitter_contact', 0),
  ];

  /* youtube */
  $form['youtube'] = [
    '#type' => 'fieldset',
    '#title' => t('YouTube'),
  ];

  $form['youtube']['etype_youtube_url'] = [
    '#type' => 'textfield',
    '#title' => t('YouTube'),
    '#description' => t('YouTube URL'),
    '#size' => 55,
    '#default_value' => variable_get('etype_youtube_url', 'https://youtube.com/'),
  ];

  $form['youtube']['etype_youtube_top'] = [
    '#type' => 'checkbox',
    '#title' => t('Add link to main navigation bar'),
    '#default_value' => variable_get('etype_youtube_top', 0),
  ];

  $form['youtube']['etype_youtube_footer'] = [
    '#type' => 'checkbox',
    '#title' => t('Add link to footer area'),
    '#default_value' => variable_get('etype_youtube_footer', 0),
  ];

  $form['youtube']['etype_youtube_contact'] = [
    '#type' => 'checkbox',
    '#title' => t('Add link to Contact page (News+ theme only)'),
    '#default_value' => variable_get('etype_youtube_contact', 0),
  ];

  /* instagram */
  $form['instagram'] = [
    '#type' => 'fieldset',
    '#title' => t('Instagram'),
  ];

  $form['instagram']['etype_instagram_url'] = [
    '#type' => 'textfield',
    '#title' => t('Instagram'),
    '#description' => t('Instagram URL'),
    '#size' => 55,
    '#default_value' => variable_get('etype_instagram_url', 'https://instagram.com/'),
  ];

  $form['instagram']['etype_instagram_top'] = [
    '#type' => 'checkbox',
    '#title' => t('Add link to main navigation bar'),
    '#default_value' => variable_get('etype_instagram_top', 0),
  ];

  $form['instagram']['etype_instagram_footer'] = [
    '#type' => 'checkbox',
    '#title' => t('Add link to footer area'),
    '#default_value' => variable_get('etype_instagram_footer', 0),
  ];

  $form['instagram']['etype_instagram_contact'] = [
    '#type' => 'checkbox',
    '#title' => t('Add link to Contact page (News+ theme only)'),
    '#default_value' => variable_get('etype_instagram_contact', 0),
  ];

  /* pinterest */
  $form['pinterest'] = [
    '#type' => 'fieldset',
    '#title' => t('Pinterest'),
  ];

  $form['pinterest']['etype_pinterest_url'] = [
    '#type' => 'textfield',
    '#title' => t('Pinterest'),
    '#description' => t('Pinterest URL'),
    '#size' => 55,
    '#default_value' => variable_get('etype_pinterest_url', 'https://pinterest.com/'),
  ];

  $form['pinterest']['etype_pinterest_top'] = [
    '#type' => 'checkbox',
    '#title' => t('Add link to main navigation bar'),
    '#default_value' => variable_get('etype_pinterest_top', 0),
  ];

  $form['pinterest']['etype_pinterest_footer'] = [
    '#type' => 'checkbox',
    '#title' => t('Add link to footer area'),
    '#default_value' => variable_get('etype_pinterest_footer', 0),
  ];

  $form['pinterest']['etype_pinterest_contact'] = [
    '#type' => 'checkbox',
    '#title' => t('Add link to Contact page (News+ theme only)'),
    '#default_value' => variable_get('etype_pinterest_contact', 0),
  ];

  /* vimeo */
  $form['vimeo'] = [
    '#type' => 'fieldset',
    '#title' => t('Vimeo'),
  ];

  $form['vimeo']['etype_vimeo_url'] = [
    '#type' => 'textfield',
    '#title' => t('Vimeo'),
    '#description' => t('Vimeo URL'),
    '#size' => 55,
    '#default_value' => variable_get('etype_vimeo_url', 'https://vimeo.com/'),
  ];

  $form['vimeo']['etype_vimeo_top'] = [
    '#type' => 'checkbox',
    '#title' => t('Add link to main navigation bar'),
    '#default_value' => variable_get('etype_vimeo_top', 0),
  ];

  $form['vimeo']['etype_vimeo_footer'] = [
    '#type' => 'checkbox',
    '#title' => t('Add link to footer area'),
    '#default_value' => variable_get('etype_vimeo_footer', 0),
  ];

  $form['vimeo']['etype_vimeo_contact'] = [
    '#type' => 'checkbox',
    '#title' => t('Add link to Contact page (News+ theme only)'),
    '#default_value' => variable_get('etype_vimeo_contact', 0),
  ];

  /* rss */
  $form['rss'] = [
    '#type' => 'fieldset',
    '#title' => t('RSS'),
  ];

  $form['rss']['etype_rss_top'] = [
    '#type' => 'checkbox',
    '#title' => t('Add link to main navigation bar'),
    '#default_value' => variable_get('etype_rss_top', 0),
  ];

  $form['rss']['etype_rss_footer'] = [
    '#type' => 'checkbox',
    '#title' => t('Add link to footer area'),
    '#default_value' => variable_get('etype_rss_footer', 0),
  ];

  $form['rss']['etype_rss_contact'] = [
    '#type' => 'checkbox',
    '#title' => t('Add link to Contact page (News+ theme only)'),
    '#default_value' => variable_get('etype_rss_contact', 0),
  ];

  /* Search box */
  $form['search_to_social'] = [
    '#type' => 'fieldset',
    '#title' => t('Search Block'),
  ];

  $form['search_to_social']['etype_add_search_to_social'] = [
    '#type' => 'checkbox',
    '#title' => t('Add Search box to header eType Social block'),
    '#description' => t('Usually checked for News+ theme, unchecked for Synergy/MDTheNews themes.'),
    '#default_value' => variable_get('etype_add_search_to_social', 0),
  ];


  /* Google Identifiers */
  $form['etype_google'] = [
    '#type' => 'fieldset',
    '#title' => t('Google'),
  ];

  $form['etype_google']['etype_google_analytics_property_id'] = [
    '#type' => 'textfield',
    '#title' => t('Analytics Web Property ID'),
    '#size' => 55,
    '#default_value' => variable_get('etype_google_analytics_property_id', ''),
  ];

  $form['etype_google']['etype_google_adsense_property_id'] = [
    '#type' => 'textfield',
    '#title' => t('Adsense ID'),
    '#size' => 55,
    '#default_value' => variable_get('etype_google_adsense_property_id', ''),
  ];

  /* Scripts */
  $form['etype_scripts'] = [
    '#type' => 'fieldset',
    '#title' => t('Scripts'),
  ];

  $form['etype_scripts']['etype_head_script'] = [
    '#type' => 'textarea',
    '#title' => t('Script(s) for &lt;head&gt;'),
    '#description' => t('Inserted at the end of &lt;head&gt; area'),
    '#size' => 55,
    '#default_value' => variable_get('etype_head_script', ''),
  ];

  $form['etype_scripts']['etype_body_script'] = [
    '#type' => 'textarea',
    '#title' => t('Script(s) for &lt;body&gt;'),
    '#description' => t('Inserted at the end of &lt;body&gt; area'),
    '#size' => 55,
    '#default_value' => variable_get('etype_body_script', ''),
  ];

  $form['etype_scripts']['etype_ada_compliance'] = [
    '#type' => 'checkbox',
    '#title' => t('Add ADA Compliance script'),
    '#default_value' => variable_get('etype_ada_compliance', 0),
  ];

  /* Classified Ads Import */
  $form['etype_classified'] = [
    '#type' => 'fieldset',
    '#title' => t('Classified Ads Import Settings'),
  ];

  $form['etype_classified']['etype_classified_import_url'] = array(
    '#type' => 'textfield',
    '#title' => t('eType Classified Import URL'),
    '#size' => 55,
    '#default_value' => variable_get('etype_classified_import_url'),
  );

  $form['etype_classified']['etype_classified_cron'] = array(
    '#type' => 'textfield',
    '#title' => t('eType Classified Import Schedule'),
    '#description' => t('Use crontab syntax'),
    '#size' => 55,
    '#default_value' => variable_get('etype_classified_cron'),
  );

  $form['etype_classified']['etype_classified_map'] = [
    '#type' => 'textarea',
    '#title' => t('eType Classified Mapping'),
    '#description' => t('Enter VDATA Category Id and matching <a href="/admin/structure/taxonomy/classified_categories" target="_blank">Classified Ad term id</a> on one line, e.g C101|123'),
    '#size' => 101,
    '#default_value' => variable_get('etype_classified_map'),
  ];

  return system_settings_form($form);
}
