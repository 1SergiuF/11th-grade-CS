using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement.ListView;

namespace JocEducativ
{
    public partial class AutentificareForm : Form
    {
        private string resPath = $@"{Directory.GetCurrentDirectory()}\..\..\csarp\";
        public static string connStr = $@"Data Source=(LocalDB)\MSSQLLocalDB;AttachDbFilename=|DataDirectory|\JocEducativ.mdf;Integrated Security=True";
        public AutentificareForm()
        {
            InitializeComponent();

            IncarcaUtilizatori();
            IncarcaRezultate();
            IncarcaItemi();
        }

        private void IncarcaItemi()
        {
            StreamReader sr = new StreamReader(resPath + "Itemi.txt");
            string line;
            char[] sep = { ';' };
            string[] s;

            while ((line = sr.ReadLine()) != null)
            {
                s = line.Split(sep, StringSplitOptions.RemoveEmptyEntries);

                string enunt = s[1];
                string r1 = s[2];
                string r2 = s[3];
                string r3 = s[4];
                int corect = int.Parse(s[5]);
                int punctajItem = int.Parse(s[6]);

                InsertItem(enunt, r1, r2, r3, corect, punctajItem);
            }
        }

        private void InsertItem(string enunt, string r1, string r2, string r3, int corect, int punctajItem)
        {
            var conn = new SqlConnection(connStr);
            conn.Open();
            string query = "INSERT INTO Itemi VALUES(@enunt, @r1, @r2, @r3, @corect, @punctaj)";

            var cmd = new SqlCommand(query, conn);
            cmd.Parameters.AddWithValue("@enunt", enunt);
            cmd.Parameters.AddWithValue("@r1", r1);
            cmd.Parameters.AddWithValue("@r2", r2);
            cmd.Parameters.AddWithValue("@r3", r3);
            cmd.Parameters.AddWithValue("@corect", corect);
            cmd.Parameters.AddWithValue("@punctaj", punctajItem);

            cmd.ExecuteNonQuery();

            conn.Close();
            conn.Dispose();
            cmd.Dispose();
        }

        private void IncarcaRezultate()
        {
            StreamReader sr = new StreamReader(resPath + "Rezultate.txt");
            string line;
            char[] sep = { ';' };
            string[] s;

            while ((line = sr.ReadLine()) != null)
            {
                s = line.Split(sep, StringSplitOptions.RemoveEmptyEntries);

                int joc = int.Parse(s[1]);
                string email = s[2];
                int punctaj = int.Parse(s[3]);

                InsertRezultat(joc, email, punctaj);
            }
        }

        private void InsertRezultat(int joc, string email, int punctaj)
        {
            var conn = new SqlConnection(connStr);
            conn.Open();
            string query = "INSERT INTO Rezultate VALUES(@joc, @email, @punctaj)";

            var cmd = new SqlCommand(query, conn);
            cmd.Parameters.AddWithValue("@joc", joc);
            cmd.Parameters.AddWithValue("@email", email);
            cmd.Parameters.AddWithValue("@punctaj", punctaj);

            cmd.ExecuteNonQuery();

            conn.Close();
            conn.Dispose();
            cmd.Dispose();
        }

        private void IncarcaUtilizatori()
        {
            StreamReader sr = new StreamReader(resPath + "Utilizatori.txt");
            string line;
            char[] sep = { ';' };
            string[] s;

            while ((line = sr.ReadLine()) != null)
            {
                s = line.Split(sep, StringSplitOptions.RemoveEmptyEntries);
                string email = s[0];
                string nume = s[1];
                string parola = s[2];

                InsertUtilizator(email, nume, parola);
            }
        }

        private void InsertUtilizator(string email, string nume, string parola)
        {
            var conn = new SqlConnection(connStr);
            conn.Open();
            string query = "INSERT INTO Utilizatori VALUES(@email, @nume, @parola)";

            var cmd = new SqlCommand(query, conn);
            cmd.Parameters.AddWithValue("@email", email);
            cmd.Parameters.AddWithValue("@nume", nume);
            cmd.Parameters.AddWithValue("@parola", parola);

            cmd.ExecuteNonQuery();

            conn.Close();
            conn.Dispose();
            cmd.Dispose();
        }

        private void btnLogare_Click(object sender, EventArgs e)
        {
            string email = txtEmail.Text;
            string parola = txtParola.Text;

            if (ExistaUtilizator(email, parola))
            {
                string nume = GasesteNumeUtilizator(email);
                this.Visible = false;
                AlegeJocForm frm = new AlegeJocForm(email, nume);
                frm.ShowDialog();
                Application.Exit();
            }

            else
            {
                MessageBox.Show("Date de autentificare invalide!");
                txtEmail.Text = "";
                txtParola.Text = "";
            }
        }

        public static string GasesteNumeUtilizator(string email)
        {
            var conn = new SqlConnection(connStr);
            conn.Open();
            string query = "SELECT NumeUtilizator FROM Utilizatori WHERE EmailUtilizator = @email";

            var cmd = new SqlCommand(query, conn);
            cmd.Parameters.AddWithValue("@email", email);

            var sc = cmd.ExecuteScalar();

            conn.Close();
            conn.Dispose();
            cmd.Dispose();

            return (string)sc;
        }

        private bool ExistaUtilizator(string email, string parola)
        {
            var conn = new SqlConnection(connStr);
            conn.Open();
            string query = "SELECT COUNT(EmailUtilizator) FROM Utilizatori WHERE EmailUtilizator = @email AND Parola = @parola";

            var cmd = new SqlCommand(query, conn);
            cmd.Parameters.AddWithValue("@email", email);
            cmd.Parameters.AddWithValue("@parola", parola);

            var sc = cmd.ExecuteScalar();
            int cnt = (int)sc;

            conn.Close();
            conn.Dispose();
            cmd.Dispose();

            return cnt == 1;
        }
    }
}
