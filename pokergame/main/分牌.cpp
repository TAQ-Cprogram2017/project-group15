
void fenpai();
void fenpai(int e[],int a[],int b[],int c[]){
	int i;
	for(i=0;i<17;i++)
		a[i]=e[i];
	for(;i<34;i++)
		b[i-17]=e[i];
	for(;i<51;i++)
		c[i-34]=e[i];
}



