using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace WindowsFormsApplication1
{
    public partial class Form1 : Form
    {
        List<Point> ligne = new List<Point>();
        private bool enDessin = false;
        private Trait trait;
        private List<Trait> traits = new List<Trait>();
        private int epaisseurParDefaut = 50;
        private Color couleurParDefaut = Color.Black;
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_MouseDown(object sender, MouseEventArgs e)
        {
            enDessin = true;
            trait = new Trait(couleurParDefaut, epaisseurParDefaut);
            traits.Add(trait);
            trait.AddPoint(e.Location);
        }

        private void Form1_MouseMove(object sender, MouseEventArgs e)
        {
            if ( enDessin )
            {
                trait.AddPoint(e.Location);
                Refresh();
            }
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            if ( traits.Count > 1 )
                foreach (Trait t in traits)
                    t.Dessine(e.Graphics);
        }

        private void Form1_MouseUp(object sender, MouseEventArgs e)
        {
            enDessin = false;
        }

        private void epaisseur1_Click(object sender, EventArgs e)
        {
            epaisseurParDefaut = 1;
        }

        private void epaisseur10_Click(object sender, EventArgs e)
        {
            epaisseurParDefaut = 10;
        }
    }
}
