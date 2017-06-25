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

int main()
{
	FILE *fp;
	fp=fopen("Periodtable004.txt","w");
	int i,j;

	printf("Input the details:\n");
	
	for(i=0;i<=1;i++)//输入第镧系，锕系元素 
	{
		for(j=0;j<=14;j++)
		{
			scanf("%d%s%lf%s",&b[i][j].order,b[i][j].symbol,&b[i][j].AR,b[i][j].structure);
			fwrite(&b[i][j],sizeof(struct element),1,fp);
		}
	}
	return 0;
}
