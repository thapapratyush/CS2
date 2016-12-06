/*
LAB 8
Today's lab is to complete the C# forms appliation that we began on Tuesday.

Form1.cs file here:
*/

using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.IO;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
 
namespace LogIn
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
 
        private void textBox1_TextChanged(object sender, EventArgs e)
        {
 
        }
 
        private void textBox2_TextChanged(object sender, EventArgs e)
        {
 
        }
 
        private void label1_Click(object sender, EventArgs e)
        { 
        }
 
        private void button1_Click(object sender, EventArgs e)
        {
            this.Close();
        }
 
        private void button2_Click(object sender, EventArgs e)
        {
            string[] lines = System.IO.File.ReadAllLines(@"C:\Users\student.TELECOM06\Documents\Visual Studio 2012\Projects\LogIn\infile.txt");
            MessageBox.Show(lines[0]);
            //if (textuName.Text == username && textPW.Text == password)
            //{
            MessageBox.Show("You are now logged in");
            //    
            //    MainMenu ss = new MainMenu();
            //    ss.Show();
            //}
            //else {
            //    MessageBox.Show("Login failed");
            //}
            this.Hide(); 
        }
    }
}
