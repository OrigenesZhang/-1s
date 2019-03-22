#include <iostream>
using namespace std;
long long N, M, A, B;
int cs;
long long Cnt(long long upp){
	if(upp<0) upp=0;
	if(N>M) swap(M, N);
	long long res=0;
	for(long long row=1; row<=N; row++){
		for(long long col=1; col<=M; col++){
			long long cnt=0, l, r;
			if(row*col<=upp) cnt+=(row+col-2)<<1;
			for(long long i=0; i<=row; i++){
				r=min((col*i+upp)/row, col);
				long long tmp=col*i-upp;
				l=(tmp>0?(tmp-1)/row+1:0);
				if(l<=r) cnt+=(r-l+1)<<1;
			}
			for(long long i=1; i<row; i++){
				long long tmp=row*col-i;
				if(tmp<=upp) cnt+=(col-1)<<2;
				else{
					tmp-=upp;
					cnt+=(col-1-min(tmp/i+(tmp%i!=0), col-1))<<2;
				}
			}
			res+=cnt*(N-row+1)*(M-col+1);
		}
	}
	return res;
}
int main(){
	cin>>cs;
	while(cs--){
		cin>>N>>M>>A>>B;
		cout<<Cnt(B<<1)-Cnt((A<<1)-1)<<endl;
	}
	return 0;
}
