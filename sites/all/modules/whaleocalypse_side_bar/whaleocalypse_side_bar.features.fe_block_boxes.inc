<?php
/**
 * @file
 * whaleocalypse_side_bar.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function whaleocalypse_side_bar_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'About';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'about';
  $fe_block_boxes->body = '<img src="' . drupal_get_path('module', 'whaleocalypse_side_bar') . '/images/about.jpg" />';

  $export['about'] = $fe_block_boxes;

  return $export;
}
