//对于题中所给的素数条件,若n为素数的话命题一定成立(费马小定理),但n不为素数时命题却不一定不成立
#include <iostream>
using namespace std;
long long N;
long long fast_pow(long long k, long long p){
	long long product=1, base=2;
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
int main(){
	while(cin>>N){
		if(N==-1) break;
		cout<<N<<" is ";
		if(fast_pow(N-1, N)!=1) cout<<"not ";//2**(n-1) mod n==1
		cout<<"a Jimmy-number"<<endl;
	}
	return 0;
}
