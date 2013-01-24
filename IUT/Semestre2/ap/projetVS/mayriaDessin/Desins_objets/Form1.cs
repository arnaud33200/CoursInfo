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
    public partial class Form1 : Form
    {
        List<Rect> rectangles;

        public Form1()
        {
            InitializeComponent();
            rectangles = new List<Rect>();
     
        
        
        }
        private Rect TrouveRect(Point p)
        {
            foreach (Rect r in rectangles)
            {
                if (r.GetRectangle().Contains(p))
                {
                    return r;
                }
                

            }
            return null;
        }

        private void toolStripContainer1_TopToolStripPanel_Click(object sender, EventArgs e)
        {

        }

        private void Boite_MouseDown(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left)
            {
               
            }
            else if (e.Button == MouseButtons.Right)
            {
                Rect curRect = TrouveRect(e.Location);
                if (curRect != null)
                {
                    Params par = new Params();
                    par.Epaisseur = curRect.getEpaisseur();
                    par.Couleur = curRect.getCouleur();
                    par.Texte = curRect.GetTexte();
                    par.Police = curRect.getFont();

                    if (par.ShowDialog() == DialogResult.OK)
                    {
                        curRect.setCouleur(par.Couleur);
                        curRect.setEpaisseur(par.Epaisseur);
                        curRect.setTexte(par.Texte);
                        curRect.setFont(par.Police);
                        Refresh();
                    }
                }
                else if (curRect == null)
                {
                    Rect r = new Rect(new Rectangle(e.Location, new Size(10, 10)), Color.Red, 1);
                    rectangles.Add(r);
                    Refresh();

                }
            }
        }



        private void Boite_MouseMove(object sender, MouseEventArgs e)
        {

        }

        private void Boite_MouseUp(object sender, MouseEventArgs e)
        {

        }

        private void Boite_MouseClick(object sender, MouseEventArgs e)
        {

        }

        private void Boite_Paint(object sender, PaintEventArgs e)
        {
            foreach (Rect r in rectangles)
            {
                r.Dessine(e.Graphics);
            }
        }

        private void toolStripButton1_Click(object sender, EventArgs e)
        {

        }

    
    }
}
