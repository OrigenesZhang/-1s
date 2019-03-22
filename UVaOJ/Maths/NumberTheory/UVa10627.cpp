#include <iostream>
using namespace std;
long long L, u, v, t, res, g;
long long gcd(long long a, long long b){
	return !b?a:gcd(b, a%b);
}
int main(){
	while(cin>>L>>u>>v>>t){
		if(!L) break;
		if(!u&&!v){
			cout<<0<<endl;
			continue;
		}
		if(u<v) swap(u, v);
		res=((u+v)*t+L)/(L<<1)+((u-v)*t+L)/(L<<1);
		g=gcd(u, v);
		if(((u-v)/g)&1) res-=(g*t+L)/(L<<1);
		cout<<res<<endl;
	}
	return 0;
}
