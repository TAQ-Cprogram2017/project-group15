#include<iostream>
using namespace std;
#include"poker.cpp"
#include"分牌.cpp"
#include"显示牌.cpp"
#include"消牌.cpp"
#include"打乱和前推.cpp"
#include"循环抽牌.cpp"
#include"判断.cpp"
#include"图像显示.cpp"
void jiaohuanshoupai(int e[],int m,int n){
	int x,y,temp;
	x=m;
	y=n;
	temp=e[x];
	e[x]=e[y];
	e[y]=temp;
}
int main(){
	int sum1=0,sum2=0,sum3=0;
	int z;/*判断动图循环的次数和大循环是否继续，游戏是否继续*/
	//system("COLOR 7c");

	tuxiang();/*显示图像*/
	cout<<"          请输入您的名字进入游戏：";
	char name[10]={0};
	cin>>name;
	cin.get();
	system("cls");

	cout<<"				【怀念经典】"<<endl;
	cout<<"				   抽乌龟"<<endl;
	cout<<"    欢迎 "<<name<<" 来到4071的纸牌屋~(≧▽≦)/~"<<endl;
	cout<<"    只要抽对方的牌，抽到一对可以打出去，最后看谁还剩下牌，这个就是乌龟牌。"<<endl;
	cout<<"    这个游戏能够勾起不少人童年的回忆，这是多数人小时候经常玩的一种牌。"<<endl;
	cout<<"			               _...._"<<endl;
	cout<<"			         .-~~/~ \\__/ ~\\~~."<<endl;
	cout<<"			        /_/``\\__/  \\__/``\\_\\.---."<<endl;
	cout<<"			       /~ \\__/  \\__/  \\__/  \\   o`."<<endl;
	cout<<"			   '==/\\__/__\\__/__\\__/__\\__/~`'--'"<<endl;
	cout<<"			       /__/__/^^^^^^\\__\\_\\ "<<endl<<endl;
	cout<<"			                 ENTER→"<<endl;
		cin.sync();
		cin.clear(0);
	cin.get();
	system("cls");

	cout<<"				【游戏说明】"<<endl;
	cout<<"  ★游戏采用一副牌，共计52 张牌"<<endl;
	cout<<"  ★系统随机抽走一张牌作为乌龟牌"<<endl;
	cout<<"  ★开局时三名玩家（两位为电脑AI）随机分配手牌，其中每人17张牌"<<endl;
	cout<<"  ★发牌后系统自动将三名玩家手牌中的对牌消除"<<endl;
	cout<<"  ★游戏开始时开始进行轮流抽牌，每个回合只能抽取对方一次牌"<<endl;
	cout<<"  ★抽到的牌组成一对时系统会自动消除（无需判定花色）"<<endl;
	cout<<"  ★所有的对牌抽完后，仅剩的最后一张牌所在的一方失败，此游戏没有和局（积分第一名30分，第二名10分，第三名0分）"<<endl<<endl;	
	cin.get();
	system("cls");
	do{
	z=0;
	int e[52]={0}, N=52;
	int a[17]={0},b[17]={0},c[17]={0},n=17,m=17,o=17;/*数组a为玩家，数组b为AL1，数组c为玩家3*/
	int q;/*玩家抽取的牌*/
	int x,y;/*玩家交换自己的手牌*/
	int first=0,second=0;/*第一名第二名*/
	char panduan;/*判断玩家是否换牌*/
	cout<<"准备好了吗~~~游戏开始了哟"<<endl;
	cin.get();
	pokerprepare(e,N);/*生产随机顺序的52张牌*/
	fenpai(e,a,b,c);/*分给3个数组*/
	xianshi(a,n,name,m,o);/*显示玩家牌组*/
	xiaopai(a,n);/*初始消牌*/
	qiantui(a,&n);/*重排并计算牌数*/
	xiaopai(b,m);
	qiantui(b,&m);
	xiaopai(c,o);
	qiantui(c,&o);
	system("pause");
	system("cls");

	while(1){
		do{/*玩家循环抽牌，并做保护*/
		system("cls");
		cin.sync();
		cin.clear(0);
	xianshi(a,n,name,m,o);
	cout<<endl<<"请输入要抽取AI1的第几张牌【1-"<<m<<"】：";
	cin>>q;
	if(q>=1&&q<=m)
		break;
	else {cout<<"请重新输入";
	_sleep(1*500);}
		}
		while(1);
	take(a,&n,b,&m,q);/*用函数抽AI1的牌，并做重排*/
	if(first=firstvictory(n,m,o)) break;/*做第一名判断*/
	system("cls");
	xianshi(a,n,name,m,o);/*显示玩家的手牌，看拿到什么牌*/	
	xiaopai(a,n);/*消去相同的牌*/
	qiantui(a,&n);/*前推重算牌数*/
	do{/*交换手牌和保护*/
		system("cls");
		cin.sync();
		cin.clear(0);
		xianshi(a,n,name,m,o);
		cout<<endl<<"是否交换手牌 "<<endl;
		cout<<"换牌输入Y/y"<<endl<<"不换牌输入N/n"<<endl;
		cin.get(panduan);
		if(panduan=='N'||panduan=='n') break;
		if(panduan=='Y'||panduan=='y') {
			do{
		system("cls");
		cin.sync();
		cin.clear(0);
		xianshi(a,n,name,m,o);
		cout<<"请输入需要交换的牌(请输入1到"<<n<<")"<<endl;
		cin>>x;
		cin>>y;
		if(x>=1&&x<=n&&y>=1&&y<=n) {jiaohuanshoupai(a,x-1,y-1);break;}
		else cout<<"请重新输入"<<endl;
		_sleep(1*500);
			}
		while(1);
		}
		else cout<<"请重新输入"<<endl;
		_sleep(1*500);
		}
		while(1);
	if(first=firstvictory(n,m,o)) break;/*做第一名判断*/
	taken(b,&m,c,&o);/*AI1抽AI2的牌*/
	if(first=firstvictory(n,m,o)) break;
	xiaopai(b,m);
	qiantui(b,&m);
	if(first=firstvictory(n,m,o)) break;
	cin.get();
	system("cls");
	xianshi(a,n,name,m,o);
	taken(c,&o,a,&n);/*AI2抽玩家的牌*/
	if(first=firstvictory(n,m,o)) break;
	xiaopai(c,o);
	qiantui(b,&m);
	if(first=firstvictory(n,m,o)) break;
	qiantui(c,&o);
	if(first=firstvictory(n,m,o)) break;
	daluan (b,m);/*打乱牌组*/
	daluan (c,o);
	cin.get();
	system("cls");
	}
	system("cls");

	while(1){/*第二名判断*/
		switch(first){
		case(1) :/*第一名为玩家，然后牌少的AI为第二*/
			if(m<=n) second=2;
			else second=3;
			break;
		case(2):/*玩家与AI对抽*/
			xianshi(a,n,name,m,o);
			taken(c,&o,a,&n);
			if(n==0){ second=1; break;}
			xiaopai(c,o);
			qiantui(c,&o);
			if(o==0){ second=3; break;}
			daluan(c,o);
			do{
		system("cls");
		cin.sync();
		cin.clear(0);
	xianshi(a,n,name,m,o);
	cout<<endl<<"请输入要抽取AI2的第几张牌【1-"<<o<<"】：";
	cin>>q;
	if(q>=1&&q<=o)
		break;
	else {cout<<"请重新输入"<<endl;
	_sleep(1*500);}
		}
		while(1);
	take(a,&n,c,&o,q);
	if(o==0){ second=3; break;}
	system("cls");
	xianshi(a,n,name,m,o);	
	xiaopai(a,n);
	qiantui(a,&n);
	if(n==0) {second=1;
	break;}
	daluan(a,n);
	do{
		system("cls");
		cin.sync();
		cin.clear(0);
		xianshi(a,n,name,m,o);
		cout<<endl<<"是否交换手牌 "<<endl;
		cout<<"换牌输入Y/y"<<endl<<"不换牌输入N/n"<<endl;
		cin.get(panduan);
		if(panduan=='N'||panduan=='n') break;
		if(panduan=='Y'||panduan=='y') {
			do{
		system("cls");
		cin.sync();
		cin.clear(0);
		xianshi(a,n,name,m,o);
		cout<<"请输入需要交换的牌(请输入1到"<<n<<")"<<endl;
		cin>>x;
		cin>>y;
		if(x>=1&&x<=n&&y>=1&&y<=n) {jiaohuanshoupai(a,x-1,y-1);break;}
		else cout<<"请重新输入"<<endl;
		_sleep(1*500);
			}
		while(1);
		}
		else cout<<"请重新输入"<<endl;
		_sleep(1*500);
		}
		while(1);
	break;
		case(3):
			do{
		system("cls");
		cin.sync();
		cin.clear(0);
	xianshi(a,n,name,m,o);
	cout<<endl<<"请输入要抽取A11的第几张牌【1-"<<m<<"】：";
	cin>>q;
	if(m>=1&&q<=m)
		break;
	else {cout<<"请重新输入"<<endl;
			_sleep(1*500);}
		}
		while(1);
	take(a,&n,b,&m,q);
	if(m==0){ second=2; break;}
	system("cls");
	xianshi(a,n,name,m,o);	
	cin.get();;
	xiaopai(a,n);
	qiantui(a,&n);
	if(n==0){
		second=1;
		break;
	}
		daluan(a,n);
		do{
		system("cls");
		cin.sync();
		cin.clear(0);
		xianshi(a,n,name,m,o);
		cout<<endl<<"是否交换手牌 "<<endl;
		cout<<"换牌输入Y/y"<<endl<<"不换牌输入N/n"<<endl;
		cin.get(panduan);
		if(panduan=='N'||panduan=='n') break;
		if(panduan=='Y'||panduan=='y') {
			do{
		system("cls");
		cin.sync();
		cin.clear(0);
		xianshi(a,n,name,m,o);
		cout<<"请输入需要交换的牌(请输入1到"<<n<<")"<<endl;
		cin>>x;
		cin>>y;
		if(x>=1&&x<=n&&y>=1&&y<=n) {jiaohuanshoupai(a,x-1,y-1);break;}
		else cout<<"请重新输入"<<endl;
		_sleep(1*500);
			}
		while(1);
		}
		else cout<<"请重新输入"<<endl;
		_sleep(1*500);
		}
		while(1);
		system("cls");
		xianshi(a,n,name,m,o);
		cin.get();;
		taken(b,&m,a,&n);
		if(n==0){ second=1; break;}
		xiaopai(b,m);
		qiantui(b,&m);
		if(m==0) {second=2;
		break;}
		daluan(b,m);
		break;
		default:break;}
		if(second!=0) break;
	}
		system("cls");
		while(z<=8){/*闪屏动图和出现本局的排名*/
		cout<<"乌龟牌是"<<endl;
		danpai(e[51]);/*显示乌龟*/
		switch(first){/*显示第一第二*/
		case(1):cout<<name<<" 第一名"<<endl;sum1+=30;break;
		case(2):cout<<"AI1 第一名"<<endl;sum2+=30;break;
		case(3):cout<<"AI2 第一名"<<endl;sum3+=30;break;
		default:break;
		}
		switch(second){
		case(1):cout<<name<<" 第二名"<<endl;sum1+=10;break;
		case(2):cout<<"AI1 第二名"<<endl;sum2+=10;break;
		case(3):cout<<"AI2 第二名"<<endl;sum3+=10;break;
		default:break;}
	cout<<"			               _...._"<<endl;
	cout<<"			         .-~~/~ |__/ ~|~~."<<endl;
	cout<<"			        /_/``|__/  |__/``|_|.---."<<endl;
	cout<<"			       /~ |__/  |__/  |__/  |   o`."<<endl;
	cout<<"			   '==/|__/__|__/__|__/__|__/~`'--'"<<endl;
	cout<<"			       /__|__|^^^^^^|__|_\\ "<<endl<<endl;
	_sleep(1*250);
	system("cls");
		cout<<"乌龟牌是"<<endl;
		danpai(e[51]);/*显示乌龟*/
		switch(first){/*显示第一第二*/
		case(1):cout<<name<<" 第一名"<<endl;sum1;break;
		case(2):cout<<"AI1 第一名"<<endl;sum2;break;
		case(3):cout<<"AI2 第一名"<<endl;sum3;break;
		default:break;
		}
		switch(second){
		case(1):cout<<name<<" 第二名"<<endl;sum1;break;
		case(2):cout<<"AI1 第二名"<<endl;sum2;break;
		case(3):cout<<"AI2 第二名"<<endl;sum3;break;
		default:break;}
	cout<<"			               _...._"<<endl;
	cout<<"			         .-~~/~ |__/ ~|~~."<<endl;
	cout<<"			        /_/``|__/  |__/``|_|.---."<<endl;
	cout<<"			       /~ |__/  |__/  |__/  |   -`."<<endl;
	cout<<"			    ==/|__/__|__/__|__/__|__/~`'--'"<<endl;
	cout<<"			   '   |__/__/^^^^^^\\__\\_| "<<endl<<endl;
	_sleep(1*250);
	z++;
	system("cls");
		}
		switch(first){/*显示第一第二并计算积分*/
		case(1):cout<<name<<" 第一名"<<endl;sum1+=30;break;
		case(2):cout<<"AI1 第一名"<<endl;sum2+=30;break;
		case(3):cout<<"AI2 第一名"<<endl;sum3+=30;break;
		default:break;
		}
		switch(second){
		case(1):cout<<name<<" 第二名"<<endl;sum1+=10;break;
		case(2):cout<<"AI1 第二名"<<endl;sum2+=10;break;
		case(3):cout<<"AI2 第二名"<<endl;sum3+=10;break;
		default:break;}
		z=0;
		cout<<"玩家积分为"<<sum1<<endl;
		cout<<"AI1积分为"<<sum2<<endl;
		cout<<"AI2积分为"<<sum3<<endl;
		system("pause");
		do{
		system("cls");
		cin.sync();
		cin.clear(0);
		cout<<"请问是否继续游戏~~~啦啦啦（y/Y继续，n/N退出）"<<endl;
		cin.get(panduan);
		if(panduan=='N'||panduan=='n') {z=0 ;break;}
		if(panduan=='Y'||panduan=='y') {z=1;break;}
		else cout<<"请重新输入"<<endl;
		_sleep(1*500);
			}
		while(1);
		system("cls");}
		while(z==1);
		if(sum1>=sum2&&sum1>=sum3) cout<<"玩家胜";
		else if(sum2>=sum1&&sum2>=sum3) cout<<"AI1胜,别灰心继续努力！！！";
		else if(sum3>=sum1&&sum3>=sum1) cout<<"AI2胜，别灰心继续努力！！！！";
	return 0;
	}

