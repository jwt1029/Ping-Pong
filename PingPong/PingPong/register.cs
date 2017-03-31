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
    public partial class register : Form
    {
        private const string IP = "10.156.145.184";
        private const int PORT = 9999;

        public register()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            // 회원가입 요청
            string id = textBox1.Text;
            string password = textBox2.Text;
            string username = textBox4.Text;

            JObject json = new JObject();
            json.Add("type", "register");
            json.Add("id", id);
            json.Add("password", password);
            json.Add("username", username);

            sendJson(json.ToString());
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
                    recStr = recStr.Trim();
                    recStr = recStr.Replace("\r\n", "");
                    JObject json = JObject.Parse(recStr);
                    string status = (string)json["status"];

                    Console.WriteLine(recStr);
                    Console.WriteLine(status);



                    sender.Shutdown(SocketShutdown.Both);
                    sender.Close();

                    if (status == "200")
                    {
                        // 회원가입에 성공하면
                        Form1 lom = new Form1();
                        this.Hide();
                        lom.Show();
                    }
                    else
                    {
                        MessageBox.Show("회원가입에 실패하였습니다.");
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

        private void register_Load(object sender, EventArgs e)
        {

        }

        private void label4_Click(object sender, EventArgs e)
        {

        }

        private void textBox4_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
