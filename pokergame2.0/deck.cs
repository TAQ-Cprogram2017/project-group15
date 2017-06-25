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
		private ArrayList cards=new ArrayList();    //��ʼ��ArrayList��ʵ��
		private int Count
		{
			get
			{
				return this.cards.Count;    //�����˿˵�����
			}
		}

		public card this[int index] //�ú������ڶ�λ�˿˵�λ�ã��������Ĺ���
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
		public deck()//��ʼ���캯��
		{
			for(int i=0;i<13;i++)   //���˿˵���ֵΪһ���ѭ��A��K
			{
				for(int j=0;j<4;j++)    //���˿˵�����ΪСѭ��  �����������
				{
					card acard=new card((suit)j,(val)i);    //�����˿�ʵ��
					this.cards.Add(acard);                  //����һ���˿ˣ��Ҿ��ڱ�ArrayList�����cards�����һ��
				}
			}
		}

		public deck(int vval)//��������������ֽ�ƣ��ƶ���ֵ����ɫ��ȫ    ͬʱҲ��һ�����캯��
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



		public void shuffe()//ϴ��
		{
			Random ran=new Random();  //�õ��Խ�������Ĳ���
			ArrayList vcards=new ArrayList();
			while(cards.Count>0)
			{
				card acard=(card)cards[ran.Next(0,cards.Count)];//ϴ�õ��˿�����ǿ��ת����ֵ��acard
				vcards.Add(acard);//���һ��ϴ�����˿�
				cards.Remove(acard);//���֮��  �Ͱ�������ɾ����  �Ѿ�û������
			}
			
			cards=vcards;
		}

		public void deal(hand[] hands)//�����������˷���
		{
			for(int i=0;i<cards.Count;i++)
			{
				hands[i%2].add((card)this[i]);//��ѭ�����е���ʽʹ�������˿���ѭ������
			}
		}

		public card draw()//����
		{
			if(this.cards.Count>0)//ǰ��������
			{
				card acard=(card)this.cards[0];//��ӵ�һ�ų��г���
				this.cards.Remove(acard);//��ѡ�е��Ƴ���
				return acard;
			}
			else
			{
				MessageBox.Show("û���ƴ���");
				return null;
			}
		}

		public  card sfd()//ƥ����
		{
			Random ran=new Random();
			int i=ran.Next(0,52);
			card thecard=(card)this.cards[i];//��ǰ�����Ƹ���������ֵһ���Ļ�
			this.cards.RemoveAt(i);//�͸����Ƴ���
			return thecard;
		}

		
	}
}
