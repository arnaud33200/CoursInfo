<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">

<?php
// VERIFICATION DES ERREURS DE PARAMETRES
// ERROR == 1 : manque d'information
// ERROR == 2 : information incorrect
		$nom = $_REQUEST['nom'];
		$prenom = $_REQUEST['prenom'];
		$login = $_REQUEST['login'];
		$pwd = $_REQUEST['pwd'];
		$url = "pageAcceuil.php";
		$Loc = "Location: ".$url;
?>

<head>
	<meta content="text/html; charset=iso-8859-15" http-equiv="Content-Type" />
	<title>Verification Identification</title>
</head>

<body>
		<?php		
			$host = "musique";
			$user = "ETD";
			$passw = "ETD";
			$conn = odbc_connect($host,$user,$passw) or die ("Echec de connection");
			$query = "INSERT INTO Mélomanes
							VALUES('".$nom."','".$prenom."','".$login."','".$pwd."')";
			$result = odbc_exec($conn, $query);
			
			if ( $result == true )
			{	
				odbc_close($conn);
				header($Loc);
			}
			else
			{
				echo "erreur de connection à la base";
			}
			
		?>
</body>

</html>