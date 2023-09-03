using JocEducativ.Properties;
using System;
using System.CodeDom;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Threading;
using System.Runtime.CompilerServices;
using System.Data.SqlClient;

namespace JocEducativ
{
    public partial class GhicesteForm : Form
    {
        private int n = 3, m = 9;
        private int L;
        private int cnt;
        private Button[,] letters;
        private TableLayoutPanel tbl;
        private string resPath = $@"{Directory.GetCurrentDirectory()}\..\..\csarp\";
        private List<string> words = new List<string>();
        private Random random = new Random();
        private Label[] wordLetters;
        private TableLayoutPanel wordTbl;
        private string fileName;
        private int counter;
        private int g;
        public static int punctaj;
        public GhicesteForm()
        {
            InitializeComponent();
            pbFloare.ImageLocation = $@"{Directory.GetCurrentDirectory()}\..\..\csarp\StadiiFloare\6.png";
            GetWords();
            string word = CreateLabelArray();

            CreateButtonGrid(word);
        }

        private void CreateButtonGrid(string word)
        {
            letters = new Button[n, m];
            tbl = new TableLayoutPanel()
            {
                Dock = DockStyle.Fill,
                RowCount = n,
                ColumnCount = m,
            };

            int H = panelAlfabet.Height;
            int W = panelAlfabet.Width;
            L = Math.Min(H, W) / Math.Max(n, m);
            for (int j = 0; j < m; j++)
                tbl.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, L));

            for (int i = 0; i < n; ++i)
            {
                tbl.RowStyles.Add(new RowStyle(SizeType.Percent, L));
                for (int j = 0; j < m; ++j)
                {
                    ++cnt;
                    int ascii = 96 + cnt;
                    char c = (char)ascii;
                    string str = c.ToString();
                    letters[i, j] = new Button()
                    {
                        Dock = DockStyle.Fill,
                        Margin = new Padding(1),
                        Text = str
                    };

                    tbl.Controls.Add(letters[i, j]);
                    letters[i, j].Click += async (sender, e) =>
                    {
                        Button btn = (Button)sender;
                        List<int> indexes = new List<int>();

                        if (!word.Contains(btn.Text)) ++g;

                        for (int k = 0; k < word.Length; ++k)
                        {
                            if (word[k].ToString() == btn.Text)
                            {
                                indexes.Add(k);
                                ++counter;
                            }
                        }

                        if (indexes.Count > 0)
                        {
                            foreach (int index in indexes)
                                wordLetters[index].Text = btn.Text;

                            fileName = Path.GetFileName(pbFloare.ImageLocation);
                            if (fileName != "6.png")
                            {
                                int nextImage = (int)Char.GetNumericValue(fileName[0]) + 1;
                                Repaint(nextImage);
                            }

                            if (counter == word.Length)
                            {
                                punctaj = 100 - (4 * g);
                                lblPunctaj.Text = $"Punctaj: {punctaj}";
                                DisableLetterButtons();
                                //InsereazaRezultat(0, JocEducativ.AlegeJocForm.loggedEmail, punctaj);
                                await Task.Delay(2000);
                                this.Dispose();
                            }
                        }

                        else
                        {
                            fileName = Path.GetFileName(pbFloare.ImageLocation);
                            int previousImage = (int)Char.GetNumericValue(fileName[0]) - 1;
                            if (previousImage > 1)
                                Repaint(previousImage);
                            else
                                if (previousImage == 1)
                                {
                                    Repaint(previousImage);
                                    punctaj = 0;
                                    lblPunctaj.Text = "Punctaj: 0";
                                    DisableLetterButtons();
                                    //InsereazaRezultat(0, JocEducativ.AlegeJocForm.loggedEmail, punctaj);
                                    await Task.Delay(2000);
                                    this.Dispose();
                                }
                        }

                        tbl.Controls.Remove(btn);
                    };
                }
            }

            panelAlfabet.Controls.Add(tbl);
            tbl.Controls.Remove(letters[n - 1, m - 1]);
        }

        private void DisableLetterButtons()
        {
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < m; ++j)
                    letters[i, j].Enabled = false;
        }

        private void Repaint(int image)
        {
            pbFloare.Image = Image.FromFile($@"{Directory.GetCurrentDirectory()}\..\..\csarp\StadiiFloare\{image}.png");
            pbFloare.ImageLocation = $@"{Directory.GetCurrentDirectory()}\..\..\csarp\StadiiFloare\{image}.png";
            pbFloare.Invalidate();
            pbFloare.Update();
        }

        private string CreateLabelArray()
        {
            string word = GetRandomWord();
            wordLetters = new Label[word.Length];
            wordTbl = new TableLayoutPanel()
            {
                Dock = DockStyle.Fill,
                RowCount = 1,
                ColumnCount = word.Length
            };

            int wH = panelWord.Height;
            int wW = panelWord.Width;
            L = Math.Min(wH, wW) / word.Length;

            for (int i = 0; i < word.Length; i++)
            {
                wordTbl.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, L));
                wordLetters[i] = new Label()
                {
                    Text = "_",
                    Margin = new Padding(1),
                    Font = new Font(FontFamily.GenericSansSerif, 12, FontStyle.Bold)
                };

                wordTbl.Controls.Add(wordLetters[i]);
            }

            panelWord.Controls.Add(wordTbl);
            return word;
        }

        private void GetWords()
        {
            StreamReader sr = new StreamReader(resPath + "Cuvinte.txt");
            string line;

            while ((line = sr.ReadLine()) != null)
            {
                words.Add(line);
            }
        }

        private string GetRandomWord()
        {
            int rand_poz = random.Next(0, words.Count);
            return words[rand_poz];
        }

        public static void InsereazaRezultat(int tipJoc, string email, int punctaj)
        {
            var conn = new SqlConnection(JocEducativ.AutentificareForm.connStr);
            conn.Open();
            string query = "INSERT INTO Rezultate VALUES(@tipJoc, @email, @punctaj)";

            var cmd = new SqlCommand(query, conn);
            cmd.Parameters.AddWithValue("@tipJoc", tipJoc);
            cmd.Parameters.AddWithValue("@email", email);
            cmd.Parameters.AddWithValue("@punctaj", punctaj);

            cmd.ExecuteNonQuery();

            conn.Close();
            conn.Dispose();
            cmd.Dispose();
        }
    }
}
