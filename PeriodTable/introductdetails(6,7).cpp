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

int main()
{
	FILE *fp;
	fp=fopen("Periodtable003.txt","w");
	int i,j;

	printf("Input the details:\n");
	
	for(i=5;i<=6;i++)//输入第六、七周期
	{
		for(j=0;j<=17;j++)
		{
			scanf("%d%s%lf%s",&a[i][j].order,a[i][j].symbol,&a[i][j].AR,a[i][j].structure);
			fwrite(&a[i][j],sizeof(struct element),1,fp);
		}
	}
	return 0;
}
