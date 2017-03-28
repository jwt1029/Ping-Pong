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
    delegate void callbackDel(string res);

    public partial class room : Form
    {
        private const string IP = "10.156.145.184";
        private const int PORT = 9999;


        private static void createRoomCallback(string res)
        {
            //this.Hide();
            // room2 rm2 = new room2();
            // rm2.Show();
        }

        callbackDel CreateRoomCallBack = new callbackDel(createRoomCallback);

        private string id;
        public string passId
        {
            get { return this.id; }
            set { this.id = value; }
        }

        public room()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            // 방 생성 요청
            string id = passId;

            JObject json = new JObject();
            json.Add("type", "createRoom");
            json.Add("id", id);

            sendJson(json.ToString());
        }

        private JObject getRoom()
        {
            JObject result = null;
            JObject paramJson = new JObject();
            paramJson.Add("type", "getRoomList");
            result = sendJson(paramJson.ToString());
            return result;
        }

        private void addRoomBox(JObject roomList)
        {
            JArray items = (JArray)roomList["list"];
            GroupBox[] boxList = new GroupBox[items.Count];
            for(int i = 0; i < items.Count; i++)
            {
                boxList[i] = new GroupBox();
                boxList[i].Location = new Point(0, i * 20);
                boxList[i].Size = new Size(100, 10);
                boxList[i].Name = "DText" + i.ToString();
                boxList[i].TabIndex = i;
                boxList[i].Click += new EventHandler(enterRoom);
                this.Controls.Add(boxList[i]);
            }
        }

        private void enterRoom (object sender, EventArgs e)
        {
            JObject paramJson = new JObject();
            paramJson.Add("type", "enterRoom");
            sendJson(paramJson.ToString());
        }

        private JObject sendJson(String data)
        {
            Console.WriteLine(data);
            JObject json = null;
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
                    var recStr = System.Text.Encoding.Default.GetString(bytes);
                    Console.WriteLine(recStr);

                    recStr = recStr.Trim();
                    recStr = recStr.Replace("\r\n", "");
                    json = JObject.Parse(recStr);
                    string status = (string)json["status"];

                    sender.Shutdown(SocketShutdown.Both);
                    sender.Close();

                    return json;
                }
                catch (Exception e)
                {
                    return json;
                }
            }
            catch (Exception e)
            {
                return json;
            }
        }
    }
}
