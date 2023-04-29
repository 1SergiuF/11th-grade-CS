namespace AplicatieFreeBook
{
    partial class MeniuFreeBookForm
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
            System.Windows.Forms.DataVisualization.Charting.ChartArea chartArea1 = new System.Windows.Forms.DataVisualization.Charting.ChartArea();
            System.Windows.Forms.DataVisualization.Charting.StripLine stripLine1 = new System.Windows.Forms.DataVisualization.Charting.StripLine();
            System.Windows.Forms.DataVisualization.Charting.Legend legend1 = new System.Windows.Forms.DataVisualization.Charting.Legend();
            System.Windows.Forms.DataVisualization.Charting.Series series1 = new System.Windows.Forms.DataVisualization.Charting.Series();
            this.lblUtilizatorEmail = new System.Windows.Forms.Label();
            this.tabMeniu = new System.Windows.Forms.TabControl();
            this.tbpCartiDisponibile = new System.Windows.Forms.TabPage();
            this.dgv = new System.Windows.Forms.DataGridView();
            this.dgvColTitlu = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dgvColAutor = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dgvColGen = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dgvColImprumuta = new System.Windows.Forms.DataGridViewButtonColumn();
            this.tbpCartiImprumutate = new System.Windows.Forms.TabPage();
            this.dgvCartiImpr = new System.Windows.Forms.DataGridView();
            this.dgvColIndex = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dgvColTitluImpr = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dgvColAutorImpr = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dgvColDataImpr = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dgvColDataDisponibilitate = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.tbpBibliotecaStats = new System.Windows.Forms.TabPage();
            this.lblDisponibilitate = new System.Windows.Forms.Label();
            this.pbDisponibilitate = new System.Windows.Forms.ProgressBar();
            this.tabControl1 = new System.Windows.Forms.TabControl();
            this.tabNrUtilizatori = new System.Windows.Forms.TabPage();
            this.tabCartiPopulare = new System.Windows.Forms.TabPage();
            this.chartUtilizatori = new System.Windows.Forms.DataVisualization.Charting.Chart();
            this.tabMeniu.SuspendLayout();
            this.tbpCartiDisponibile.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dgv)).BeginInit();
            this.tbpCartiImprumutate.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dgvCartiImpr)).BeginInit();
            this.tbpBibliotecaStats.SuspendLayout();
            this.tabControl1.SuspendLayout();
            this.tabNrUtilizatori.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.chartUtilizatori)).BeginInit();
            this.SuspendLayout();
            // 
            // lblUtilizatorEmail
            // 
            this.lblUtilizatorEmail.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblUtilizatorEmail.Location = new System.Drawing.Point(12, 9);
            this.lblUtilizatorEmail.Name = "lblUtilizatorEmail";
            this.lblUtilizatorEmail.Size = new System.Drawing.Size(489, 28);
            this.lblUtilizatorEmail.TabIndex = 0;
            this.lblUtilizatorEmail.Text = "label1";
            // 
            // tabMeniu
            // 
            this.tabMeniu.Controls.Add(this.tbpCartiDisponibile);
            this.tabMeniu.Controls.Add(this.tbpCartiImprumutate);
            this.tabMeniu.Controls.Add(this.tbpBibliotecaStats);
            this.tabMeniu.Location = new System.Drawing.Point(3, 40);
            this.tabMeniu.Name = "tabMeniu";
            this.tabMeniu.SelectedIndex = 0;
            this.tabMeniu.Size = new System.Drawing.Size(548, 515);
            this.tabMeniu.TabIndex = 1;
            // 
            // tbpCartiDisponibile
            // 
            this.tbpCartiDisponibile.Controls.Add(this.dgv);
            this.tbpCartiDisponibile.Location = new System.Drawing.Point(4, 22);
            this.tbpCartiDisponibile.Name = "tbpCartiDisponibile";
            this.tbpCartiDisponibile.Padding = new System.Windows.Forms.Padding(3);
            this.tbpCartiDisponibile.Size = new System.Drawing.Size(540, 489);
            this.tbpCartiDisponibile.TabIndex = 0;
            this.tbpCartiDisponibile.Text = "Carti disponibile";
            this.tbpCartiDisponibile.UseVisualStyleBackColor = true;
            // 
            // dgv
            // 
            this.dgv.AutoSizeColumnsMode = System.Windows.Forms.DataGridViewAutoSizeColumnsMode.Fill;
            this.dgv.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dgv.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.dgvColTitlu,
            this.dgvColAutor,
            this.dgvColGen,
            this.dgvColImprumuta});
            this.dgv.Location = new System.Drawing.Point(0, 0);
            this.dgv.Name = "dgv";
            this.dgv.Size = new System.Drawing.Size(540, 489);
            this.dgv.TabIndex = 0;
            this.dgv.CellContentClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.dgv_CellContentClick);
            // 
            // dgvColTitlu
            // 
            this.dgvColTitlu.HeaderText = "Titlu";
            this.dgvColTitlu.Name = "dgvColTitlu";
            // 
            // dgvColAutor
            // 
            this.dgvColAutor.HeaderText = "Autor";
            this.dgvColAutor.Name = "dgvColAutor";
            // 
            // dgvColGen
            // 
            this.dgvColGen.HeaderText = "Gen";
            this.dgvColGen.Name = "dgvColGen";
            // 
            // dgvColImprumuta
            // 
            this.dgvColImprumuta.HeaderText = "Imprumuta carte";
            this.dgvColImprumuta.Name = "dgvColImprumuta";
            this.dgvColImprumuta.Resizable = System.Windows.Forms.DataGridViewTriState.True;
            this.dgvColImprumuta.SortMode = System.Windows.Forms.DataGridViewColumnSortMode.Automatic;
            // 
            // tbpCartiImprumutate
            // 
            this.tbpCartiImprumutate.Controls.Add(this.pbDisponibilitate);
            this.tbpCartiImprumutate.Controls.Add(this.dgvCartiImpr);
            this.tbpCartiImprumutate.Controls.Add(this.lblDisponibilitate);
            this.tbpCartiImprumutate.Location = new System.Drawing.Point(4, 22);
            this.tbpCartiImprumutate.Name = "tbpCartiImprumutate";
            this.tbpCartiImprumutate.Padding = new System.Windows.Forms.Padding(3);
            this.tbpCartiImprumutate.Size = new System.Drawing.Size(540, 489);
            this.tbpCartiImprumutate.TabIndex = 1;
            this.tbpCartiImprumutate.Text = "Carti imprumutate";
            this.tbpCartiImprumutate.UseVisualStyleBackColor = true;
            // 
            // dgvCartiImpr
            // 
            this.dgvCartiImpr.AutoSizeColumnsMode = System.Windows.Forms.DataGridViewAutoSizeColumnsMode.Fill;
            this.dgvCartiImpr.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dgvCartiImpr.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.dgvColIndex,
            this.dgvColTitluImpr,
            this.dgvColAutorImpr,
            this.dgvColDataImpr,
            this.dgvColDataDisponibilitate});
            this.dgvCartiImpr.Location = new System.Drawing.Point(0, 0);
            this.dgvCartiImpr.Name = "dgvCartiImpr";
            this.dgvCartiImpr.Size = new System.Drawing.Size(540, 440);
            this.dgvCartiImpr.TabIndex = 0;
            this.dgvCartiImpr.CellDoubleClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.dgvCartiImpr_CellDoubleClick);
            this.dgvCartiImpr.RowsRemoved += new System.Windows.Forms.DataGridViewRowsRemovedEventHandler(this.dgvCartiImpr_RowsRemoved);
            // 
            // dgvColIndex
            // 
            this.dgvColIndex.HeaderText = "Index";
            this.dgvColIndex.Name = "dgvColIndex";
            // 
            // dgvColTitluImpr
            // 
            this.dgvColTitluImpr.HeaderText = "Titlu";
            this.dgvColTitluImpr.Name = "dgvColTitluImpr";
            // 
            // dgvColAutorImpr
            // 
            this.dgvColAutorImpr.HeaderText = "Autor";
            this.dgvColAutorImpr.Name = "dgvColAutorImpr";
            // 
            // dgvColDataImpr
            // 
            this.dgvColDataImpr.HeaderText = "Data imprumut";
            this.dgvColDataImpr.Name = "dgvColDataImpr";
            // 
            // dgvColDataDisponibilitate
            // 
            this.dgvColDataDisponibilitate.HeaderText = "Data disponibilitate";
            this.dgvColDataDisponibilitate.Name = "dgvColDataDisponibilitate";
            // 
            // tbpBibliotecaStats
            // 
            this.tbpBibliotecaStats.Controls.Add(this.tabControl1);
            this.tbpBibliotecaStats.Location = new System.Drawing.Point(4, 22);
            this.tbpBibliotecaStats.Name = "tbpBibliotecaStats";
            this.tbpBibliotecaStats.Size = new System.Drawing.Size(540, 489);
            this.tbpBibliotecaStats.TabIndex = 2;
            this.tbpBibliotecaStats.Text = "Statistici biblioteca";
            this.tbpBibliotecaStats.UseVisualStyleBackColor = true;
            // 
            // lblDisponibilitate
            // 
            this.lblDisponibilitate.AutoSize = true;
            this.lblDisponibilitate.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblDisponibilitate.Location = new System.Drawing.Point(6, 459);
            this.lblDisponibilitate.Name = "lblDisponibilitate";
            this.lblDisponibilitate.Size = new System.Drawing.Size(44, 16);
            this.lblDisponibilitate.TabIndex = 2;
            this.lblDisponibilitate.Text = "label1";
            // 
            // pbDisponibilitate
            // 
            this.pbDisponibilitate.Location = new System.Drawing.Point(192, 459);
            this.pbDisponibilitate.Name = "pbDisponibilitate";
            this.pbDisponibilitate.Size = new System.Drawing.Size(348, 23);
            this.pbDisponibilitate.TabIndex = 3;
            // 
            // tabControl1
            // 
            this.tabControl1.Controls.Add(this.tabNrUtilizatori);
            this.tabControl1.Controls.Add(this.tabCartiPopulare);
            this.tabControl1.Location = new System.Drawing.Point(0, 3);
            this.tabControl1.Name = "tabControl1";
            this.tabControl1.SelectedIndex = 0;
            this.tabControl1.Size = new System.Drawing.Size(540, 486);
            this.tabControl1.TabIndex = 0;
            // 
            // tabNrUtilizatori
            // 
            this.tabNrUtilizatori.Controls.Add(this.chartUtilizatori);
            this.tabNrUtilizatori.Location = new System.Drawing.Point(4, 22);
            this.tabNrUtilizatori.Name = "tabNrUtilizatori";
            this.tabNrUtilizatori.Padding = new System.Windows.Forms.Padding(3);
            this.tabNrUtilizatori.Size = new System.Drawing.Size(532, 460);
            this.tabNrUtilizatori.TabIndex = 0;
            this.tabNrUtilizatori.Text = "Numar utilizatori";
            this.tabNrUtilizatori.UseVisualStyleBackColor = true;
            // 
            // tabCartiPopulare
            // 
            this.tabCartiPopulare.Location = new System.Drawing.Point(4, 22);
            this.tabCartiPopulare.Name = "tabCartiPopulare";
            this.tabCartiPopulare.Padding = new System.Windows.Forms.Padding(3);
            this.tabCartiPopulare.Size = new System.Drawing.Size(532, 460);
            this.tabCartiPopulare.TabIndex = 1;
            this.tabCartiPopulare.Text = "Carti populare";
            this.tabCartiPopulare.UseVisualStyleBackColor = true;
            // 
            // chartUtilizatori
            // 
            chartArea1.AxisX.IsStartedFromZero = false;
            chartArea1.AxisX.MajorGrid.Enabled = false;
            chartArea1.AxisX.MaximumAutoSize = 50F;
            chartArea1.AxisX.StripLines.Add(stripLine1);
            chartArea1.AxisY.Enabled = System.Windows.Forms.DataVisualization.Charting.AxisEnabled.True;
            chartArea1.AxisY.MajorGrid.Enabled = false;
            chartArea1.AxisY.MajorTickMark.Enabled = false;
            chartArea1.BackColor = System.Drawing.Color.Transparent;
            chartArea1.BorderColor = System.Drawing.Color.Transparent;
            chartArea1.Name = "ChartArea1";
            chartArea1.Position.Auto = false;
            chartArea1.Position.Height = 50F;
            chartArea1.Position.Width = 90F;
            chartArea1.Position.X = 2F;
            chartArea1.Position.Y = 40F;
            this.chartUtilizatori.ChartAreas.Add(chartArea1);
            legend1.Alignment = System.Drawing.StringAlignment.Center;
            legend1.Docking = System.Windows.Forms.DataVisualization.Charting.Docking.Bottom;
            legend1.Name = "Luna";
            this.chartUtilizatori.Legends.Add(legend1);
            this.chartUtilizatori.Location = new System.Drawing.Point(-8, 0);
            this.chartUtilizatori.Name = "chartUtilizatori";
            series1.ChartArea = "ChartArea1";
            series1.Legend = "Luna";
            series1.Name = "Luna";
            this.chartUtilizatori.Series.Add(series1);
            this.chartUtilizatori.Size = new System.Drawing.Size(548, 460);
            this.chartUtilizatori.TabIndex = 0;
            this.chartUtilizatori.Text = "chart1";
            // 
            // MeniuFreeBookForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(549, 555);
            this.Controls.Add(this.tabMeniu);
            this.Controls.Add(this.lblUtilizatorEmail);
            this.Name = "MeniuFreeBookForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Meniu FreeBook";
            this.tabMeniu.ResumeLayout(false);
            this.tbpCartiDisponibile.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.dgv)).EndInit();
            this.tbpCartiImprumutate.ResumeLayout(false);
            this.tbpCartiImprumutate.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dgvCartiImpr)).EndInit();
            this.tbpBibliotecaStats.ResumeLayout(false);
            this.tabControl1.ResumeLayout(false);
            this.tabNrUtilizatori.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.chartUtilizatori)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Label lblUtilizatorEmail;
        private System.Windows.Forms.TabControl tabMeniu;
        private System.Windows.Forms.TabPage tbpCartiDisponibile;
        private System.Windows.Forms.TabPage tbpCartiImprumutate;
        private System.Windows.Forms.TabPage tbpBibliotecaStats;
        private System.Windows.Forms.DataGridView dgv;
        private System.Windows.Forms.DataGridViewTextBoxColumn dgvColTitlu;
        private System.Windows.Forms.DataGridViewTextBoxColumn dgvColAutor;
        private System.Windows.Forms.DataGridViewTextBoxColumn dgvColGen;
        private System.Windows.Forms.DataGridViewButtonColumn dgvColImprumuta;
        private System.Windows.Forms.DataGridView dgvCartiImpr;
        private System.Windows.Forms.DataGridViewTextBoxColumn dgvColIndex;
        private System.Windows.Forms.DataGridViewTextBoxColumn dgvColTitluImpr;
        private System.Windows.Forms.DataGridViewTextBoxColumn dgvColAutorImpr;
        private System.Windows.Forms.DataGridViewTextBoxColumn dgvColDataImpr;
        private System.Windows.Forms.DataGridViewTextBoxColumn dgvColDataDisponibilitate;
        private System.Windows.Forms.Label lblDisponibilitate;
        private System.Windows.Forms.ProgressBar pbDisponibilitate;
        private System.Windows.Forms.TabControl tabControl1;
        private System.Windows.Forms.TabPage tabNrUtilizatori;
        private System.Windows.Forms.TabPage tabCartiPopulare;
        private System.Windows.Forms.DataVisualization.Charting.Chart chartUtilizatori;
    }
}