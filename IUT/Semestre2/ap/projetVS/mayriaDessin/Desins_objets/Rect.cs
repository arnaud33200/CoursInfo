using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Drawing;

namespace Desins_objets
{
    class Rect
    {
        private Rectangle rect;
        private Color couleur;
        private decimal epaisseur;
        private string texte;
        private Font police;
        public Rect(Rectangle r, Color c, decimal e)
        {
            rect = r;
            couleur = c;
            epaisseur = e;
            texte = "Base Text";
            police = new Font("Arial", 10);
        }
        public void Dessine(Graphics g)
        {
            Pen p = new Pen(couleur, (int) epaisseur );
            g.DrawRectangle(p, rect);
            g.DrawString(texte, police, Brushes.Black , new Point(rect.X + 7, rect.Y));
           
        }
        public void setCouleur(Color c)
        {
            couleur = c;
        }
        public void setEpaisseur(decimal e)
        {
            epaisseur = e;
        }
        public decimal getEpaisseur()
        {
            return epaisseur;
        }
        public Color getCouleur()
        {
            return couleur;
        }
        public Rectangle GetRectangle()
        {
            return rect;
        }
        public string GetTexte()
        {
            return texte;
        }
        public void setTexte(string s)
        {
            texte = s;
        }
        public void setFont(Font f)
        {
            police = f;
        }
        public Font getFont()
        {
            return police;
        }
    }
}
