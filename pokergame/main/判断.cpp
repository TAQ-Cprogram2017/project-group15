
int firstvictory();
int firstvictory(int n,int m,int k)
{
	if (n==0) return 1;
	else if (m==0) return 2;
	else if (k==0) return 3;
	else return 0;
}
int secondvictory();
int secondvicory(int first,int n,int m,int o){
	int k=0,x,y,z,l;
	x=n,y=m,z=0,l=first;
	switch(l){
	case(2):if(x==0) return k=1;if(z==0) return k=3;else return k=0;
	case(3):if(y==0) return k=2;if(x==0) return k=1;else return k=0;
	default:return k=0;break;
	}
}

