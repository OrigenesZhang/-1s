long long fast_pow(long long x, int k, int p){
	long long product=1, base=x;
	while(k){
		if(k&1){
			product*=base;
			product%=p;
		}
		base*=base;
		base%=p;
		k>>=1;
	}
	return product;
}
int mod(int m, int n, int p){
	long long nom=1, den=1;
	for(int i=m-n+1; i<=m; i++){
		nom*=i;
		nom%=p;
	}
	for(int i=2; i<=n; i++){
		den*=i;
		den%=p;
	}
	den=fast_pow(den, p-2, p);
	return (nom*den)%p;
}
