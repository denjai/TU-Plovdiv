<?php
include('config/boot.php');

$result = mysql_query("
	SELECT * 
	FROM PERSONS_TBL 
	ORDER BY ID
	");

$persons = array();
while($p = mysql_fetch_object($result)) {
	$persons[] = $p;
}

?>
<!DOCTYPE html>
<html>
<head>
	<title>Telbook</title>
	<meta http-equiv='Content-Type' content='text/html; charset=UTF-8' />
	<link rel="stylesheet" type="text/css" href="css/default.css">
	<script type="text/javascript" src="js/jquery-1.7.1.min.js"></script>
	<script type="text/javascript" src="js/application.js"></script>
</head>
<body>
	<table class='layout'>
		<tr>
			<td class='panel'>
			<h1>Persons</h1>
			<table class='grid'>
				<tr>
					<th>ID</th>
					<th>NAME</th>
					<th>FAM</th>
					<th>ADDRESS</th>
					<th> </th>
					<th> </th>
				<tr>
				<?php
					foreach($persons as $p) {
						echo "<tr>
							<td>".$p->ID."</td>
							<td>".$p->NAME."</td>
							<td>".$p->FAM."</td>
							<td>".$p->ADDRESS."</td>
							<td>
								<a href='tels-list-ajax.php?id=".$p->ID."' class='icon view_icon person-show-tels'>Show Tels</a>
							</td>
							<td>
								<a href='person-edit-ajax.php?id=$p->ID' class='icon edit_icon person-edit'>Edit</a>
								<a href='person-delete-ajax.php?id=$p->ID' class='icon delete_icon person-delete'>Delete</a>
							</td>
						</tr>";
					}
				?>
			</table>
			<p>
				<a href='person-edit-ajax.php' class='icon add_icon person-edit'>Add new person</a>
				<a href='' class='icon refresh_icon'>Refresh</a>
			</p>
			</td>
			<td class='panel'>
				<div id='person-details'>
				</div>
			</td>
		</tr>
		<tr>
			<td class='panel'>
				<h1>Telephones</h1>
				<div id='tels'>
					<p class='icon info_icon'>Select a person to view his telephones.</p>
				</div>
			</td>
			<td class='panel'>
				<div id='tel-details'>
				</div>
			</td>
		</tr>
	</table>
	<div id='placeholder'>
	</div>
	<script>
		var e = document.getElementById('placeholder');
		if(e != undefined) {
			e.innerHTML = "<i class='icon app_icon'>TU Plovdiv, AJAX DEMO, 2013.</i>";
		}
	</script>
</body>
</html>
