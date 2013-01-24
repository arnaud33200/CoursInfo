using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Drawing;

namespace edvqrv
{
    class Piece
    {
        private Color color;
        public Color Color
        {
            get { return color; }
            set { color = value; }
        }

        private bool dame;
        public bool Dame
        {
            get { return dame; }
            set { dame = value; }
        }

        public Piece(Color c)
        {
            color = c;
            dame = false;
        }
    }
}
