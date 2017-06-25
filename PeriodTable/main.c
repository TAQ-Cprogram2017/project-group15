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
	fread(&a[0][0],sizeof(struct element),1,fp);//����H
	fread(&a[0][17],sizeof(struct element),1,fp);//����He
	fclose(fp);
	
	fp=fopen("Periodtable001.txt","r");
	for(i=1;i<=2;i++)//����ڶ�,������
	{
		for(j=0;j<=1;j++)//����Li,Be,Na,Mg 
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
	for(i=3;i<=4;i++)//�������,������
	{
		for(j=0;j<=17;j++)
		{
			fread(&a[i][j],sizeof(struct element),1,fp);
		}
	} 
	fclose(fp);
	
	fp=fopen("Periodtable003.txt","r");
	for(i=5;i<=6;i++)//���������������
	{
		for(j=0;j<=17;j++)
		{
			fread(&a[i][j],sizeof(struct element),1,fp);
		}
	} 
	fclose(fp);
	
	fp=fopen("Periodtable004.txt","r");
	for(i=0;i<=1;i++)//����Laϵ��Acϵ 
	{
		for(j=0;j<=14;j++)
		{
			fread(&b[i][j],sizeof(struct element),1,fp);
		}
	} 
	fclose(fp);
	
	for(j=1;j<=16;j++)//����ո� 
	{
		strcpy(a[0][j].symbol,"  ");
	}
	
	for(i=1;i<=2;i++)//����ո�
	{
		for(j=2;j<=11;j++)
		{
			strcpy(a[i][j].symbol,"  ");
		}
	}

	show1(a,b);//��һ����ʾ���ڱ� 
	move(x,y,a,b);//����ƶ� 

}	

