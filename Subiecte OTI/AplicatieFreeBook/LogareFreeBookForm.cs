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
    public partial class LogareFreeBookForm : Form
    {
        private string connStr = @"Data Source=(LocalDB)\MSSQLLocalDB;AttachDbFilename=|DataDirectory|\FreeBook.mdf;Integrated Security=True";
        public LogareFreeBookForm()
        {
            InitializeComponent();
        }

        private void btnLogareLog_Click(object sender, EventArgs e)
        {
            string email = txtEmailLog.Text;
            string pass = txtParolaLog.Text;
            if (email == string.Empty || pass == string.Empty)
            {
                MessageBox.Show("Toate campurile trebuie completate !");
                return;
            }

            if (!ExistaUtilizator(email, pass))
            {
                MessageBox.Show("Eroare autentificare!");
                txtEmailLog.Text = string.Empty;
                txtParolaLog.Text = string.Empty;
                return;
            }

            else
            {
                MeniuFreeBookForm frm = new MeniuFreeBookForm(email);
                this.Visible = false;
                frm.ShowDialog();
                Application.Exit();
            }
        }

        private bool ExistaUtilizator(string email, string pass)
        {
            var conn = new SqlConnection(connStr);
            conn.Open();
            string query = "SELECT COUNT(email) FROM utilizatori WHERE email = @email AND parola = @parola";

            var cmd = new SqlCommand(query, conn);
            cmd.Parameters.AddWithValue("@email", email);
            cmd.Parameters.AddWithValue("@parola", pass);

            int x = (int)cmd.ExecuteScalar();

            conn.Close();
            conn.Dispose();
            cmd.Dispose();

            return x == 1;
        }
    }
}
