<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">

<head>
	<meta content="text/html; charset=iso-8859-15" http-equiv="Content-Type" />
	<title>Verification Identification</title>
</head>

<body>
		<?php
			session_start();	
			$code = $_SESSION['CODE_USER'];
			
			$host = "musique";
			$user = "ETD";
			$passw = "ETD";
			$conn = odbc_connect($host,$user,$passw) or die ("Echec de connection");
			
			$query = "select count(*) 
						from T�l�chargements T 
						join Oeuvres_Enregistr�es OE on OE.Code_Oeuvre_Enregistr�e=T.Code_Oeuvre_Enregistr�e 
						join Oeuvres_Musicales OM on OM.Code_Oeuvre=OE.Code_Oeuvre_Musicale
						WHERE Code_M�lomane='546'";
			$result = odbc_exec($conn, $query);
			if ( $result == true )
				if( odbc_fetch_row($result))
				{
					$nbtele = odbc_result($result,1);
					echo "<p>vous avez actuellement " . $nbtele . " musiques dans votre panier</p>";
				}
			else
				echo "erreur connection a la base : recup nb telecharge";

			
			$query = "select Niveau, Libell�_Type 
						from Pr�f�rences 
						join Types_Morceaux on Pr�f�rences.Code_Type = Types_Morceaux.Code_Type
						WHERE Code_M�lomane='546'";
			$result = odbc_exec($conn, $query);
			
			if ( $result == true )
			{	
				echo "<h3>Vos pr�f�rences :<h3>";
				echo "<ul>";
				while( odbc_fetch_row($result))
				{
					$note = odbc_result($result,1);
					$type = odbc_result($result,2);
					echo "<li>".$type."&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;".$note."</li>";
				}
				echo"</ul>";
				odbc_close($conn);					
			}
			else
			{
				echo "erreur de connection � la base";
			}
			
		?>
</body>

</html>
