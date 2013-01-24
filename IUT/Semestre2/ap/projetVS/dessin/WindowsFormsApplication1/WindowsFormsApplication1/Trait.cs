using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Drawing;

namespace WindowsFormsApplication1
{
    class Trait
    {
        private List<Point> points;
        private Color couleur;
        private int epaisseur;

        public Trait(Color c, int e)
        {
            this.couleur = c;
            this.epaisseur = e;
            points = new List<Point>();
        }

        public void Dessine(Graphics g)
        {
            g.DrawLines( new Pen(couleur, epaisseur), points.ToArray() );
        }

        public void AddPoint(Point p)
        {
            points.Add(p);
        }
    }
}
