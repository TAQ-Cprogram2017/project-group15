#include<iostream>
using namespace std;
#include"poker.cpp"
#include"����.cpp"
#include"��ʾ��.cpp"
#include"����.cpp"
#include"���Һ�ǰ��.cpp"
#include"ѭ������.cpp"
#include"�ж�.cpp"
#include"ͼ����ʾ.cpp"
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
	int z;/*�ж϶�ͼѭ���Ĵ����ʹ�ѭ���Ƿ��������Ϸ�Ƿ����*/
	//system("COLOR 7c");

	tuxiang();/*��ʾͼ��*/
	cout<<"          �������������ֽ�����Ϸ��";
	char name[10]={0};
	cin>>name;
	cin.get();
	system("cls");

	cout<<"				������䡿"<<endl;
	cout<<"				   ���ڹ�"<<endl;
	cout<<"    ��ӭ "<<name<<" ����4071��ֽ����~(�R���Q)/~"<<endl;
	cout<<"    ֻҪ��Է����ƣ��鵽һ�Կ��Դ��ȥ�����˭��ʣ���ƣ���������ڹ��ơ�"<<endl;
	cout<<"    �����Ϸ�ܹ���������ͯ��Ļ��䣬���Ƕ�����Сʱ�򾭳����һ���ơ�"<<endl;
	cout<<"			               _...._"<<endl;
	cout<<"			         .-~~/~ \\__/ ~\\~~."<<endl;
	cout<<"			        /_/``\\__/  \\__/``\\_\\.---."<<endl;
	cout<<"			       /~ \\__/  \\__/  \\__/  \\   o`."<<endl;
	cout<<"			   '==/\\__/__\\__/__\\__/__\\__/~`'--'"<<endl;
	cout<<"			       /__/__/^^^^^^\\__\\_\\ "<<endl<<endl;
	cout<<"			                 ENTER��"<<endl;
		cin.sync();
		cin.clear(0);
	cin.get();
	system("cls");

	cout<<"				����Ϸ˵����"<<endl;
	cout<<"  ����Ϸ����һ���ƣ�����52 ����"<<endl;
	cout<<"  ��ϵͳ�������һ������Ϊ�ڹ���"<<endl;
	cout<<"  �￪��ʱ������ң���λΪ����AI������������ƣ�����ÿ��17����"<<endl;
	cout<<"  �﷢�ƺ�ϵͳ�Զ���������������еĶ�������"<<endl;
	cout<<"  ����Ϸ��ʼʱ��ʼ�����������ƣ�ÿ���غ�ֻ�ܳ�ȡ�Է�һ����"<<endl;
	cout<<"  ��鵽�������һ��ʱϵͳ���Զ������������ж���ɫ��"<<endl;
	cout<<"  �����еĶ��Ƴ���󣬽�ʣ�����һ�������ڵ�һ��ʧ�ܣ�����Ϸû�к;֣����ֵ�һ��30�֣��ڶ���10�֣�������0�֣�"<<endl<<endl;	
	cin.get();
	system("cls");
	do{
	z=0;
	int e[52]={0}, N=52;
	int a[17]={0},b[17]={0},c[17]={0},n=17,m=17,o=17;/*����aΪ��ң�����bΪAL1������cΪ���3*/
	int q;/*��ҳ�ȡ����*/
	int x,y;/*��ҽ����Լ�������*/
	int first=0,second=0;/*��һ���ڶ���*/
	char panduan;/*�ж�����Ƿ���*/
	cout<<"׼��������~~~��Ϸ��ʼ��Ӵ"<<endl;
	cin.get();
	pokerprepare(e,N);/*�������˳���52����*/
	fenpai(e,a,b,c);/*�ָ�3������*/
	xianshi(a,n,name,m,o);/*��ʾ�������*/
	xiaopai(a,n);/*��ʼ����*/
	qiantui(a,&n);/*���Ų���������*/
	xiaopai(b,m);
	qiantui(b,&m);
	xiaopai(c,o);
	qiantui(c,&o);
	system("pause");
	system("cls");

	while(1){
		do{/*���ѭ�����ƣ���������*/
		system("cls");
		cin.sync();
		cin.clear(0);
	xianshi(a,n,name,m,o);
	cout<<endl<<"������Ҫ��ȡAI1�ĵڼ����ơ�1-"<<m<<"����";
	cin>>q;
	if(q>=1&&q<=m)
		break;
	else {cout<<"����������";
	_sleep(1*500);}
		}
		while(1);
	take(a,&n,b,&m,q);/*�ú�����AI1���ƣ���������*/
	if(first=firstvictory(n,m,o)) break;/*����һ���ж�*/
	system("cls");
	xianshi(a,n,name,m,o);/*��ʾ��ҵ����ƣ����õ�ʲô��*/	
	xiaopai(a,n);/*��ȥ��ͬ����*/
	qiantui(a,&n);/*ǰ����������*/
	do{/*�������ƺͱ���*/
		system("cls");
		cin.sync();
		cin.clear(0);
		xianshi(a,n,name,m,o);
		cout<<endl<<"�Ƿ񽻻����� "<<endl;
		cout<<"��������Y/y"<<endl<<"����������N/n"<<endl;
		cin.get(panduan);
		if(panduan=='N'||panduan=='n') break;
		if(panduan=='Y'||panduan=='y') {
			do{
		system("cls");
		cin.sync();
		cin.clear(0);
		xianshi(a,n,name,m,o);
		cout<<"��������Ҫ��������(������1��"<<n<<")"<<endl;
		cin>>x;
		cin>>y;
		if(x>=1&&x<=n&&y>=1&&y<=n) {jiaohuanshoupai(a,x-1,y-1);break;}
		else cout<<"����������"<<endl;
		_sleep(1*500);
			}
		while(1);
		}
		else cout<<"����������"<<endl;
		_sleep(1*500);
		}
		while(1);
	if(first=firstvictory(n,m,o)) break;/*����һ���ж�*/
	taken(b,&m,c,&o);/*AI1��AI2����*/
	if(first=firstvictory(n,m,o)) break;
	xiaopai(b,m);
	qiantui(b,&m);
	if(first=firstvictory(n,m,o)) break;
	cin.get();
	system("cls");
	xianshi(a,n,name,m,o);
	taken(c,&o,a,&n);/*AI2����ҵ���*/
	if(first=firstvictory(n,m,o)) break;
	xiaopai(c,o);
	qiantui(b,&m);
	if(first=firstvictory(n,m,o)) break;
	qiantui(c,&o);
	if(first=firstvictory(n,m,o)) break;
	daluan (b,m);/*��������*/
	daluan (c,o);
	cin.get();
	system("cls");
	}
	system("cls");

	while(1){/*�ڶ����ж�*/
		switch(first){
		case(1) :/*��һ��Ϊ��ң�Ȼ�����ٵ�AIΪ�ڶ�*/
			if(m<=n) second=2;
			else second=3;
			break;
		case(2):/*�����AI�Գ�*/
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
	cout<<endl<<"������Ҫ��ȡAI2�ĵڼ����ơ�1-"<<o<<"����";
	cin>>q;
	if(q>=1&&q<=o)
		break;
	else {cout<<"����������"<<endl;
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
		cout<<endl<<"�Ƿ񽻻����� "<<endl;
		cout<<"��������Y/y"<<endl<<"����������N/n"<<endl;
		cin.get(panduan);
		if(panduan=='N'||panduan=='n') break;
		if(panduan=='Y'||panduan=='y') {
			do{
		system("cls");
		cin.sync();
		cin.clear(0);
		xianshi(a,n,name,m,o);
		cout<<"��������Ҫ��������(������1��"<<n<<")"<<endl;
		cin>>x;
		cin>>y;
		if(x>=1&&x<=n&&y>=1&&y<=n) {jiaohuanshoupai(a,x-1,y-1);break;}
		else cout<<"����������"<<endl;
		_sleep(1*500);
			}
		while(1);
		}
		else cout<<"����������"<<endl;
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
	cout<<endl<<"������Ҫ��ȡA11�ĵڼ����ơ�1-"<<m<<"����";
	cin>>q;
	if(m>=1&&q<=m)
		break;
	else {cout<<"����������"<<endl;
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
		cout<<endl<<"�Ƿ񽻻����� "<<endl;
		cout<<"��������Y/y"<<endl<<"����������N/n"<<endl;
		cin.get(panduan);
		if(panduan=='N'||panduan=='n') break;
		if(panduan=='Y'||panduan=='y') {
			do{
		system("cls");
		cin.sync();
		cin.clear(0);
		xianshi(a,n,name,m,o);
		cout<<"��������Ҫ��������(������1��"<<n<<")"<<endl;
		cin>>x;
		cin>>y;
		if(x>=1&&x<=n&&y>=1&&y<=n) {jiaohuanshoupai(a,x-1,y-1);break;}
		else cout<<"����������"<<endl;
		_sleep(1*500);
			}
		while(1);
		}
		else cout<<"����������"<<endl;
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
		while(z<=8){/*������ͼ�ͳ��ֱ��ֵ�����*/
		cout<<"�ڹ�����"<<endl;
		danpai(e[51]);/*��ʾ�ڹ�*/
		switch(first){/*��ʾ��һ�ڶ�*/
		case(1):cout<<name<<" ��һ��"<<endl;sum1+=30;break;
		case(2):cout<<"AI1 ��һ��"<<endl;sum2+=30;break;
		case(3):cout<<"AI2 ��һ��"<<endl;sum3+=30;break;
		default:break;
		}
		switch(second){
		case(1):cout<<name<<" �ڶ���"<<endl;sum1+=10;break;
		case(2):cout<<"AI1 �ڶ���"<<endl;sum2+=10;break;
		case(3):cout<<"AI2 �ڶ���"<<endl;sum3+=10;break;
		default:break;}
	cout<<"			               _...._"<<endl;
	cout<<"			         .-~~/~ |__/ ~|~~."<<endl;
	cout<<"			        /_/``|__/  |__/``|_|.---."<<endl;
	cout<<"			       /~ |__/  |__/  |__/  |   o`."<<endl;
	cout<<"			   '==/|__/__|__/__|__/__|__/~`'--'"<<endl;
	cout<<"			       /__|__|^^^^^^|__|_\\ "<<endl<<endl;
	_sleep(1*250);
	system("cls");
		cout<<"�ڹ�����"<<endl;
		danpai(e[51]);/*��ʾ�ڹ�*/
		switch(first){/*��ʾ��һ�ڶ�*/
		case(1):cout<<name<<" ��һ��"<<endl;sum1;break;
		case(2):cout<<"AI1 ��һ��"<<endl;sum2;break;
		case(3):cout<<"AI2 ��һ��"<<endl;sum3;break;
		default:break;
		}
		switch(second){
		case(1):cout<<name<<" �ڶ���"<<endl;sum1;break;
		case(2):cout<<"AI1 �ڶ���"<<endl;sum2;break;
		case(3):cout<<"AI2 �ڶ���"<<endl;sum3;break;
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
		switch(first){/*��ʾ��һ�ڶ����������*/
		case(1):cout<<name<<" ��һ��"<<endl;sum1+=30;break;
		case(2):cout<<"AI1 ��һ��"<<endl;sum2+=30;break;
		case(3):cout<<"AI2 ��һ��"<<endl;sum3+=30;break;
		default:break;
		}
		switch(second){
		case(1):cout<<name<<" �ڶ���"<<endl;sum1+=10;break;
		case(2):cout<<"AI1 �ڶ���"<<endl;sum2+=10;break;
		case(3):cout<<"AI2 �ڶ���"<<endl;sum3+=10;break;
		default:break;}
		z=0;
		cout<<"��һ���Ϊ"<<sum1<<endl;
		cout<<"AI1����Ϊ"<<sum2<<endl;
		cout<<"AI2����Ϊ"<<sum3<<endl;
		system("pause");
		do{
		system("cls");
		cin.sync();
		cin.clear(0);
		cout<<"�����Ƿ������Ϸ~~~��������y/Y������n/N�˳���"<<endl;
		cin.get(panduan);
		if(panduan=='N'||panduan=='n') {z=0 ;break;}
		if(panduan=='Y'||panduan=='y') {z=1;break;}
		else cout<<"����������"<<endl;
		_sleep(1*500);
			}
		while(1);
		system("cls");}
		while(z==1);
		if(sum1>=sum2&&sum1>=sum3) cout<<"���ʤ";
		else if(sum2>=sum1&&sum2>=sum3) cout<<"AI1ʤ,����ļ���Ŭ��������";
		else if(sum3>=sum1&&sum3>=sum1) cout<<"AI2ʤ������ļ���Ŭ����������";
	return 0;
	}

