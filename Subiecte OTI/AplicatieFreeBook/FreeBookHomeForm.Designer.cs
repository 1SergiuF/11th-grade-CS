namespace AplicatieFreeBook
{
    partial class FreeBookHomeForm
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(FreeBookHomeForm));
            this.pbBooks = new System.Windows.Forms.PictureBox();
            this.gbDescriere = new System.Windows.Forms.GroupBox();
            this.btnLogare = new System.Windows.Forms.Button();
            this.btnInregistrare = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.pbBooks)).BeginInit();
            this.SuspendLayout();
            // 
            // pbBooks
            // 
            this.pbBooks.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("pbBooks.BackgroundImage")));
            this.pbBooks.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.pbBooks.Location = new System.Drawing.Point(1, 2);
            this.pbBooks.Name = "pbBooks";
            this.pbBooks.Size = new System.Drawing.Size(817, 320);
            this.pbBooks.TabIndex = 0;
            this.pbBooks.TabStop = false;
            // 
            // gbDescriere
            // 
            this.gbDescriere.Font = new System.Drawing.Font("Microsoft Sans Serif", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.gbDescriere.Location = new System.Drawing.Point(12, 328);
            this.gbDescriere.Name = "gbDescriere";
            this.gbDescriere.Size = new System.Drawing.Size(794, 99);
            this.gbDescriere.TabIndex = 1;
            this.gbDescriere.TabStop = false;
            this.gbDescriere.Text = resources.GetString("gbDescriere.Text");
            // 
            // btnLogare
            // 
            this.btnLogare.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnLogare.ForeColor = System.Drawing.Color.Red;
            this.btnLogare.Location = new System.Drawing.Point(94, 457);
            this.btnLogare.Name = "btnLogare";
            this.btnLogare.Size = new System.Drawing.Size(218, 63);
            this.btnLogare.TabIndex = 0;
            this.btnLogare.Text = "Logare";
            this.btnLogare.UseVisualStyleBackColor = true;
            this.btnLogare.Click += new System.EventHandler(this.btnLogare_Click);
            // 
            // btnInregistrare
            // 
            this.btnInregistrare.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnInregistrare.ForeColor = System.Drawing.Color.Red;
            this.btnInregistrare.Location = new System.Drawing.Point(500, 457);
            this.btnInregistrare.Name = "btnInregistrare";
            this.btnInregistrare.Size = new System.Drawing.Size(209, 63);
            this.btnInregistrare.TabIndex = 2;
            this.btnInregistrare.Text = "Inregistrare";
            this.btnInregistrare.UseVisualStyleBackColor = true;
            this.btnInregistrare.Click += new System.EventHandler(this.btnInregistrare_Click);
            // 
            // FreeBookHomeForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(818, 532);
            this.Controls.Add(this.btnInregistrare);
            this.Controls.Add(this.btnLogare);
            this.Controls.Add(this.gbDescriere);
            this.Controls.Add(this.pbBooks);
            this.Name = "FreeBookHomeForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "FreeBook Home";
            ((System.ComponentModel.ISupportInitialize)(this.pbBooks)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.PictureBox pbBooks;
        private System.Windows.Forms.GroupBox gbDescriere;
        private System.Windows.Forms.Button btnLogare;
        private System.Windows.Forms.Button btnInregistrare;
    }
}

