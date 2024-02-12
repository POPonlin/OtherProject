using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 记事本2
{
    public partial class Form2 : Form
    {
        
        public Form2()
        {
            InitializeComponent();
            
        }

        private void label2_Click(object sender, EventArgs e)
        {
            
        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void Form2_Load(object sender, EventArgs e)
        {
            radioButton2.Checked=true;//开启向下查找
        }

        private void button1_Click(object sender, EventArgs e)
        {
           // RichTextBox rbox = mainform1.RichTextBox;
            string str = this.textBox2.Text;
            if(this.checkBox1.Checked)
            {
                
            }
        }
    }
}
