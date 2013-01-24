namespace Desins_objets
{
    partial class Params
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.button1 = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.ParamsTexte = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.ParamsEpaisseur = new System.Windows.Forms.NumericUpDown();
            this.colorDialog1 = new System.Windows.Forms.ColorDialog();
            this.couleur = new System.Windows.Forms.Label();
            this.fontDialog1 = new System.Windows.Forms.FontDialog();
            this.FontButton = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.ParamsEpaisseur)).BeginInit();
            this.SuspendLayout();
            // 
            // button1
            // 
            this.button1.DialogResult = System.Windows.Forms.DialogResult.OK;
            this.button1.Location = new System.Drawing.Point(210, 33);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(66, 23);
            this.button1.TabIndex = 0;
            this.button1.Text = "OK";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.ParamsOK_Click);
            // 
            // button2
            // 
            this.button2.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.button2.Location = new System.Drawing.Point(210, 74);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(65, 23);
            this.button2.TabIndex = 1;
            this.button2.Text = "Annuler";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.ParamsAnnuler_Click);
            // 
            // ParamsTexte
            // 
            this.ParamsTexte.Location = new System.Drawing.Point(85, 5);
            this.ParamsTexte.Name = "ParamsTexte";
            this.ParamsTexte.Size = new System.Drawing.Size(72, 20);
            this.ParamsTexte.TabIndex = 2;
            this.ParamsTexte.TextChanged += new System.EventHandler(this.textBox1_TextChanged);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(16, 15);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(34, 13);
            this.label1.TabIndex = 3;
            this.label1.Text = "Texte";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(16, 62);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(53, 13);
            this.label2.TabIndex = 4;
            this.label2.Text = "Epaisseur";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(16, 100);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(43, 13);
            this.label3.TabIndex = 5;
            this.label3.Text = "Couleur";
            // 
            // ParamsEpaisseur
            // 
            this.ParamsEpaisseur.Location = new System.Drawing.Point(86, 62);
            this.ParamsEpaisseur.Name = "ParamsEpaisseur";
            this.ParamsEpaisseur.Size = new System.Drawing.Size(71, 20);
            this.ParamsEpaisseur.TabIndex = 6;
            // 
            // couleur
            // 
            this.couleur.AutoSize = true;
            this.couleur.BackColor = System.Drawing.Color.Red;
            this.couleur.Location = new System.Drawing.Point(83, 100);
            this.couleur.Name = "couleur";
            this.couleur.Size = new System.Drawing.Size(25, 13);
            this.couleur.TabIndex = 7;
            this.couleur.Text = "      ";
            this.couleur.Click += new System.EventHandler(this.ColorClick);
            // 
            // FontButton
            // 
            this.FontButton.Location = new System.Drawing.Point(85, 31);
            this.FontButton.Name = "FontButton";
            this.FontButton.Size = new System.Drawing.Size(72, 25);
            this.FontButton.TabIndex = 8;
            this.FontButton.Text = "Police";
            this.FontButton.UseMnemonic = false;
            this.FontButton.UseVisualStyleBackColor = true;
            this.FontButton.Click += new System.EventHandler(this.FontClick);
            // 
            // Params
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(297, 122);
            this.Controls.Add(this.FontButton);
            this.Controls.Add(this.couleur);
            this.Controls.Add(this.ParamsEpaisseur);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.ParamsTexte);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.button1);
            this.Name = "Params";
            this.Text = "Params";
            ((System.ComponentModel.ISupportInitialize)(this.ParamsEpaisseur)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.TextBox ParamsTexte;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.NumericUpDown ParamsEpaisseur;
        private System.Windows.Forms.ColorDialog colorDialog1;
        private System.Windows.Forms.Label couleur;
        private System.Windows.Forms.FontDialog fontDialog1;
        private System.Windows.Forms.Button FontButton;
        
    }
}