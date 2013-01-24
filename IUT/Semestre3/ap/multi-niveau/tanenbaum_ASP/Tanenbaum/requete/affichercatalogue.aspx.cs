using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data.SqlClient;

namespace Tanenbaum.requete
{
    public partial class affichercatalogue : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

            string alpha = "%";
            string cat = "%";
            if( Request.Params["alpha"] != null )
			    alpha = Request.Params["alpha"];
	        if( Request.Params["cat"] != null )
			    cat = Request.Params["cat"];
	
		   
		
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//		afficher les catégories		
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

            affichercategorie(alpha);


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//		afficher le panneau alphabet		
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~	
	
		string[] alp = new string[26] {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
		Response.Write("<table class=\"tabrest\"><tr class=\"tabhead\"><td onclick=\"connectCat('requete/affichercatalogue.aspx')\">*</td>");
		foreach( string let in alp )
			Response.Write("<td onclick=\"connectCat('requete/affichercatalogue.apsx?alpha=" + let + "&cat=" + cat + "')\">" + let + "</td>");
		Response.Write("</tr></table>");
		
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//		ajout dans le panier		
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

        ajouterpanier();
		
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//		afficher les musiques		
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        affichercata(alpha, cat);
		 
        }

        protected void affichercategorie( string alpha)
        {
            System.Data.SqlClient.SqlConnection connexion;
            connexion = new System.Data.SqlClient.SqlConnection();

            string sConnectionString = "Server=info-simplet;Initial Catalog=musique;uid=ETD;password=ETD";
            connexion.ConnectionString = sConnectionString;
            connexion.Open();

            string query = "select Code_Catégorie_Musicale, Catégorie_Musicale from Catégories_musicales";
            SqlCommand myCommand = new SqlCommand(query, connexion);
            SqlDataReader mySqDataReader = myCommand.ExecuteReader();

            Response.Write("<table class=\"tabrest\"><tr><td onclick=\"connectCat('requete/affichercatalogue.aspx?cat=%&alpha=" + alpha + "')\">Toutes Catégories</td>");

            if (mySqDataReader.HasRows == false)
                Response.Write("ERREUR DANS LA REQUETE AFFICHER CATEGORIE");

            while (mySqDataReader.Read())
            {
                Response.Write("<td onclick=\"connectCat('requete/affichercatalogue.aspx?cat=" + mySqDataReader["Code_Catégorie_Musicale"] + "&alpha=" + alpha + "')\">" + mySqDataReader["Catégorie_Musicale"] + "</td>");
            }
            Response.Write("</tr></table>");

            connexion.Close();
        }

        protected void ajouterpanier()
        {
            System.Data.SqlClient.SqlConnection connexion;
            connexion = new System.Data.SqlClient.SqlConnection();

            string sConnectionString = "Server=info-simplet;Initial Catalog=musique;uid=ETD;password=ETD";
            connexion.ConnectionString = sConnectionString;
            connexion.Open();

            if (Request.Params["add"] != null)
            {
                if (Session["NOM_USER"] == null)
                    Response.Redirect("connexion.aspx", true);

                string add = Request.Params["add"];
                string melo = (string)Session["CODE_USER"];

                string query = "insert into Téléchargements ( Code_Mélomane, Code_Oeuvre_Enregistrée) values ('" + melo + "', '" + add + "')";
                SqlCommand myCommand = new SqlCommand(query, connexion);
                SqlDataReader mySqDataReader = myCommand.ExecuteReader();
                if (mySqDataReader.HasRows == false)
                    Response.Write("ERREUR DANS LA REQUETE AJOUT PANIER");
                while (mySqDataReader.Read())
                { }
            }

            connexion.Close();
        }

        protected void affichercata( string alpha, string cat)
        {
            System.Data.SqlClient.SqlConnection connexion;
            connexion = new System.Data.SqlClient.SqlConnection();

            string sConnectionString = "Server=info-simplet;Initial Catalog=musique;uid=ETD;password=ETD";
            connexion.ConnectionString = sConnectionString;
            connexion.Open();

            Response.Write(alpha + " - " + cat);
            //string query = "select E.Format, M.Titre_Oeuvre, C.Prénom_Compositeur, C.Nom_Compositeur, O.Code_Oeuvre_Enregistrée from Oeuvres_Enregistrées O join Oeuvres_Musicales M on O.Code_Oeuvre_Musicale = M.Code_Oeuvre join Enregistrements E on O.Code_Enregistrement = E.Code_Enregistrement join Types_morceaux T on M.Code_Type = T.Code_Type join Compositeurs C on M.Code_Compositeur = C.Code_Compositeur where M.Titre_Oeuvre like ('" + alpha + "%') and E.Code_Catégori_eMusicale like ('" + cat + "') order by E.Code_Enregistrement";
            string query = "select E.Format, M.Titre_Oeuvre, C.Prénom_Compositeur, C.Nom_Compositeur, O.Code_Oeuvre_Enregistrée from Oeuvres_Enregistrées O join Oeuvres_Musicales M on O.Code_Oeuvre_Musicale = M.Code_Oeuvre join Enregistrements E on O.Code_Enregistrement = E.Code_Enregistrement join Types_morceaux T on M.Code_Type = T.Code_Type join Compositeurs C on M.Code_Compositeur = C.Code_Compositeur order by E.Code_Enregistrement";

            SqlCommand myCommanda = new SqlCommand(query, connexion);
            SqlDataReader mySqDataReadera = myCommanda.ExecuteReader();

            if (mySqDataReadera.HasRows == false)
                Response.Write("ERREUR DANS LA REQUETE AFFICHER CATALOGUE");

            int num = 0;
            string song, alb, sing;

            Response.Write("<table class=\"tab\">");
            Response.Write("<tr class=\"tabhead\"> <td>support</td> <td>chanson</td> <td>Auteur</td> <td>Info</td> <td>panier</td> </tr>");
            while (mySqDataReadera.Read())
            {
                if ( (string)mySqDataReadera["Format"] == "CD")
                    Response.Write("<tr><td><img src=\"http://www.manytoo-blues.com/disc71.gif\"/></td>");
                else
                    Response.Write("<tr><td><img src=\"http://upload.wikimedia.org/wikipedia/commons/thumb/0/02/Disque_Vinyl.svg/35px-Disque_Vinyl.svg.png\"/></td>");

                song = (string)mySqDataReadera["Titre_Oeuvre"];
                sing = (string)mySqDataReadera["Prénom_Compositeur"] + " " + (string)mySqDataReadera["Nom_Compositeur"];
                num = (int)mySqDataReadera["Code_Oeuvre_Enregistrée"];

                Response.Write("<td>" + song + "</td>");
       
                Response.Write("<td>" + sing + "</td>");
                Response.Write("<td><a href=\"infoChanson.aspx?num=" + num + "\" target=_blank><img src=\"image/info.png\"/></a></td>");
                Response.Write("<td onclick=\"connectCat('requete/affichercatalogue.aspx?add=" + num + "&alpha=" + alpha + "&cat=" + cat + "')\">ajouter</td></tr>");
            }

            Response.Write("</table>");

            connexion.Close();
        }
    }
}