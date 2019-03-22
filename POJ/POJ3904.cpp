#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
using namespace std;
#ifndef ONLINE_JUDGE
ifstream fin("test.in");
ofstream fout("test.out");
#define cin fin
#define cout fout
#endif
typedef long long ll;
const int maxn=10000;
bool vis[maxn+123];
int mo[maxn+123], primes[maxn+123], a[maxn+123], pcnt, N;
void mobius(){
	mo[1]=1;
	for(int i=2; i<=maxn; i++){
		if(!vis[i]){
			mo[i]=-1;
			primes[pcnt++]=i;
		}
		for(int j=0; j<pcnt&&ll(i)*primes[j]<=maxn; j++){
			vis[i*primes[j]]=true;
			if(i%primes[j]) mo[i*primes[j]]=-mo[i];
			else{
				mo[i*primes[j]]=false;
				break;
			}
		}
	}
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	mobius();
	while(cin>>N){
		int tmp;
		memset(a, 0, sizeof(a));
		for(int i=0; i<N; i++){
			cin>>tmp;
			int upp=sqrt(tmp)+0.5;
			for(int j=1; j<=upp; j++)
				if(tmp%j==0){
					a[j]++;
					a[tmp/j]++;
				}
			if(upp*upp==tmp) a[upp]--;
		}
		ll res=0;
		for(int i=1; i<=maxn; i++){
			if(!mo[i]||a[i]<4) continue;
			res+=ll(a[i])*(a[i]-1)*(a[i]-2)*(a[i]-3)/24*mo[i];
		}
		cout<<res<<endl;
	}
	return 0;
}
