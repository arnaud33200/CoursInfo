<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">

<?php		
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
	<div>
	
		<?php		
			$host = "musique";
			$user = "ETD";
			$passw = "ETD";
			$conn = odbc_connect($host,$user,$passw) or die ("Echec de connection");
			
			$query = "Select count(*) from Enregistrements";
			
			$result = odbc_exec($conn, $query);
			
			if ( $result == true )
			{	
				if( odbc_fetch_row($result))
				{
					echo "<p>Nous avons actuelement : " . odbc_result($result,1) . " enregistrements</p>";
					odbc_close($conn);
				}
				else
				{
					echo "Aucun resultat";
					odbc_close($conn);
				}
			}
			else
			{
				echo "erreur de connection à la base";
				odbc_close($conn);
			}
			
		?>
	</div>
</body>

</html>
