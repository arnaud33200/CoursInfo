<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">

<?php
// VERIFICATION DES ERREURS DE PARAMETRES
// ERROR == 1 : manque d'information
// ERROR == 2 : information incorrect

		if( isset($_REQUEST['login']) && isset($_REQUEST['passwd']) )
		{
			$login = $_REQUEST['login'];
			$passwd = $_REQUEST['passwd'];
		}
		else
		{
			$link = "Location: connexion.php?error=1";
			header($link);
		}
		
		if( isset($_REQUEST['url']) )
			$url = $_REQUEST['url'];
		else
			$url = "pageAcceuil.php";
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
			
			//$query = "SELECT nom FROM lecteur WHERE login ='".$login."' and password ='".$passwd."'";
			$query = "SELECT * FROM Mélomanes WHERE Login ='".$login."' and Mot_De_Passe ='".$passwd."'";
			$result = odbc_exec($conn, $query);
			
			if ( $result == true )
			{	
				if( odbc_fetch_row($result))
				{
					$Code = odbc_result($result,1);
					$Nom = odbc_result($result,2);
					$Prenom = odbc_result($result,3);
					$Login = odbc_result($result,4);
					$mdp = odbc_result($result,5);

					$Loc = "Location: ".$url;
					odbc_close($conn);
					
			// ouverture de la session avec les informations necessaire
					session_start();
					$_SESSION['Valide'] = "true";
					$_SESSION['NOM_USER'] = $Nom;
					$_SESSION['PRENOM_USER'] = $Prenom;
					$_SESSION['LOGIN_USER'] = $Login;
					$_SESSION['CODE_USER'] = $Code;
					$_SESSION['PASS_USER'] = $mdp;
					
					 header($Loc);					// retour à la page de depart
				}
				else
				{
					$link = "Location: connexion.php?error=2";
					header($link);
				}
			}
			else
			{
				echo "erreur de connection à la base";
			}
			
		?>
</body>

</html>
