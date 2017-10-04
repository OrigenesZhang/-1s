#include <iostream>
#include <set>
#include <cmath>
using namespace std;
long long X, N, r, cs=1;
set<long long> res;
void exgcd(long long a, long long b, long long& d, long long& x, long long& y){
	if(!b){
		d=a;
		x=1;
		y=0;
	}else{
		exgcd(b, a%b, d, y, x);
		y-=x*(a/b);
	}
}
void solve(long long a, long long b, long long n){
	long long x, y, d;
	exgcd(a, n, d, x, y);
	if(b%d) return;
	x*=b/d;
	x=(x%(n/d)+(n/d))%(n/d);
	long long start=x*a-b/2;
	long long inc=a*n/d;
	for(long long i=start; i<N; i+=inc)
		if(i>=0) res.insert(i);
}
int main(){
	while(cin>>X>>N>>r){
		if(!X&&!N&&!r) break;
		res.clear();
		long long upp=sqrt(N)+0.5;
		for(long long i=1; i<=upp; i++){
			if(N%i) continue;
			solve(i, r<<1, N/i);
			solve(N/i, r<<1, i);
		}
		cout<<"Case "<<cs++<<":";
		for(auto it=res.begin(); it!=res.end(); ++it)
			cout<<' '<<*it;
		cout<<endl;
	}
	return 0;
}
