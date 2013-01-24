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
    class Trait
    {
        public Rect source;
        public Rect destination;
        private Color couleur;
        private int epaisseur;

        public Trait(Rect sour, Rect dest, Color c, int e)
        {
            source = sour;
            destination = dest;
            couleur = c;
            epaisseur = e;
        }

        public void dessinetrait(Graphics g)
        {
            Pen p = new Pen(couleur, epaisseur);
            g.DrawLine(p, source.centre, destination.centre);
        }
    }
}
