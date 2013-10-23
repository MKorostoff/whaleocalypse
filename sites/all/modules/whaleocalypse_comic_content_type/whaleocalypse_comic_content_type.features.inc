<?php
/**
 * @file
 * whaleocalypse_comic_content_type.features.inc
 */

/**
 * Implements hook_views_api().
 */
function whaleocalypse_comic_content_type_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function whaleocalypse_comic_content_type_image_default_styles() {
  $styles = array();

  // Exported image style: comic_main.
  $styles['comic_main'] = array(
    'name' => 'comic_main',
    'label' => 'Comic',
    'effects' => array(
      2 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'retina_images_image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'retina_images_image_scale_form',
        'summary theme' => 'retina_images_image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 788,
          'height' => '',
          'upscale' => 0,
          'retinafy' => 1,
        ),
        'weight' => 2,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function whaleocalypse_comic_content_type_node_info() {
  $items = array(
    'comic' => array(
      'name' => t('Comic'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
