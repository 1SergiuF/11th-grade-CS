namespace JocEducativ
{
    partial class GhicesteForm
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(GhicesteForm));
            this.pbFloare = new System.Windows.Forms.PictureBox();
            this.lblPunctaj = new System.Windows.Forms.Label();
            this.panelAlfabet = new System.Windows.Forms.Panel();
            this.panelWord = new System.Windows.Forms.Panel();
            ((System.ComponentModel.ISupportInitialize)(this.pbFloare)).BeginInit();
            this.SuspendLayout();
            // 
            // pbFloare
            // 
            this.pbFloare.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.pbFloare.Image = ((System.Drawing.Image)(resources.GetObject("pbFloare.Image")));
            this.pbFloare.Location = new System.Drawing.Point(564, 12);
            this.pbFloare.Name = "pbFloare";
            this.pbFloare.Size = new System.Drawing.Size(148, 368);
            this.pbFloare.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pbFloare.TabIndex = 0;
            this.pbFloare.TabStop = false;
            // 
            // lblPunctaj
            // 
            this.lblPunctaj.AutoSize = true;
            this.lblPunctaj.Location = new System.Drawing.Point(12, 39);
            this.lblPunctaj.Name = "lblPunctaj";
            this.lblPunctaj.Size = new System.Drawing.Size(67, 13);
            this.lblPunctaj.TabIndex = 1;
            this.lblPunctaj.Text = "Punctaj: 100";
            // 
            // panelAlfabet
            // 
            this.panelAlfabet.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.panelAlfabet.Location = new System.Drawing.Point(15, 366);
            this.panelAlfabet.Name = "panelAlfabet";
            this.panelAlfabet.Size = new System.Drawing.Size(409, 127);
            this.panelAlfabet.TabIndex = 2;
            // 
            // panelWord
            // 
            this.panelWord.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.panelWord.Location = new System.Drawing.Point(15, 307);
            this.panelWord.Name = "panelWord";
            this.panelWord.Size = new System.Drawing.Size(409, 22);
            this.panelWord.TabIndex = 3;
            // 
            // GhicesteForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(769, 528);
            this.Controls.Add(this.panelWord);
            this.Controls.Add(this.panelAlfabet);
            this.Controls.Add(this.lblPunctaj);
            this.Controls.Add(this.pbFloare);
            this.Name = "GhicesteForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "GhicesteCuvant";
            ((System.ComponentModel.ISupportInitialize)(this.pbFloare)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.PictureBox pbFloare;
        private System.Windows.Forms.Label lblPunctaj;
        private System.Windows.Forms.Panel panelAlfabet;
        private System.Windows.Forms.Panel panelWord;
    }
}