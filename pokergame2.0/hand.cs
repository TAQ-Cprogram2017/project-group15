using System;
using System.Collections;
using System.Windows.Forms;
namespace 纸牌
{
	/// <summary>
	/// hand 的摘要说明。
	/// </summary>
	public class hand//传牌
	{
		private ArrayList cards=new ArrayList();
		public hand()//初始构造函数 空  不需要有什么操作
		{
			
		}

		public hand(card[] thecards)//构造函数
		{
			this.cards.AddRange(thecards);	
		}

		public card this[int index]//定位选择的哪张牌
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
		
		public int Count//手中牌的数量
		{
			get
			{
				return this.cards.Count;
			}
		}

		public void add(card newcard)//如果选的牌跟手中的牌无法匹配  就加入当前手中牌的队列
		{
			this.cards.Add(newcard);
		}

		public bool contains(card thecard)//当前手中牌
		{
			return cards.Contains(thecard);
		}

		public bool contains(val aval)//便利手中牌
		{
			for(int i=0;i<cards.Count;i++)
			{
				card acard=(card)this[i];
				if(acard.Val==aval)
					return true;
			}

			return false;
		}

		public bool contains(suit asuit,val aval)//匹配选定牌和手中牌
		{
			for(int i=0;i<cards.Count;i++)
			{
				card acard=(card)this[i];
				if(acard.Suit==asuit&&acard.Val==aval)
					return true;
			}

			return false;
		}

		public void remove(suit asuit,val aval)//匹配成功的话  就移除手中牌
		{
			card acard=new card(asuit,aval);
			for(int i=0;i<cards.Count;i++)
			{
				if(acard.Suit==asuit&&acard.Val==aval)
					cards.Remove(acard);
				return;
			}

			MessageBox.Show("无此牌");
		}

		public void remove(card acard)//移除对手中的牌
		{
			if(this.contains(acard))
				this.cards.Remove(acard);
			else
				MessageBox.Show("无此牌");
		}

		public void removepairs()//筛选手中配对的牌
        {
			int i=0;
			bool same;
			while(i<this.Count-1)
			{
				card acard=this[i];
				same=false;
				for(int j=i+1;j<this.Count;j++)
				{
					card bcard=this[j];
					if(/*acard.Suit==bcard.Suit&&*/bcard.Val==acard.Val)
					{
						cards.Remove(acard);
						cards.Remove(bcard);
						same=true;
						break;
					}
				}
				if(!same)
					i++;
			}
		}

		public void shuffe()//一轮结束手中的牌  要洗牌
		{
			Random ran=new Random();
			ArrayList vcards=new ArrayList();
			while(cards.Count>0)
			{
				card acard=(card)cards[ran.Next(0,cards.Count)];
				vcards.Add(acard);
				cards.Remove(acard);
			}
			
			cards=vcards;
		}
	}
}
