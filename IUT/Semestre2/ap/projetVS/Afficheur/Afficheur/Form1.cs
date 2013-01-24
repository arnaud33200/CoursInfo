using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO;

namespace Afficheur
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void nouveauToolStripButton_Click(object sender, EventArgs e)
        {
            OpenFileDialog opfd = new OpenFileDialog();
            opfd.Filter = "Fichiers images JPEG|*.jpg";
            opfd.Title = "choisir le fichier";
            opfd.InitialDirectory = @"Z:\Desktop";

            if (opfd.ShowDialog() == DialogResult.OK)
            {
                boiteimage.Image = Image.FromFile(opfd.FileName);
            }
        }


        private void ouvrirToolStripButton_Click(object sender, EventArgs e)
        {
            FolderBrowserDialog fld = new FolderBrowserDialog();
            fld.Description = "Choisir le répertoire d'images";
            fld.RootFolder = Environment.SpecialFolder.Desktop;

            if (fld.ShowDialog() == DialogResult.OK)
            {
                repertoire.Nodes.Clear();
                TreeNode root = new TreeNode(fld.SelectedPath);
                root.Tag = fld.SelectedPath;
                repertoire.Nodes.Add(root);

                foreach ( string f in Directory.GetDirectories(fld.SelectedPath))
                {
                    string s = f.Substring(fld.SelectedPath.Length + 1);
                    TreeNode tn = new TreeNode(s);
                    tn.Tag = f;
                    root.Nodes.Add(tn);
                }
              /* foreach ( string f in Directory.GetFiles(fld.SelectedPath))
                {
                    if (f.Contains("jpg") || f.Contains("JPG"))
                    {
                        ListView lv = new ListView();
                    }
                }*/
            }
        }

        private void repertoire_AfterSelect(object sender, TreeViewEventArgs e)
        {
            string path = repertoire.SelectedNode.Tag.ToString();
            string[] files = Directory.GetFiles(path);
            listefichier.Clear();
            listefichier.Tag = path;
            foreach (string s in files)
            {
                if (s.Contains("jpg") || s.Contains("JPG"))
                {
                    string f = s.Substring(path.Length + 1);
                    listefichier.Items.Add(f);
                }
            }

            foreach ( string f in Directory.GetDirectories(path ) )
            {
                string s = f.Substring(path.Length + 1);
                TreeNode tn = new TreeNode(s);
                tn.Tag = f;
                repertoire.SelectedNode.Nodes.Add(tn);
            }

        }

        private void listefichier_ItemSelectionChanged(object sender, ListViewItemSelectionChangedEventArgs e)
        {
            string[] files = Directory.GetFiles(listefichier.Tag.ToString());
            foreach (string f in files)
            {
                //sdfghsdadasdqsdsdfsdf
                   boiteimage.Image = Image.FromFile(listefichier.SelectedItems.ToString());
            }

        }

    }
}
