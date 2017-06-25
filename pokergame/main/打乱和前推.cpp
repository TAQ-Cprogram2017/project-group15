#include<cstdlib>
#include<ctime>
void daluan();
void daluan (int e[],int n){
	srand(unsigned (time(0)));
	int i,k=rand()%n,m,temp,j;
	for(m=0;m<k;m++){
		i=rand()%n;
		j=rand()%n;
		if(i==j) {m--;continue;}
		temp=e[i];
		e[i]=e[j];
		e[j]=temp;
	}
}
void qiantui();
void qiantui(int e[],int *n)
{
	int i,j,k,temp ;
	for(i=*n-1;i>0;i--)
		for(j=0;j<i;j++)
			if(e[j]==0)
			{
				temp=e[j+1];
				e[j+1]=0;
				e[j]=temp;
			}
	for(k=0;e[k]!=0&&k<=*n;k++);
	*n=k;
}



	
