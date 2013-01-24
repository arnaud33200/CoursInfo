<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<?php
	function disconnect()
	{
		echo "entre disconnect";
		unset($_SESSION['NOM_USER']);
		$loc = "Location: ".$_SERVER["REQUEST_URI"];
		header($loc);
	}	
?>

<html xmlns="http://www.w3.org/1999/xhtml">
<head>
	<meta content="text/html; charset=utf-8" http-equiv="Content-Type" />
	<title>Page Public</title>
</head>

<body>
	
	<h1>Bienvenue sur la page public</h1>
	<div id="menu">
		<a href="pagepublic.php">pagepublic</a>
		<a href="pageprive1.php">pageprive1</a>
		<a href="pageprive2.php">pageprive2</a>
	</div>

	<form method="post">
		<?php
			$urlcourant = "connexion.php?url=" . $_SERVER["REQUEST_URI"];
			session_start();
			if( isset( $_SESSION['NOM_USER'] ) )
			  echo "<input name=\"deco\" type=\"button\" value=\"DECONNEXION\" onclick=\"disconnect()\" />";
			else
			  echo "<input name=\"co\" type=\"button\" value=\"CONNEXION\" onclick=\"" . $urlcourant . "\" />";
		?>	
	</form>
	
	
</body>

</html>
