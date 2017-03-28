using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Net.Sockets;
using System.Net;
using Newtonsoft.Json.Linq;

namespace PingPong
{
    public partial class Form1 : Form
    {
        private const string IP = "10.156.145.184";
        private const int PORT = 9999;

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            string id = textBox1.Text;
            string password = textBox2.Text;

            JObject json = new JObject();
            json.Add("type", "login");
            json.Add("id", id);
            json.Add("password",password);

            sendJson(json.ToString());

            this.Hide();
            //room.show();
        }

        private void linkLabel2_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            // 회원가입
            register regiForm = new register();
            this.Hide();
            regiForm.Show();

  
        }

        private void sendJson(String data)
        {
            Console.WriteLine(data);
            try
            {
                Console.WriteLine(data);
                IPAddress ipAdress = IPAddress.Parse(IP);
                IPEndPoint remoteEP = new IPEndPoint(ipAdress, PORT);
                Socket sender = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
                byte[] bytes = new byte[1024];

                try
                {

                    sender.Connect(remoteEP);
                    byte[] msg = Encoding.ASCII.GetBytes(data);
                    int bytesSent = sender.Send(msg);
                    int bytesRec = sender.Receive(bytes);
                    string input = textBox1.Text;
                    var recStr = System.Text.Encoding.Default.GetString(bytes);
                    Console.WriteLine(recStr);

                    recStr = recStr.Trim();
                    recStr = recStr.Replace("\r\n", "");
                    JObject json = JObject.Parse(recStr);
                    string status = (string)json["status"];

                    sender.Shutdown(SocketShutdown.Both);
                    sender.Close();

                    if (status == "200")
                    {
                        // 로그인에 성공하면
                        room rm = new room();
                        rm.passId = textBox1.Text;
                        this.Hide();
                        rm.Show();
                    } else
                    {
                        MessageBox.Show("로그인 정보가 잘못되었습니다.");
                    }

                }
                catch (Exception e)
                {

                }
            }
            catch (Exception e)
            {

            }
        }



    }
}
