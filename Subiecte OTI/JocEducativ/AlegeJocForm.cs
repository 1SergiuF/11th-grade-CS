using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.SqlClient;

namespace JocEducativ
{
    public partial class AlegeJocForm : Form
    {
        public static string loggedEmail;
        private List<Tuple<string, string, int>> listGhiceste = new List<Tuple<string, string, int>>();
        private List<Tuple<string, string, int>> listSarpe = new List<Tuple<string, string, int>>();
        public AlegeJocForm(string email, string nume)
        {
            InitializeComponent();
            loggedEmail = email;
            lblWelcome.Text = $"Bine ai venit, {nume}! ({email})";

            CreateTopScoreTables();
        }

        private void CreateTopScoreTables()
        {
            CreateTopScoreGhiceste();
            CreateTopScoreSarpe();
        }

        private void CreateTopScoreSarpe()
        {
            PushToListSarpe();
            listSarpe.Sort((t1, t2) => t2.Item3.CompareTo(t1.Item3));
            for (int i = 0; i < 3; ++i)
                this.dgvSarpe.Rows.Add(listSarpe[i].Item1,
                    listSarpe[i].Item2,
                    listSarpe[i].Item3);
        }

        private void CreateTopScoreGhiceste()
        {
            PushToListGhiceste();
            listGhiceste.Sort((t1, t2) => t2.Item3.CompareTo(t1.Item3));
            for (int i = 0; i < 3; ++i)
                this.dgvGhiceste.Rows.Add(listGhiceste[i].Item1,
                    listGhiceste[i].Item2,
                    listGhiceste[i].Item3);
        }
        private void PushToListSarpe()
        {
            var conn = new SqlConnection(JocEducativ.AutentificareForm.connStr);
            conn.Open();
            string query = "SELECT EmailUtilizator, PunctajJoc FROM Rezultate WHERE TipJoc = @joc";

            var cmd = new SqlCommand(query, conn);
            cmd.Parameters.AddWithValue("@joc", 1);

            var rd = cmd.ExecuteReader();
            while (rd.Read())
            {
                string nume = AutentificareForm.GasesteNumeUtilizator((string)rd[0]);
                listSarpe.Add(new Tuple<string, string, int>(nume, (string)rd[0], (int)rd[1]));
            }

            conn.Close();
            conn.Dispose();
            cmd.Dispose();
            rd.Close();
        }

        private void PushToListGhiceste()
        {
            var conn = new SqlConnection(JocEducativ.AutentificareForm.connStr);
            conn.Open();
            string query = "SELECT EmailUtilizator, PunctajJoc FROM Rezultate WHERE TipJoc = @joc";

            var cmd = new SqlCommand(query, conn);
            cmd.Parameters.AddWithValue("@joc", 0);

            var rd = cmd.ExecuteReader();
            while (rd.Read())
            {
                string nume = AutentificareForm.GasesteNumeUtilizator((string)rd[0]);
                listGhiceste.Add(new Tuple<string, string, int>(nume, (string)rd[0], (int)rd[1]));
            }

            conn.Close();
            conn.Dispose();
            cmd.Dispose();
            rd.Close();
        }

        private void btnGhiceste_Click(object sender, EventArgs e)
        {
            this.Visible = false;
            GhicesteForm ghicesteForm = new GhicesteForm();
            ghicesteForm.ShowDialog();
            this.Visible = true;

            GhicesteForm.InsereazaRezultat(0, loggedEmail, GhicesteForm.punctaj);
            GhicesteForm.punctaj = 100;

            listGhiceste.Clear();
            dgvGhiceste.Rows.Clear();
            CreateTopScoreGhiceste();
            DeleteLastRowRezultate();
        }

        private void DeleteLastRowRezultate()
        {
            var conn = new SqlConnection(JocEducativ.AutentificareForm.connStr);
            conn.Open();
            string query = "DELETE FROM Rezultate WHERE idRezultat = (SELECT MAX(idRezultat) FROM Rezultate)";

            var cmd = new SqlCommand(query, conn);
            cmd.ExecuteNonQuery();

            conn.Close();
            conn.Dispose();
            cmd.Dispose();
        }

        private void btnSarpe_Click(object sender, EventArgs e)
        {
            this.Visible = false;
            SarpeForm sarpeForm = new SarpeForm();
            sarpeForm.ShowDialog();
            this.Visible = true;

            GhicesteForm.InsereazaRezultat(1, loggedEmail, SarpeForm.score);
            SarpeForm.score = 0;

            listSarpe.Clear();
            dgvSarpe.Rows.Clear();
            CreateTopScoreSarpe();
            DeleteLastRowRezultate();
        }

        private void AlegeJocForm_FormClosing(object sender, FormClosingEventArgs e)
        {
            DialogResult dialogResult = MessageBox.Show("Esti sigur ca vrei sa iesi din aplicatie ?", "Intrebare", MessageBoxButtons.YesNo);
            if (dialogResult == DialogResult.No)
            {
                e.Cancel = true;
            }
        }
    }
}
