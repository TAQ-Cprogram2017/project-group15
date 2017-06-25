void xiaopai();

void xiaopai(int a[],int n){
	int i,j;
	for(i=0;i<n;i++){
		if(a[i]==0)	continue;
		for(j=i+1;j<n;j++){
			if(a[j]==0) continue;
			if(a[i]%13==a[j]%13){
				a[i]=0;
				a[j]=0;
				break;
			}}
	}
}
