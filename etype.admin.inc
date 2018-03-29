<?php

/* Admin Settings */
function etype_admin() {

  $form = array();

  /* e_edition settings */
  $form['e_edition'] = array(
    '#type' => 'fieldset',
    '#title' => t('e-Edition'),
  );

  $form['e_edition']['etype_e_edition'] = array(
    '#type' => 'textarea',
    '#title' => t('e-Edition'),
    '#description' => t('For one paper enter the e-Edition like <code>Mitchell%20News-JournalID617</code>, for more than one format like this: <code>Mitchell%20News-JournalID617|Mitchell News Journal,The%20Yorktown%20News-ViewID84|The Yorktown News View</code>'),
    '#size' => 101,
    '#default_value' => variable_get('etype_e_edition'),
  );

  $form['e_edition']['etype_pub'] = array(
    '#type' => 'textfield',
    '#title' => t('eType Pub'),
    '#description' => t('Separate multiple entries with a comma, in the same order as the e-Editions'),
    '#size' => 55,
    '#default_value' => variable_get('etype_pub'),
  );

  $form['e_edition']['etype_ptype'] = array(
    '#type' => 'textfield',
    '#title' => t('eType PType'),
    '#description' => t('Separate multiple entries with a comma, in the same order as the e-Editions'),
    '#size' => 55,
    '#default_value' => variable_get('etype_ptype'),
  );

  return system_settings_form($form);
}