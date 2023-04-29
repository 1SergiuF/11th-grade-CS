namespace AplicatieFreeBook
{
    partial class LogareFreeBookForm
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
            this.label1 = new System.Windows.Forms.Label();
            this.txtEmailLog = new System.Windows.Forms.TextBox();
            this.txtParolaLog = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.btnLogareLog = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(29, 40);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(48, 20);
            this.label1.TabIndex = 0;
            this.label1.Text = "Email";
            // 
            // txtEmailLog
            // 
            this.txtEmailLog.Location = new System.Drawing.Point(115, 37);
            this.txtEmailLog.Name = "txtEmailLog";
            this.txtEmailLog.Size = new System.Drawing.Size(264, 20);
            this.txtEmailLog.TabIndex = 1;
            // 
            // txtParolaLog
            // 
            this.txtParolaLog.Location = new System.Drawing.Point(115, 75);
            this.txtParolaLog.Name = "txtParolaLog";
            this.txtParolaLog.PasswordChar = '*';
            this.txtParolaLog.Size = new System.Drawing.Size(264, 20);
            this.txtParolaLog.TabIndex = 3;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.Location = new System.Drawing.Point(29, 78);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(54, 20);
            this.label2.TabIndex = 2;
            this.label2.Text = "Parola";
            // 
            // btnLogareLog
            // 
            this.btnLogareLog.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnLogareLog.ForeColor = System.Drawing.Color.Blue;
            this.btnLogareLog.Location = new System.Drawing.Point(115, 113);
            this.btnLogareLog.Name = "btnLogareLog";
            this.btnLogareLog.Size = new System.Drawing.Size(175, 40);
            this.btnLogareLog.TabIndex = 4;
            this.btnLogareLog.Text = "Logare";
            this.btnLogareLog.UseVisualStyleBackColor = true;
            this.btnLogareLog.Click += new System.EventHandler(this.btnLogareLog_Click);
            // 
            // LogareFreeBookForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(420, 167);
            this.Controls.Add(this.btnLogareLog);
            this.Controls.Add(this.txtParolaLog);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.txtEmailLog);
            this.Controls.Add(this.label1);
            this.Name = "LogareFreeBookForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "Logare FreeBook";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox txtEmailLog;
        private System.Windows.Forms.TextBox txtParolaLog;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button btnLogareLog;
    }
}