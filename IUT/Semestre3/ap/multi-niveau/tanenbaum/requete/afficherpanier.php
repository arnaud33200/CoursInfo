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
	
	<h1>Panier Téléchargement</h1>
	<hr/>
	<p>
		le panier de 
		<?php
			echo $_SESSION['NOM_USER'] . " " . $_SESSION['PRENOM_USER'];
		?>
	</p>

	<?php		
		$host = "musique";
		$user = "ETD";
		$passw = "ETD";
		$conn = odbc_connect($host,$user,$passw) or die ("Echec de connection");

		$query = "Select M.Titre_Oeuvre, E.Titre_Enregistrement, T.Date_Téléchargement, T.Date_Paiement from Téléchargements T join Oeuvres_Enregistrées O on T.Code_Oeuvre_Enregistrée = O.Code_Oeuvre_Enregistrée join Oeuvres_Musicales M on O.Code_Oeuvre_Musicale = M.Code_Oeuvre join Enregistrements E on O.Code_Enregistrement = E.Code_Enregistrement where Code_Mélomane = " . $_SESSION['CODE_USER'] . " order by T.Date_Téléchargement";
		
		$result = odbc_exec($conn, $query);
		
		if ( $result == true )
		{	
			$bon = "non";
			
			echo "<table class=\"tab\">";
			echo "<tr class=\"tabhead\"><td>Chanson</td><td>Album</td><td>Date Téléchargement</td><td>Date Payement</td></tr>";
			while( odbc_fetch_row($result))
			{
				$bon = "ok";
				echo "<tr>";
				echo "<td>" . odbc_result($result,1) . "</td>";
				echo "<td>" . odbc_result($result,2) . "</td>";
				
				if( odbc_result($result,3) == NULL )
					echo "<td>TELECHARGER</td>";
				else
					echo "<td>" . odbc_result($result,3) . "</td>";
				if( odbc_result($result,4) == NULL )
					echo "<td>PAYEMENT</td>";
				else
					echo "<td>" . odbc_result($result,4) . "</td>";
				echo "<tr>";			
			}
			if( $bon != "ok" )
			{
				echo "<tr>Aucune musiques est actuelement dans votre panier</tr>";
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
