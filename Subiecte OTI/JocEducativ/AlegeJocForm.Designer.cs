namespace JocEducativ
{
    partial class AlegeJocForm
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
            this.lblWelcome = new System.Windows.Forms.Label();
            this.dgvGhiceste = new System.Windows.Forms.DataGridView();
            this.colNumeG = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.colEmailG = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.colPunctajG = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dgvSarpe = new System.Windows.Forms.DataGridView();
            this.colNumeS = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.colEmailS = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.colPunctajS = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.btnGhiceste = new System.Windows.Forms.Button();
            this.btnSarpe = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.dgvGhiceste)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dgvSarpe)).BeginInit();
            this.SuspendLayout();
            // 
            // lblWelcome
            // 
            this.lblWelcome.AutoSize = true;
            this.lblWelcome.Font = new System.Drawing.Font("Microsoft Sans Serif", 18F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblWelcome.Location = new System.Drawing.Point(21, 25);
            this.lblWelcome.Name = "lblWelcome";
            this.lblWelcome.Size = new System.Drawing.Size(79, 29);
            this.lblWelcome.TabIndex = 0;
            this.lblWelcome.Text = "label1";
            // 
            // dgvGhiceste
            // 
            this.dgvGhiceste.AutoSizeColumnsMode = System.Windows.Forms.DataGridViewAutoSizeColumnsMode.Fill;
            this.dgvGhiceste.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dgvGhiceste.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.colNumeG,
            this.colEmailG,
            this.colPunctajG});
            this.dgvGhiceste.Location = new System.Drawing.Point(26, 138);
            this.dgvGhiceste.Name = "dgvGhiceste";
            this.dgvGhiceste.Size = new System.Drawing.Size(366, 205);
            this.dgvGhiceste.TabIndex = 1;
            // 
            // colNumeG
            // 
            this.colNumeG.HeaderText = "NumeUtilizator";
            this.colNumeG.Name = "colNumeG";
            // 
            // colEmailG
            // 
            this.colEmailG.HeaderText = "EmailUtilizator";
            this.colEmailG.Name = "colEmailG";
            // 
            // colPunctajG
            // 
            this.colPunctajG.HeaderText = "PunctajJoc";
            this.colPunctajG.Name = "colPunctajG";
            // 
            // dgvSarpe
            // 
            this.dgvSarpe.AutoSizeColumnsMode = System.Windows.Forms.DataGridViewAutoSizeColumnsMode.Fill;
            this.dgvSarpe.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dgvSarpe.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.colNumeS,
            this.colEmailS,
            this.colPunctajS});
            this.dgvSarpe.Location = new System.Drawing.Point(420, 138);
            this.dgvSarpe.Name = "dgvSarpe";
            this.dgvSarpe.Size = new System.Drawing.Size(349, 205);
            this.dgvSarpe.TabIndex = 2;
            // 
            // colNumeS
            // 
            this.colNumeS.HeaderText = "NumeUtilizator";
            this.colNumeS.Name = "colNumeS";
            // 
            // colEmailS
            // 
            this.colEmailS.HeaderText = "EmailUtilizator";
            this.colEmailS.Name = "colEmailS";
            // 
            // colPunctajS
            // 
            this.colPunctajS.HeaderText = "PunctajJoc";
            this.colPunctajS.Name = "colPunctajS";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(133, 97);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(138, 20);
            this.label1.TabIndex = 3;
            this.label1.Text = "Top scor Ghiceste";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.Location = new System.Drawing.Point(498, 97);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(178, 20);
            this.label2.TabIndex = 4;
            this.label2.Text = "Top scor SarpeEducativ";
            // 
            // btnGhiceste
            // 
            this.btnGhiceste.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(192)))), ((int)(((byte)(0)))));
            this.btnGhiceste.Font = new System.Drawing.Font("Microsoft Sans Serif", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnGhiceste.ForeColor = System.Drawing.Color.White;
            this.btnGhiceste.Location = new System.Drawing.Point(111, 362);
            this.btnGhiceste.Name = "btnGhiceste";
            this.btnGhiceste.Size = new System.Drawing.Size(190, 64);
            this.btnGhiceste.TabIndex = 5;
            this.btnGhiceste.Text = "Ghiceste";
            this.btnGhiceste.UseVisualStyleBackColor = false;
            this.btnGhiceste.Click += new System.EventHandler(this.btnGhiceste_Click);
            // 
            // btnSarpe
            // 
            this.btnSarpe.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(192)))), ((int)(((byte)(0)))));
            this.btnSarpe.Font = new System.Drawing.Font("Microsoft Sans Serif", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnSarpe.ForeColor = System.Drawing.Color.White;
            this.btnSarpe.Location = new System.Drawing.Point(502, 362);
            this.btnSarpe.Name = "btnSarpe";
            this.btnSarpe.Size = new System.Drawing.Size(178, 64);
            this.btnSarpe.TabIndex = 6;
            this.btnSarpe.Text = "SarpeEducativ";
            this.btnSarpe.UseVisualStyleBackColor = false;
            this.btnSarpe.Click += new System.EventHandler(this.btnSarpe_Click);
            // 
            // AlegeJocForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(192)))), ((int)(((byte)(192)))));
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.btnSarpe);
            this.Controls.Add(this.btnGhiceste);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.dgvSarpe);
            this.Controls.Add(this.dgvGhiceste);
            this.Controls.Add(this.lblWelcome);
            this.Name = "AlegeJocForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "AlegeJoc";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.AlegeJocForm_FormClosing);
            ((System.ComponentModel.ISupportInitialize)(this.dgvGhiceste)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dgvSarpe)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label lblWelcome;
        private System.Windows.Forms.DataGridView dgvGhiceste;
        private System.Windows.Forms.DataGridView dgvSarpe;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.DataGridViewTextBoxColumn colNumeG;
        private System.Windows.Forms.DataGridViewTextBoxColumn colEmailG;
        private System.Windows.Forms.DataGridViewTextBoxColumn colPunctajG;
        private System.Windows.Forms.DataGridViewTextBoxColumn colNumeS;
        private System.Windows.Forms.DataGridViewTextBoxColumn colEmailS;
        private System.Windows.Forms.DataGridViewTextBoxColumn colPunctajS;
        private System.Windows.Forms.Button btnGhiceste;
        private System.Windows.Forms.Button btnSarpe;
    }
}