using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 图片查看器
{
    public partial class Form1 : Form
    {
        private int ImageCount;

        private  List<string> ImagePaths = new List<string>();
        //static string pictureFile;
        private int nowCount = 0;
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            pictureBox1.SizeMode=PictureBoxSizeMode.Zoom;

        }
    
        public  void button6_Click(object sender, EventArgs e)
        {
            nowCount = 0;
            if (this.openFileDialog1.ShowDialog()==DialogResult.OK)
              {
                 toolStripTextBox1.Text=this.openFileDialog1.FileName;
                 pictureBox1.SizeMode=PictureBoxSizeMode.Zoom;
                    
                 pictureBox1.Image=Image.FromFile(toolStripTextBox1.Text);
                
                if(ImagePaths.Count !=0)
                {                                    
                    ImagePaths.Clear();                    
                    pictureBox1.Image = null;
                }
               foreach(string Path in Directory.GetFiles(Path.GetDirectoryName(openFileDialog1.FileName)))
                {
                    ImagePaths.Add(Path);
                }
               if(ImagePaths.Count != 0)
                {
                    ImageCount = ImagePaths.Count;
                    pictureBox1.Image = Bitmap.FromFile(ImagePaths[nowCount]);
                    textBox1.Text = "1";
                }

               
            }
        }
        private void button2_Click(object sender, EventArgs e)
        {
            try
            {
                nowCount++;
                  if (nowCount==ImageCount)
                {
                    nowCount=0;
                    textBox1.Text=Convert.ToString(nowCount + 1);
                    this.pictureBox1.Image=Bitmap.FromFile(ImagePaths[nowCount]);
                }
                //if (nowCount<ImageCount)
                //{
                    
                    this.pictureBox1.Image=Bitmap.FromFile(ImagePaths[nowCount]);
                    
                    //nowCount++;
                    textBox1.Text=Convert.ToString(nowCount + 1);
            }
            catch
            {
                MessageBox.Show("未选择路径", "提示", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }


        private void pictureBox1_Click(object sender, EventArgs e)
        {

        }

        private void pictureBox1_MouseEnter(object sender, EventArgs e)
        {
            //pictureBox1.Focus();
        }
        private void pictureBox1_MouseWheel(object sender, MouseEventArgs e)
        {

        }
        
        private void button3_Click(object sender, EventArgs e)
        {
            pictureBox1.Width = (int)(pictureBox1.Width * 1.1);
            pictureBox1.Height = (int)(pictureBox1.Height * 1.1);
        }

        private void button4_Click(object sender, EventArgs e)
        {
            pictureBox1.Width = (int)(pictureBox1.Width * 0.9);
            pictureBox1.Height = (int)(pictureBox1.Height * 0.9);
        }
         public static bool FilePicDlete(string path1)
        {
            bool ret = false;
            System.IO.FileInfo file = new System.IO.FileInfo(path1);
            if(file.Exists)
            {
                file.Delete();
                ret=true;
            }
            return ret;
        }
        private void button5_Click(object sender, EventArgs e)
        {
            Image.FromFile(ImagePaths[nowCount]).Dispose();
            pictureBox1.Image=null;
            File.Delete(ImagePaths[nowCount]);
        }
       
    }
}
