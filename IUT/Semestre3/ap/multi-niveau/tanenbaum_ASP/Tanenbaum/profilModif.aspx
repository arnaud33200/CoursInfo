<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="profilModif.aspx.cs" Inherits="Tanenbaum.profilModif" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Modification Profile</title>
    <link href="style1.css" rel="stylesheet" type="text/css" />
</head>
<body>

    <form id="form1" runat="server">

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
			<h1>Modification du compte</h1>
			<hr/>
            <br />
            Prénom :
            <asp:TextBox ID="TextBox1" runat="server" style="margin-left: 6px"></asp:TextBox>
            <br />
            <br />
            Nom :
            <asp:TextBox ID="TextBox2" runat="server" style="margin-left: 27px" 
                Width="127px"></asp:TextBox>
            <br />
            <br />
            Login :
            <asp:TextBox ID="TextBox3" runat="server" style="margin-left: 25px"></asp:TextBox>
            <br />
            <br />
            Pass :
            <asp:TextBox ID="TextBox4" runat="server" style="margin-left: 31px"></asp:TextBox>
            <br />
            <br />
            <br />
            <asp:Button ID="modifProfil" runat="server" Text="Changer" />
		</div>
	</div>

    </form>

</body>
</html>

