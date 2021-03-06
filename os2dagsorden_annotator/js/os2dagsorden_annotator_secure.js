function init(name, meeting_id, bullet_point_id, bilag_id) {
	jQuery(document).ready(function() {
          	"use strict";
		jQuery('#content').annotator().annotator('addPlugin', 'Auth', {
			//tokenUrl: 'http://192.168.1.69:5001/auth',
			token: 'eyJhbGciOiAiSFMyNTYiLCAidHlwIjogIkpXVCJ9.eyJpc3N1ZWRBdCI6ICIyMDEyLTA3LTA5VDExOjMwOjQ2KzAwOjAwIiwgImNvbnN1bWVyS2V5IjogIjYwMjM2OGEwZTkwNTQ5MmZhZTg3Njk3ZWRhZDE0YzNhIiwgInVzZXJJZCI6ICJyb290IiwgInR0bCI6IDg2NDAwfQ.cnY_Q7IYMCbHiWyzeT-PnpLSpkq7QwmqGHAMBWLLzNc'
			//token: 'eyJhbGciOiAiSFMyNTYiLCAidHlwIjogIkpXVCJ9.eyJpc3N1ZWRBdCI6ICIyMDEyLTA3LTA5VDEyOjE2OjUyKzAwOjAwIiwgImNvbnN1bWVyS2V5IjogIjYwMjM2OGEwZTkwNTQ5MmZhZTg3Njk3ZWRhZDE0YzNhIiwgInVzZXJJZCI6ICJuZXJvb3QiLCAidHRsIjogODY0MDB9.FahfrNkrGy5GdV74P_clzG95zhYvo2KSDWPpgwCRHoQ'
		});
	
		jQuery('#content').annotator().annotator('addPlugin', 'Touch', {
			force: location.search.indexOf('force') > -1,
			useHighlighter: location.search.indexOf('highlighter') > -1
		});
	
		jQuery('#content').annotator().annotator('addPlugin', 'Filter');
	
		jQuery('#content').annotator().annotator('addPlugin', 'Permissions', {
			user: name
		});
	
		jQuery('#content').annotator().annotator('addPlugin', 'Store', {
			// The endpoint of the store on your server.
			prefix: 'http://192.168.1.69:5000/',
			annotationData: {
				'drupal_user': name,
				'bilag_id': bilag_id,
				'bullet_point_id': bullet_point_id,
				'meeting_id': meeting_id
			},
			loadFromSearch: {
				'drupal_user': name,
				'bilag_id': bilag_id,
				'bullet_point_id': bullet_point_id,
				'meeting_id': meeting_id
			}
		});	
	});
}