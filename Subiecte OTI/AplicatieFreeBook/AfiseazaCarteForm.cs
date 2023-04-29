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
using System.Drawing.Printing;
using System.Linq.Expressions;
using System.Drawing.Drawing2D;
using System.Security.Policy;
using System.Net;
using System.Drawing.Imaging;
using System.Runtime.InteropServices;

namespace AplicatieFreeBook
{
    [ComVisible(true)]
    public partial class AfiseazaCarteForm : Form
    {
        private string connStr = @"Data Source=(LocalDB)\MSSQLLocalDB;AttachDbFilename=|DataDirectory|\FreeBook.mdf;Integrated Security=True";
        private string pathToPdfFile = $@"{Directory.GetCurrentDirectory()}\..\..\csarp\cartipdf\";

        public AfiseazaCarteForm(int id)
        {
            InitializeComponent();
            pathToPdfFile += $"{id}.pdf";

            webCarti.IsWebBrowserContextMenuEnabled = false;
            webCarti.Navigate(pathToPdfFile, false);
        }
    }
}
