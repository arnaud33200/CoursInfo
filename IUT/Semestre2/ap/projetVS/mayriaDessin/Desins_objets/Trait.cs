using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Drawing;

namespace Desins_objets
{
    class Trait
    {
        private Rect source;
        private Rect destination;
        private Color couleur;
        private int epaisseur;
        public Trait(Rect sour, Rect dest, Color c, int e)
        {
            source = sour;
            destination = dest;
            couleur = c;
            epaisseur = e;
        }
        public void Dessine(Graphics g)
        {
            Pen p = new Pen(couleur, epaisseur);
     
        }

    }
}
