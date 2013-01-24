<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">

<?php
	session_start();	
	if( isset($_SESSION['CODE_USER']) )
		$log = $_SESSION['CODE_USER'];
	$alpha = "%";
	$cat = "%";
?>

<head>
	<meta content="text/html; charset=iso-8859-15" http-equiv="Content-Type" />
	<title>Verification Identification</title>
	<style type="text/css">
	</style>
</head>

<body>

	<?php	
	
		if( isset($_REQUEST['alpha']) )
			$alpha = $_REQUEST['alpha'];
		if( isset($_REQUEST['cat']) )
			$cat = $_REQUEST['cat'];
	
		$host = "musique";
		$user = "ETD";
		$passw = "ETD";
		$conn = odbc_connect($host,$user,$passw) or die ("Echec de connection");
		
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//		afficher les catégories		
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

		$query = "select Code_Catégorie_Musicale, Catégorie_Musicale from Catégories_musicales";
		$result = odbc_exec($conn, $query);
		if ( $result == true )
		{	
			echo "<table class=\"tabrest\"><tr><td onclick=\"connectCat('requete/affichercatalogue.php?cat=%&alpha=" . $alpha . "')\">Toutes Catégories</td>";
			while( odbc_fetch_row($result))
			{
				echo "<td onclick=\"connectCat('requete/affichercatalogue.php?cat=" . odbc_result($result,1) . "&alpha=" . $alpha . "')\">" . odbc_result($result,2) . "</td>";		
			}
			echo "</tr></table>";
		}
		else
		{
			echo "erreur de connection à la base";
		}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//		afficher le panneau alphabet		
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~	
	
		$alp = array("a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z");
		echo "<table class=\"tabrest\"><tr class=\"tabhead\"><td onclick=\"connectCat('requete/affichercatalogue.php')\">*</td>";
		foreach ( $alp as $let )
			echo "<td onclick=\"connectCat('requete/affichercatalogue.php?alpha=" . $let . "&cat=" . $cat . "')\">" . $let . "</td>";
		echo "</tr></table>";
		
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//		ajout dans le panier		
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

		if( isset($_REQUEST['add']) )
		{
			if( !isset($_SESSION['NOM_USER']) )
			{
				$link = "Location: connexion.php?url=" .$_SERVER["REQUEST_URI"];
				header($link);
			}

			$add = $_REQUEST['add'];
			$melo = $_SESSION['CODE_USER'];
			$query = "insert into Téléchargements ( Code_Mélomane, Code_Oeuvre_Enregistrée) values ('" . $melo . "', '" . $add . "')";
			$result = odbc_exec($conn, $query);
		}
		
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//		afficher les musiques		
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

		
		$query = "select E.Format, M.Titre_Oeuvre, E.Titre_Enregistrement, C.Prénom_Compositeur, C.Nom_Compositeur, O.Code_Oeuvre_Enregistrée from Oeuvres_Enregistrées O join Oeuvres_Musicales M on O.Code_Oeuvre_Musicale = M.Code_Oeuvre join Enregistrements E on O.Code_Enregistrement = E.Code_Enregistrement join Types_morceaux T on M.Code_Type = T.Code_Type join Compositeurs C on M.Code_Compositeur = C.Code_Compositeur where M.Titre_Oeuvre like ('" . $alpha . "%') and E.Code_Catégori_eMusicale like ('" . $cat . "') order by E.Code_Enregistrement";
		$result = odbc_exec($conn, $query);
		
		if ( $result == true )
		{	
			$num = 0;
			echo "<table class=\"tab\">";
			echo "<tr class=\"tabhead\"> <td>support</td> <td>chanson</td> <td>Album</td> <td>Auteur</td> <td>Info</td> <td>panier</td> </tr>";
			while( odbc_fetch_row($result))
			{
				if( odbc_result($result,1) == "CD" )
					echo "<tr><td><img src=\"http://www.manytoo-blues.com/disc71.gif\"/></td>";
				else
					echo "<tr><td><img src=\"http://upload.wikimedia.org/wikipedia/commons/thumb/0/02/Disque_Vinyl.svg/35px-Disque_Vinyl.svg.png\"/></td>";
					
				$song = odbc_result($result,2);
				$alb = odbc_result($result,3);
				$sing = odbc_result($result,4) . " " . odbc_result($result,5);
				$num = odbc_result($result,6);
					
				echo "<td>" . $song . "</td>";
				echo "<td>" . $alb . "</td>";
				echo "<td>" . $sing . "</td>";
				echo "<td><a href=\"infoChanson.php?num=" . $num . "\" target=_blank><img src=\"image/info.png\"/></a></td>";
				echo "<td onclick=\"connectCat('requete/affichercatalogue.php?add=" . $num . "&alpha=" . $alpha . "&cat=" . $cat . "')\">ajouter</td></tr>";
			}
			
			echo "</table>";
			odbc_close($conn);
		}
		else
		{
			echo "erreur de connection à la base";
			odbc_close($conn);
		}
	
	?>
	
</body>

</html>
