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
        List<Tuple<string, string, int>> listGhiceste = new List<Tuple<string, string, int>>();
        List<Tuple<string, string, int>> listSarpe = new List<Tuple<string, string, int>>();
        public AlegeJocForm(string email, string nume)
        {
            InitializeComponent();
            lblWelcome.Text = $"Bine ai venit, {nume}! ({email})";

            PushToListGhiceste();
            PushToListSarpe();

            listGhiceste.Sort((t1, t2) => t2.Item3.CompareTo(t1.Item3));
            for (int i = 0; i < 3; ++i)
                this.dgvGhiceste.Rows.Add(listGhiceste[i].Item1,
                    listGhiceste[i].Item2,
                    listGhiceste[i].Item3);

            listSarpe.Sort((t1, t2) => t2.Item3.CompareTo(t1.Item3));
            for (int i = 0; i < 3; ++i)
                this.dgvSarpe.Rows.Add(listSarpe[i].Item1,
                    listSarpe[i].Item2,
                    listSarpe[i].Item3);
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
    }
}
