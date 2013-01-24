using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data.SqlClient;

namespace Tanenbaum.requete
{
    public partial class infogeneral : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (Session["LOGIN_USER"] != null)
                Response.Write("Bonjour " + Session["PRENOM_USER"] + " " + Session["NOM_USER"]);

            System.Data.SqlClient.SqlConnection connexion;
            connexion = new System.Data.SqlClient.SqlConnection();

            string sConnectionString = "Server=info-simplet;Initial Catalog=musique;uid=ETD;password=ETD";
            connexion.ConnectionString = sConnectionString;
            connexion.Open();

            string query = "Select count(*) as nb from Enregistrements";

            SqlCommand myCommand = new SqlCommand(query, connexion);

            SqlDataReader mySqDataReader = myCommand.ExecuteReader();

            if (mySqDataReader.HasRows == false)
            {
                Response.Write("ERREUR DANS LA REQUETE");
            }

            if(mySqDataReader.Read())
            {
                Response.Write("<p>Nous avons actuelement : " + mySqDataReader["nb"] + " enregistrements</p>");
                 
            }

            connexion.Close();
        }

    }
}