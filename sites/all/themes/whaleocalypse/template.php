<?php

function whaleocalypse_preprocess_page(&$vars) {
	if ($vars['is_front']) {
		$node = menu_get_object();
		$vars['title'] = l($node->title, 'node/' . $node->nid);
	}
}

/**
 * Implements theme_preprocess_comment.
 *
 * This accomplishes two things for us.  First of all, 
 */
function whaleocalypse_preprocess_comment(&$vars) {
	$cid = $vars['elements']['#comment']->cid;
	$author_name = $vars['elements']['#comment']->name;
	if ('Anonymous' == $author_name) {
		$result = db_query('SELECT c.name,c.homepage FROM {comment} c WHERE c.cid = :cid', array(':cid' => $cid))->fetchAssoc();
		$vars['real_name'] = t('Anonymous');
		
		if ($result['name']) {
			$vars['author'] = $result['name'];
		}

		if ($result['homepage']) {
			$vars['author'] = l($vars['author'], $result['homepage'], array("attributes" => array("target" => "_blank")));
		}
	}
}