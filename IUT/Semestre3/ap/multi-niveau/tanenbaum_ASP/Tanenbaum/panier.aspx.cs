using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Tanenbaum
{
    public partial class panier : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void pageprivate()
        {
            if (Session["LOGIN_USER"] == null)
                Response.Redirect("connexion.aspx", true);
        }

        protected void veriflogin()
        {
            if (Session["LOGIN_USER"] != null)
            {
                Response.Write("<li><a>PROFIL</a><ul>");
                Response.Write("<li><a href=\"profilInfo.aspx\">information</a> </li>");
                Response.Write("<li><a href=\"profilModif.aspx\">modifier</a></li></ul></li>");
                Response.Write("<li><a href=\"panier.aspx\">PANIER</a></li>");
                Response.Write("<li><a href=\"deconnexion.aspx\">DECONEXION</a></li>");
            }
            else
            {
                Response.Write("<li><a href=\"connexion.aspx\">CONNEXION</a></li>");
                Response.Write("<li><a href=\"inscription.aspx\">INSCRIPTION</a></li>");
            }
        }
    }
}