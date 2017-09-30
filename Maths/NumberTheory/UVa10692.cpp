//io坑,应该用python写的
#include <iostream>
#include <sstream>
#include <cstring>
using namespace std;
const int maxn=10000;
int phi[maxn+100], m, n, a[15], cs=1;
string s;
void phi_table(){
	memset(phi, 0, sizeof(phi));
	phi[1]=1;
	for(int i=2; i<=maxn; i++){
		if(!phi[i]){
			for(int j=i; j<=maxn; j+=i){
				if(!phi[j]) phi[j]=j;
				phi[j]=phi[j]/i*(i-1);
			}
		}
	}
}
long long fast_pow(long long x, long long k, long long MOD){
	long long product=1, base=x;
	while(k){
		if(k&1){
			product*=base;
			product%=MOD;
		}
		base*=base;
		base%=MOD;
		k>>=1;
	}
	return product+MOD;
}
long long euler_theorem(long long cur, long long MOD){
	if(cur==n-1) return a[cur]<MOD?a[cur]:a[cur]%MOD+MOD;
	return fast_pow(a[cur], euler_theorem(cur+1, phi[MOD]), MOD);
}
int main(){
	phi_table();
	while(getline(cin, s)){
		if(s=="#") break;
		stringstream ss(s);
		ss>>m>>n;
		for(int i=0; i<n; i++) ss>>a[i];
		cout<<"Case #"<<cs++<<": "<<euler_theorem(0, m)%m<<endl;
	}
	return 0;
}
