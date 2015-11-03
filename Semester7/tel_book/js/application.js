var PERSON_ID = 0;
$(document).ready(function() {

	//$('a.person-edit, a.person-delete').click(function(e) {
	$(document).on('click', 'a.person-edit, a.person-delete', function(e) {
		$.get($(this).attr('href'), function(data) {
			$('#person-details').html(data);
		});
		return false;
	});

	function show_tels(href) {
		$.getJSON(href, function(json_data) {
			var html = '';
			html += "<p class='icon user_icon'>"+json_data.person.NAME+" "+json_data.person.FAM+"</p>";
			html += "<table class='grid'>";
			html += "<tr><th>ID</td><th>NOMER</th><th>TELTYPE</th><th></th></tr>";
			$.each(json_data.tels, function(i, item) {
				html += 
					"<tr>"+
					"<td>"+item.ID+"</td>"+
					"<td>"+item.NOMER+"</td>"+
					"<td>"+item.TELTYPE+"</td>"+
					"<td>"+
						"<a href='tel-edit-ajax.php?id=" + (item.ID) + "' class='icon edit_icon tel-edit'>Edit</a> "+
						"<a href='tel-delete-ajax.php?id=" + (item.ID) + "' class='icon delete_icon tel-delete'>Delete</a>"+
					"</td>"+
				"</tr>";
			});
			html += "</table>";
			html += "<p>"+
				"<a href='tel-edit-ajax.php?pid=" + (json_data.PID) + "' class='icon add_icon tel-edit'>Add new telephone</a> "+
				"<a href='tels-list-ajax.php?id=" + (json_data.PID) + "' class='icon refresh_icon tels-refresh'>Refresh</a>"+
				"</p>";
			$('#tels').html(html);
			PERSON_ID = json_data.person.ID;
		});
	}

	$(document).on('click', 'a.person-show-tels, a.tels-refresh', function(e) {
		show_tels($(this).attr('href'));
		$('#tel-details').html('');
		return false;
	});

	$(document).on('submit', '#person-edit-form', function(e) {
		$.post($(this).attr('action'),$(this).serialize(),function(data){
			$('#person-details').html(data);
		});
		return false;
	});

	$(document).on('click', 'a.tel-edit, a.tel-delete', function(e) {
		$.get($(this).attr('href'), function(data) {
			$('#tel-details').html(data);
		});
		return false;
	});

	$(document).on('submit', '#tel-edit-form', function(e) {
		$.post($(this).attr('action'),$(this).serialize(),function(data){
			$('#tel-details').html(data);
		});
		return false;
	});
	
});
