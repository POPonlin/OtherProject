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

namespace 记事本2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        string filename = string.Empty;
        public Form1(string filename)
        {
            InitializeComponent();
            if(filename!=null)
            {
                this.filename=filename;
                OpenFile();
            }
        }
        protected void OpenFile()
        {
            try
            {
                richTextBox1.Clear();
                richTextBox1.Text = File.ReadAllText(filename);
            }
            catch
            { MessageBox.Show("Error!"); }
        }

        private void menuStrip2_ItemClicked(object sender, ToolStripItemClickedEventArgs e)
        {
         

        }

        private void 打开ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            //OpenFileDialog ofd = new OpenFileDialog();
            //ofd.Title="请选择要打开的文本文件";
            //ofd.InitialDirectory=@"C:\Users\胡桃单推人\Desktop";
            //ofd.Multiselect=true;
            //ofd.Filter="文本文件|*.txt|所有文件|*.*";
            //ofd.ShowDialog();

            //string path = ofd.FileName;
            //if (path=="")
            //{
            //    return;
            //}
            //using (FileStream fsRead = new FileStream(path, FileMode.OpenOrCreate, FileAccess.Read))
            //{
            //    byte[] buffer = new byte[1024*1024*5];
            //    int r = fsRead.Read(buffer, 0, buffer.Length);
            //    textBox1.Text=Encoding.Default.GetString(buffer, 0, r);
            //}
            OpenFileDialog openFileDialog = new OpenFileDialog();
            if (openFileDialog.ShowDialog() == DialogResult.OK)
            {
                filename = openFileDialog.FileName;
                OpenFile();
            }


        }

        private void 新建ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (richTextBox1.Modified==true)
            {
                DialogResult dr = MessageBox.Show("是否要将更改内容保存", "记事本", MessageBoxButtons.YesNoCancel);
                if(dr==DialogResult.Yes)
                {
                    保存ToolStripMenuItem_Click(sender,e);
                    return;
                }
                else if(dr==DialogResult.Cancel)
                {
                    return;
                }
                richTextBox1.Clear();
                this.Text="新建-记事本";
            }
            else
            {
                richTextBox1.Clear();
                this.Text="新建-记事本";
            }
        }

        private void 保存ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            try
            {
                StreamWriter sw = File.AppendText(Application.ExecutablePath);
                sw.Write(richTextBox1.Text);
                sw.Dispose();
            }
            catch
            {
                SaveFileDialog sfd = new SaveFileDialog();
                sfd.DefaultExt="*.txt";//设置默认格式
                sfd.Filter="文本文件|*.txt|所有文件|*.*";
                if(sfd.ShowDialog()==DialogResult.OK)
                {
                    StreamWriter sw = File.AppendText(sfd.FileName);
                    sw.Write(richTextBox1.Text);
                    sw.Dispose();
                }
            }
        }

        private void 另存为ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            string name;
            SaveFileDialog save = new SaveFileDialog();
            save.Filter = "*.txt|*.TXT|(*.*)|*.*";
            if (save.ShowDialog() == DialogResult.OK)
            {
                name = save.FileName;
                FileInfo info = new FileInfo(name);
                StreamWriter writer = info.CreateText();
                writer.Write(richTextBox1.Text);
                writer.Close();
            }
        }

        private void 退出ToolStripMenuItem_Click(object sender, EventArgs e)
        {
          
            if (richTextBox1.Modified==true)
            {
                DialogResult dr = MessageBox.Show("是否要将更改内容保存", "记事本", MessageBoxButtons.YesNoCancel);
                if (dr==DialogResult.Yes)
                {
                    保存ToolStripMenuItem_Click(sender, e);
                    return;
                }
                else if (dr==DialogResult.Cancel)
                {
                    return;
                }

                Test._frm1.Close();
                
            }
            else
            {
                Test._frm1.Close();
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            Test._frm1=this;
        }

        private void 新建窗口ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Form1 fm = new Form1();
            fm.Show();
        }

        private void 文件ToolStripMenuItem_Click(object sender, EventArgs e)
        {

        }

        private void toolStripStatusLabel1_Click(object sender, EventArgs e)
        {
            

        }

        private void textBox1_Click(object sender, EventArgs e)
        {
           

        }

        private void textBox1_KeyUp(object sender, KeyEventArgs e)
        {
            

        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            toolStripStatusLabel1.Text = "共" +  richTextBox1.Text.Length.ToString() + "个字符";
           // int line = textBox1.GetLineFromCharIndex(textBox1.Text.Length);//得到总行数
            int index = richTextBox1.GetFirstCharIndexOfCurrentLine();//得到当前行第一个字符的索引
            int line = richTextBox1.GetLineFromCharIndex(index) + 1;//得到当前行的行号
            int col = richTextBox1.SelectionStart - index + 1;//.SelectionStart得到光标所在位置的索引 - 当前行第一个字符的索引 = 光标所在的列数
            toolStripStatusLabel2.Text = "第" + line + "行，第" + col + "列";
        }

        private void 状态栏ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if(状态栏ToolStripMenuItem.Checked==true)
            {
                状态栏ToolStripMenuItem.Checked=false;
                statusStrip1.Visible=false;
            }
            else
            {
                状态栏ToolStripMenuItem.Checked=true;
                statusStrip1.Visible=true;
            }
        }

        private void 自动换行ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if(自动换行ToolStripMenuItem.Checked==true)
            {
                自动换行ToolStripMenuItem.Checked=false;
                richTextBox1.WordWrap=false;
            }
            else
            {
                自动换行ToolStripMenuItem.Checked=true;
                richTextBox1.WordWrap=true;
            }
        }

        private void 撤销ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (richTextBox1.CanUndo)
            {
                richTextBox1.Undo();
                richTextBox1.ClearUndo();
            }
        }

        private void 剪切ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            richTextBox1.Cut();
        }

        private void 粘贴ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            richTextBox1.Paste();
        }

        private void 复制ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            richTextBox1.Copy();
        }

        private void 删除ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            richTextBox1.SelectedText=string.Empty;
        }

        private void 全选ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (richTextBox1.Text != string.Empty)
                richTextBox1.SelectAll();
        }

        private void 字体ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            //FontDialog fontDialog = new FontDialog();
            //if (fontDialog.ShowDialog() == DialogResult.OK)
            //{
            //    textBox1.Font = fontDialog.Font;
            //}
            FontDialog fontDialog = new FontDialog();
            
            if (fontDialog.ShowDialog() == DialogResult.OK)
            {
                richTextBox1.Font = fontDialog.Font;
            }


        }

        private void 时间字体ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            richTextBox1.AppendText(DateTime.Now.ToString());        //DateTime.Now.ToString();
        }

        private void 查找ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            
        }

        private void 编辑ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (richTextBox1.SelectedText==String.Empty)
            {
                剪切ToolStripMenuItem.Enabled=false;
                复制ToolStripMenuItem.Enabled=false;
                删除ToolStripMenuItem.Enabled=false;

            }
            else
            {
                剪切ToolStripMenuItem.Enabled=true;
                复制ToolStripMenuItem.Enabled=true;
                删除ToolStripMenuItem.Enabled=true;
            }
            if (richTextBox1.Text==String.Empty)
            {
                查找ToolStripMenuItem.Enabled=false;
                撤销ToolStripMenuItem.Enabled=false;
                查找下一个ToolStripMenuItem.Enabled=false;
                查找上一个ToolStripMenuItem.Enabled=false;
                替换ToolStripMenuItem.Enabled=false;
            }
            else
            {
                查找ToolStripMenuItem.Enabled=true;
                撤销ToolStripMenuItem.Enabled=true;
                查找下一个ToolStripMenuItem.Enabled=true;
                查找上一个ToolStripMenuItem.Enabled=true;
                替换ToolStripMenuItem.Enabled=true;
            }
        }

        private void 查找下一个ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            down.Checked = true;
            upward.Checked = false;
            try
            {
                FindWords(word);
            }
            catch
            {
                查找ToolStripMenuItem_Click(sender, e);
            }

        }

        private void 查找上一个ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            upward.Checked = true;
            down.Checked = false;
            try
            {
                FindWordsLast(word);
            }
            catch
            {
                查找ToolStripMenuItem_Click(sender, e);
            }

        }

        private void 替换ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            //Form2 fm2 = new Form2();
            //fm2.Show();
            txtInput.Size = new Size(190, 30);
            txtInput.Location = new Point(70, 12);
            txtInput.Multiline = true;

            txtInputReplace.Size = new Size(190, 30);
            txtInputReplace.Location = new Point(70, 47);
            txtInputReplace.Multiline = true;

            Button Replace = new Button
            {
                Name = "btnReplace",
                Text = "替换",
                Size = new Size(80, 25),
                Location = new Point(265, 15)
            };
            Replace.Click += new EventHandler(Replace_Click);
            Cancel.Click += new EventHandler(Cancel_Click);

            ReplaceForm.Controls.Add(lblSearch);
            ReplaceForm.Controls.Add(LblReplace);
            ReplaceForm.Controls.Add(txtInput);
            ReplaceForm.Controls.Add(txtInputReplace);
            ReplaceForm.Controls.Add(Replace);
            ReplaceForm.Controls.Add(Cancel);
            ReplaceForm.Top = this.Top + 50;
            ReplaceForm.Left = this.Left + 50;
            ReplaceForm.Height = 140;
            ReplaceForm.Width = 380;
            ReplaceForm.StartPosition = FormStartPosition.CenterParent;
            ReplaceForm.ShowDialog();

        }

        private void 转到ToolStripMenuItem_Click(object sender, EventArgs e)
        {

        }

        private void 放大ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            var size = richTextBox1.Font.Size;
            var family = richTextBox1.Font.FontFamily;
            richTextBox1.Font=new Font(family, size+1);
        }

        private void 缩小ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            var size = richTextBox1.Font.Size;
            var family = richTextBox1.Font.FontFamily;
            richTextBox1.Font=new Font(family, size-1);
        }

        private void 恢复默认ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            //richTextBox1.Font = new Font(richTextBox1.Font.FontFamily, 9);
        }
        TextBox txtInput = new TextBox()
        {
            Font = new Font("宋体", 10)
        };
        TextBox txtInputReplace = new TextBox()
        {
            Font = new Font("宋体", 10)
        };
        Label lblSearch = new Label
        {
            Text = "查找内容：",
            Size = new Size(65, 25),
            Location = new Point(5, 22)
        };
        Label lblDirection = new Label
        {
            Text = "查找方向：",
            Size = new Size(65, 25),
            Location = new Point(5, 58)
        };
        Button FindNext = new Button
        {
            Name = "btnFindNext",
            Text = "查找下一项",
            Size = new Size(80, 25),
            Location = new Point(265, 15)
        };
        Button Cancel = new Button
        {
            Name = "btnCancel",
            Text = "取消",
            Size = new Size(80, 25),
            Location = new Point(265, 50)
        };
        RadioButton down = new RadioButton
        {
            Name = "radDown",
            Text = "向下",
            Size = new Size(55, 25),
            Location = new Point(70, 53),
            Checked = true
        };
        RadioButton upward = new RadioButton
        {
            Name = "radUpward",
            Text = "向上",
            Size = new Size(55, 25),
            Location = new Point(140, 53),
            Checked = false
        };
        new Form FindForm = new Form
        {
            Text = "查找文本",
            FormBorderStyle = FormBorderStyle.FixedSingle,
            MaximizeBox = false,
            MinimizeBox = false
        };

        private void 查找ToolStripMenuItem_Click_1(object sender, EventArgs e)
        {
            txtInput.Size = new Size(190, 33);
            txtInput.Location = new Point(70, 15);
            txtInput.Multiline = true;

            FindNext.Click += new EventHandler(Direction_Click);
            //FindNext.Click += new EventHandler(Visible_Click);

            Cancel.Click += new EventHandler(Cancel_Click);

            FindForm.Controls.Add(lblSearch);
            FindForm.Controls.Add(lblDirection);
            FindForm.Controls.Add(txtInput);
            FindForm.Controls.Add(down);
            FindForm.Controls.Add(upward);
            FindForm.Controls.Add(FindNext);
            FindForm.Controls.Add(Cancel);
            FindForm.Top = this.Top + 50;
            FindForm.Left = this.Left + 50;
            FindForm.Height = 120;
            FindForm.Width = 380;
            FindForm.StartPosition = FormStartPosition.CenterParent;
            FindForm.ShowDialog();

        }
        private void Visible_Click(object sender, EventArgs e)
        {
            FindForm.Visible = false;
        }
        private void Cancel_Click(object sender, EventArgs e)
        {
            //关闭对话框
            FindForm.Close();
            ReplaceForm.Close();
        }
        private void Direction_Click(object sender, EventArgs e)
        {
            //选择字符查找方向
            if (down.Checked == true)
            {
                Find_Click(sender, e);
            }
            else if (upward.Checked == true)
            {
                FindLast_Click(sender, e);
            }
        }
        int nextPosition, firstPosition;
        string word;
        Boolean IF = false;
        private void Find_Click(object sender, EventArgs e)
        {
            richTextBox1.Focus();
            FindWords(txtInput.Text);
        }
        private void FindWords(string words)
        {
            //向下查找字符
            if (nextPosition >=  richTextBox1.Text.Length)
                nextPosition = 0;
            firstPosition =  richTextBox1.Text.IndexOf(words, nextPosition);
            if (firstPosition == -1)
                nextPosition = 0;
            else
            {
                richTextBox1.Select(firstPosition, words.Length);
                nextPosition = firstPosition + 1;
            }
            word = words;
            IF = true;
        }
        private void FindLast_Click(object sender, EventArgs e)
        {
            richTextBox1.Focus();
            FindWordsLast(txtInput.Text);
        }
        private void FindWordsLast(string words)
        {
            //向上查找字符
            if (IF == false)
                nextPosition =  richTextBox1.Text.Length;
            if (nextPosition < 0)
                nextPosition = richTextBox1.Text.Length;

            firstPosition =  richTextBox1.Text.LastIndexOf(words, nextPosition);

            if (firstPosition == -1)
                nextPosition =  richTextBox1.Text.Length;
            else
            {
                richTextBox1.Select(firstPosition, words.Length);
                nextPosition = firstPosition - 1;
            }
            word = words;
            IF = true;
        }
        Label LblReplace = new Label
        {
            Name = "lblReplace",
            Text = "替换：",
            Size = new Size(55, 25),
            Location = new Point(15, 50)
        };
        Form ReplaceForm = new Form
        {
            Text = "替换文本",
            FormBorderStyle = FormBorderStyle.FixedSingle,
            MaximizeBox = false,
            MinimizeBox = false
        };

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            
            if (richTextBox1.Modified==true)
            {
                DialogResult dr = MessageBox.Show("内容以发生改变，是否保存", "注意", MessageBoxButtons.YesNoCancel); 
               if(dr==DialogResult.Yes)
                {
                    保存ToolStripMenuItem_Click(sender, e);
                    return;
                }
                else if(dr==DialogResult.No)
                 {
                    return;
                 }
                 else if(dr==DialogResult.Cancel)
                 {
                    e.Cancel=true;
                 }
            }
            
        }

        private void Replace_Click(object sender, EventArgs e)
        {
            richTextBox1.Text =  richTextBox1.Text.Replace(txtInput.Text, txtInputReplace.Text);
        }


    }
}
