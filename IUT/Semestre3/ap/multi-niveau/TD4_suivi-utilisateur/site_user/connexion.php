<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta content="text/html; charset=utf-8" http-equiv="Content-Type" />
<title>HOLA</title>
</head>

<body>
	<h1>PAGE DE CONNEXION</h1>	
	<p>&nbsp;</p>
	<?php
	if( isset($_REQUEST['url']) )			// recupére le paramètre : URL de la page prive
		$url = $_REQUEST['url'];
else
  $url = "pagepublic.php";

		echo "<form method=\"post\" action=\"veriflogin.php?url=" . $url . "\">"; ?>	
				
			<p>Nom :<input name="login" type="text"/></p>
			<p>Mot de passe :<input name="passwd" type="text" /></p>
			<input name="Envoyer" type="submit" />
	<?php echo "</form>" ?>
	
</body>

</html>
