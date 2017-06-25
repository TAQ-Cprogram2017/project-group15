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

ele a[7][18];
ele b[2][15];

//a+1

int main(void)
{ 
	int i,j,x=6,y=4;
	char input;

	FILE *fp;
	fp=fopen("Periodtable.txt","r");
	fread(&a[0][0],sizeof(struct element),1,fp);//读入H
	fread(&a[0][17],sizeof(struct element),1,fp);//读入He
	fclose(fp);
	
	fp=fopen("Periodtable001.txt","r");
	for(i=1;i<=2;i++)//读入第二,三周期
	{
		for(j=0;j<=1;j++)//读入Li,Be,Na,Mg 
		{
			fread(&a[i][j],sizeof(struct element),1,fp);
		} 

		for(j=12;j<=17;j++)
		{
			fread(&a[i][j],sizeof(struct element),1,fp);	
		} 
	}
	fclose(fp);
	
	fp=fopen("Periodtable002.txt","r");
	for(i=3;i<=4;i++)//读入第四,五周期
	{
		for(j=0;j<=17;j++)
		{
			fread(&a[i][j],sizeof(struct element),1,fp);
		}
	} 
	fclose(fp);
	
	fp=fopen("Periodtable003.txt","r");
	for(i=5;i<=6;i++)//读入第六，七周期
	{
		for(j=0;j<=17;j++)
		{
			fread(&a[i][j],sizeof(struct element),1,fp);
		}
	} 
	fclose(fp);
	
	fp=fopen("Periodtable004.txt","r");
	for(i=0;i<=1;i++)//读入La系，Ac系 
	{
		for(j=0;j<=14;j++)
		{
			fread(&b[i][j],sizeof(struct element),1,fp);
		}
	} 
	fclose(fp);
	
	for(j=1;j<=16;j++)//补充空格 
	{
		strcpy(a[0][j].symbol,"  ");
	}
	
	for(i=1;i<=2;i++)//补充空格
	{
		for(j=2;j<=11;j++)
		{
			strcpy(a[i][j].symbol,"  ");
		}
	}

	show1(a,b);//第一次显示周期表 
	move(x,y,a,b);//光标移动 

}	

