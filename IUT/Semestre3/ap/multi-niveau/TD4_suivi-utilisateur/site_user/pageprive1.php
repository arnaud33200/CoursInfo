<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
   
<?php
	$urlCourant = "Location: connexion.php?url=\"pageprive1.php\"";
$loc = "Location: ".$_SERVER["REQUEST_URI"]; 	
session_start();
	
// detecte si il y a une session ouverte
// redirige vers la page "connexion.php"
// avec comme parametre l'url de cette page 
	if ( !isset( $_SESSION['NOM_USER']) )
		header($urlCourant);
/*	
	function disconnect()
	{
		echo "entre disconnect";
		unset($_SESSION['NOM_USER']);
		$loc = "Location: ".$_SERVER["REQUEST_URI"];
		header($loc);
		}	*/
	?> 


<head>
<meta content="text/html; charset=utf-8" http-equiv="Content-Type" />
<title>Page Privee 1</title>
</head>

<body>
	
	<h1>Bienvenue sur la page privée 1</h1>
	<div id="menu">
		<a href="pagepublic.php">pagepublic</a>
		<a href="pageprive1.php">pageprive1</a>
		<a href="pageprive2.php">pageprive2</a>
	</div>

	<p>CLIQUER ICI POUR VOUS DECONNECTER</p>
	<form method="post">
		<input name="Image1" type="image" src="http://1.bp.blogspot.com/-JdQcfgvVJy0/TXJ76hfmVdI/AAAAAAAAHPQ/BufKcuioP2E/s400/disconnect2-300x274.jpg" onclick="<?php disconnect() ?>" />
	</form>
	
</body>

</html>
