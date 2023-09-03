using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace JocEducativ
{
    class Settings
    {
        public static int Width { get; set; }
        public static int Height { get; set; }
        public static string directions;
        
        public Settings()
        {
            Width = 20;
            Height = 20;
            directions = "down";
        }
    }
}
