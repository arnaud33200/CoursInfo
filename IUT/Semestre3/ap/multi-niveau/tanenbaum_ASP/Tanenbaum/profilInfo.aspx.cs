using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Security;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data.SqlClient;

namespace Tanenbaum
{
    public partial class profilInfo : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (Request.Params["page"] != null && Request.Params["page"] == "deco")
            {
                Response.Write("<h2>Vous avez été déconnecté</h2>");
                Session.Abandon();
                Response.Redirect("Default.aspx", true);
            }
            int code = (int)(Session["CODE_USER"]);
            string nom = (string)(Session["NOM_USER"]);
            string prenom = (string)(Session["PRENOM_USER"]);
            string login = (string)(Session["LOGIN_USER"]);

            Response.Write("<p>Nom :"+ nom +"</p>");
            Response.Write("<p>Prenom :" + prenom + "</p>");
            Response.Write("<p>Login :" + login + "</p>");
          
                // Déclaration de l'objet de connexion
                System.Data.SqlClient.SqlConnection connexion;

                // Création de l'objet de connexion
                connexion = new System.Data.SqlClient.SqlConnection();

                // Ecriture de la chaîne de connexion
                string sConnectionString;
                sConnectionString = "Server=info-simplet;Initial Catalog=musique;uid=ETD;password=ETD";
                connexion.ConnectionString = sConnectionString;

                // Ouverture de la connexion
                connexion.Open();

                // Traitement des opération à effectuer sur la base de données
                string query = "SELECT Niveau, Libellé_Type FROM Préférences JOIN Types_Morceaux on Préférences.Code_Type = Types_Morceaux.Code_Type WHERE Code_Mélomane='" + code  + "';";

                //Execution de la requête
                SqlCommand myCommand = new SqlCommand(query, connexion);

                //Lecture des enregistrements à l’aide d’un SqlDataReader
                SqlDataReader mySqDataReader = myCommand.ExecuteReader();

                //Execution de la requête
                myCommand = new SqlCommand(query, connexion);

                Response.Write("<ul>");
                while (mySqDataReader.HasRows)
                {
                    mySqDataReader.Read();
                    Response.Write("<li>" + (string)mySqDataReader["Libellé_Type"] + " : " + (string)mySqDataReader["Niveau"] + "</li>");
                }
                Response.Write("</ul>");

                // Fermeture de la connexion
                connexion.Close();
        }
    }
}