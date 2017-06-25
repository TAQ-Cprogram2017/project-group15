using System;
using System.Collections;
using System.Windows.Forms;
namespace ֽ��
{
	/// <summary>
	/// hand ��ժҪ˵����
	/// </summary>
	public class hand//����
	{
		private ArrayList cards=new ArrayList();
		public hand()//��ʼ���캯�� ��  ����Ҫ��ʲô����
		{
			
		}

		public hand(card[] thecards)//���캯��
		{
			this.cards.AddRange(thecards);	
		}

		public card this[int index]//��λѡ���������
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
		
		public int Count//�����Ƶ�����
		{
			get
			{
				return this.cards.Count;
			}
		}

		public void add(card newcard)//���ѡ���Ƹ����е����޷�ƥ��  �ͼ��뵱ǰ�����ƵĶ���
		{
			this.cards.Add(newcard);
		}

		public bool contains(card thecard)//��ǰ������
		{
			return cards.Contains(thecard);
		}

		public bool contains(val aval)//����������
		{
			for(int i=0;i<cards.Count;i++)
			{
				card acard=(card)this[i];
				if(acard.Val==aval)
					return true;
			}

			return false;
		}

		public bool contains(suit asuit,val aval)//ƥ��ѡ���ƺ�������
		{
			for(int i=0;i<cards.Count;i++)
			{
				card acard=(card)this[i];
				if(acard.Suit==asuit&&acard.Val==aval)
					return true;
			}

			return false;
		}

		public void remove(suit asuit,val aval)//ƥ��ɹ��Ļ�  ���Ƴ�������
		{
			card acard=new card(asuit,aval);
			for(int i=0;i<cards.Count;i++)
			{
				if(acard.Suit==asuit&&acard.Val==aval)
					cards.Remove(acard);
				return;
			}

			MessageBox.Show("�޴���");
		}

		public void remove(card acard)//�Ƴ������е���
		{
			if(this.contains(acard))
				this.cards.Remove(acard);
			else
				MessageBox.Show("�޴���");
		}

		public void removepairs()//ɸѡ������Ե���
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

		public void shuffe()//һ�ֽ������е���  Ҫϴ��
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
