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
/*
void savetabletoPeriodtable(int i,int j)
{		
	fwrite(&a[i][j],sizeof(struct element),1,fp);
}
*/
int main()
{
	FILE *fp;
	fp=fopen("Periodtable001.txt","w");
	int i,j;

	printf("Input the details:\n");
	
	for(i=1;i<=2;i++)//输入第二,三周期
	{
		for(j=0;j<=1;j++)//输入Li,Be,Na,Mg 
		{
			scanf("%d%s%lf%s",&a[i][j].order,a[i][j].symbol,&a[i][j].AR,a[i][j].structure);
			fwrite(&a[i][j],sizeof(struct element),1,fp);
//			savetabletoPeriodtable(i,j);
		} 
		
		for(j=12;j<=17;j++)
		{
			scanf("%d%s%lf%s",&a[i][j].order,a[i][j].symbol,&a[i][j].AR,a[i][j].structure);
			fwrite(&a[i][j],sizeof(struct element),1,fp);
//			savetabletoPeriodtable(i,j);	
		} 
	}
	fclose(fp);
	return 0;
}










