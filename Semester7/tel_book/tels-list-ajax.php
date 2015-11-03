<?php
include('config/boot.php');

$PID = $_GET['id']+0;

$result = mysql_query("
	SELECT 
		t.ID,
		t.NOMER,
		tt.TELTYPE
	FROM
		TELS_TBL t
		JOIN TELTYPES_TBL tt on(tt.ID = t.TID)
	WHERE
		t.PID = ".($PID)."
	ORDER BY tt.ID
	");
$tels = array();
while($t = mysql_fetch_object($result)) {
	$tels[] = $t;
}

$result = mysql_query("
	SELECT *
	FROM PERSONS_TBL
	WHERE ID = ".($PID)."
	");
$person = mysql_fetch_object($result);


$response = new stdClass();
$response->tels = $tels;
$response->PID = $PID;
$response->person = $person;
//$response->person->tels = $tels;
echo json_encode($response);
