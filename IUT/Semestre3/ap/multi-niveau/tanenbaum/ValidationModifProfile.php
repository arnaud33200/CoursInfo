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
		$url = "deconnexion.php";
		$code = $_REQUEST['code'];
		$Loc = "Location: ".$url;
?>

<head>
	<meta content="text/html; charset=iso-8859-15" http-equiv="Content-Type" />
	<title>Verification Modification profile</title>
</head>

<body>
		<?php		
			$host = "musique";
			$user = "ETD";
			$passw = "ETD";
			$conn = odbc_connect($host,$user,$passw) or die ("Echec de connection");
			
			//$query = "SELECT nom FROM lecteur WHERE login ='".$login."' and password ='".$passwd."'";
			$query = "UPDATE M�lomanes SET Nom_M�lomane='".$nom."' , 
											Pr�nom_M�lomane='".$prenom."' ,
											Login='".$login."' ,
											Mot_De_Passe='".$pwd."'
											WHERE Code_M�lomane='".$code."'";
			$result = odbc_exec($conn, $query);
			
			if ( $result == true )
			{	
				session_start();
				$_SESSION['NOM_USER'] = $nom;
				$_SESSION['PRENOM_USER'] = $prenom;
				$_SESSION['LOGIN_USER'] = $login;
				$_SESSION['PASS_USER'] = $pwd;
				
				odbc_close($conn);
				header($Loc);
			}
			else
			{
				echo "erreur de connection � la base";
			}
			
		?>
</body>

</html>
