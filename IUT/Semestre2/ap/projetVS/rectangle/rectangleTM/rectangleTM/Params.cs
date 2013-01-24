using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace rectangleTM
{
    public partial class Params : Form
    {
/*************************************************/
        public string Texte
        {
            get { return texototo.Text; }
            set { texototo.Text = value; }
        }

        public decimal Epaisseur
        {
            get { return epaissetasoeur.Value; }
            set { epaissetasoeur.Value = value; }
        }

        public decimal Taille
        {
            get { return taillo.Value; }
            set { taillo.Value = value; }
        }

/******************************************************/
        public Color couleur
        {
            get { return cololo.BackColor; }
            set { cololo.BackColor = value; }
        }

        public Params()
        {
            InitializeComponent();
        }



        private void taille_rectangle_ValueChanged(object sender, EventArgs e)
        {

        }

        private void groupBox1_Enter(object sender, EventArgs e)
        {

        }

        private void cololo_MouseDown(object sender, MouseEventArgs e)
        {

        }

    }
}
