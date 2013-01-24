using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Drawing;
using System.IO;
using System.Runtime.Serialization.Formatters.Binary;

namespace rectangleTM
{
    [Serializable]
    public class Rect
    {
        public Rectangle rect;
        public Color couleur;
        public int epaisseur;
        public String Texte;
        public int Taille;
        public Point centre;

        public Rect(int t, Rectangle r, Color c, int e)
        {
            Taille = t;
            rect = r;
            couleur = c;
            epaisseur = e;
            centre = new Point(r.X, r.Y);

        }


        public void Dessine(Graphics g)
        {
            
            Pen p = new Pen(couleur, epaisseur);
            g.DrawRectangle(p, new Rectangle(rect.X - (Taille / 2), rect.Y - (Taille / 2), Taille, Taille) );
        }

        public bool Contains(Point p)
        {
            if (rect.Contains(p))
                return true;
            else
                return false;
        }

        public void moveRect(Point p)
        {
            centre.X = p.X;
            centre.Y = p.Y;
            rect.Location = p;
        }
    }
}
