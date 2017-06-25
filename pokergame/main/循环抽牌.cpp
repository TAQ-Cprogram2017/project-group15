void take();
void take(int a[],int *n,int b[],int *m,int q){
	int temp;
	temp=b[q-1];
	b[q-1]=b[*m-1];
	b[--(*m)]=0;
	a[(*n)++]=temp;
}
void taken();
void taken(int a[],int *n,int b[],int *m){
	int temp,k;
	srand(unsigned(time(0)));
	k=rand()%*m;
	temp=b[k];
	b[k]=b[*m-1];
	b[--(*m)]=0;
	a[(*n)++]=temp;
}