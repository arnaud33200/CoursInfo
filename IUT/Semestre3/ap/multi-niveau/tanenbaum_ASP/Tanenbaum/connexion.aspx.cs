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
    public partial class WebForm3 : System.Web.UI.Page
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

            if (Request.Params["login"] != null && Request.Params["mdp"] != null)
            {
                    string login = Request.Params["login"];
                    string mdp = Request.Params["mdp"];

                    System.Data.SqlClient.SqlConnection connexion;

                    connexion = new System.Data.SqlClient.SqlConnection();

                    string sConnectionString;
                    sConnectionString = "Server=info-simplet;Initial Catalog=musique;uid=ETD;password=ETD";
                    connexion.ConnectionString = sConnectionString;

                    connexion.Open();
                    string query = "SELECT * FROM Mélomanes WHERE Login = '" + login + "' AND Mot_De_Passe = '" + mdp + "';";

                    SqlCommand myCommand = new SqlCommand(query, connexion);
                    SqlDataReader mySqDataReader = myCommand.ExecuteReader();

                    if (mySqDataReader.HasRows)
                    {
                        mySqDataReader.Read();
                        Session["CODE_USER"] = (int)mySqDataReader["Code_Mélomane"];
                        Session["NOM_USER"] = (string)mySqDataReader["Nom_Mélomane"];
                        Session["PRENOM_USER"] = (string)mySqDataReader["Prénom_Mélomane"];
                        Session["LOGIN_USER"] = login;
                        Session["PASS_USER"] = mdp;
                    }
                    else
                    {
                        Response.Redirect("connexion.aspx", true);
                    }
                    Response.Redirect("Default.aspx", true);
            }
        }

        protected void valdcon_Click(object sender, EventArgs e)
        {
            connect();
        }
    }
}