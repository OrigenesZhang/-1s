#include <iostream>
#include <algorithm>
using namespace std;
int N, D, P[20], Q, cs=1;
long long res;
int b_count(int x){
	x=(x&0x55555555)+(x>>1&0x55555555);
	x=(x&0x33333333)+(x>>2&0x33333333);
	x=(x&0x0f0f0f0f)+(x>>4&0x0f0f0f0f);
	x=(x&0x00ff00ff)+(x>>8&0x00ff00ff);
	x=(x&0x0000ffff)+(x>>16&0x0000ffff);
	return x;
}
int gcd(int a, int b){
	return !b?a:gcd(b, a%b);
}
int main(){
	cin>>N;
	for(cs=1; cs<=N; cs++){
		cin>>D;
		for(int i=0; i<D; i++)
			cin>>P[i];
		for(int i=0; i<D; i++){
			cin>>Q;
			P[i]-=Q;
			P[i]=abs(P[i]);
		}
		res=0;
		for(int i=0; i<(1<<D); i++){
			int cnt=b_count(i), s=0;
			for(int j=0; j<D; j++)
				if(i&(1<<j)) s=gcd(s, P[j]);
			cnt&1?res+=s:res-=s;
		}
		cout<<"Case "<<cs<<": "<<res<<endl;
	}
	return 0;
}
