using System;
using System.Collections;
using System.Windows.Forms;
namespace 纸牌
{
	/// <summary>
	/// deck 的摘要说明。
	/// </summary>
	public class deck   
	{
		private ArrayList cards=new ArrayList();    //初始化ArrayList的实例
		private int Count
		{
			get
			{
				return this.cards.Count;    //返回扑克的数量
			}
		}

		public card this[int index] //该函数用于定位扑克的位置，起到索引的功能
		{
			get
			{
				if(index>=0&&index<cards.Count)
					return (card)cards[index];
				else
				{
					MessageBox.Show("索引超出范围！");
					return null;
				}
			}
		}

		
		//完整的52张创建一副纸牌
		public deck()//初始构造函数
		{
			for(int i=0;i<13;i++)   //以扑克的数值为一组大循环A到K
			{
				for(int j=0;j<4;j++)    //以扑克的类型为小循环  例如红桃类型
				{
					card acard=new card((suit)j,(val)i);    //创建扑克实例
					this.cards.Add(acard);                  //创建一张扑克，我就在被ArrayList定义的cards中添加一张
				}
			}
		}

		public deck(int vval)//创建有限数量的纸牌，制定面值，花色齐全    同时也是一个构造函数
		{
			for(int i=0;i<vval;i++)
			{
				for(int j=0;j<4;j++)
				{
					card acard=new card((suit)j,(val)i);
					this.cards.Add(acard);
				}
			}
		}



		public void shuffe()//洗牌
		{
			Random ran=new Random();  //让电脑进行随机的操作
			ArrayList vcards=new ArrayList();
			while(cards.Count>0)
			{
				card acard=(card)cards[ran.Next(0,cards.Count)];//洗好的扑克类型强行转化赋值给acard
				vcards.Add(acard);//添加一张洗过的扑克
				cards.Remove(acard);//添加之后  就把那张牌删除掉  已经没有用了
			}
			
			cards=vcards;
		}

		public void deal(hand[] hands)//轮流给两个人发牌
		{
			for(int i=0;i<cards.Count;i++)
			{
				hands[i%2].add((card)this[i]);//以循环队列的形式使得两个人可以循环发牌
			}
		}

		public card draw()//抽牌
		{
			if(this.cards.Count>0)//前提是有牌
			{
				card acard=(card)this.cards[0];//会从第一张陈列出来
				this.cards.Remove(acard);//讲选中的移除掉
				return acard;
			}
			else
			{
				MessageBox.Show("没有牌存在");
				return null;
			}
		}

		public  card sfd()//匹配牌
		{
			Random ran=new Random();
			int i=ran.Next(0,52);
			card thecard=(card)this.cards[i];//当前这张牌跟其他牌数值一样的话
			this.cards.RemoveAt(i);//就给它移除掉
			return thecard;
		}

		
	}
}
