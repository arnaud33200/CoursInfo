using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace draganddrop
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            for (int i=0; i<5; i++ )
                listBox1.Items.Add(i.ToString());
            listBox1.Items.Add(9);
            listBox1.Items.Add("F");

        }

        private void listBox1_MouseDown(object sender, MouseEventArgs e)
        {
            if (listBox1.Items.Count == 0) return;
            int index = listBox1.IndexFromPoint(e.X, e.Y);
            string s = listBox1.Items[index].ToString();
            DragDropEffects dde1 = DoDragDrop(s, DragDropEffects.Move);
            if (dde1 == DragDropEffects.All)
            {
                listBox1.Items.RemoveAt(index);
            }
        }

        private void listBox2_DragOver(object sender, DragEventArgs e)
        {
            if (e.Data.GetDataPresent(DataFormats.StringFormat))
                e.Effect = DragDropEffects.All;
            else
                e.Effect = DragDropEffects.None;
        }

        private void listBox2_DragDrop(object sender, DragEventArgs e)
        {
            if (e.Data.GetDataPresent(DataFormats.StringFormat))
            {
                string str = (string)e.Data.GetData(DataFormats.StringFormat);
                listBox2.Items.Add(str);
            }
        }

        private void listBox2_MouseDown(object sender, MouseEventArgs e)
        {
            if (listBox2.Items.Count == 0) return;
            int index = listBox2.IndexFromPoint(e.X, e.Y);
            string s = listBox2.Items[index].ToString();
            DragDropEffects dde2 = DoDragDrop(s, DragDropEffects.Move);
            if (dde2 == DragDropEffects.All)
            {
                listBox2.Items.RemoveAt(index);
            }
        }

        private void listBox1_DragOver(object sender, DragEventArgs e)
        {
            if (e.Data.GetDataPresent(DataFormats.StringFormat))
                e.Effect = DragDropEffects.All;
            else
                e.Effect = DragDropEffects.None;
        }

        private void listBox1_DragDrop(object sender, DragEventArgs e)
        {
            if (e.Data.GetDataPresent(DataFormats.StringFormat))
            {
                string str = (string)e.Data.GetData(DataFormats.StringFormat);
                listBox1.Items.Add(str);
            }
        }

        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Control && e.KeyCode == Keys.Z)
            {
                if (listBox2.Items.Count != 0)
                {
                    int index = listBox2.In;
                    listBox2.Items.RemoveAt(listBox2.Items);
                }
            }
        }




    }
}
