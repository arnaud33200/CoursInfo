<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">

<head>
<meta content="text/html; charset=utf-8" http-equiv="Content-Type" />
<title>sans titre 1</title>
</head>

<body>
	<?php
		echo $_POST['prenom'] . "<br>";
		echo $_POST['quiqui'] . "<br>" . "caca";
		if ( isset($_POST['permi']) && $_POST['permi'] == 'on' )
			echo 'permis en poche negger';
			
		$host = "Bibli";
		$user = "ETD";
		$passw = "ETD";
		$conn = odbc_connect($host,$user,$passw) or die ("HOLY SHIT");
		
	// ACCES A LA TABLE
		$query = "SELECT Nom FROM auteur WHERE Nom LIKE '" . $_POST['ini'] . "%'";
		$query = "SELECT * FROM auteur";
		$result = odbc_exec($conn, $query);
		
		
	// BOUCLE DE LECTURE
		while( odbc_fetch_row($result))
		{
			$nom = odbc_result($result,1);
			echo "<p> NOM : " . htmlentities($nom);
			echo "<a href='listeoeuvre.php?aut=$nom'>     liste des oeuvres de $nom </a> </p>";
		}
		
		odbc_close($conn);
		
	?>
</body>

</html>
