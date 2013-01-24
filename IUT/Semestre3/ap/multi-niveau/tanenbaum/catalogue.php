<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">

<?php	
	session_start();
	if( !isset($_SESSION['NOM_USER']) )
		$conn = "no";
	else
		$conn = "yes";
?>

<head>
	<meta content="text/html; charset=utf-8" http-equiv="Content-Type" />
	<title>CATALOGUE</title>
	<script type="text/javascript" src="javascript/ajax.js" ></script>
	<script type="text/javascript">
		function loadajax()
		{
			connectCat('requete/affichercatalogue.php');
			connectBan();
		}
	</script>
	<link href="style1.css" rel="stylesheet" type="text/css" />
</head>

<body onload="loadajax()">	
	
<!--####################################################################################
		BANIERE
#################################################################################### -->

	<div id="baniere">
		<a href="pageAcceuil.php"><img src="image/logo.png" /></a>
	</div>
	
		
<!--####################################################################################
		PANNEAU
#################################################################################### -->

	<div id="panneau">

	<!-- ~~~~~~~~~~~~~~~~~~~~~~~~ INFORMATION ~~~~~~~~~~~~~~~~~~~~~ -->	
	
		<!-- ~~~~~~~~~~~~~~~~~~~~~~~~ MENU ~~~~~~~~~~~~~~~~~~~~~ -->	
	
		<div id="info">			
			<a class="titlemen">Menu</a>
			<hr />
			<div id="menu">
		  		<ul>
		    		<li><a href="pageAcceuil.php">ACCEUIL</a> </li>
		   			<li><a href="catalogue.php">CATALOGUE</a></li>
		   			
		   			<?php
						if( $conn == "no" )
						{
			    			echo "<li><a href=\"connexion.php\">CONNEXION</a></li>";
			    			echo "<li><a href=\"inscription.php\">INSCRIPTION</a></li>";
			    		}
			    		else
			    		{
			    			echo "<li><a>PROFIL</a><ul>";
								echo "<li><a href=\"profilInfo.php\">information</a> </li>";
								echo "<li><a href=\"profilModif.php\">modifier</a></li></ul></li>";
							echo "<li><a href=\"panier.php\">PANIER</a></li>";
							echo "<li><a href=\"deconnexion.php\">DECONEXION</a></li>";				
						}
		    		?>
		 	 	</ul>
			 </div>
			 
			<hr />
			<a class="titlemen">Information</a>
			<hr />
			<div id="infosite"></div>
			
		</div>
		
	<!-- ~~~~~~~~~~~~~~~~~~~~~~~~ AFFICHAGE ~~~~~~~~~~~~~~~~~~~~~ -->	
		
		<div id="affichage">
			<h1>Catalogue de musique</h1>
			<hr/>
			<p></p>
			<div id="catalogue">
			blabla</div>				
		</div>
	</div>
		
<!--####################################################################################
		BARRE DU BAS
#################################################################################### -->

</body>

</html>
