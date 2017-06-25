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

int main()
{
	FILE *fp;
	fp=fopen("Periodtable.txt","w");

	printf("Input the details:\n");
		
	scanf("%s%lf%s",a[0][0].symbol,&a[0][0].AR,a[0][0].structure);					// ‰»ÎH 
	fwrite(&a[0][0],sizeof(struct element),1,fp);
	
	scanf("%s%lf%s",a[0][17].symbol,&a[0][17].AR,a[0][17].structure);				// ‰»ÎHe 
	fwrite(&a[0][17],sizeof(struct element),1,fp);
	fclose(fp);	
	return 0;
}

