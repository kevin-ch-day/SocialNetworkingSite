<?php
require_once 'includes\Header.inc';
echo "<br><span class='main'>Welcome to $appname,";
if($loggedin){
	echo " $user, you are logged in.";
}else{
	echo '<br/><strong>please sign up or log in to join in.</strong>';
}
?>
</span><br><br>
</body>
</html>