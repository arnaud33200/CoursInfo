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
	<meta content="text/html; charset=iso-8859-15" http-equiv="Content-Type" />
	<title>INSCRIPTION</title>
	<script type="text/javascript" src="javascript/ajax.js" ></script>
	<link href="style1.css" rel="stylesheet" type="text/css" />
</head>

<body onload="connectBan()">	
	
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
			<h1>Inscription...</h1>
			<hr/>
			<?php 
				echo "<form method="."post"." action="."validationInscription.php>";
				echo "<p>Nom :<input type="."text"." name="."nom"." value="."Nom"."></p>";
				echo "<p>Prénom :<input type="."text"." name="."prenom"." value="."Prénom"."></p>";
				echo "<p>Login :<input type="."text"." name="."login"." value="."Login"."></p>";
				echo "<p>Mot De Passe :<input type="."text"." name="."pwd"." value="."Password"."></p>";
				echo "<input name="."Modifier"." type="."submit"." />";
				echo "</form>";
			?>		
		</div>
	</div>

</body>

</html>
