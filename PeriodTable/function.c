#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
typedef struct element
{ 
	int order;
	char symbol[2];
	double AR;
	char structure[20]; 
}ele; 






void gotoxy(int x, int y) 
{ 
	COORD pos;
	pos.X = x - 1;
	pos.Y = y - 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}






void show1(ele* a,ele*b)		//第一次显示周期表 
{
	int i,j,atemp,btemp;
	printf("    1A   2A   3B   4B   5B   6B   7B        8族       1B   2B   3A   4A   5A   6A   7A   0族\n\n");  
	printf("    01   02   03   04   05   06   07   08   09   10   11   12   13   14   15   16   17   18\n");
	
	for(i=0;i<=6;i++)
	{
		printf("0%d  ",i+1);
		for(j=0;j<=17;j++)
		{
			atemp=18*i+j;
			printf("%2s   ",((*(a+atemp)).symbol));   
		}
		printf("\n");
	}

	gotoxy(15,12);
	
	for(i=0;i<=1;i++)
	{	
		for(j=0;j<=14;j++)
		{
			btemp=15*i+j;
			printf("%2s   ",((*(b+btemp)).symbol));  
		}
		printf("\n");
		gotoxy(15,13);
	}
	gotoxy(15,20);
	printf("Please push 'w','a','s','d' to move the cursor");
	gotoxy(15,21);
	printf("Please push the space key to see the information of the element");
	gotoxy(5,4);
}









void move(int x,int y,ele* a,ele*b)		//光标移动 
{
	gotoxy(x,y);
	char input; 	
	while(1)
	{
		input=getch();
		switch(input)
		{
			case'w':y=y-1;
			
					if(y>=4)
						gotoxy(x,y);
					else
						y=y+1;
					break;
			case'a':x=x-5;
					if(x>=4)
						gotoxy(x,y);
					else
						x=x+5;
					break;
			case's':y=y+1;
					if(y<=13)
						gotoxy(x,y);
					else
						y=y-1;
					break;
			case'd':x=x+5;
					if(x<=91)
						gotoxy(x,y);
					else
						x=x-5;
					break;
			case' ':switch(y)	//查看信息 
					{
						case 4:if((x!=6)&&(x!=91)) ;
								else
									{
										eledetails(x,y,a,b);
									}
								break;
						case 5:if((x>11)&&(x<65)) ;		//((x!=6)&&(x!=11)&&(x!=66)&&(x!=71)&&(x!=76)&&(x!=81)&&(x!=86)&&(x!=91)) ;
								else
									{
										eledetails(x,y,a,b);
									}
								break;
						case 6:if((x>11)&&(x<65)) ;	
								else
									{
										eledetails(x,y,a,b);
									}
								break;
						case 7:eledetails(x,y,a,b);break;
						case 8:eledetails(x,y,a,b);break;
						case 9:eledetails(x,y,a,b);break;
						case 10:eledetails(x,y,a,b);break;
						case 12:if((x>15)&&(x<87))
									details(x,y,a,b);
								break;
						case 13:if((x>15)&&(x<87))
									details(x,y,a,b);
								break;
						default: ;
					}
					break;
			default:gotoxy(x,y);
		}	
	}
} 














void eledetails(int x,int y, ele* a,ele* b)		//查看主表元素的具体信息 
{
	system("CLS");
	char input;
	int atemp;
	atemp=x/5+18*y-73; 		//计算光标位置与二维数组向量 a 的 对应关系 
	printf("Symbol: %s\n\n",(*(a+atemp)).symbol);
	printf("Atomic number: %d\n\n",(*(a+atemp)).order);
	printf("AR: %9.6lf\n\n",(*(a+atemp)).AR);
	printf("Structure: %s\n\n\n\n",(*(a+atemp)).structure);
	printf("If an element has a symbol like this '(!)',it is radioactive\nPlease push the space key to go back\n");
	input=getch(); 
	if(input==' ')
	{
		system("CLS");
		gotoxy(1,1);
		show2(a,b,x,y); 	//返回周期表 
	}
}











void details(int x,int y,ele* a,ele* b)		//查看La系，Ac系元素的具体信息 
{
	system("CLS");
	char input;
	int btemp;
	btemp=(x-16)/5+15*(y-12);		//计算光标位置与二维数组向量 b 的对应关系 
	printf("Symbol: %s\n\n",(*(b+btemp)).symbol);
	printf("Atomic number: %d\n\n",(*(b+btemp)).order);
	printf("AR: %9.6lf\n\n",(*(b+btemp)).AR);
	printf("Structure: %s\n\n\n\n",(*(b+btemp)).structure);
	printf("If an element has a symbol like this '(!)',it is radioactive\nPlease push the space key to go back\n");
	input=getch(); 
	if(input==' ')
	{
		system("CLS");
		gotoxy(1,1);
		show2(a,b,x,y);		//返回周期表 
	}
}









	
void show2(ele* a,ele*b,int x,int y)	//第二次显示周期表 
{
	int i,j,atemp,btemp;
	printf("    1A   2A   3B   4B   5B   6B   7B        8族       1B   2B   3A   4A   5A   6A   7A   0族\n\n");  
	printf("    01   02   03   04   05   06   07   08   09   10   11   12   13   14   15   16   17   18\n");
	
	for(i=0;i<=6;i++)
	{
		printf("0%d  ",i+1);
		for(j=0;j<=17;j++)
		{
			atemp=18*i+j;
			printf("%2s   ",((*(a+atemp)).symbol)); 
		}
		printf("\n");
	}
	
	gotoxy(15,12);
	for(i=0;i<=1;i++)
	{	
		for(j=0;j<=14;j++)
		{
			btemp=15*i+j;
			printf("%2s   ",((*(b+btemp)).symbol));  
		}
		printf("\n");
		gotoxy(15,13);
	}
	gotoxy(15,20);
	printf("Please push 'w','a','s','d' to move the cursor");
	gotoxy(15,21);
	printf("Please push the space key to see the information of the element");
	gotoxy(x,y);
}



