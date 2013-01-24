using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Drawing;

namespace WindowsFormsApplication1
{
    class Rect
    {
        private Rectangle rect;
        private Color couleur;
        private int epaisseur;

        public Rect(Rectangle r, Color c, int e)
        {
            rect = r;
            couleur = c;
            epaisseur = e;
        }

        public void Dessine(Graphics g)
        {
            Pen p = new Pen(couleur, epaisseur);
            g.DrawRectangle(p, rect);
        }
         
    }
}
