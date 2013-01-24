<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<?php session_start(); ?>

<head>
	<meta content="text/html; charset=iso-8859-15" http-equiv="Content-Type" />
	<title>Verification Identification</title>
	<style type="text/css">
	</style>
</head>

<body>
	
	<?php	
		if( isset($_REQUEST['num']) )
			$num = $_REQUEST['num'];
			
		$host = "musique";
		$user = "ETD";
		$passw = "ETD";
		$conn = odbc_connect($host,$user,$passw) or die ("Echec de connection");
		
		$query = "select M.Titre_Oeuvre, T.Libellé_Type, E.Titre_Enregistrement, E.Année_Parution, E.Format, E.Nombre_De_Morceaux, CA.Catégorie_Musicale, C.Prénom_Compositeur, C.Nom_Compositeur, C.Date_naissance, C.Date_Décès, P.Nom_Pays, E.Code_Enregistrement from Oeuvres_Enregistrées O  join Oeuvres_Musicales M on O.Code_Oeuvre_Musicale = M.Code_Oeuvre join Types_morceaux T on M.Code_Type = T.Code_Type join Compositeurs C on M.Code_Compositeur = C.Code_Compositeur join Pays P on C.Code_Pays = P.Code_Pays join Enregistrements E on O.Code_Enregistrement = E.Code_Enregistrement join Catégories_musicales CA on E.Code_Catégori_eMusicale = CA.Code_Catégorie_Musicale where O.Code_Oeuvre_Enregistrée = " . $num;
		$result = odbc_exec($conn, $query);
		
		if ( $result == true )
		{	
			while( odbc_fetch_row($result))
			{
				echo "<h3>Chansons</h3>";
				echo "<p>Titre : " . odbc_result($result,1) . "</p>";
				echo "<p>Type : " . odbc_result($result,2) . "</p>";
				
				echo "<h3>Album</h3>";
				echo "<p>Nom : " . odbc_result($result,3) . "</p>";
				echo "<p>Annee : " . odbc_result($result,4) . "</p>";
				echo "<p>Format : " . odbc_result($result,5) . "</p>";
				echo "<p>Nombre de morceau : " . odbc_result($result,6) . "</p>";
				echo "<p>Categorie : " . odbc_result($result,7) . "</p>";
				
				echo "<h3>Auteur</h3>";
				echo "<p>Prenom Nom : " . odbc_result($result,8) . " " . odbc_result($result,9) . "</p>";
				echo "<p>Date : " . odbc_result($result,10) . " --> " . odbc_result($result,11) . "</p>";
				echo "<p>Origine : " . odbc_result($result,12) . "</p>";
				
				$code = odbc_result($result,13);
			}
			for ($i=0; $i<5; $i++)
				echo "</br>";
		}		
		else
			echo "erreur de connection à la base";
		

		$query = "select M.Prénom_Mélomane, M.Nom_Mélomane, A.Notes, A.Texte from Avis A join Enregistrements E on A.Code_Enregistrement = E.Code_Enregistrement join Mélomanes M on A.Code_Mélomane = M.Code_Mélomane where A.Code_Enregistrement = " . $code;
		
		$result = odbc_exec($conn, $query);
		
		if ( $result == true )
		{	
			echo "<h1>Commentaires :</h1><hr/><hr/>";
			while( odbc_fetch_row($result))
			{
				echo "<p>Commentaire de : " . odbc_result($result,1) . " " . odbc_result($result,2) . "</p>";
				echo "<p>Note : " . odbc_result($result,3) . "/20</p>";
				echo "<p>Message :" . odbc_result($result,4) . "</p>";
				echo "<hr/>";
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
