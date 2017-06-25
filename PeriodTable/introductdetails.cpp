#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

typedef struct element
{
	char symbol[2];
	double AR;
	char structure[30]; 
}ele; 

ele a[5][18];
/*
void savetabletoPeriodtable(int i,int j)
{
	FILE *fp;
	fp=fopen("Periodtable.txt","a");		
	fwrite(&a[i][j],sizeof(struct element),1,fp);
	fclose(fp);
}
*/
int main()
{
	int i,j;
	FILE *fp;
	fp=fopen("Periodtable001.txt","w");

	printf("Input the details:\n");
		
	scanf("%s%lf%s",a[0][0].symbol,&a[0][0].AR,a[0][0].structure);					//输入H 
	fwrite(&a[0][0],sizeof(struct element),1,fp);
	
	scanf("%s%lf%s",a[0][17].symbol,&a[0][17].AR,a[0][17].structure);				//输入He 
	fwrite(&a[0][17],sizeof(struct element),1,fp);
	
	for(i=1;i<=2;i++)//输入第二,三周期
	{
		for(j=0;j<=1;j++)//输入Li,Be,Na,Mg 
		{
			scanf("%s%lf%s",a[i][j].symbol,&a[i][j].AR,a[i][j].structure);
			fwrite(&a[i][j],sizeof(struct element),1,fp);
//			savetabletoPeriodtable(i,j);
		} 
		
		for(j=12;j<=17;j++)
		{
			scanf("%s%lf%s",a[i][j].symbol,&a[i][j].AR,a[i][j].structure);
			fwrite(&a[i][j],sizeof(struct element),1,fp);
//			savetabletoPeriodtable(i,j);	
		} 
	}
		
	for(i=3;i<=4;i++)//输入第四,五周期
	{
		for(j=0;j<=17;j++)
		{
			scanf("%s%lf%s",a[i][j].symbol,&a[i][j].AR,a[i][j].structure);
			fwrite(&a[i][j],sizeof(struct element),1,fp);
//			savetabletoPeriodtable(i,j);
		}
	}
	return 0;	
}
