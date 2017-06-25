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
	FILE *fp;
	fp=fopen("Periodtable.txt","w");		
	fwrite(&a[i][j],sizeof(struct element),1,fp);
	fclose(fp);
}
*/
int main()
{
	FILE *fp;
	fp=fopen("Periodtable002.txt","w");
	int i,j;

	printf("Input the details:\n");
	
	for(i=3;i<=4;i++)//输入第四,五周期
	{
		for(j=0;j<=17;j++)
		{
			scanf("%d%s%lf%s",&a[i][j].order,a[i][j].symbol,&a[i][j].AR,a[i][j].structure);
			fwrite(&a[i][j],sizeof(struct element),1,fp);
		}
	}
	return 0;
}


