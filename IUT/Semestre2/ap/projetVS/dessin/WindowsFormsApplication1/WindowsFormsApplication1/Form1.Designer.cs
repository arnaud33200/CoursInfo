namespace WindowsFormsApplication1
{
    partial class Form1
    {
        /// <summary>
        /// Variable nécessaire au concepteur.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Nettoyage des ressources utilisées.
        /// </summary>
        /// <param name="disposing">true si les ressources managées doivent être supprimées ; sinon, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Code généré par le Concepteur Windows Form

        /// <summary>
        /// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
        /// le contenu de cette méthode avec l'éditeur de code.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.toolStrip1 = new System.Windows.Forms.ToolStrip();
            this.Epaisseur = new System.Windows.Forms.ToolStripDropDownButton();
            this.epaisseur1 = new System.Windows.Forms.ToolStripMenuItem();
            this.epaisseur10 = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // toolStrip1
            // 
            this.toolStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.Epaisseur});
            this.toolStrip1.Location = new System.Drawing.Point(0, 0);
            this.toolStrip1.Name = "toolStrip1";
            this.toolStrip1.Size = new System.Drawing.Size(774, 25);
            this.toolStrip1.TabIndex = 0;
            this.toolStrip1.Text = "toolStrip1";
            // 
            // Epaisseur
            // 
            this.Epaisseur.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.Epaisseur.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.epaisseur1,
            this.epaisseur10});
            this.Epaisseur.Image = ((System.Drawing.Image)(resources.GetObject("Epaisseur.Image")));
            this.Epaisseur.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.Epaisseur.Name = "Epaisseur";
            this.Epaisseur.Size = new System.Drawing.Size(29, 22);
            this.Epaisseur.Text = "Epaisseur du trait";
            // 
            // epaisseur1
            // 
            this.epaisseur1.Name = "epaisseur1";
            this.epaisseur1.Size = new System.Drawing.Size(152, 22);
            this.epaisseur1.Text = "1";
            this.epaisseur1.Click += new System.EventHandler(this.epaisseur1_Click);
            // 
            // epaisseur10
            // 
            this.epaisseur10.Name = "epaisseur10";
            this.epaisseur10.Size = new System.Drawing.Size(152, 22);
            this.epaisseur10.Text = "10";
            this.epaisseur10.Click += new System.EventHandler(this.epaisseur10_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackgroundImage = global::WindowsFormsApplication1.Properties.Resources.Collines;
            this.ClientSize = new System.Drawing.Size(774, 586);
            this.Controls.Add(this.toolStrip1);
            this.Cursor = System.Windows.Forms.Cursors.Cross;
            this.DoubleBuffered = true;
            this.Name = "Form1";
            this.Text = "dessin";
            this.TransparencyKey = System.Drawing.Color.Transparent;
            this.MouseUp += new System.Windows.Forms.MouseEventHandler(this.Form1_MouseUp);
            this.Paint += new System.Windows.Forms.PaintEventHandler(this.Form1_Paint);
            this.MouseDown += new System.Windows.Forms.MouseEventHandler(this.Form1_MouseDown);
            this.MouseMove += new System.Windows.Forms.MouseEventHandler(this.Form1_MouseMove);
            this.toolStrip1.ResumeLayout(false);
            this.toolStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ToolStrip toolStrip1;
        private System.Windows.Forms.ToolStripDropDownButton Epaisseur;
        private System.Windows.Forms.ToolStripMenuItem epaisseur1;
        private System.Windows.Forms.ToolStripMenuItem epaisseur10;
    }
}

