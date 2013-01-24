<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="catalogue.aspx.cs" Inherits="Tanenbaum.WebForm2" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
    <script type="text/javascript" src="javascript/ajax.js" ></script>
	<script type="text/javascript">
	    function loadajax() {
	        connectCat('requete/affichercatalogue.aspx');
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

		   			<% veriflogin(); %>
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

</body>
</html>

