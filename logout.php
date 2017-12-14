<?php
require_once 'includes\Header.inc';
require_once 'includes\Functions.inc';
if (isset($_SESSION['user'])){
	destorySession();
	echo "<div class='main'>You have been logged out. Please <a href='index.php'>click here</a> to refresh the screen.";
}else{
	echo "<div class='main'><br> You cannot log out because you are not logged in";
}
?>
		<br><br></div>
	</body>
</html>