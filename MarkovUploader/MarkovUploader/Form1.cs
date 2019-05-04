using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using System.Runtime.InteropServices;

namespace MarkovUploader
{
    public partial class Form1 : Form
    {
       
        String markov = "";
        [DllImport("C:\\Users\\Diana Contreras\\source\\repos\\MarkovDll\\Debug\\MarkovDll.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern char run(String sInp);
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            String sInp = textBox1.Text;
            char output = run(sInp);
            if (output == 'Y')
            {
                
                label1.Text = "Markov Chain file has been generated in your Desktop!";
            }
            
        }
        
        private void label2_Click(object sender, EventArgs e)
        {
           
        }
    }
}
