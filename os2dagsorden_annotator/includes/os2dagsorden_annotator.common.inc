<?php

/**
 * os2dagsorden_annotator
 *
 * PHP version 5
 *
 * @category OS2Dagsorden
 * @package  OS2Dagsorden_Annotator
 * @file     The annotator module help functions, which might be used by another modules or views.
 * @author   Stanislav Kutasevits <stan@bellcom.dk>
 * @license  http://www.gnu.org/licenses/gpl-2.0.html GNU General Public License, version 2
 * @link     http://bellcom.dk
 *
 */

/**
 * Returns the notes using the attachment id.
 *
 * @param int $bilag_id attachment id
 *
 * @return array of notes.
 */
function os2dagsorden_annotator_get_notes_by_attachment_id($bilag_id) {
    global $user;
    $url = variable_get('os2dagsorden_annotator_url') . ':' . variable_get('os2dagsorden_annotator_port_nr') . '/search?drupal_user=' . $user->name . '&bilag_id=' . $bilag_id;

    return os2dagsorden_annotator_get_results($url);
}

/**
 * Returns the notes using the bullet point id.
 *
 * @param int $bullet_point_id bullet point id
 *
 * @return array of notes.
 */
function os2dagsorden_annotator_get_notes_by_bullet_point_id($bullet_point_id) {
    global $user;
    $url = variable_get('os2dagsorden_annotator_url') . ':' . variable_get('os2dagsorden_annotator_port_nr') . '/search?drupal_user=' . $user->name . '&bullet_point_id=' . $bullet_point_id;

    return os2dagsorden_annotator_get_results($url);
}

/**
 * Returns the notes using the meeting id.
 *
 * @param int $meeting_id meeting id
 *
 * @return array of notes.
 */
function os2dagsorden_annotator_get_notes_by_meeting_id($meeting_id) {
    global $user;
    $url = variable_get('os2dagsorden_annotator_url') . ':' . variable_get('os2dagsorden_annotator_port_nr') . '/search?drupal_user=' . $user->name . '&meeting_id=' . $meeting_id;

    return os2dagsorden_annotator_get_results($url);
}

/**
 * Helper function. Initiates curl procedure, that fetches the notes from the storage.
 *
 * @param string $url the composed search specification. Helps to filter the output results.
 *
 * @return array of notes.
 */
function os2dagsorden_annotator_get_results($url) {
    $ch = curl_init();

    // Set query data here with the URL
    curl_setopt($ch, CURLOPT_URL, $url);

    curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
    curl_setopt($ch, CURLOPT_TIMEOUT, '1');
    $content_json = trim(curl_exec($ch));
    curl_close($ch);

    $content = json_decode($content_json, TRUE);
    return $content['rows'];
}