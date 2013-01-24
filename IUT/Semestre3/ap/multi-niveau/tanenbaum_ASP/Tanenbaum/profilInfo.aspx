<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="profilInfo.aspx.cs" Inherits="Tanenbaum.profilInfo" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
    <link href="style1.css" rel="stylesheet" type="text/css" />
</head>
<body>

<!--####################################################################################
		BANIERE
#################################################################################### -->

	<div id="baniere">
		<a href="Default.aspx"><img src="image/logo.png" /></a>
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
		    		<li><a href="Default.aspx">ACCEUIL</a> </li>
		   			<li><a href="catalogue.aspx">CATALOGUE</a></li>

		   			<!--<?php
						if( $conn == "no" )
						{
			    			echo "<li><a href=\"connexion.aspx\">CONNEXION</a></li>";
			    			echo "<li><a href=\"inscription.aspx\">INSCRIPTION</a></li>";
			    		}
			    		else
			    		{
			    			echo "<li><a>PROFIL</a><ul>";
								echo "<li><a href=\"profilInfo.aspx\">information</a> </li>";
								echo "<li><a href=\"profilModif.aspx\">modifier</a></li></ul></li>";
							echo "<li><a href=\"panier.aspx\">PANIER</a></li>";
							echo "<li><a href=\"deconnexion.aspx\">DECONEXION</a></li>";				
						}?>-->
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
			<div id="infocompte"></div>
        </div>
	</div>

</body>
</html>

