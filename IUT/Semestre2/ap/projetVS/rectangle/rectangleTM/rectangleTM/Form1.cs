using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO;
using System.Runtime.Serialization.Formatters.Binary;

namespace rectangleTM
{
    public partial class Form1 : Form
    {
        private List<Rect> rectangles;
        private Rect curRect = null;
        private Trait curTrait = null;
        private Rect sour;
        private Rect dest;
        private int cote;
        private List<Trait> traits;
        private Trait trait;
        private Point curPoint = Point.Empty;
        private bool move;

        public Form1()
        {
            InitializeComponent();
            cote = 10;
            rectangles = new List<Rect>();
            traits = new List<Trait>();
        }

        private void Form1_MouseDown(object sender, MouseEventArgs e)
        {
            curRect = TrouveObjet(e.Location); 
  // ~~~~~~ boutton dessin enfoncé
            if (e.Button == MouseButtons.Left)
            {
                if (!buttonDessin.Checked)
                {
                    if (curRect == null)
                    {
                        curRect = new Rect(cote, new Rectangle(e.X - (cote / 2), e.Y - (cote / 2), cote, cote), Color.Black, 3);
                        sour = null;
                        rectangles.Add(curRect);
                    }
                    else
                    {
                        sour = curRect;
                    }
                    Refresh();
                }
                else
                {
                        move = true;
                }

// ############### CLICK DROIT ################### //
            }
            else
            {
                if (!buttonDessin.Checked)
                {

                    if (TrouveObjet(e.Location) != null)
                    {

                        Params par = new Params();
                        par.Epaisseur = curRect.epaisseur;
                        par.couleur = curRect.couleur;
                        par.Texte = curRect.Texte;
                        par.Taille = curRect.Taille;
                        if (par.ShowDialog() == DialogResult.OK)
                        {
                            curRect.epaisseur = (int)par.Epaisseur;
                            curRect.Texte = par.Texte;
                            curRect.Taille = (int)par.Taille;
                            Refresh();
                        }
                    }
                }
                else
                {
                    do
                    {
                        curTrait = TrouveTrait(curRect);
                        traits.Remove(curTrait);
                    }
                    while (curTrait != null);
                    rectangles.Remove(curRect);
                    Refresh();
                }
            }
        }

        private Rect TrouveObjet(Point p)
        {
            foreach (Rect re in rectangles)
            {
                if ( re.Contains(p) )
                {
                    return re;
                }
            }
            return null;
        }

        private Trait TrouveTrait(Rect r)
        {
            foreach (Trait tr in traits)
            {
                if (tr.source == r || tr.destination == r)
                    return tr;
            }
            return null;
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            foreach (Rect r in rectangles)
                r.Dessine(e.Graphics);

            foreach (Trait t in traits)
                t.dessinetrait(e.Graphics);

        }

        private void Form1_MouseUp(object sender, MouseEventArgs e)
        {
            curRect = TrouveObjet(e.Location);
            move = false;
            if (sour != null && !buttonDessin.Checked)
            {
                if (TrouveObjet(e.Location) != null)
                {
                    dest = curRect;
                }
                else
                {
                    curRect = new Rect(cote, new Rectangle(e.X - (cote / 2), e.Y - (cote / 2), cote, cote), Color.Black, 3);
                    dest = curRect;
                }

                rectangles.Add(dest);
                trait = new Trait(sour, dest, Color.Blue, 2);
                traits.Add(trait);
                Refresh();
            }
        }

        private void Form1_MouseMove(object sender, MouseEventArgs e)
        {
            if (buttonDessin.Checked && curRect != null && move )
            {
                curRect.moveRect(e.Location);
                Refresh();
            }
        }

// LE BOUTTON ENREGISTRER !!!

        private void enregistrerToolStripButton_Click(object sender, EventArgs e)
        {
            SaveFileDialog save = new SaveFileDialog();
            save.Filter = "*fichier sauvegarde RPZ(*.XsavX)|*.XsavX";
            if (save.ShowDialog() == DialogResult.OK)
            {
                Stream stream = File.Open(save.FileName, FileMode.Create);
                BinaryFormatter bifo = new BinaryFormatter();
                bifo.Serialize(stream, rectangles);
                bifo.Serialize(stream, traits);
                if (!stream.CanWrite) MessageBox.Show("marche PO !!!! O___o");
                stream.Close();
            }
        }

        private void ouvrirToolStripButton_Click(object sender, EventArgs e)
        {
            OpenFileDialog open = new OpenFileDialog();
            open.Filter = "*fichier sauvegarde RPZ(*.XsavX)|*.XsavX";
            if (open.ShowDialog() == DialogResult.OK)
            {
                Stream stream = File.Open(open.FileName, FileMode.Open);
                BinaryFormatter bifo = new BinaryFormatter();
                rectangles = (List<Rect>)bifo.Deserialize(stream);
                traits = (List<Trait>)bifo.Deserialize(stream);

            // retrouver tous les rectangles qui définissent les traits
                foreach (Trait tr in traits)
                {
                    curRect = TrouveObjet(tr.source.centre);
                    if (curRect != null)
                        tr.source = curRect;
                    curRect = TrouveObjet(tr.destination.centre);
                    if (curRect != null)
                        tr.destination = curRect;
                }

                stream.Close();
                Refresh();
            }
        }

        private void nouveauToolStripButton_Click(object sender, EventArgs e)
        {
            traits.Clear();
            rectangles.Clear();
            Refresh();
        }

        private void toolStripButton1_Click(object sender, EventArgs e)
        {
            SaveFileDialog save = new SaveFileDialog();
            save.Filter = "format XML (*.xml)|*.xml";
            if (save.ShowDialog() == DialogResult.OK)
            {
                StreamWriter lecture = new StreamWriter(save.FileName);
                lecture.WriteLine("<?xml version=\"1.0\" encoding=\"UTF-8\" ?>");
                lecture.WriteLine("<DESSIN>");
                foreach (Rect re in rectangles)
                {
                    lecture.WriteLine("     <RECTANGLE>");
                    lecture.WriteLine("         <EPAISSEUR>");
                    lecture.WriteLine("             " + re.epaisseur.ToString() );
                    lecture.WriteLine("         </EPAISSEUR>");
                    lecture.WriteLine("         <COULEUR>");
                    lecture.WriteLine("             " + re.couleur.ToString() );
                    lecture.WriteLine("         </COULEUR>");
                    lecture.WriteLine("         <CENTRE>");
                    lecture.WriteLine("             " + re.centre.ToString() );
                    lecture.WriteLine("         </CENTRE>");
                    lecture.WriteLine("     </RECTANGLE>");
                }
                lecture.WriteLine("</DESSIN>");
                lecture.Close();
            }
        }


    }
}
