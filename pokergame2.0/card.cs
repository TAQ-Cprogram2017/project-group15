using System;

namespace 纸牌
{
	/// <summary>
	/// card 的摘要说明。
	/// </summary>
	/// 
	public enum suit //扑克定义了四种类型
	{
		heart,  //红桃
		diamond,    //方片
		spade,  //黑桃
		club    //梅花
	}

	public enum val
	{
		//A,TWO,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE,TEN,J,Q,K
		A,II,III,IV,V,VI,VII,IIX,IX,X,J,Q,K     //定义了一组扑克的数字
	}
	public class card
	{
        //一张扑克具备两种属性：扑克类型和扑克的数值  都是私有的
		private suit suit;
		
		private val val;
		
		public suit Suit
		{
			get
			{
				return this.suit;   //返回扑克的类型值
			}
		}

		public val Val
		{
			get
			{
				return this.val;    //返回扑克的数值
			}
		}

		public card(suit asuit,val aval) //构造函数  与本类同名 起到一个赋值的功能
		{
			this.suit=asuit;
			this.val=aval;
		}

		public card() //初始构造函数 本函数默认的是红桃A为第一张牌  所以从红桃A开始
		{
			this.suit=suit.heart;
			this.val=val.A;
		}
	}
}
