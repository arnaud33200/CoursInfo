using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Drawing;

namespace edvqrv
{
    class CaseDamier : Panel
    {
        private Piece p;
        public Color pieceColor ()
        {
            if (p != null)
                return p.Color;
            else
                return Color.Purple;
        }

        public bool pieceDame
        {
            get { return p.Dame; }
            set { if (p!= null) p.Dame = value; }
        }

        private bool select;
        public bool estSelect
        {
            get { return select; }
            set { select = value; }
        }

        public Color backColor
        {
            get { return BackColor; }
            set { BackColor = value; }
        }

        public CaseDamier(Color cc, Color pc)
        {
            select = false;
            BackColor = cc;
            p = new Piece(pc);
            Width = 54;
            Height = 54;
        }

        public CaseDamier(Color cc)
        {
            select = false;
            BackColor = cc;
            p = null;
            Width = 54;
            Height = 54;
        }

        private void InitializeComponent()
        {
            this.SuspendLayout();
            // 
            // CaseDamier
            // 
            this.ResumeLayout(false);

        }

        public void Dessine(Graphics g, int i, int j)
        {
            Brush b;
            if (!select || p == null)
                b = new SolidBrush(BackColor);
            else
                b = new SolidBrush(Color.Red);
            Rectangle r = new Rectangle(this.Top, this.Left, Width, Height);
            g.FillRectangle(b, r);
            if (p != null)
            {
                if (p.Color == Color.Blue)
                {
                   if ( pieceDame )
                        g.DrawImage(JeuDeDames.Properties.Resources.noirdame, new Point(this.Top, this.Left));
                    else
                        g.DrawImage(JeuDeDames.Properties.Resources.noir, new Point(this.Top, this.Left));
                }
                else if (p.Color == Color.White)
                {
                    if ( pieceDame )
                        g.DrawImage(JeuDeDames.Properties.Resources.blancdame, new Point(this.Top, this.Left));
                    else
                        g.DrawImage(JeuDeDames.Properties.Resources.blanc, new Point(this.Top, this.Left));
                }

            }
        }

        public void movePiece(CaseDamier c)
        {
            if (c.p == null)
            {
                c.p = p;
                p = null;
            }
        }

        public void estMange()
        {
            p = null;
        }

        public bool estVide()
        {
            if (p != null)
                return false;
            else
                return true;
        }

        public void verifDame(int i)
        {
          if (pieceColor() == Color.White && i == 0)
            {
                pieceDame = true;
            }
            else if (pieceColor() == Color.Blue && i == 9)
            {
                pieceDame = true;
            }

        }
    }
}
