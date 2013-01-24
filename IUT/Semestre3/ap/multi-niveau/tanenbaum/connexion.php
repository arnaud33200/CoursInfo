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
	<title>CONNEXION</title>
	<script type="text/javascript" src="javascript/ajax.js" ></script>
	<link href="style1.css" rel="stylesheet" type="text/css" />
	<style type="text/css">
	</style>
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
			<h1>Connexion</h1>
			<hr />
			
			<a class="erreur">
				<?php
					if( isset($_REQUEST['error']) )
					{
						$err = $_REQUEST['error'];
						echo "ERREUR " . $err . " : ";
						if( $err == 1 )
							echo "Vous n'avez pas rempli tous les champs nécessaires</a>";
						else if( $err == 2 )
							echo "Mot de passe ou identifiant incorrect</a>";
						echo "<hr/>";
					}
				?>
			<?php
					
				if( isset($_REQUEST['url']) )		// recupére le paramètre : URL de la page prive
					$url = $_REQUEST['url'];
				else
					$url = "pageAcceuil.php";
			
				echo "<form method=\"post\" action=\"verifconnexion.php?url=" . $url . "\">"; ?>	
						
					<p>Login&nbsp; <input name="login" type="text" /></p>
					<p>Pass&nbsp;&nbsp;&nbsp; <input name="passwd" type="password" /></p>
					<input name="Envoyer" type="submit" />
					
			<?php echo "</form>" ?>					
		</div>
	</div>

</body>

</html>


<!--
<a class="erreur"></a>		
		    <br />
            <form runat=server>
            Login :
            <asp:TextBox ID="login" runat="server"></asp:TextBox>
            <br />
            <br />
            Pass :&nbsp;&nbsp;
            <asp:TextBox ID="mdp" runat="server"></asp:TextBox>
            <br />
            <br />
            <asp:Button ID="valdcon" runat="server" Text="Valider" 
                onclientclick="connect()" /> -->