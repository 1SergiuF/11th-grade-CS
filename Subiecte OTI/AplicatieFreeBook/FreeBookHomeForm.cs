using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using System.Data.SqlClient;

namespace AplicatieFreeBook
{
    public partial class FreeBookHomeForm : Form
    {
        private string connStr = @"Data Source=(LocalDB)\MSSQLLocalDB;AttachDbFilename=|DataDirectory|\FreeBook.mdf;Integrated Security=True";
        private string resPath = $@"{Directory.GetCurrentDirectory()}\..\..\csarp\";
        public FreeBookHomeForm()
        {
            InitializeComponent();

            IncarcaUtilizatori();
            IncarcaCarti();
            IncarcaImprumuturi();
        }

        private void IncarcaImprumuturi()
        {
            StreamReader sr = new StreamReader(resPath + "imprumuturi.txt");
            string line;
            string[] s;
            char[] sep = { '*' };

            while ((line = sr.ReadLine()) != null)
            {
                s = line.Split(sep, StringSplitOptions.RemoveEmptyEntries);

                string titlu = s[0];
                string email = s[1];
                int id_carte = GetIdCarte(titlu);
                DateTime data_imprumut = DateTime.Parse(s[2]);

                InsertImprumut(id_carte, email, data_imprumut);
            }
        }

        private void InsertImprumut(int id_carte, string email, DateTime data_imprumut)
        {
            var conn = new SqlConnection(connStr);
            conn.Open();
            string query = "INSERT INTO imprumut VALUES (@id_carte, @email, @data_imprumut)";
            
            var cmd = new SqlCommand(query, conn);
            cmd.Parameters.AddWithValue("@id_carte", id_carte);
            cmd.Parameters.AddWithValue("@email", email);
            cmd.Parameters.AddWithValue("@data_imprumut", data_imprumut);
            cmd.ExecuteNonQuery();

            conn.Close();
            cmd.Dispose();
            conn.Dispose();
        }

        private void IncarcaCarti()
        {
            StreamReader sr = new StreamReader(resPath + "carti.txt");
            string line;
            string[] s;
            char[] sep = { '*' };

            while ((line = sr.ReadLine()) != null)
            {
                s = line.Split(sep, StringSplitOptions.RemoveEmptyEntries);

                string titlu = s[0];
                string autor  = s[1];
                string gen = s[2];

                InsertCarte(titlu, autor, gen);
            }
        }

        private void InsertCarte(string titlu, string autor, string gen)
        {
            var conn = new SqlConnection(connStr);
            conn.Open();
            string query = "INSERT INTO carti VALUES (@titlu, @autor, @gen)";

            var cmd = new SqlCommand(query, conn);
            cmd.Parameters.AddWithValue("@titlu", titlu);
            cmd.Parameters.AddWithValue("@autor", autor);
            cmd.Parameters.AddWithValue("@gen", gen);
            cmd.ExecuteNonQuery();

            conn.Close();
            cmd.Dispose();
            conn.Dispose();
        }

        private int GetIdCarte(string titlu)
        {
            var conn = new SqlConnection(connStr);
            conn.Open();
            string query = "SELECT id_carte FROM carti WHERE titlu = @titlu";
            var cmd = new SqlCommand(query, conn);
            cmd.Parameters.AddWithValue("@titlu", titlu);

            var rd = cmd.ExecuteReader();
            rd.Read();
            int id = (int)rd[0];

            rd.Close();
            conn.Close();
            cmd.Dispose();
            conn.Dispose();

            return id;
        }

        private void IncarcaUtilizatori()
        {
            StreamReader sr = new StreamReader(resPath + "utilizatori.txt");
            string line;
            string[] s;
            char[] sep = { '*' };

            while ((line = sr.ReadLine()) != null)
            {
                s = line.Split(sep, StringSplitOptions.RemoveEmptyEntries);
                string email = s[0];
                string parola = s[1];
                string nume = s[2];
                string prenume = s[3];

                InsertUtilizator(email, parola, nume, prenume);
            }
        }

        private void InsertUtilizator(string email, string parola, string nume, string prenume)
        {
            var conn = new SqlConnection(connStr);
            conn.Open();
            string query = "INSERT INTO utilizatori VALUES (@email, @parola, @nume, @prenume)";
            var cmd = new SqlCommand(query, conn);

            cmd.Parameters.AddWithValue("@email", email);
            cmd.Parameters.AddWithValue("@parola", parola);
            cmd.Parameters.AddWithValue("@nume", nume);
            cmd.Parameters.AddWithValue("@prenume", prenume);
            cmd.ExecuteNonQuery();

            conn.Close();
            conn.Dispose();
            cmd.Dispose();
        }

        private void btnInregistrare_Click(object sender, EventArgs e)
        {
            ContFreeBook frm = new ContFreeBook();
            this.Visible = false;
            frm.ShowDialog();
            this.Visible = true;
        }

        private void btnLogare_Click(object sender, EventArgs e)
        {
            LogareFreeBookForm frm = new LogareFreeBookForm();
            this.Visible = false;
            frm.ShowDialog();
            this.Visible = true;
        }
    }
}
