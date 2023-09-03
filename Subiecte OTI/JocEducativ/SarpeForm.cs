using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Windows.Input;
using System.Diagnostics;
using System.Data.SqlClient;

namespace JocEducativ
{
    public partial class SarpeForm : Form
    {
        private List<Circle> Snake = new List<Circle>();
        private Circle food = new Circle();

        private int maxWidth;
        private int maxHeight;
        public static int score;

        private Random random = new Random();

        public static bool goRight;
        public static bool goDown;
        public static bool goLeft;
        public static bool goUp;

        private bool isStarted;
        public static Timer timer = new Timer();

        public SarpeForm()
        {
            InitializeComponent();

            timer.Interval = 70;
            timer.Tick += GameTimerEvent;
            btnStopSarpe.Enabled = false;
            new Settings();
        }

        private void KeyIsDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.A && Settings.directions != "right" && this.Focused == true)
            {
                goLeft = true;  
            }

            if (e.KeyCode == Keys.D && Settings.directions != "left" && this.Focused == true)
            {
                goRight = true;
            }

            if (e.KeyCode == Keys.Z && Settings.directions != "up" && this.Focused == true)
            {
                goDown = true;
            }

            if (e.KeyCode == Keys.W && Settings.directions != "down" && this.Focused == true)
            {
                goUp = true;
            }
        }

        private void KeyIsUp(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.A)
            {
                goLeft = false;
            }

            if (e.KeyCode == Keys.D)
            {
                goRight = false;
            }

            if (e.KeyCode == Keys.Z)
            {
                goDown = false;
            }

            if (e.KeyCode == Keys.W)
            {
                goUp = false;
            }
        }

        private void StartGame(object sender, EventArgs e)
        {
            isStarted = true;
            RestartGame();
        }

        private void StopGame(object sender, EventArgs e)
        {
            GameOver();
        }

        private void GameTimerEvent(object sender, EventArgs e)
        {
            if (goLeft)
            {
                Settings.directions = "left";
            }

            if (goRight)
            {
                Settings.directions = "right";
            }

            if (goDown)
            {
                Settings.directions = "down";
            }

            if (goUp)
            {
                Settings.directions = "up";
            }

            for (int i = Snake.Count - 1; i >= 0; --i)
            {
                if (i == 0)
                {
                    switch (Settings.directions)
                    {
                        case "left":
                            Snake[i].X--;
                            break;
                        case "right":
                            Snake[i].X++;
                            break;
                        case "down":
                            Snake[i].Y++;
                            break;
                        case "up":
                            Snake[i].Y--;
                            break;
                    }

                    if (Snake[i].X < 0 || Snake[i].X > maxWidth ||
                        Snake[i].Y < 0 || Snake[i].Y > maxHeight)
                    {
                        GameOver();
                    }

                    if (Snake[i].X == food.X && Snake[i].Y == food.Y)
                    {
                        EatFood();
                        timer.Stop();
                        this.Visible = false;
                        Intrebare intrebareForm = new Intrebare();
                        intrebareForm.ShowDialog();
                        this.Visible = true;
                        lblSarpe.Text = "Punctaj: " + score;
                    }

                    for (int j = 1; j < Snake.Count; ++j)
                    {
                        if (Snake[i].X == Snake[j].X && Snake[i].Y == Snake[j].Y && Snake.Count > 2)
                        {
                            GameOver();
                        }
                    }
                }

                else
                {
                    Snake[i].X = Snake[i - 1].X;
                    Snake[i].Y = Snake[i - 1].Y;
                }
            }

            pbJocSarpe.Invalidate();
        }

        private void UpdatePictureBoxGraphics(object sender, PaintEventArgs e)
        {
            Graphics canvas = e.Graphics;

            Brush snakeColor;

            for (int i = 0; i < Snake.Count; ++i)
            {
                if (i == 0)
                {
                    snakeColor = Brushes.White;
                }
                else
                {
                    snakeColor = Brushes.Green;
                }


                canvas.FillEllipse(snakeColor, new Rectangle(Snake[i].X * Settings.Width, Snake[i].Y * Settings.Height, Settings.Width, Settings.Height));
            }

            if (isStarted == true)
                canvas.FillEllipse(Brushes.Red, new Rectangle(food.X * Settings.Width, food.Y * Settings.Height, Settings.Width, Settings.Height));
        }

        private void RestartGame()
        {
            Settings.directions = "down";

            maxWidth = pbJocSarpe.Width / Settings.Width - 1;
            maxHeight = pbJocSarpe.Height / Settings.Height - 1;

            Snake.Clear();

            btnStartSarpe.Enabled = false;
            btnStopSarpe.Enabled = true;
            this.Focus();

            score = 0;
            lblSarpe.Text = "Punctaj: " + score;

            Circle head = new Circle
            {
                X = random.Next(2, maxWidth),
                Y = random.Next(2, maxHeight / 2)
            };

            Snake.Add(head);

            food = new Circle
            {
                X = random.Next(2, maxWidth),
                Y = random.Next(maxHeight / 2 + 1, maxHeight)
            };

            timer.Start();
        }

        private void EatFood()
        {
            score += 10;

            lblSarpe.Text = "Punctaj: " + score;

            Circle body = new Circle
            {
                X = Snake[Snake.Count - 1].X,   
                Y = Snake[Snake.Count - 1].Y
            };

            Snake.Add(body);

            food = new Circle
            {
                X = random.Next(2, maxWidth),
                Y = random.Next(2, maxHeight)
            };
        }

        private void GameOver()
        {
            goLeft = false;
            goUp = false;
            goRight = false;
            goDown = false;

            this.Dispose();
        }
    }
}
