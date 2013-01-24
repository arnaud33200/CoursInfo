<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">

<?php	
	session_start();
	if( !isset($_SESSION['NOM_USER']) )
	{
		$link = "Location: connexion.php?url=" .$_SERVER["REQUEST_URI"];
		header($link);
		$conn = "no";
	}
	else
	{
		$conn = "yes";
	}
?>

<head>
	<meta content="text/html; charset=utf-8" http-equiv="Content-Type" />
	<title>MODIFICATION PROFIL</title>
	<script type="text/javascript" src="javascript/ajax.js" ></script>
	<link href="style1.css" rel="stylesheet" type="text/css" />
</head>

<body onload="connectBan()">	
	
<!--####################################################################################
		BANIERE
#################################################################################### -->

	<div id="baniere">
		<a href="pageAcceuil.php">
			<img src="logo.png" />
		</a>
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
			<h1>Modification du compte</h1>
			<hr/>

			<?php 
				echo "<form method="."post"." action="."validationModifProfile.php?code=".$_SESSION['CODE_USER'].">";
				echo "<p>Nom :<input type="."text"." name="."nom"." value=".$_SESSION['NOM_USER']."></p>";
				echo "<p>Prénom :<input type="."text"." name="."prenom"." value=".$_SESSION['PRENOM_USER']."></p>";
				echo "<p>Login :<input type="."text"." name="."login"." value=".$_SESSION['LOGIN_USER']."></p>";
				echo "<p>Mot De Passe :<input type="."password"." name="."pwd"." value=".$_SESSION['PASS_USER']."></p>";
				echo "<input name="."Modifier"." type="."submit"." />";
				echo "</form>";
			?>
		</div>
	</div>

</body>

</html>
