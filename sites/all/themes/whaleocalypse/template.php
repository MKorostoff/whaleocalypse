<?php

/**
 * Implements theme_preprocess_page.
 * This fixes a bug in top_node where the page title fails to show up.
 * @todo
 *   Generalize this fix to respect views page title settings and contribute it
 *   back to the top node project.  While we're at it, try and fix that problem
 *   where top_node replaces the $_GET['q'] variable.
 */
function whaleocalypse_preprocess_page(&$vars) {
	$node = menu_get_object();
	if ( is_object($node) && $node->type == 'comic') {
		$vars['title'] = l($node->title, 'node/' . $node->nid);
	}
}

/**
 * Implements theme_preprocess_comment.  This controls the display of the
 * username in comments.  Logic works like this:
 * 
 * 1) if the commenter does not supply an author name, default to 'Anonymous'
 * 2) if the author does supply a name, show the name.
 * 3) if the author supplies a homepage, link the name to the homepage (i.e. <a href="homepage">author</a>)
 *
 * We'll also use this to get the gravatar if one exists and cache a 60x60 pixel
 * version using imagecache_external.
 *
 * @todo 
 *   Fix it so that my personal picture and username link to mattkorostoff.com 
 *   instead of the drupal user profile page.
 */
function whaleocalypse_preprocess_comment(&$vars) {
	$cid = $vars['elements']['#comment']->cid;
	$author_name = $vars['elements']['#comment']->name;
	if ('Anonymous' == $author_name) {
		$result = db_query('SELECT c.name,c.homepage,c.mail FROM {comment} c WHERE c.cid = :cid', array(':cid' => $cid))->fetchAssoc();
		$vars['real_name'] = t('Anonymous');
		
		$email = '';
		if ($result['mail']) {
			$email = $result['mail'];
		}
		//Light weight gravatar implementation
		$gravatar = "http://www.gravatar.com/avatar/" . 
		md5( strtolower( trim( $email ) ) ) . 
		"?d=" . urlencode( 'identicon' ) . 
		"&s=60";

		$vars['picture'] = '<div class="user-picture">' . 
		theme('imagecache_external', array('path' => $gravatar, 'style_name'=> 'user_image')) . 
		'</div>';

		if ($result['name']) {
			$vars['author'] = $result['name'];
		}

		if ($result['homepage']) {
			$vars['author'] = l($vars['author'], $result['homepage'], array("attributes" => array("target" => "_blank")));
		}
	} 
}