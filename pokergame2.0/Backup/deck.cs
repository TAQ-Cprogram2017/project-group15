using System;
using System.Collections;
using System.Windows.Forms;
namespace ֽ��
{
	/// <summary>
	/// deck ��ժҪ˵����
	/// </summary>
	public class deck
	{
		private ArrayList cards=new ArrayList();
		private int Count
		{
			get
			{
				return this.cards.Count;
			}
		}

		public card this[int index]
		{
			get
			{
				if(index>=0&&index<cards.Count)
					return (card)cards[index];
				else
				{
					MessageBox.Show("����������Χ��");
					return null;
				}
			}
		}

		
		//������52�Ŵ���һ��ֽ��
		public deck()
		{
			for(int i=0;i<13;i++)
			{
				for(int j=0;j<4;j++)
				{
					card acard=new card((suit)j,(val)i);
					this.cards.Add(acard);
				}
			}
		}

		public deck(int vval)//��������������ֽ�ƣ��ƶ���ֵ����ɫ��ȫ
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

		public void deal(hand[] hands)//�����������˷���
		{
			for(int i=0;i<cards.Count;i++)
			{
				hands[i%2].add((card)this[i]);
			}
		}

		public card draw()
		{
			if(this.cards.Count>0)
			{
				card acard=(card)this.cards[0];
				this.cards.Remove(acard);
				return acard;
			}
			else
			{
				MessageBox.Show("û���ƴ���");
				return null;
			}
		}

		public  card sfd()
		{
			Random ran=new Random();
			int i=ran.Next(0,52);
			card thecard=(card)this.cards[i];
			this.cards.RemoveAt(i);
			return thecard;
		}

		
	}
}
