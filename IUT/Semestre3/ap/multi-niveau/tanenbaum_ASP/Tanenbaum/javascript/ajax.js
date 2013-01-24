// Cette page JAVASCRIPT execute une requete ajax sur la "page"
// qui sera ensuite placé dans la div "id"

var requeteBan;
var requeteAjaxPanier;
var requeteCat;
var requeteAv;

function connectPanier()
{
	requeteAjaxPanier = creerRequete();
	if (requeteAjaxPanier != null)
	{
		requeteAjaxPanier.open("GET", "requete/afficherpanier.php", true);
		requeteAjaxPanier.onreadystatechange = handlerPanier;
		requeteAjaxPanier.send();
	}
	else
		window.alert("Pas de support AJAX (XMLHTTP)");
}

function handlerPanier()
{
	if (requeteAjaxPanier.readyState == 4 && requeteAjaxPanier.status == 200)
		document.getElementById('affichage').innerHTML = requeteAjaxPanier.responseText;
} 

//##########################################################################################
// AJAX POUR LA BANIERE DU BAS
//##########################################################################################  

function connectBan()
{
	requeteBan = creerRequete();
	if (requeteBan != null)
	{
		requeteBan.open("GET", "requete/infogeneral.aspx", true);
		requeteBan.onreadystatechange = handlerBan;
		requeteBan.send();
	}
	else
		window.alert("Pas de support AJAX (XMLHTTP)");
}

function handlerBan()
{
	if (requeteBan.readyState == 4 && requeteBan.status == 200)
	{
		var datetoday = new Date();
		document.getElementById('infosite').innerHTML = requeteBan.responseText;
		document.getElementById('infosite').innerHTML += ('date : ' + datetoday.getDay() + ' / ' + datetoday.getMonth() + ' / ' + datetoday.getFullYear() );
		document.getElementById('infosite').innerHTML += ' ';
	}
} 


//##########################################################################################
// AJAX POUR LE CATALOGUE
//##########################################################################################  

function connectCat(page)
{
	document.getElementById('catalogue').innerHTML = "<center><img src=\"image/load.gif\"/></center>";
	requeteCat = creerRequete();
	if (requeteCat != null)
	{
		requeteCat.open("GET", page, true);
		requeteCat.onreadystatechange = handlerCat;
		requeteCat.send();
	}
	else
		window.alert("Pas de support AJAX (XMLHTTP)");
}

function handlerCat()
{
	if (requeteCat.readyState == 4 && requeteCat.status == 200)
		document.getElementById('catalogue').innerHTML = requeteCat.responseText;
} 


//##########################################################################################
// AJAX POUR LES AVIS CHANSONS
//##########################################################################################  

function connectAv(num)
{
	requeteAv = creerRequete();
	if (requeteAv != null)
	{
		var page = "requete/affichercom.php?num=" + num;
		requeteAv.open("GET", page, true);
		requeteAv.onreadystatechange = handlerAv;
		requeteAv.send();
	}
	else
		window.alert("Pas de support AJAX (XMLHTTP)");
}

function handlerAv()
{
	if (requeteAv.readyState == 4 && requeteAv.status == 200)
		document.getElementById('com').innerHTML = requeteAv.responseText;
} 


// ##############################################################################################

function creerRequete()
{
	var requete = null;
	try { requete = new XMLHttpRequest(); } 
	catch(e1) 
	{
		try { requete = new ActiveXObject("Msxml2.XMLHTTP"); }
		catch(e2) 
		{
			try { requete = new ActiveXObject("Microsoft.XMLHTTP"); } 
			catch (echec)
			{
				requete = null;
			}
		 }
	}
	return requete;
} 
