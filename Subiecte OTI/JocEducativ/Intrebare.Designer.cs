namespace JocEducativ
{
    partial class Intrebare
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
            this.rtbIntrebare = new System.Windows.Forms.RichTextBox();
            this.rbA = new System.Windows.Forms.RadioButton();
            this.rbC = new System.Windows.Forms.RadioButton();
            this.rbB = new System.Windows.Forms.RadioButton();
            this.btnInregistreaza = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // rtbIntrebare
            // 
            this.rtbIntrebare.Font = new System.Drawing.Font("Microsoft Sans Serif", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.rtbIntrebare.Location = new System.Drawing.Point(12, 12);
            this.rtbIntrebare.Name = "rtbIntrebare";
            this.rtbIntrebare.ReadOnly = true;
            this.rtbIntrebare.Size = new System.Drawing.Size(512, 133);
            this.rtbIntrebare.TabIndex = 0;
            this.rtbIntrebare.Text = "";
            this.rtbIntrebare.KeyUp += new System.Windows.Forms.KeyEventHandler(this.rtbIntrebare_KeyUp);
            // 
            // rbA
            // 
            this.rbA.AutoSize = true;
            this.rbA.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.rbA.Location = new System.Drawing.Point(12, 201);
            this.rbA.Name = "rbA";
            this.rbA.Size = new System.Drawing.Size(119, 24);
            this.rbA.TabIndex = 1;
            this.rbA.TabStop = true;
            this.rbA.Text = "radioButton1";
            this.rbA.UseVisualStyleBackColor = true;
            this.rbA.Click += new System.EventHandler(this.rbA_Click);
            this.rbA.KeyUp += new System.Windows.Forms.KeyEventHandler(this.rbA_KeyUp);
            // 
            // rbC
            // 
            this.rbC.AutoSize = true;
            this.rbC.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.rbC.Location = new System.Drawing.Point(12, 270);
            this.rbC.Name = "rbC";
            this.rbC.Size = new System.Drawing.Size(119, 24);
            this.rbC.TabIndex = 2;
            this.rbC.TabStop = true;
            this.rbC.Text = "radioButton3";
            this.rbC.UseVisualStyleBackColor = true;
            this.rbC.Click += new System.EventHandler(this.rbA_Click);
            this.rbC.KeyUp += new System.Windows.Forms.KeyEventHandler(this.rbA_KeyUp);
            // 
            // rbB
            // 
            this.rbB.AutoSize = true;
            this.rbB.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.rbB.Location = new System.Drawing.Point(12, 235);
            this.rbB.Name = "rbB";
            this.rbB.Size = new System.Drawing.Size(119, 24);
            this.rbB.TabIndex = 3;
            this.rbB.TabStop = true;
            this.rbB.Text = "radioButton2";
            this.rbB.UseVisualStyleBackColor = true;
            this.rbB.Click += new System.EventHandler(this.rbA_Click);
            this.rbB.KeyUp += new System.Windows.Forms.KeyEventHandler(this.rbA_KeyUp);
            // 
            // btnInregistreaza
            // 
            this.btnInregistreaza.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnInregistreaza.Location = new System.Drawing.Point(13, 323);
            this.btnInregistreaza.Name = "btnInregistreaza";
            this.btnInregistreaza.Size = new System.Drawing.Size(234, 52);
            this.btnInregistreaza.TabIndex = 4;
            this.btnInregistreaza.Text = "Inregistreaza raspuns";
            this.btnInregistreaza.UseVisualStyleBackColor = true;
            this.btnInregistreaza.Click += new System.EventHandler(this.btnInregistreaza_Click);
            this.btnInregistreaza.KeyUp += new System.Windows.Forms.KeyEventHandler(this.btnInregistreaza_KeyUp);
            // 
            // Intrebare
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(536, 393);
            this.Controls.Add(this.btnInregistreaza);
            this.Controls.Add(this.rbB);
            this.Controls.Add(this.rbC);
            this.Controls.Add(this.rbA);
            this.Controls.Add(this.rtbIntrebare);
            this.Name = "Intrebare";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Intrebare";
            this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.Intrebare_FormClosed);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.RichTextBox rtbIntrebare;
        private System.Windows.Forms.RadioButton rbA;
        private System.Windows.Forms.RadioButton rbC;
        private System.Windows.Forms.RadioButton rbB;
        private System.Windows.Forms.Button btnInregistreaza;
    }
}