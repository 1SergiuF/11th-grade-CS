namespace JocEducativ
{
    partial class SarpeForm
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
            this.lblSarpe = new System.Windows.Forms.Label();
            this.btnStartSarpe = new System.Windows.Forms.Button();
            this.btnStopSarpe = new System.Windows.Forms.Button();
            this.pbJocSarpe = new System.Windows.Forms.PictureBox();
            ((System.ComponentModel.ISupportInitialize)(this.pbJocSarpe)).BeginInit();
            this.SuspendLayout();
            // 
            // lblSarpe
            // 
            this.lblSarpe.AutoSize = true;
            this.lblSarpe.Font = new System.Drawing.Font("Microsoft Sans Serif", 20.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblSarpe.Location = new System.Drawing.Point(563, 197);
            this.lblSarpe.Name = "lblSarpe";
            this.lblSarpe.Size = new System.Drawing.Size(120, 31);
            this.lblSarpe.TabIndex = 1;
            this.lblSarpe.Text = "Punctaj: ";
            // 
            // btnStartSarpe
            // 
            this.btnStartSarpe.Font = new System.Drawing.Font("Microsoft Sans Serif", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnStartSarpe.Location = new System.Drawing.Point(12, 403);
            this.btnStartSarpe.Name = "btnStartSarpe";
            this.btnStartSarpe.Size = new System.Drawing.Size(147, 35);
            this.btnStartSarpe.TabIndex = 2;
            this.btnStartSarpe.Text = "Start";
            this.btnStartSarpe.UseVisualStyleBackColor = true;
            this.btnStartSarpe.Click += new System.EventHandler(this.StartGame);
            // 
            // btnStopSarpe
            // 
            this.btnStopSarpe.Font = new System.Drawing.Font("Microsoft Sans Serif", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnStopSarpe.Location = new System.Drawing.Point(287, 403);
            this.btnStopSarpe.Name = "btnStopSarpe";
            this.btnStopSarpe.Size = new System.Drawing.Size(150, 35);
            this.btnStopSarpe.TabIndex = 3;
            this.btnStopSarpe.Text = "Stop joc";
            this.btnStopSarpe.UseVisualStyleBackColor = true;
            this.btnStopSarpe.Click += new System.EventHandler(this.StopGame);
            // 
            // pbJocSarpe
            // 
            this.pbJocSarpe.BackColor = System.Drawing.Color.Black;
            this.pbJocSarpe.Location = new System.Drawing.Point(13, 12);
            this.pbJocSarpe.Name = "pbJocSarpe";
            this.pbJocSarpe.Size = new System.Drawing.Size(424, 385);
            this.pbJocSarpe.TabIndex = 4;
            this.pbJocSarpe.TabStop = false;
            this.pbJocSarpe.Paint += new System.Windows.Forms.PaintEventHandler(this.UpdatePictureBoxGraphics);
            // 
            // SarpeForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.pbJocSarpe);
            this.Controls.Add(this.btnStopSarpe);
            this.Controls.Add(this.btnStartSarpe);
            this.Controls.Add(this.lblSarpe);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Name = "SarpeForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Sarpe";
            this.KeyDown += new System.Windows.Forms.KeyEventHandler(this.KeyIsDown);
            this.KeyUp += new System.Windows.Forms.KeyEventHandler(this.KeyIsUp);
            ((System.ComponentModel.ISupportInitialize)(this.pbJocSarpe)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.Label lblSarpe;
        private System.Windows.Forms.Button btnStartSarpe;
        private System.Windows.Forms.Button btnStopSarpe;
        private System.Windows.Forms.PictureBox pbJocSarpe;
    }
}