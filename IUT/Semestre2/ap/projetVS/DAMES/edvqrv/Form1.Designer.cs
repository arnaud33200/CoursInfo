namespace edvqrv
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
            this.nouveauToolStripButton = new System.Windows.Forms.ToolStripButton();
            this.ouvrirToolStripButton = new System.Windows.Forms.ToolStripButton();
            this.enregistrerToolStripButton = new System.Windows.Forms.ToolStripButton();
            this.toolStripSeparator = new System.Windows.Forms.ToolStripSeparator();
            this.nbBlanc = new System.Windows.Forms.ToolStripLabel();
            this.txtpionblanc = new System.Windows.Forms.ToolStripLabel();
            this.nbNoir = new System.Windows.Forms.ToolStripLabel();
            this.pionsnoirs = new System.Windows.Forms.ToolStripLabel();
            this.toolStripSeparator2 = new System.Windows.Forms.ToolStripSeparator();
            this.txtpionnoiretautour = new System.Windows.Forms.ToolStripLabel();
            this.aquiletour = new System.Windows.Forms.ToolStripLabel();
            this.txtdejouer = new System.Windows.Forms.ToolStripLabel();
            this.toolStripSeparator1 = new System.Windows.Forms.ToolStripSeparator();
            this.toolStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // toolStrip1
            // 
            this.toolStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.nouveauToolStripButton,
            this.ouvrirToolStripButton,
            this.enregistrerToolStripButton,
            this.toolStripSeparator,
            this.nbBlanc,
            this.txtpionblanc,
            this.nbNoir,
            this.pionsnoirs,
            this.toolStripSeparator2,
            this.txtpionnoiretautour,
            this.aquiletour,
            this.txtdejouer,
            this.toolStripSeparator1});
            this.toolStrip1.Location = new System.Drawing.Point(0, 0);
            this.toolStrip1.Name = "toolStrip1";
            this.toolStrip1.Size = new System.Drawing.Size(534, 25);
            this.toolStrip1.TabIndex = 2;
            this.toolStrip1.Text = "toolStrip1";
            // 
            // nouveauToolStripButton
            // 
            this.nouveauToolStripButton.AccessibleDescription = "nouvelle partie";
            this.nouveauToolStripButton.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.nouveauToolStripButton.Image = ((System.Drawing.Image)(resources.GetObject("nouveauToolStripButton.Image")));
            this.nouveauToolStripButton.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.nouveauToolStripButton.Name = "nouveauToolStripButton";
            this.nouveauToolStripButton.Size = new System.Drawing.Size(23, 22);
            this.nouveauToolStripButton.Text = "&Nouveau";
            this.nouveauToolStripButton.Click += new System.EventHandler(this.nouveauToolStripButton_Click);
            // 
            // ouvrirToolStripButton
            // 
            this.ouvrirToolStripButton.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.ouvrirToolStripButton.Image = ((System.Drawing.Image)(resources.GetObject("ouvrirToolStripButton.Image")));
            this.ouvrirToolStripButton.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.ouvrirToolStripButton.Name = "ouvrirToolStripButton";
            this.ouvrirToolStripButton.Size = new System.Drawing.Size(23, 22);
            this.ouvrirToolStripButton.Text = "&Ouvrir";
            this.ouvrirToolStripButton.Click += new System.EventHandler(this.ouvrirToolStripButton_Click);
            // 
            // enregistrerToolStripButton
            // 
            this.enregistrerToolStripButton.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.enregistrerToolStripButton.Image = ((System.Drawing.Image)(resources.GetObject("enregistrerToolStripButton.Image")));
            this.enregistrerToolStripButton.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.enregistrerToolStripButton.Name = "enregistrerToolStripButton";
            this.enregistrerToolStripButton.Size = new System.Drawing.Size(23, 22);
            this.enregistrerToolStripButton.Text = "&Enregistrer";
            this.enregistrerToolStripButton.Click += new System.EventHandler(this.enregistrerToolStripButton_Click);
            // 
            // toolStripSeparator
            // 
            this.toolStripSeparator.Margin = new System.Windows.Forms.Padding(6, 0, 6, 0);
            this.toolStripSeparator.Name = "toolStripSeparator";
            this.toolStripSeparator.Size = new System.Drawing.Size(6, 25);
            // 
            // nbBlanc
            // 
            this.nbBlanc.Name = "nbBlanc";
            this.nbBlanc.Size = new System.Drawing.Size(13, 22);
            this.nbBlanc.Text = "0";
            // 
            // txtpionblanc
            // 
            this.txtpionblanc.Name = "txtpionblanc";
            this.txtpionblanc.Size = new System.Drawing.Size(76, 22);
            this.txtpionblanc.Text = "Pions Blancs ";
            // 
            // nbNoir
            // 
            this.nbNoir.Name = "nbNoir";
            this.nbNoir.Size = new System.Drawing.Size(13, 22);
            this.nbNoir.Text = "0";
            // 
            // pionsnoirs
            // 
            this.pionsnoirs.Name = "pionsnoirs";
            this.pionsnoirs.Size = new System.Drawing.Size(67, 22);
            this.pionsnoirs.Text = "Pions Noirs";
            // 
            // toolStripSeparator2
            // 
            this.toolStripSeparator2.BackColor = System.Drawing.SystemColors.ControlText;
            this.toolStripSeparator2.ForeColor = System.Drawing.SystemColors.ActiveCaption;
            this.toolStripSeparator2.Margin = new System.Windows.Forms.Padding(6, 0, 6, 0);
            this.toolStripSeparator2.Name = "toolStripSeparator2";
            this.toolStripSeparator2.Size = new System.Drawing.Size(6, 25);
            // 
            // txtpionnoiretautour
            // 
            this.txtpionnoiretautour.Name = "txtpionnoiretautour";
            this.txtpionnoiretautour.Size = new System.Drawing.Size(71, 22);
            this.txtpionnoiretautour.Text = "Au Tour des";
            // 
            // aquiletour
            // 
            this.aquiletour.Name = "aquiletour";
            this.aquiletour.Size = new System.Drawing.Size(72, 22);
            this.aquiletour.Text = "blancs/noirs";
            // 
            // txtdejouer
            // 
            this.txtdejouer.Name = "txtdejouer";
            this.txtdejouer.Size = new System.Drawing.Size(50, 22);
            this.txtdejouer.Text = "de jouer";
            // 
            // toolStripSeparator1
            // 
            this.toolStripSeparator1.Name = "toolStripSeparator1";
            this.toolStripSeparator1.Size = new System.Drawing.Size(6, 25);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(534, 558);
            this.Controls.Add(this.toolStrip1);
            this.DoubleBuffered = true;
            this.MaximumSize = new System.Drawing.Size(562, 608);
            this.MinimumSize = new System.Drawing.Size(562, 608);
            this.Name = "Form1";
            this.Text = "Form1";
            this.MouseUp += new System.Windows.Forms.MouseEventHandler(this.Form1_MouseUp);
            this.Paint += new System.Windows.Forms.PaintEventHandler(this.Form1_Paint);
            this.MouseDown += new System.Windows.Forms.MouseEventHandler(this.Form1_MouseDown);
            this.toolStrip1.ResumeLayout(false);
            this.toolStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ToolStrip toolStrip1;
        private System.Windows.Forms.ToolStripButton nouveauToolStripButton;
        private System.Windows.Forms.ToolStripButton ouvrirToolStripButton;
        private System.Windows.Forms.ToolStripButton enregistrerToolStripButton;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator;
        private System.Windows.Forms.ToolStripLabel nbBlanc;
        private System.Windows.Forms.ToolStripLabel txtpionblanc;
        private System.Windows.Forms.ToolStripLabel nbNoir;
        private System.Windows.Forms.ToolStripLabel txtpionnoiretautour;
        private System.Windows.Forms.ToolStripLabel aquiletour;
        private System.Windows.Forms.ToolStripLabel txtdejouer;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator1;
        private System.Windows.Forms.ToolStripLabel pionsnoirs;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator2;
    }
}

