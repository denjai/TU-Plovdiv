<?php
include('config/boot.php');
$errors = array();
$infos = array();


$form = $_POST['person'];
if(isset($form['ID'])) {
	$PID = $form['ID']+0;
}
else {
	$PID = $_GET['id']+0;
}

if($PID == 0) { // new person, no data
	$title = "Add New Person";
	$person = array();
}
else if(isset($form)) { // save/update person
	$title = "Edit Person";
}
else { // edit person
	$title = "Edit Person";
	$result = mysql_query("
		SELECT *
		FROM PERSONS_TBL
		WHERE ID = ".($PID)."
	");
	$person = mysql_fetch_assoc($result);
}


if(isset($_POST['person'])) { // if any data posted -> validate and update data
	$form = $_POST['person'];
	if(strlen(trim($form['NAME']))<=1) $errors[] = "NAME should be more than 1 character.";
	if(strlen(trim($form['FAM']))<=1) $errors[] = "FAM should be more than 1 character.";
	if(strlen(trim($form['ADDRESS']))<=5) $errors[] = "ADDRESS should be more than 5 characters.";

	if(count($errors) == 0) {
		$infos[] = "Person successfully saved.";

		if($PID == 0) { // no ID -> insert
			mysql_query(sprintf(
				"INSERT INTO PERSONS_TBL(NAME, FAM, ADDRESS) VALUES('%s','%s','%s')",
				mysql_real_escape_string(trim($form['NAME'])),
				mysql_real_escape_string(trim($form['FAM'])),
				mysql_real_escape_string(trim($form['ADDRESS']))
			));
		}
		else { // update
			mysql_query(sprintf(
				"UPDATE PERSONS_TBL SET NAME='%s', FAM='%s', ADDRESS='%s' WHERE ID=%d",
				mysql_real_escape_string(trim($form['NAME'])),
				mysql_real_escape_string(trim($form['FAM'])),
				mysql_real_escape_string(trim($form['ADDRESS'])),
				$PID
			));
		}
	}
}
else { // if no data submitted -> fill the form with data from the DB
	$form = $person; 
}

echo "<h1>$title</h1>";

if(count($errors)>0) {
	foreach($errors as $e) {
		echo "<p class='icon error_icon msg_err'>".$e."</p>";
	}
}
if(count($infos)>0) {
	foreach($infos as $i) {
		echo "<p class='icon ok_icon msg_ok'>".$i."</p>";
	}
}

echo "<form id='person-edit-form' action='person-edit-ajax.php' enctype='multipart/form-data' method='post'>";
echo "<input type='hidden' name='person[ID]' value='".htmlspecialchars($form['ID'])."'/>";
echo "<p><label>NAME</label><input name='person[NAME]' class='txt medium' value='".htmlspecialchars($form['NAME'])."'/></p>";
echo "<p><label>FAM</label><input name='person[FAM]' class='txt medium' value='".htmlspecialchars($form['FAM'])."'/></p>";
echo "<p><label>ADDRESS</label><input name='person[ADDRESS]' class='txt medium' value='".htmlspecialchars($form['ADDRESS'])."'/></p>";
echo "<p><input type='submit' value='Save'/></p>";
echo "</form>";

?>
