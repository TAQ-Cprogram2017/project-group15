using System;

namespace ֽ��
{
	/// <summary>
	/// card ��ժҪ˵����
	/// </summary>
	/// 
	public enum suit //�˿˶�������������
	{
		heart,  //����
		diamond,    //��Ƭ
		spade,  //����
		club    //÷��
	}

	public enum val
	{
		//A,TWO,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE,TEN,J,Q,K
		A,II,III,IV,V,VI,VII,IIX,IX,X,J,Q,K     //������һ���˿˵�����
	}
	public class card
	{
        //һ���˿˾߱��������ԣ��˿����ͺ��˿˵���ֵ  ����˽�е�
		private suit suit;
		
		private val val;
		
		public suit Suit
		{
			get
			{
				return this.suit;   //�����˿˵�����ֵ
			}
		}

		public val Val
		{
			get
			{
				return this.val;    //�����˿˵���ֵ
			}
		}

		public card(suit asuit,val aval) //���캯��  �뱾��ͬ�� ��һ����ֵ�Ĺ���
		{
			this.suit=asuit;
			this.val=aval;
		}

		public card() //��ʼ���캯�� ������Ĭ�ϵ��Ǻ���AΪ��һ����  ���ԴӺ���A��ʼ
		{
			this.suit=suit.heart;
			this.val=val.A;
		}
	}
}
