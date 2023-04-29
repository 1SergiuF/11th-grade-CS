namespace AplicatieFreeBook
{
    partial class AfiseazaCarteForm
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
            this.webCarti = new System.Windows.Forms.WebBrowser();
            this.SuspendLayout();
            // 
            // webCarti
            // 
            this.webCarti.Dock = System.Windows.Forms.DockStyle.Fill;
            this.webCarti.Location = new System.Drawing.Point(0, 0);
            this.webCarti.MinimumSize = new System.Drawing.Size(20, 20);
            this.webCarti.Name = "webCarti";
            this.webCarti.Size = new System.Drawing.Size(800, 450);
            this.webCarti.TabIndex = 0;
            // 
            // AfiseazaCarteForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.webCarti);
            this.Name = "AfiseazaCarteForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "AfiseazaCarte";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.WebBrowser webCarti;
    }
}