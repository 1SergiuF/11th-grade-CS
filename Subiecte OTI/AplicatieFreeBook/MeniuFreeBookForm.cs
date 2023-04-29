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
using static System.Windows.Forms.VisualStyles.VisualStyleElement.ListView;
using System.Runtime.InteropServices;

namespace AplicatieFreeBook
{
    public partial class MeniuFreeBookForm : Form
    {
        private string connStr = @"Data Source=(LocalDB)\MSSQLLocalDB;AttachDbFilename=|DataDirectory|\FreeBook.mdf;Integrated Security=True";
        private List<Tuple<string, string, string>> informatiiCarte = new List<Tuple<string, string, string>>();
        private List<Tuple<int, string, string>> cartiImprumutate = new List<Tuple<int, string, string>>();
        private List<int> indexCarteImprumutata = new List<int>();
        private List<DateTime> dateImprumuturi = new List<DateTime>();
        private List<DateTime> dateDisponibilitate = new List<DateTime>(); 
        private string emailUtilizator;
        private int nrCartiDisponibile = 0;
        private int nrCartiFosteDisponibile = 0;
        public MeniuFreeBookForm(string email)
        {
            InitializeComponent();
            emailUtilizator = email;
            lblUtilizatorEmail.Text = $"Email utilizator: {email}";

            PopuleazaCartiDisponibile();
            foreach (var t in informatiiCarte)
                this.dgv.Rows.Add(t.Item1, t.Item2, t.Item3);

            PushIdsSiDateCarteImprumutata(email);
            PushInformatiiCartiImprumutate();

            for (int i = 0; i < cartiImprumutate.Count; ++i)
            {
                this.dgvCartiImpr.Rows.Add(cartiImprumutate[i].Item1,
                                           cartiImprumutate[i].Item2,
                                           cartiImprumutate[i].Item3,
                                           dateImprumuturi[i],
                                           dateDisponibilitate[i]);

                this.dgvCartiImpr.Rows[i].DefaultCellStyle.BackColor = Color.Green;
            }

            VerificaDate(dateImprumuturi, dateDisponibilitate);
            lblDisponibilitate.Text = $"Disponibilitate imprumuturi {nrCartiDisponibile}/3";
            pbDisponibilitate.Maximum = 3;
            pbDisponibilitate.Increment(nrCartiDisponibile);
        }

        private void VerificaDate(List<DateTime> dateImprumuturi, List<DateTime> dateDisponibilitate)
        {
            dateImprumuturi.Sort((a, b) => b.CompareTo(a));
            for (int i = 0; i < cartiImprumutate.Count; i++)
            {
                if (DateTime.Compare(dateDisponibilitate[i], dateImprumuturi[0]) < 0 ||
                    DateTime.Compare(dateDisponibilitate[i], dateImprumuturi[0]) == 0)
                    this.dgvCartiImpr.Rows[i].DefaultCellStyle.BackColor = Color.Red;
                else
                    ++nrCartiDisponibile;
            }
        }

        private void PushInformatiiCartiImprumutate()
        {
            for (int i = 0; i < indexCarteImprumutata.Count; i++)
            {
                GasesteCarte(indexCarteImprumutata[i], i);
            }
        }

        private void GasesteCarte(int id_carte, int index)
        {
            var conn = new SqlConnection(connStr);
            conn.Open();
            string query = "SELECT titlu, autor FROM carti WHERE id_carte = @id";

            var cmd = new SqlCommand(query, conn);
            cmd.Parameters.AddWithValue("@id", id_carte);

            var rd = cmd.ExecuteReader();
            rd.Read();
            cartiImprumutate.Add(new Tuple<int, string, string>(index + 1, rd.GetString(0), rd.GetString(1)));

            rd.Close();
            conn.Close();
            conn.Dispose();
            cmd.Dispose();
        }

        private void PushIdsSiDateCarteImprumutata(string email)
        {
            var conn = new SqlConnection(connStr);
            conn.Open();
            string query = "SELECT id_carte, data_imprumut FROM imprumut WHERE email = @email";
            
            var cmd = new SqlCommand(query, conn);
            cmd.Parameters.AddWithValue("@email", email);

            var rd = cmd.ExecuteReader();
            while (rd.Read())
            {
                indexCarteImprumutata.Add((int)rd[0]);
                dateImprumuturi.Add((DateTime)rd[1]);

                DateTime newDate = dateImprumuturi[dateImprumuturi.Count - 1].AddDays(30);
                dateDisponibilitate.Add(newDate);
            }

            conn.Close();
            rd.Close();
            conn.Dispose();
            cmd.Dispose();
        }

        private void PopuleazaCartiDisponibile()
        {
            var conn = new SqlConnection(connStr);
            conn.Open();
            string query = "SELECT titlu, autor, gen FROM carti";
            var cmd = new SqlCommand(query, conn);

            var rd = cmd.ExecuteReader();
            while (rd.Read())
            {
                informatiiCarte.Add(new Tuple<string, string, string>(
                    rd.GetString(0), 
                    rd.GetString(1), 
                    rd.GetString(2))
                 );
            }

            conn.Close();
            rd.Close();
            conn.Dispose();
            cmd.Dispose();
        }

        private void dgv_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
            if (pbDisponibilitate.Value < 3)
            {
                nrCartiFosteDisponibile = 0;
                var senderGrid = (DataGridView)sender;

                if (senderGrid.Columns[e.ColumnIndex] is DataGridViewButtonColumn &&
                    e.RowIndex >= 0)
                {
                    DateTime data_imprumut = DateTime.Now;
                    string email = emailUtilizator;

                    int index = e.RowIndex;
                    DataGridViewRow row = senderGrid.Rows[index];
                    string titlu = row.Cells[0].Value?.ToString();

                    int id_carte = GetIdCarte(titlu);
                    string autor = GetAutorCarte(titlu);
                    InsertImprumut(id_carte, email, data_imprumut);

                    for (int i = 0; i < dgvCartiImpr.Rows.Count; ++i)
                    {
                        string r = dgvCartiImpr.Rows[i].Cells[1].Value?.ToString();
                        if (r == titlu && (dgvCartiImpr.Rows[i].DefaultCellStyle.BackColor == Color.Green))
                        {
                            MessageBox.Show("Cartea nu este disponibila !");
                            return;
                        }

                        else
                            if (r == titlu && (dgvCartiImpr.Rows[i].DefaultCellStyle.BackColor == Color.Red))
                                dgvCartiImpr.Rows.RemoveAt(i);
                    }

                    DateTime newDate = DateTime.Now.AddDays(30);
                    dgvCartiImpr.Rows.Add(dgvCartiImpr.RowCount, titlu, autor, DateTime.Now, newDate);
                    dgvCartiImpr.Rows[dgvCartiImpr.Rows.Count - 2].DefaultCellStyle.BackColor = Color.Green;

                    for (int i = 0; i < dgvCartiImpr.RowCount; ++i)
                    {
                        if (dgvCartiImpr.Rows[i].DefaultCellStyle.BackColor == Color.Green)
                        {
                            DateTime dt = (DateTime)dgvCartiImpr[4, i].Value;
                            if (DateTime.Compare(dt, DateTime.Now) < 0 ||
                                DateTime.Compare(dt, DateTime.Now) == 0)
                            {
                                ++nrCartiFosteDisponibile;
                                dgvCartiImpr.Rows[i].DefaultCellStyle.BackColor = Color.Red;
                            }
                        }
                    }

                    pbDisponibilitate.Increment(-nrCartiFosteDisponibile + 1);
                    lblDisponibilitate.Text = $"Disponibilitate imprumuturi {pbDisponibilitate.Value}/3";
                    tabMeniu.SelectTab(1);
                }
            }

            else
                MessageBox.Show("Nu se mai pot imprumuta carti !");
        }

        private string GetAutorCarte(string titlu)
        {
            var conn = new SqlConnection(connStr);
            conn.Open();
            string query = "SELECT autor FROM carti WHERE titlu = @titlu";
            var cmd = new SqlCommand(query, conn);

            cmd.Parameters.AddWithValue("@titlu", titlu);
            var rd = cmd.ExecuteReader();
            rd.Read();

            string autor = (string)rd[0];

            rd.Close();
            conn.Close();
            conn.Dispose();
            cmd.Dispose();

            return autor;
        }

        private void InsertImprumut(int id_carte, string email, DateTime data_imprumut)
        {
            var conn = new SqlConnection(connStr);
            conn.Open();
            string query = "INSERT INTO imprumut VALUES(@id_carte, @email, @data_imprumut)";

            var cmd = new SqlCommand(query, conn);
            cmd.Parameters.AddWithValue("@id_carte", id_carte);
            cmd.Parameters.AddWithValue("@email", email);
            cmd.Parameters.AddWithValue("@data_imprumut", data_imprumut);

            cmd.ExecuteNonQuery();

            conn.Close();
            conn.Dispose();
            cmd.Dispose();
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
            conn.Dispose();
            cmd.Dispose();
            
            return id;
        }

        private void dgvCartiImpr_RowsRemoved(object sender, DataGridViewRowsRemovedEventArgs e)
        {
            for (int j = 0; j < dgvCartiImpr.RowCount - 1; ++j)
                dgvCartiImpr[0, j].Value = j + 1;
        }

        private void dgvCartiImpr_CellDoubleClick(object sender, DataGridViewCellEventArgs e)
        {
            var senderGrid = (DataGridView)sender;
            if (senderGrid.Rows[e.RowIndex].DefaultCellStyle.BackColor == Color.Red)
                MessageBox.Show("Perioada imprumutului expirata!");
            else
            {
                string titlu = (string)senderGrid[1, e.RowIndex].Value;
                int id_carte = GetIdCarte(titlu);
                AfiseazaCarteForm form = new AfiseazaCarteForm(id_carte);
                this.Visible = false;
                form.ShowDialog();
                this.Visible = true;
            }
        }
    }
}
