char color(int a);
char number(int a);
void danpai(int a);
void xianshi(int a[],int n);
void xianshi(int a[],int n,char name[],int m,int o){
	int i;
	cout<<"��� "<<name<<" �����ƣ�"<<n<<"��"<<endl;
	for(i=0;i<n;i++)
	cout<<"����";
	cout<<"������"<<endl;
	for(i=0;i<n;i++){
		if(number(a[i])!='T')
		cout<<"�� "<<number(a[i]);
		else cout<<"��10";
	}
	cout<<"    ��"<<endl;
	for(i=0;i<n;i++)
	cout<<"�� "<<color(a[i]);
	cout<<"    ��"<<endl;
		for(i=0;i<n;i++)
	cout<<"��  ";
	cout<<"  �驦"<<endl;
		for(i=0;i<n;i++)
	cout<<"��  ";
	cout<<"  �ک�"<<endl;
		for(i=0;i<n;i++)
	cout<<"��  ";
	cout<<"  �ꩦ"<<endl;
		for(i=0;i<n;i++)
	cout<<"����";
	cout<<"������"<<endl;
	cout<<endl<<"AI1��"<<m<<"����"<<endl;
	cout<<"AI2��"<<o<<"����"<<endl;
}

void danpai(int a){

	cout<<"����";
	cout<<"������"<<endl;

		if(number(a)!='T')
		cout<<"�� "<<number(a);
		else cout<<"��10";
	
	cout<<"    ��"<<endl;

	cout<<"�� "<<color(a);
	cout<<"    ��"<<endl;

	cout<<"��  ";
	cout<<"  �驦"<<endl;

	cout<<"��  ";
	cout<<"  �ک�"<<endl;

	cout<<"��  ";
	cout<<"  �ꩦ"<<endl;

	cout<<"����";
	cout<<"������"<<endl;
}
char color(int a){
	
		if (a/13==0||a==13) {
			return 3;	/*hongtao*/
		}
		if(a/13==1||a==26) {
			return 12;	/*fangkuai*/
		}
		if(a/13==2||a==39) {
			return 38;	/*heitao*/
		}
		if(a/13==3||a==52) {
			return 64;	/*caohua*/
		}
	}

char number(int a){
	if(a%13==1)
		return 'A';
	else if(a%13==11)
		return 'J';
	else if(a%13==12)
		return 'Q';
	else if(a%13==0)
		return 'K';
	else if(a%13==10)
		return 'T';
	else 
		return a%13+48;
}
