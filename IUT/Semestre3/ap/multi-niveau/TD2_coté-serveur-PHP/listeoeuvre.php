<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">

<head>
<meta content="text/html; charset=utf-8" http-equiv="Content-Type" />
<title>sans titre 1</title>
</head>

<body>
	<?php		
		$host = "Bibli";
		$user = "ETD";
		$passw = "ETD";
		$conn = odbc_connect($host,$user,$passw) or die ("HOLY SHIT");
		
	// ACCES A LA TABLE
		$auteur = $_POST['aut']
		$query = "SELECT  FROM Oeuvre WHERE Nom LIKE '" . $_POST['ini'] . "%'";
		$result = odbc_exec($conn, $query);
		
	// BOUCLE DE LECTURE
		while( odbc_fetch_row($result))
		{
			$nom = odbc_result($result,1);
			echo "<p> NOM : " . htmlentities($nom);
		}
		
		odbc_close($conn);
		
	?>
</body>

</html>
