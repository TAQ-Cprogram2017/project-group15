using System;
using System.Collections;
using System.Windows.Forms;
namespace 纸牌
{
	/// <summary>
	/// hand 的摘要说明。
	/// </summary>
	public class hand
	{
		private ArrayList cards=new ArrayList();
		public hand()
		{
			
		}

		public hand(card[] thecards)
		{
			this.cards.AddRange(thecards);	
		}

		public card this[int index]
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
		
		public int Count
		{
			get
			{
				return this.cards.Count;
			}
		}

		public void add(card newcard)
		{
			this.cards.Add(newcard);
		}

		public bool contains(card thecard)
		{
			return cards.Contains(thecard);
		}

		public bool contains(val aval)
		{
			for(int i=0;i<cards.Count;i++)
			{
				card acard=(card)this[i];
				if(acard.Val==aval)
					return true;
			}

			return false;
		}

		public bool contains(suit asuit,val aval)
		{
			for(int i=0;i<cards.Count;i++)
			{
				card acard=(card)this[i];
				if(acard.Suit==asuit&&acard.Val==aval)
					return true;
			}

			return false;
		}

		public void remove(suit asuit,val aval)
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

		public void remove(card acard)
		{
			if(this.contains(acard))
				this.cards.Remove(acard);
			else
				MessageBox.Show("无此牌");
		}

		public void removepairs()
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

		public void shuffe()
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
