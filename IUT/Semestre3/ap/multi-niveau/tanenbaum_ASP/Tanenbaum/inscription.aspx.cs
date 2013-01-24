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
    public partial class inscription : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }
        protected void connect()
        {
            if (Request.Params["page"] != null && Request.Params["page"] == "deco")
            {
                Response.Write("<h2>Vous avez été déconnecté</h2>");
                Session.Abandon();
                Response.Redirect("Default.aspx", true);
            }

            if (Request.Params["prenom"] != null && Request.Params["nom"] != null && Request.Params["login"] != null && Request.Params["mdp"] != null)
            {
                    string prenom = Request.Params["prenom"];
                    string nom = Request.Params["nom"];
                    string login = Request.Params["login"];
                    string mdp = Request.Params["mdp"];

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

                        Response.Write("<h2>Inscription Réussie!</h2>");
                        // Traitement des opération à effectuer sur la base de données
                        string query = "INSERT INTO Mélomanes( Nom_Mélomane, Prénom_Mélomane, Login, Mot_De_Passe ) VALUES( '" + nom + "', '" + prenom + "','" + login + "' ,'" + mdp + "' )";

                        //Execution de la requête
                        SqlCommand myCommand = new SqlCommand(query, connexion);

                        //Lecture des enregistrements à l’aide d’un SqlDataReader
                        SqlDataReader mySqDataReader = myCommand.ExecuteReader();

                        //Execution de la requête
                        myCommand = new SqlCommand(query, connexion);

                        // Fermeture de la connexion
                        connexion.Close();
                }
            else
            {
                Response.Redirect("inscription.aspx", true);
            }
        }
    }
}