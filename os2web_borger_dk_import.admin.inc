<?php
/**
 * @file
 *
 */

/**
 * Implements hook_form().
 */
function os2web_borger_dk_import_settings_form($form, $form_state) {
  $form['vertical_settings_tab'] = array(
    '#type' => 'vertical_tabs',
    '#weight' => 0,
  );
  // Form element. It's a fieldset , "Toggle display"
  $form['os2web_borger_dk_import_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Toggle display'),
    '#collapsible' => TRUE,
    '#group' => 'vertical_settings_tab',
  );
  $data = field_info_instances('node', 'borger_dk_article');
  $newdata = array();
  $field_name = array();
  $field_name['title'] = 'title';
  $newdata['title'] = t('Title');
  foreach ($data as $type => $item) {
    $newdata[$type] = t($item['label']);
    $field_name[$type] = $type;
  }
  $form_display = variable_get('os2web_borger_dk_import_display', array(NULL));
  (!empty($form_display)) ? $selected = $form_display : $selected = $field_name;
  $form['os2web_borger_dk_import_settings']['os2web_borger_dk_import_display'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Visible article fields'),
    '#options' => $newdata,
    '#description' => t('Check or uncheck the respective fields'),
    '#default_value' => $selected,
    '#group' => 'vertical_settings_tab',
  );
  $form['os2web_borger_dk_import_settings_2'] = array(
    '#type' => 'fieldset',
    '#title' => t('Editable article fields'),
    '#collapsible' => TRUE,
    '#group' => 'vertical_settings_tab',
  );
  $form_editable = variable_get('os2web_borger_dk_import_editable', array(NULL));
  (!empty($form_editable)) ? $selected2 = $form_editable : $selected2 = $field_name;
  $form['os2web_borger_dk_import_settings_2']['os2web_borger_dk_import_editable'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Editable article fields'),
    '#options' => $newdata,
    '#description' => t('Check or uncheck the respective fields'),
    '#default_value' => $selected2,
    '#group' => 'vertical_settings_tab',
  );

  $form['os2web_borger_dk_import_settings_3'] = array(
    '#type' => 'fieldset',
    '#title' => t('Activate nightly article syncronization'),
    '#collapsible' => TRUE,
   // '#group' => 'vertical_settings_tab',
  );

  // error_log(print_r($form_nightly_sync, TRUE) ."\n");
  $form['os2web_borger_dk_import_settings_3']['nightly_article_sync'] = array(
    '#type' => 'select',
    '#title' => t('Select when you want to syncronize'),
    '#options' => drupal_map_assoc(range(1, 24)),
    '#description' => t("Syncronization time"),
    '#default_value' => variable_get('nightly_article_sync'),
    // '#group' => 'vertical_settings_tab',
  );

  return system_settings_form($form);
}
