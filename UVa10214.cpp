#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#ifndef ONLINE_JUDGE
ifstream fin("test.in");
ofstream fout("test.out");
#define cin fin
#define cout fout
#endif
typedef long long ll;
const int maxn=2000;
bool vis[maxn+123];
int mo[maxn+123], primes[maxn+123], pcnt, a, b;
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
	for(int i=2; i<=maxn; i++) mo[i]+=mo[i-1];//mo记录前缀和
}
int main(){
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cout<<fixed<<setprecision(10);
	mobius();
	while(cin>>a>>b){
		if(!a&&!b) break;
		ll K=0, N=ll(2*a+1)*(2*b+1)-1;
		if(a>b) swap(a, b);
		for(int i=1, j; i<=a; i=j+1){
			j=min(a/(a/i), b/(b/i));
			K+=ll(mo[j]-mo[i-1])*(a/i)*(b/i);
		}
		K=(K+1)*4;
		cout<<double(K)/N<<endl;
	}
	return 0;
}
