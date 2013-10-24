<?php
/**
 * @file
 * whaleocalypse_side_bar.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function whaleocalypse_side_bar_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['block-about'] = array(
    'cache' => -1,
    'custom' => 0,
    'machine_name' => 'about',
    'module' => 'block',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'whaleocalypse' => array(
        'region' => 'sidebar_second',
        'status' => 1,
        'theme' => 'whaleocalypse',
        'weight' => 0,
      ),
    ),
    'title' => 'About',
    'visibility' => 0,
  );

  $export['search-form'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'form',
    'module' => 'search',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'seven' => array(
        'region' => 'dashboard_sidebar',
        'status' => 1,
        'theme' => 'seven',
        'weight' => -10,
      ),
      'whaleocalypse' => array(
        'region' => 'sidebar_second',
        'status' => 1,
        'theme' => 'whaleocalypse',
        'weight' => -8,
      ),
    ),
    'title' => 'Search Transcripts',
    'visibility' => 0,
  );

  return $export;
}
