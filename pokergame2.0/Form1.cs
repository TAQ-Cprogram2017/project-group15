using System;
using System.Drawing;
using System.Collections;
using System.ComponentModel;
using System.Windows.Forms;
using System.Data;

namespace 纸牌
{
	/// <summary>
	/// Form1 的摘要说明。
	/// </summary>
	public class Form1 : System.Windows.Forms.Form
	{
		SortedList icons=new SortedList();
		private hand mhand;
		private hand yhand;
		private Button pick;
		private card wugui;
		private bool select=true;
		private System.Windows.Forms.Panel panel1;
		private System.Windows.Forms.Panel panel2;
		private System.Windows.Forms.Button ng;
		private System.Windows.Forms.Panel panel3;
		private System.Windows.Forms.Button button1;
		private System.Windows.Forms.TextBox info;
		private System.Windows.Forms.Button button2;
		private System.Windows.Forms.Button button3;
		private System.Windows.Forms.GroupBox groupBox1;
		private System.Windows.Forms.TextBox password;
		/// <summary>
		/// 必需的设计器变量。
		/// </summary>
		private System.ComponentModel.Container components = null;

		public Form1()
		{
			//
			// Windows 窗体设计器支持所必需的
			//
			InitializeComponent();

			//
			// TODO: 在 InitializeComponent 调用后添加任何构造函数代码
			//
		}

		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		protected override void Dispose( bool disposing )
		{
			if( disposing )
			{
				if (components != null) 
				{
					components.Dispose();
				}
			}
			base.Dispose( disposing );
		}

		#region Windows Form Designer generated code
		/// <summary>
		/// 设计器支持所需的方法 - 不要使用代码编辑器修改
		/// 此方法的内容。
		/// </summary>
		private void InitializeComponent()
		{
			System.Resources.ResourceManager resources = new System.Resources.ResourceManager(typeof(Form1));
			this.panel1 = new System.Windows.Forms.Panel();
			this.panel2 = new System.Windows.Forms.Panel();
			this.ng = new System.Windows.Forms.Button();
			this.panel3 = new System.Windows.Forms.Panel();
			this.button1 = new System.Windows.Forms.Button();
			this.info = new System.Windows.Forms.TextBox();
			this.button2 = new System.Windows.Forms.Button();
			this.button3 = new System.Windows.Forms.Button();
			this.groupBox1 = new System.Windows.Forms.GroupBox();
			this.password = new System.Windows.Forms.TextBox();
			this.groupBox1.SuspendLayout();
			this.SuspendLayout();
			// 
			// panel1
			// 
			this.panel1.AutoScroll = true;
			this.panel1.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("panel1.BackgroundImage")));
			this.panel1.Location = new System.Drawing.Point(88, 40);
			this.panel1.Name = "panel1";
			this.panel1.Size = new System.Drawing.Size(504, 80);
			this.panel1.TabIndex = 3;
			this.panel1.DragEnter += new System.Windows.Forms.DragEventHandler(this.panel1_DragEnter);
			this.panel1.DragDrop += new System.Windows.Forms.DragEventHandler(this.panel1_DragDrop);
			// 
			// panel2
			// 
			this.panel2.AutoScroll = true;
			this.panel2.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("panel2.BackgroundImage")));
			this.panel2.Location = new System.Drawing.Point(88, 168);
			this.panel2.Name = "panel2";
			this.panel2.Size = new System.Drawing.Size(504, 80);
			this.panel2.TabIndex = 4;
			this.panel2.DragEnter += new System.Windows.Forms.DragEventHandler(this.panel2_DragEnter);
			this.panel2.DragDrop += new System.Windows.Forms.DragEventHandler(this.panel2_DragDrop);
			// 
			// ng
			// 
			this.ng.Location = new System.Drawing.Point(32, 312);
			this.ng.Name = "ng";
			this.ng.Size = new System.Drawing.Size(40, 40);
			this.ng.TabIndex = 6;
			this.ng.Text = "New Game";
			this.ng.Click += new System.EventHandler(this.ng_Click);
			// 
			// panel3
			// 
			this.panel3.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("panel3.BackgroundImage")));
			this.panel3.Location = new System.Drawing.Point(88, 272);
			this.panel3.Name = "panel3";
			this.panel3.Size = new System.Drawing.Size(104, 80);
			this.panel3.TabIndex = 7;
			// 
			// button1
			// 
			this.button1.Location = new System.Drawing.Point(496, 136);
			this.button1.Name = "button1";
			this.button1.Size = new System.Drawing.Size(88, 24);
			this.button1.TabIndex = 8;
			this.button1.Text = "电脑取牌>>";
			this.button1.Click += new System.EventHandler(this.button1_Click);
			// 
			// info
			// 
			this.info.AutoSize = false;
			this.info.Font = new System.Drawing.Font("NSimSun", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((System.Byte)(134)));
			this.info.ForeColor = System.Drawing.Color.Red;
			this.info.Location = new System.Drawing.Point(240, 272);
			this.info.Name = "info";
			this.info.ReadOnly = true;
			this.info.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
			this.info.Size = new System.Drawing.Size(280, 80);
			this.info.TabIndex = 9;
			this.info.Text = "";
			// 
			// button2
			// 
			this.button2.Image = ((System.Drawing.Image)(resources.GetObject("button2.Image")));
			this.button2.Location = new System.Drawing.Point(24, 40);
			this.button2.Name = "button2";
			this.button2.Size = new System.Drawing.Size(56, 56);
			this.button2.TabIndex = 10;
			// 
			// button3
			// 
			this.button3.Image = ((System.Drawing.Image)(resources.GetObject("button3.Image")));
			this.button3.Location = new System.Drawing.Point(24, 168);
			this.button3.Name = "button3";
			this.button3.Size = new System.Drawing.Size(56, 56);
			this.button3.TabIndex = 11;
			// 
			// groupBox1
			// 
			this.groupBox1.Controls.Add(this.ng);
			this.groupBox1.Controls.Add(this.panel1);
			this.groupBox1.Controls.Add(this.info);
			this.groupBox1.Controls.Add(this.button3);
			this.groupBox1.Controls.Add(this.panel3);
			this.groupBox1.Controls.Add(this.button2);
			this.groupBox1.Controls.Add(this.panel2);
			this.groupBox1.Controls.Add(this.button1);
			this.groupBox1.Location = new System.Drawing.Point(8, 8);
			this.groupBox1.Name = "groupBox1";
			this.groupBox1.Size = new System.Drawing.Size(600, 392);
			this.groupBox1.TabIndex = 12;
			this.groupBox1.TabStop = false;
			this.groupBox1.Text = "抽乌龟";
			this.groupBox1.Enter += new System.EventHandler(this.groupBox1_Enter);
			// 
			// password
			// 
			this.password.Location = new System.Drawing.Point(8, 408);
			this.password.Name = "password";
			this.password.PasswordChar = '*';
			this.password.Size = new System.Drawing.Size(152, 21);
			this.password.TabIndex = 13;
			this.password.Text = "";
			this.password.TextChanged += new System.EventHandler(this.textBox1_TextChanged);
			// 
			// Form1
			// 
			this.AutoScaleBaseSize = new System.Drawing.Size(6, 14);
			this.AutoScroll = true;
			this.ClientSize = new System.Drawing.Size(632, 430);
			this.Controls.Add(this.password);
			this.Controls.Add(this.groupBox1);
			this.Name = "Form1";
			this.Text = "抽乌龟";
			this.Load += new System.EventHandler(this.Form1_Load);
			this.groupBox1.ResumeLayout(false);
			this.ResumeLayout(false);

		}
		#endregion

		/// <summary>
		/// 应用程序的主入口点。
		/// </summary>
		[STAThread]
		static void Main() 
		{
			Application.Run(new Form1());
		}

		private void Form1_Load(object sender, System.EventArgs e)
		{
			icons.Add(suit.club,Image.FromFile(@"..\..\club.ico"));
			icons.Add(suit.diamond,Image.FromFile(@"..\..\diamond.ico"));
			icons.Add(suit.heart,Image.FromFile(@"..\..\heart.ico"));
			icons.Add(suit.spade,Image.FromFile(@"..\..\spade.ico"));
			this.setup();
		//	this.groupBox1.Enabled=false;
		}

		private void ng_Click(object sender, System.EventArgs e)
		{
			this.setup();
		}
		
		private void setup()
		{
			info.Text=null;
			deck adeck=new deck();
			adeck.shuffe();
			wugui=adeck.sfd();
			panel1.Controls.Clear();
			panel2.Controls.Clear();
		
			mhand=new hand();
			yhand=new hand();
			adeck.deal(new hand[]{mhand,yhand});
			this.showhand(panel1,mhand);
			this.showhand(panel2,yhand,0);
			password.Text="";
			MessageBox.Show("乌龟已抽出","抽乌龟");
//			this.groupBox1.Enabled=false;
//			MessageBox.Show("请先输入六位密码！");
			if(mhand.Count<yhand.Count)
			{
				select=true;
				info.Text="先从电脑抽牌";
			}
			else
			{
				select=false;
				info.Text="电脑先抽你的牌";
			}
			this.password.Text=null;
		}

		private void showhand(Panel apanel,hand ahand)
		{
			apanel.Controls.Clear();
			ahand.removepairs();
			for(int i=0;i<ahand.Count;i++)
			{
				card acard=ahand[i];
				Button abutton=new Button();
				apanel.Controls.Add(abutton);
				abutton.Image=(Image)icons[acard.Suit];
				abutton.Text=acard.Val.ToString();
				abutton.TextAlign=ContentAlignment.BottomCenter;
				abutton.ImageAlign=ContentAlignment.TopCenter;
				abutton.Height=66;
				abutton.Width=37;
				abutton.FlatStyle=FlatStyle.Flat;
				abutton.Tag=acard;
				abutton.Location=new Point(45*i+10,10);
				abutton.Click+=new EventHandler(mmp); 
			}
		}

		private void mmp(object o,EventArgs e)
		{
			if(select==true)
			{
				MessageBox.Show("点击选取电脑的牌！","抽乌龟");
			}

			else
			{
				MessageBox.Show("轮到电脑选你的牌！\n点击\"电脑选牌\"");
			}
		}

		private void showhand(Panel apanel,hand ahand,int a)
		{
			apanel.Controls.Clear();
			ahand.removepairs();
			ahand.shuffe();
			for(int i=0;i<ahand.Count;i++)
			{
				card acard=ahand[i];
				Button abutton=new Button();
				apanel.Controls.Add(abutton);
			//	abutton.Image=Image.FromFile("D:\\Documents and Settings\\kamv\\My Documents\\My Pictures\\wu1.bmp");
				abutton.Height=66;
				abutton.Width=37;
				abutton.FlatStyle=FlatStyle.Flat;
				abutton.Tag=acard;
				abutton.Location=new Point(45*i+10,10);
				abutton.Click+=new EventHandler(mousedown);
			}
		}

		private void bmd(object o,MouseEventArgs e)
		{
			pick =(Button)o;
			pick.DoDragDrop(o,DragDropEffects.Move);
		}

		private void panel1_DragEnter(object sender, System.Windows.Forms.DragEventArgs e)
		{
			e.Effect=DragDropEffects.Move;
		}

		private void panel2_DragEnter(object sender, System.Windows.Forms.DragEventArgs e)
		{
			e.Effect=DragDropEffects.Move;
		}

		private void panel1_DragDrop(object sender, System.Windows.Forms.DragEventArgs e)
		{
			card thecard=(card)pick.Tag;
			if(!mhand.contains(thecard))
			{
				mhand.add(thecard);
				yhand.remove(thecard);
			}
			this.showhand(panel1,mhand);
			this.showhand(panel2,yhand);
			pick=null;
		}

		private void panel2_DragDrop(object sender, System.Windows.Forms.DragEventArgs e)
		{
			card thecard=(card)pick.Tag;
			if(!yhand.contains(thecard))
			{
				yhand.add(thecard);
				mhand.remove(thecard);
			}
			this.showhand(panel1,mhand);
			this.showhand(panel2,yhand);
			pick=null;
		}

		private void dp_Click(object sender, System.EventArgs e)
		{
			mhand.removepairs();
			yhand.removepairs();
			this.showhand(panel1,mhand);
			this.showhand(panel2,yhand,0);
		}

		private void mousedown(object o,EventArgs e)
		{
			info.Text=null;
			if(select==true)
			{
				
				Button now=(Button)o;
				card thecard=(card)now.Tag;
			
				panel3.Controls.Clear();
				if(mhand.contains(thecard.Val))
				{
					for(int i=0;i<2;i++)
					{
						Button abutton=new Button();
						panel3.Controls.Add(abutton);
						abutton.Image=(Image)icons[thecard.Suit];
						abutton.Text=thecard.Val.ToString();
						abutton.TextAlign=ContentAlignment.BottomCenter;
						abutton.ImageAlign=ContentAlignment.TopCenter;
						abutton.Height=66;
						abutton.Width=37;
						abutton.FlatStyle=FlatStyle.Flat;
						abutton.Tag=thecard;
						abutton.Location=new Point(45*i+10,10);
					}
					
					info.Text="恭喜，抽到一对牌！";
				}

				else
					info.Text="抽到乌龟！";
				yhand.remove(thecard);
				mhand.add(thecard);
				this.showhand(panel1,mhand);
				this.showhand(panel2,yhand,0);
				select=false;
				if(mhand.Count==0)
					MessageBox.Show("恭喜你\n获胜！","抽乌龟");
				else if(yhand.Count==0)
					MessageBox.Show("你输了\n电脑获胜！","抽乌龟");
			}

			else
				MessageBox.Show("现在轮到电脑取牌！","抽乌龟");
		}

		private void button1_Click(object sender, System.EventArgs e)
		{
			info.Text=null;
			if(select==false)
			{
				panel3.Controls.Clear();
				Random r=new Random();
				int i=r.Next(0,mhand.Count);
				card acard=(card)mhand[i];
				if(yhand.contains(acard.Val))
					info.Text="电脑抽走一对牌！";
				else
					info.Text="恭喜，电脑抽到乌龟！";
				mhand.remove(acard);
				yhand.add(acard);
				this.showhand(panel1,mhand);
				this.showhand(panel2,yhand,0);
				select=true;
				if(mhand.Count==0)
				{
					MessageBox.Show("恭喜你\n获胜！","抽乌龟");
					this.setup();
				}
				else if(yhand.Count==0)
				{
					MessageBox.Show("你输了\n电脑获胜！","抽乌龟");
					this.setup();
				}
				
			}

			else
				MessageBox.Show("现在请为电脑抽牌","抽乌龟");
			
		}

		private void textBox1_TextChanged(object sender, System.EventArgs e)
		{
			if(password.Text=="smile ")
				this.groupBox1.Enabled=true;
		}

		private void groupBox1_Enter(object sender, System.EventArgs e)
		{
		
		}

	}
}