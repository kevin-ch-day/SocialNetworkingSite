<?php
/* When the session started, the program then checks whether the session
 * variable user is currently assigned a value. If so, a user has logged
 * in and the variable $loggedin is set to TRUE.
 */
session_start();
require_once 'includes\Database.inc';
require_once 'includes\Functions.inc';
	
echo "<!DOCTYPE html><html><head>";
	
$userstr = ' (Guest)';
	
if (isset($_SESSION['user'])){
	$user = $_SESSION['user'];
	$loggedin = TRUE;
	$userstr = " ($user)";
}else{
	$loggedin = FALSE;
}
	
$output = "<title>$appname$userstr</title>"; // title
$output .= "<link rel='stylesheet' href='style/styles.css' type='text/css'>"; // css
$output .= "</head>";
$output .= "<body><center><canvas id='logo' width='624' height='96'>$appname</canvas></center>";
$output .= "<div class='appname'>$appname$userstr</div>";
$output .= "<script src='script.js'></script>";
echo $output;

if ($loggedin){
	$output = "<br ><ul class='menu'>";
	$output .= "<li><a href='members.php?view=$user'>Home</a></li>";
	$output .= "<li><a href='members.php'>Members</a></li>";
	$output .= "<li><a href='friends.php'>Friends</a></li>";
	$output .= "<li><a href='messages.php'>Messages</a></li>";
	$output .= "<li><a href='profile.php'>Edit Profile</a></li>" ;
	$output .= "<li><a href='logout.php'>Log out</a></li></ul><br>";
	echo $output;
	
}else{
	$output = "<br><ul class='menu'>";
	$output .= "<li><a href='index.php'>Home</a></li>";
	$output .= "<li><a href='signup.php'>Sign up</a></li>";
	$output .= "<li><a href='login.php'>Log in</a></li></ul><br>";
	$output .= "<span class='info'>&#8658; You must be logged in to ";
	$output .= "view this page.</span><br><br>";
	echo $output;
}
?>