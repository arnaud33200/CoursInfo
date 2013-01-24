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

namespace edvqrv
{
    [Serializable]
    public partial class Form1 : Form
    {
        private CaseDamier[,] jeuDeDames;
        private int cur_i, cur_j;
        private int blancrest, noirrest;

        private bool tour_blanc;
        public Form1()
        {
            InitializeComponent();
            blancrest = -1;
            noirrest = -1;

            jeuDeDames = new CaseDamier[10, 10];
            for (int i = 0; i < 10; i++)
                for (int j = 0; j < 10; j++)
                {
                    if (i % 2 == 0)
                    {
                        if (j % 2 != 0)
                        {
                            if (i < 4)
                                jeuDeDames[j, i] = new CaseDamier(Color.CadetBlue);
                            else if (i > 5)
                                jeuDeDames[j, i] = new CaseDamier(Color.CadetBlue);
                            else
                                jeuDeDames[j, i] = new CaseDamier(Color.CadetBlue);
                        }
                        else
                            jeuDeDames[j, i] = new CaseDamier(Color.White);
                    }
                    else
                        if (j % 2 != 0)
                            jeuDeDames[j, i] = new CaseDamier(Color.White);
                        else
                            if (i < 4)
                                jeuDeDames[j, i] = new CaseDamier(Color.CadetBlue);
                            else if (i > 5)
                                jeuDeDames[j, i] = new CaseDamier(Color.CadetBlue);
                            else
                                jeuDeDames[j, i] = new CaseDamier(Color.CadetBlue);

                    jeuDeDames[j, i].Top = j * jeuDeDames[j, i].Width;
                    jeuDeDames[j, i].Left = (i * jeuDeDames[j, i].Height) + toolStrip1.Height;
                }
        }


        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            for (int i = 0; i < 10; i++)
                for (int j = 0; j < 10; j++)
                    jeuDeDames[i, j].Dessine(e.Graphics, i, j);
        }

#region GESTION PRESSION SOURIE
        private void Form1_MouseDown(object sender, MouseEventArgs e)
        {
            // si la partie est pas terminée
            if (blancrest != 0 && noirrest != 0)
            {
                cur_i = (e.Y - toolStrip1.Height) / jeuDeDames[0, 0].Height;
                cur_j = e.X / jeuDeDames[0, 0].Width;
                if (cur_i < 10 && cur_i >= 0 && cur_j < 10 && cur_j >= 0 &&
                    jeuDeDames[cur_j, cur_i].backColor != Color.White)
                {
                    if (veriftour_blanc(jeuDeDames[cur_j, cur_i].pieceColor()))
                        jeuDeDames[cur_j, cur_i].estSelect = true;
                }
                Refresh();
            }
        }

        private void Form1_MouseUp(object sender, MouseEventArgs e)
        {
            // si la case courante existe 
            if (cur_i >= 0 && cur_i < 10 && cur_j >= 0 && cur_j < 10)
            {

                jeuDeDames[cur_j, cur_i].estSelect = false;
                int cur_i_deux = (e.Y - toolStrip1.Height) / jeuDeDames[0, 0].Height;
                int cur_j_deux = e.X / jeuDeDames[0, 0].Width;
                // si le déplacement d'un pion noir est possible
                if (deplacementBleuPossible(cur_i_deux, cur_j_deux))
                {
                    jeuDeDames[cur_j, cur_i].movePiece(jeuDeDames[cur_j_deux, cur_i_deux]);
                    if (cur_i != cur_i_deux && cur_j != cur_j_deux)
                    {
                        // verifie si ça devient une dame
                        jeuDeDames[cur_j_deux, cur_i_deux].verifDame(cur_i_deux);
                        tour_blanc = true;
                        aquiletour.Text = "BLANCS";
                    }
                }
                else if (deplacementBlancPossible(cur_i_deux, cur_j_deux))
                {
                    jeuDeDames[cur_j, cur_i].movePiece(jeuDeDames[cur_j_deux, cur_i_deux]);
                    if (cur_i != cur_i_deux && cur_j != cur_j_deux)
                    {
                        // verifie si ça devient une dame
                        jeuDeDames[cur_j_deux, cur_i_deux].verifDame(cur_i_deux);
                        tour_blanc = false;
                        aquiletour.Text = "NOIRS";
                    }
                }
                Refresh();
            }
            if (blancrest == 0 || noirrest == 0)
            {
                MessageBox.Show("La partie est terminée !");
                if (blancrest == 0)
                    MessageBox.Show("Partie terminée ! Les noirs gagnent la partie !");
                else
                    MessageBox.Show("Partie terminée ! Les blancs gagnent la partie !");
                blancrest = -1;
                noirrest = -1;
            }
        }
        #endregion

#region Possibilités de déplacements des pions
        private bool deplacementBleuPossible(int cur_i_deux, int cur_j_deux)
        {
            if (!tour_blanc)
            {

                if (cur_i_deux < 10 && cur_i_deux <= cur_i + 1 && cur_i_deux >= cur_i &&
                   (cur_j_deux < 10 && cur_j_deux >= 0 && (cur_j_deux == cur_j + 1 || cur_j_deux == cur_j - 1)) &&
                   jeuDeDames[cur_j_deux, cur_i_deux].backColor != Color.White &&
                   jeuDeDames[cur_j, cur_i].pieceColor() == Color.Blue &&
                   jeuDeDames[cur_j_deux, cur_i_deux].estVide())
                    return true;
                // si le pion est normal et qu'il mange un autre
                else if (cur_i_deux < 10 && cur_j_deux < 10 && cur_i_deux >= 0 && cur_j_deux >= 0 &&
                        (cur_i_deux == cur_i + 2 || cur_i_deux == cur_i - 2) && (cur_j_deux == cur_j - 2 || cur_j_deux == cur_j + 2) &&
                        jeuDeDames[cur_j_deux, cur_i_deux].backColor != Color.White &&
                        jeuDeDames[cur_j, cur_i].pieceColor() == Color.Blue &&
                        jeuDeDames[cur_j_deux, cur_i_deux].estVide() &&
                        jeuDeDames[cur_j_deux - ((cur_j_deux - cur_j) / 2), cur_i_deux - ((cur_i_deux - cur_i) / 2)].pieceColor() == Color.White)
                {
                    jeuDeDames[cur_j_deux - ((cur_j_deux - cur_j) / 2), cur_i_deux - ((cur_i_deux - cur_i) / 2)].estMange();
                    blancrest--;
                    nbBlanc.Text = blancrest.ToString();
                    return true;
                }
                else if (cur_i_deux < 10 && cur_j_deux < 10 && cur_i_deux >= 0 && cur_j_deux >= 0
                        && jeuDeDames[cur_j_deux, cur_i_deux].backColor != Color.White &&
                        jeuDeDames[cur_j, cur_i].pieceColor() == Color.Blue &&
                        estdiaguonale(cur_i, cur_j, cur_i_deux, cur_j_deux) &&
                        piondansladiago(cur_i, cur_j, cur_i_deux, cur_j_deux, Color.White) && jeuDeDames[cur_j, cur_i].pieceDame == true)
                {
                    return true;
                }

                else
                    return false;
            }
            else
                return false;
        }

        private bool deplacementBlancPossible(int cur_i_deux, int cur_j_deux)
        {
            if (tour_blanc)
            {
                if (cur_i_deux < 10 && cur_i_deux >= cur_i - 1 && cur_i_deux < cur_i &&
                  (cur_j_deux < 10 && cur_j_deux >= 0 && (cur_j_deux == cur_j + 1 || cur_j_deux == cur_j - 1)) &&
                  jeuDeDames[cur_j_deux, cur_i_deux].backColor != Color.White &&
                  jeuDeDames[cur_j, cur_i].pieceColor() == Color.White &&
                  jeuDeDames[cur_j_deux, cur_i_deux].estVide())
                    return true;
                // si le pion est normal et qu'il
                else if (cur_i_deux < 10 && cur_j_deux < 10 && cur_i_deux >= 0 && cur_j_deux >= 0 &&
                        (cur_i_deux == cur_i + 2 || cur_i_deux == cur_i - 2) && (cur_j_deux == cur_j - 2 || cur_j_deux == cur_j + 2) &&
                        jeuDeDames[cur_j_deux, cur_i_deux].backColor != Color.White &&
                        jeuDeDames[cur_j, cur_i].pieceColor() == Color.White &&
                        jeuDeDames[cur_j_deux, cur_i_deux].estVide() &&
                        jeuDeDames[cur_j_deux - ((cur_j_deux - cur_j) / 2), cur_i_deux - ((cur_i_deux - cur_i) / 2)].pieceColor() == Color.Blue)
                {
                    jeuDeDames[cur_j_deux - ((cur_j_deux - cur_j) / 2), cur_i_deux - ((cur_i_deux - cur_i) / 2)].estMange();
                    noirrest--;
                    nbNoir.Text = noirrest.ToString();
                    return true;
                }
                // si le pion est une dame et qu'il se déplace normalement ou pour manger
                else if (cur_i_deux < 10 && cur_j_deux < 10 && cur_i_deux >= 0 && cur_j_deux >= 0
                        && jeuDeDames[cur_j_deux, cur_i_deux].backColor != Color.Blue &&
                        jeuDeDames[cur_j, cur_i].pieceColor() == Color.White &&
                        estdiaguonale(cur_i, cur_j, cur_i_deux, cur_j_deux) &&
                        piondansladiago(cur_i, cur_j, cur_i_deux, cur_j_deux, Color.Blue) && jeuDeDames[cur_j, cur_i].pieceDame == true)
                {
                    return true;
                }
                else
                    return false;
            }
            else
                return false;
        }
        #endregion


        public bool veriftour_blanc(Color c)
        {
            if ((c == Color.White && tour_blanc == false)
                || (c == Color.Blue && tour_blanc == true))
            {
                if (tour_blanc) MessageBox.Show("c'est le tour des BLANCS !");
                else MessageBox.Show("c'est le tour des NOIRS !");
                return false;
            }
            else return true;
        }

#region vérification des diaguonales
        public bool estdiaguonale(int i1, int j1, int i2, int j2)
        {
            int a, b;
            if (i1 > i2) a = i1 - i2;
            else a = i2 - i1;
            if (j1 > j2) b = j1 - j2;
            else b = j2 - j1;

            if (a == b) return true;
            else return false;
        }

        public bool piondansladiago(int i1, int j1, int i2, int j2, Color couleurmange)
        {
            // si on les deux clics ne sont pas confondu
            if (i1 == i2 || j1 == j2)
                return false;
            // on récupére sens pour se déplace en ligne et colonne
            int a, b;
            if (i1 > i2) a = -1;
            else a = 1;
            if (j1 > j2) b = -1;
            else b = 1;

      // une exception pour un deplacement de une case
            if ( i2+(-1*a)*i1 == 1 || j2+(-1*b)*j1 == 1 )
                return jeuDeDames[j2, i2].estVide();

            // on regarde si la diaguonale est posséde aucun pion a part l'avant dernier
            int j = j1 + b;
            int i = i1 + a;
            while (j != j2 + b && i != i2 + a)
            {
                if (!jeuDeDames[j, i].estVide() && j != j2 + (-1 * b) && i != i2 + (-1 * a))
                    return false;
                j += b;
                i += a;
            }
            // si l'avant derniere case non verifié est vide
            if (jeuDeDames[j2 + (-1 * b), i2 + (-1 * a)].estVide())
            {
                return true;
            }
            // si l'avant derniere case est de la coleur opposé
            else if (!jeuDeDames[j2 + (-1 * b), i2 + (-1 * a)].estVide() && jeuDeDames[j2 + (-1 * b), i2 + (-1 * a)].pieceColor() == couleurmange)
            {
                jeuDeDames[j2 + (-1 * b), i2 + (-1 * a)].estMange();
                if (couleurmange == Color.White)
                {
                    blancrest--;
                    nbBlanc.Text = blancrest.ToString();
                }
                else
                {
                    noirrest--;
                    nbNoir.Text = noirrest.ToString();
                }
                return true;
            }
            else
                return false;
        }


        #endregion


        #region Enregistrer Nouveau Ouvrir
        private void enregistrerToolStripButton_Click(object sender, EventArgs e)
        {
            SaveFileDialog save = new SaveFileDialog();
            save.Filter = "*fichier sauvegarde(*.sav)|*.sav";
            if (save.ShowDialog() == DialogResult.OK)
            {
                Stream stream = File.Open(save.FileName, FileMode.Create);
                BinaryFormatter bifo = new BinaryFormatter();
                bifo.Serialize(stream, jeuDeDames);
                bifo.Serialize(stream, tour_blanc);
                if (!stream.CanWrite) MessageBox.Show("marche PO !!!! O___o");
                stream.Close();
            }
        }

        private void nouveauToolStripButton_Click(object sender, EventArgs e)
        {
            tour_blanc = true;
            blancrest = noirrest = 20;
            jeuDeDames = new CaseDamier[10, 10];
            for (int i = 0; i < 10; i++)
                for (int j = 0; j < 10; j++)
                {
                    if (i % 2 == 0)
                    {
                        if (j % 2 != 0)
                        {
                            if (i < 4)
                                jeuDeDames[j, i] = new CaseDamier(Color.CadetBlue, Color.Blue);
                            else if (i > 5)
                                jeuDeDames[j, i] = new CaseDamier(Color.CadetBlue, Color.White);
                            else
                                jeuDeDames[j, i] = new CaseDamier(Color.CadetBlue);
                        }
                        else
                            jeuDeDames[j, i] = new CaseDamier(Color.White);
                    }
                    else
                        if (j % 2 != 0)
                            jeuDeDames[j, i] = new CaseDamier(Color.White);
                        else
                            if (i < 4)
                                jeuDeDames[j, i] = new CaseDamier(Color.CadetBlue, Color.Blue);
                            else if (i > 5)
                                jeuDeDames[j, i] = new CaseDamier(Color.CadetBlue, Color.White);
                            else
                                jeuDeDames[j, i] = new CaseDamier(Color.CadetBlue);

                    jeuDeDames[j, i].Top = j * jeuDeDames[j, i].Width;
                    jeuDeDames[j, i].Left = (i * jeuDeDames[j, i].Height) + toolStrip1.Height;
                }
            nbBlanc.Text = blancrest.ToString();
            nbNoir.Text = noirrest.ToString();
            tour_blanc = true;
            aquiletour.Text = "BLANCS";
            Refresh();
        }

        private void ouvrirToolStripButton_Click(object sender, EventArgs e)
        {
            OpenFileDialog open = new OpenFileDialog();
            open.Filter = "*fichier sauvegarde (*.sav)|*.sav";
            if (open.ShowDialog() == DialogResult.OK)
            {
                Stream stream = File.Open(open.FileName, FileMode.Open);
                BinaryFormatter bifo = new BinaryFormatter();
                jeuDeDames = (CaseDamier[,])bifo.Deserialize(stream);
                tour_blanc = (bool)bifo.Deserialize(stream);

                stream.Close();
                Refresh();
            }
        }
#endregion

    }
}
