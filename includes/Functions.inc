<?php

$appname = "Blue Knight Site";

function setupDatabase(){
	createTable('members',
	'user VARCHAR(16),
	pass VARCHAR(16),
	INDEX(user(6))');

createTable('messages',
	'id INT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	auth VARCHAR(16),
	recip VARCHAR(16),
	pm CHAR(1),
	time INT UNSIGNED,
	message VARCHAR(4096),
	INDEX(auth(6)),
	INDEX(recip(6))');

createTable('friends',
	'user VARCHAR(16),
	friend VARCHAR(16),
	INDEX(user(6)),
	INDEX(friend(6))');

createTable('profiles',
	'user VARCHAR(16),
	text VARCHAR(4096),
	INDEX(user(6))');
}

function createTable($tableName, $query){
	aQuery("create table if not exists $tableName($query)");
	//echo "Table {$tableName} created or already exists<br/>";
}

function aQuery($query){
	global $conn;
	
	$result = $conn->query($query);
	if(!$result){
		die("Query Failed: ".$conn->error);
	}
	
	return $result;
}

function destorySession(){
	$_SESSION = array();
	if(session_id() != "" || isset($_COOKIE[session_name()])){
		setcookie(session_name(), '', time()-2592000, '/');
	}
	session_destroy();
}

function sanitizeString($var){
	global $conn;
	
	$var = strip_tags($var);
	$var = htmlentities($var);
	$var = stripslashes($var);
	
	return $conn->real_escape_string($var);
}

function showProfile($user){
	if (file_exists("images/$user.jpg")){
		echo "<img src='images/$user.jpg' style='float:left;'>";
	}
	
	$result = aQuery("SELECT * FROM profiles WHERE user='$user'");
	if ($result->num_rows){
		$row = $result->fetch_array(MYSQLI_ASSOC);
		echo stripslashes($row['text']) . "<br style='clear:left;'><br>";
	}
}
?>