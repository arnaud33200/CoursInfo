using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace Desins_objets
{
    public partial class Params : Form
    {
        public decimal Epaisseur
        {
            get
            {
                return ParamsEpaisseur.Value;
            }
            set
            {
                ParamsEpaisseur.Value = value;
            }
        }
        public string Texte
        {
            get
            {
                return ParamsTexte.Text;
            }
            set
            {
                ParamsTexte.Text = value;
            }
        }
        public Color Couleur
        {
            get
            {
                return couleur.BackColor;
            }
            set
            {
                couleur.BackColor = value;
            }
        }
        public Font Police
        {
            get
            {
                return ParamsTexte.Font;
            }
            set
            {
                ParamsTexte.Font = value;
            }
        }
        public Params()
        {
            InitializeComponent();

        }

        private void ParamsOK_Click(object sender, EventArgs e)
        {
            
            Close();
            
           
        }

        private void ParamsAnnuler_Click(object sender, EventArgs e)
        {
            Close();

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void ColorClick(object sender, EventArgs e)
        {
            ColorDialog cld = new ColorDialog();
            cld.Color = couleur.BackColor;
            if (cld.ShowDialog() == DialogResult.OK)
                couleur.BackColor = cld.Color;

        }

        private void FontClick(object sender, EventArgs e)
        {
            FontDialog ftd = new FontDialog();
            ftd.Font = ParamsTexte.Font;
            if (ftd.ShowDialog() == DialogResult.OK)
                ParamsTexte.Font = ftd.Font;

        }



    }
}
