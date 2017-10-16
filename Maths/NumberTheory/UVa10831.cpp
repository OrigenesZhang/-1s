//本题考查勒让德符号的欧拉准则(可以看作是费马小定理的变型)
#include <iostream>
using namespace std;
long long a, p;
long long fast_pow(long long x, long long k, long long mod){
	long long product=1, base=x;
	while(k){
		if(k&1){
			product*=base;
			product%=mod;
		}
		base*=base;
		base%=p;
		k>>=1;
	}
	return product;
}
int main(){
	while(cin>>a>>p){
		if(a==-1&&p==-1) break;
		a%=p;
		if(a<=1||p<=2||fast_pow(a, (p-1)/2, p)==1) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}
