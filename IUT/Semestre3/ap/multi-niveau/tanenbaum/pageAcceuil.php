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
	<title>ACCEUIL</title>
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
			<h1>Bienvenue</h1>
			<hr/>
			<p>TANENBAUM est un site consacré aux mélomanes cherchant à 
			s&#39;approvisionner en musiques et à partager leur passion.</p>
			<p>Vous pouvez accéder au Catalogue en ligne, consulter toutes les musiques présentent dans notre base. 
			Un tri par alphabet et par catégorie musical vous aideront dans vos recherches.&nbsp; A l'aide de l'icone <img src="image/info.png" /> 
			vous aurez accés aux informations sur une musique.</p>
			<p>Actuelement vous pouvez vous connecter et accéder à votre panier et à vos informations personelles. 
			Vous avez la possibilité de modifier vos informations à tout moment.</p>
			<p>Si vous n'avez pas de compte, vous pouvez eventuelement vous inscrire, c'est gratuit et rapide.</p>
			<br/>
			<br/>
			<p>Notre site manque la possibilité de :
			<ul>
				<li>Ajouter des commentaires sur une musique</li>
				<li>Modifier ses préférences musicales</li>
				<li>Faire une recherche précise dans le catalogue</li>
				<li>Telecharger une musique via le panier</li>
				<li>Payer une musique via le panier</li>
			</ul></p>
		</div>
	</div>
		
</body>

</html>
