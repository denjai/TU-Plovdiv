<?php
include('config/boot.php');
$errors = array();
$infos = array();


$PID = $_GET['pid']+0; // perdon_id when new telephone is added

$form = $_POST['tel'];
if(isset($form['ID'])) {
	$ID = $form['ID']+0;
}
else {
	$ID = $_GET['id']+0;
}

if($ID == 0) { // new person, no data
	$title = "Add New Telephone";
	$tel = array();
}
else if(isset($form)) { // save/update person
	$title = "Edit Telephone";
}
else { // edit person
	$title = "Edit Telephone";
	$result = mysql_query(" SELECT * FROM TELS_TBL WHERE ID = ".($ID)." ");
	$tel = mysql_fetch_assoc($result);
}


if(isset($_POST['tel'])) { // if any data posted -> validate and update data
	$form = $_POST['tel'];
	if(strlen(trim($form['NOMER']))<=5) $errors[] = "NOMER should be more than 5 characters.";
	if(($form['TID']+0)==0) $errors[] = "Select TELTYPE.";
	if($ID == 0 && $PID == 0) $errors[] = "Unknown PID.";

	if(count($errors) == 0) {
		$infos[] = "Telephone successfully saved.";

		if($ID == 0) { // no ID -> insert
			$sql = sprintf(
				"INSERT INTO TELS_TBL(NOMER, TID, PID) VALUES('%s',%d,%d)",
				mysql_real_escape_string(trim($form['NOMER'])),
				$form['TID']+0,
				$PID
			);
			$infos[] = "sql: $sql";
			mysql_query($sql);
		}
		else { // update
			$sql = sprintf(
				"UPDATE TELS_TBL SET NOMER='%s', TID=%d WHERE ID=%d",
				mysql_real_escape_string(trim($form['NOMER'])),
				$form['TID']+0,
				$ID
			);
			$infos[] = "sql: $sql";
			mysql_query($sql);
		}
	}
}
else { // if no data submitted -> fill the form with data from the DB
	$form = $tel; 
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

$teltypes = array();
$result = mysql_query(" SELECT * FROM TELTYPES_TBL ORDER BY ID ");
while($t = mysql_fetch_object($result)) {
	$teltypes[] = $t;
}

echo "<form id='tel-edit-form' action='tel-edit-ajax.php?pid=$PID' enctype='multipart/form-data' method='post'>";
echo "<input type='hidden' name='tel[ID]' value='".htmlspecialchars($form['ID'])."'/>";
echo "<p><label>NOMER</label><input name='tel[NOMER]' class='txt medium' value='".htmlspecialchars($form['NOMER'])."'/></p>";
echo "<p><label>TEL TYPE</label><select name='tel[TID]' class='txt medium'>";
echo "<option value='0'> </option>";
foreach($teltypes as $tt) {
	$selected = "";
	if($form['TID'] == $tt->ID) $selected = " selected='selected' ";
	echo "<option value='$tt->ID' $selected>$tt->TELTYPE</option>";
}
echo "</select></p>";
echo "<p><input type='submit' value='Save'/></p>";
echo "</form>";

?>
