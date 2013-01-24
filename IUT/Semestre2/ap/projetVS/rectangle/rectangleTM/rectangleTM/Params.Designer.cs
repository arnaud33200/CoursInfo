namespace rectangleTM
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
            this.epaissetasoeur = new System.Windows.Forms.NumericUpDown();
            this.texototo = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.cololo = new System.Windows.Forms.Label();
            this.button1 = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.taillo = new System.Windows.Forms.NumericUpDown();
            this.colorDialog1 = new System.Windows.Forms.ColorDialog();
            ((System.ComponentModel.ISupportInitialize)(this.epaissetasoeur)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.taillo)).BeginInit();
            this.SuspendLayout();
            // 
            // epaissetasoeur
            // 
            this.epaissetasoeur.Location = new System.Drawing.Point(84, 44);
            this.epaissetasoeur.Name = "epaissetasoeur";
            this.epaissetasoeur.Size = new System.Drawing.Size(100, 20);
            this.epaissetasoeur.TabIndex = 0;
            this.epaissetasoeur.ValueChanged += new System.EventHandler(this.taille_rectangle_ValueChanged);
            // 
            // texototo
            // 
            this.texototo.Location = new System.Drawing.Point(61, 6);
            this.texototo.Name = "texototo";
            this.texototo.Size = new System.Drawing.Size(123, 20);
            this.texototo.TabIndex = 4;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(21, 9);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(34, 13);
            this.label1.TabIndex = 5;
            this.label1.Text = "Texte";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(18, 46);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(53, 13);
            this.label2.TabIndex = 6;
            this.label2.Text = "Epaisseur";
            // 
            // cololo
            // 
            this.cololo.AutoSize = true;
            this.cololo.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(192)))), ((int)(((byte)(0)))));
            this.cololo.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.cololo.Location = new System.Drawing.Point(84, 147);
            this.cololo.Name = "cololo";
            this.cololo.Size = new System.Drawing.Size(21, 15);
            this.cololo.TabIndex = 8;
            this.cololo.Text = "    ";
            this.cololo.MouseDown += new System.Windows.Forms.MouseEventHandler(this.cololo_MouseDown);
            // 
            // button1
            // 
            this.button1.DialogResult = System.Windows.Forms.DialogResult.OK;
            this.button1.Location = new System.Drawing.Point(12, 202);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(75, 23);
            this.button1.TabIndex = 9;
            this.button1.Text = "Ok";
            this.button1.UseVisualStyleBackColor = true;
            // 
            // button2
            // 
            this.button2.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.button2.Location = new System.Drawing.Point(128, 202);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(75, 23);
            this.button2.TabIndex = 10;
            this.button2.Text = "Annuler";
            this.button2.UseVisualStyleBackColor = true;
            // 
            // taillo
            // 
            this.taillo.Location = new System.Drawing.Point(84, 98);
            this.taillo.Name = "taillo";
            this.taillo.Size = new System.Drawing.Size(100, 20);
            this.taillo.TabIndex = 11;
            // 
            // Params
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(215, 237);
            this.Controls.Add(this.taillo);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.cololo);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.texototo);
            this.Controls.Add(this.epaissetasoeur);
            this.Name = "Params";
            this.Text = "Params";
            ((System.ComponentModel.ISupportInitialize)(this.epaissetasoeur)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.taillo)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.NumericUpDown epaissetasoeur;
        private System.Windows.Forms.TextBox texototo;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label cololo;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.NumericUpDown taillo;
        private System.Windows.Forms.ColorDialog colorDialog1;
    }
}