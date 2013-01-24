<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">

<head>
<meta content="text/html; charset=utf-8" http-equiv="Content-Type" />
<title>sans titre 1</title>
</head>

<body>
	<?php
		$fp = fopen('\\info\www\perso\2011-2012\aladouce\test.xml', 'w');
		$host = "Bibli";
		$user = "ETD";
		$passw = "ETD";
		$conn = odbc_connect($host,$user,$passw) or die ("HOLY SHIT");
		
	// ACCES A LA TABLE
		$query = "SELECT  Nom FROM Auteur WHERE Nom LIKE 'A%'";
		$result = odbc_exec($conn, $query);
		
	// BOUCLE DE LECTURE
		while( odbc_fetch_row($result))
		{
			$nom = odbc_result($result,1);
			fwrite($fp, htmlentities($nom));
		}
		
		odbc_close($conn);
		fclose($fp);
	?>
</body>

</html>
