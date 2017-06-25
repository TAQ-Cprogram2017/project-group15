
#include<cstdlib>
#include<ctime>
void pokerprepare();
void pokerprepare(int e[],int n){
	srand(unsigned(time(0)));
	int i=0,j,k=0;
	while(i<52)
	{
		e[i]=rand()%52+1;
		k=0;
		for(j=0;j<i;j++)
			if(e[i]==e[j]){
				k=1;
				break;}
			if(k!=1) i++;
			}
}
