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
    public partial class Intrebare : Form
    {
        private int qCount;
        private Random rand = new Random();

        private string enuntItem;
        private string raspuns1;
        private string raspuns2;
        private string raspuns3;
        private int raspunsCorect;
        private int punctajItem;
        private string correctAnswer;
        private List<Tuple<string, string, string, string, int, int>> cols = new List<Tuple<string, string, string, string, int, int>>();

        private const int CP_NOCLOSE_BUTTON = 0x200;
        public Intrebare()
        {
            InitializeComponent();
            btnInregistreaza.Enabled = false;
            SelectQuestions();

            DisplayQuestion();
        }

        private void DisplayQuestion()
        {
            int randNum = rand.Next(qCount);

            enuntItem = cols[randNum].Item1;
            raspuns1 = cols[randNum].Item2;
            raspuns2 = cols[randNum].Item3;
            raspuns3 = cols[randNum].Item4;
            raspunsCorect = cols[randNum].Item5;
            punctajItem = cols[randNum].Item6;

            rtbIntrebare.Text = enuntItem;
            rbA.Text = raspuns1;
            rbB.Text = raspuns2;
            rbC.Text = raspuns3;
        }

        private void Intrebare_FormClosed(object sender, FormClosedEventArgs e)
        {
            JocEducativ.SarpeForm.timer.Start();
        }

        private void SelectQuestions()
        {
            var conn = new SqlConnection(AutentificareForm.connStr);
            conn.Open();
            string query = "SELECT * FROM Itemi";

            var cmd = new SqlCommand(query, conn);

            var rd = cmd.ExecuteReader();
            while (rd.Read())
            {
                qCount++;
                enuntItem = rd.GetString(1);
                raspuns1 = rd.GetString(2);
                raspuns2 = rd.GetString(3);
                raspuns3 = rd.GetString(4);
                raspunsCorect = rd.GetInt32(5);
                punctajItem = rd.GetInt32(6);

                cols.Add(new Tuple<string, string, string, string, int, int>(
                    enuntItem, raspuns1, raspuns2, raspuns3, raspunsCorect, punctajItem));
            }

            conn.Close();
            conn.Dispose();
            cmd.Dispose();
            rd.Close();
        }

        private void rtbIntrebare_KeyUp(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.W) SarpeForm.goUp = false;
            if (e.KeyCode == Keys.D) SarpeForm.goRight = false;
            if (e.KeyCode == Keys.Z) SarpeForm.goDown = false;
            if (e.KeyCode == Keys.A) SarpeForm.goLeft = false;
        }

        private void rbA_KeyUp(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.W) SarpeForm.goUp = false;
            if (e.KeyCode == Keys.D) SarpeForm.goRight = false;
            if (e.KeyCode == Keys.Z) SarpeForm.goDown = false;
            if (e.KeyCode == Keys.A) SarpeForm.goLeft = false;
        }

        private void btnInregistreaza_Click(object sender, EventArgs e)
        {
            switch(raspunsCorect)
            {
                case 1:
                    correctAnswer = rbA.Text;
                    break;
                case 2:
                    correctAnswer = rbB.Text;
                    break;
                case 3:
                    correctAnswer = rbC.Text;
                    break;
            }

            var checkedButton = this.Controls.OfType<RadioButton>().FirstOrDefault(r => r.Checked);
            if (checkedButton.Text == correctAnswer)
            {
                if (MessageBox.Show("Felicitari, ai raspuns corect!") == DialogResult.OK)
                {
                    SarpeForm.score += punctajItem;
                    this.Dispose();
                }
            }
            else
            {
                if (MessageBox.Show($"Raspunsul tau este gresit! Raspunsul corect este {correctAnswer}") == DialogResult.OK)
                    this.Dispose();
            }

        }

        private void rbA_Click(object sender, EventArgs e)
        {
            btnInregistreaza.Enabled = true;
        }

        private void btnInregistreaza_KeyUp(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.W) SarpeForm.goUp = false;
            if (e.KeyCode == Keys.D) SarpeForm.goRight = false;
            if (e.KeyCode == Keys.Z) SarpeForm.goDown = false;
            if (e.KeyCode == Keys.A) SarpeForm.goLeft = false;
        }

        protected override CreateParams CreateParams
        {
            get
            {
                CreateParams cp = base.CreateParams;
                cp.ClassStyle = cp.ClassStyle | CP_NOCLOSE_BUTTON;
                return cp;
            }
        }
    }
}
