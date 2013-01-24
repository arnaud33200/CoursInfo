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
	<title>INFO PROFIL</title>
	<script type="text/javascript" src="javascript/ajax.js" ></script>
	<script type="text/javascript">
		function loadajax()
		{
			connectCo();
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
		<h1>Vos Information de compte</h1>
		<hr/>
		<?php
			if( $conn == "no" )
			{
				echo "<p>information indisponible</p>";
				echo "<p>veuillez vous connecter</p>";
			}
			else
			{
				echo "<p>Nom : " . $_SESSION['NOM_USER'] . "</p>";
				echo "<p>Prenom : ".$_SESSION['PRENOM_USER']."</p>";
				echo "<p>Login : ".$_SESSION['LOGIN_USER']."</p>";
			}
			?>
			
			<div id="infocompte"></div>
		</div>
	</div>
		
</body>

</html>
