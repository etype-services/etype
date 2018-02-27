<?php

/* Admin Settings */
function etype_admin() {

  $form = [];

  /* e_edition settings */
  $form['e_edition'] = [
    '#type' => 'fieldset',
    '#title' => t('e-Edition'),
  ];

  $form['e_edition']['etype_e_edition'] = [
    '#type' => 'textfield',
    '#title' => t('e-Edition'),
    '#description' => t('For one paper enter the e-Edition like <code>Mitchell%20News-JournalID617</code>, for more than one format like this: <code>Mitchell%20News-JournalID617|Mitchell News Journal,The%20Yorktown%20News-ViewID84|The Yorktown News View</code>'),
    '#size' => 101,
    '#default_value' => variable_get('etype_e_edition'),
  ];

  $form['e_edition']['etype_pub'] = [
    '#type' => 'textfield',
    '#title' => t('eType Pub Id'),
    '#description' => t('Separate multiple entries with a comma, in the same order as the e-Editions'),
    '#size' => 55,
    '#default_value' => variable_get('etype_pub'),
  ];

  $form['e_edition']['etype_ptype'] = [
    '#type' => 'textfield',
    '#title' => t('eType PType'),
    '#description' => t('Separate multiple entries with a comma, in the same order as the e-Editions'),
    '#size' => 55,
    '#default_value' => variable_get('etype_ptype'),
  ];

  $form['e_edition']['etype_classified_cron'] = array(
    '#type' => 'textfield',
    '#title' => t('eType Classified Import Schedule'),
    '#description' => t('Use crontab syntax'),
    '#size' => 55,
    '#default_value' => variable_get('etype_classified_cron'),
  );

  return system_settings_form($form);
}