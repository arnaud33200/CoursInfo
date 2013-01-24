<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">

<head>
<meta content="text/html; charset=utf-8" http-equiv="Content-Type" />
<title>Verification Identification</title>
</head>

<body>
	<?php 
		$login = $_REQUEST['login'];
		$passwd = $_REQUEST['passwd'];
		$url = $_REQUEST['url'];
		
		$host = "Bibli";
		$user = "ETD";
		$passw = "ETD";
		$conn = odbc_connect($host,$user,$passw) or die ("Echec de connection");
		
		$query = "SELECT nom FROM lecteur WHERE login ='".$login."' and password ='".$passwd."'";
		$result = odbc_exec($conn, $query);
		
		if ( $result == true )
		{	
			if( odbc_fetch_row($result))
			{
				$Nom = odbc_result($result,1);
				$Code = "bmambam";
				$Loc = "Location: ".$url;
				odbc_close($conn);
				
		// ouverture de la session avec les informations necessaire
				session_start();
				$_SESSION['Valide'] = "true";
				$_SESSION['NOM_USER'] = $Nom;
				header($Loc);					// retour à la page de depart
			}
			else
			{
				echo "<p>Mauvais identifiant ou mauvais mot de passe</p>";
				odbc_close($conn);
				echo "<p><form methode=\"post\" action=\"connexion.php?url=" . $url . "\">";
				echo "<input name=\"Retour connexion\" value=\"Retour connexion\"type=\"submit\" />";
				echo "</form></p>";
			}
		}
	?>
</body>

</html>
