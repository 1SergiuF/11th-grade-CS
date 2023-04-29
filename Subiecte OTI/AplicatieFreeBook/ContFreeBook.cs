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

namespace AplicatieFreeBook
{
    public partial class ContFreeBook : Form
    {
        private string connStr = @"Data Source=(LocalDB)\MSSQLLocalDB;AttachDbFilename=|DataDirectory|\FreeBook.mdf;Integrated Security=True";
        public ContFreeBook()
        {
            InitializeComponent();
        }

        private void btnContNou_Click(object sender, EventArgs e)
        {
            if (txtEmail.Text == "" || txtNume.Text == "" ||
                txtPrenume.Text == "" || txtParola.Text == "" ||
                txtConfirmare.Text == "")
            {
                MessageBox.Show("Toate campurile trebuie completate !");
                return;
            }

            string email = txtEmail.Text;
            if (ExistaEmail(email))
            {
                MessageBox.Show("Emailul exista deja in baza de date !");
                return;
            }

            if (!EmailValid(email))
            {
                MessageBox.Show("Adresa de email invalida !");
                return;
            }

            string parola = txtParola.Text;
            string confirmare = txtConfirmare.Text;

            if (parola != confirmare)
            {
                MessageBox.Show("Campurile 'Parola' si 'Confirmare parola' nu coincid !");
                return;
            }

            string nume = txtNume.Text;
            string prenume = txtPrenume.Text;
            InsertUtilizator(email, parola, nume, prenume);
            this.Visible = false;
            MeniuFreeBookForm frm = new MeniuFreeBookForm(email);
            frm.ShowDialog();
            Application.Exit();
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

        private bool ExistaEmail(string email)
        {
            var conn = new SqlConnection(connStr);
            conn.Open();
            string query = "SELECT COUNT(email) FROM utilizatori WHERE email = @email";
            var cmd = new SqlCommand(query, conn);

            cmd.Parameters.AddWithValue("@email", email);
            int cnt = (int)cmd.ExecuteScalar();

            conn.Close();
            conn.Dispose();
            cmd.Dispose();

            return cnt > 0;
        }

        private bool EmailValid(string email)
        {
            var trimmedEmail = email.Trim();

            if (trimmedEmail.EndsWith("."))
            {
                return false;
            }
            try
            {
                var addr = new System.Net.Mail.MailAddress(email);
                return addr.Address == trimmedEmail;
            }
            catch
            {
                return false;
            }
        }
    }
}
