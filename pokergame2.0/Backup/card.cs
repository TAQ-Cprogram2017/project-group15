using System;

namespace 纸牌
{
	/// <summary>
	/// card 的摘要说明。
	/// </summary>
	/// 
	public enum suit
	{
		heart,
		diamond,
		spade,
		club
	}

	public enum val
	{
		//A,TWO,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE,TEN,J,Q,K
		A,II,III,IV,V,VI,VII,IIX,IX,X,J,Q,K
	}
	public class card
	{
		private suit suit;
		
		private val val;
		
		public suit Suit
		{
			get
			{
				return this.suit;
			}
		}

		public val Val
		{
			get
			{
				return this.val;
			}
		}

		public card(suit asuit,val aval)
		{
			this.suit=asuit;
			this.val=aval;
		}

		public card()
		{
			this.suit=suit.heart;
			this.val=val.A;
		}
	}
}
