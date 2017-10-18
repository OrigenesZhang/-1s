#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
const int maxn=1234567;
double d[maxn];
bool vis[maxn];
int prime[maxn], prime_cnt, T, N;
void init(){
	prime[prime_cnt++]=2;
	for(long long i=3; i<maxn; i+=2){
		if(vis[i]) continue;
		prime[prime_cnt++]=i;
		for(long long j=i*i; j<maxn; j+=2*i)
			vis[j]=true;
	}
	memset(vis, false, sizeof(vis));
}
double dp(int x){
	if(x==1) return 0;
	if(vis[x]) return d[x];
	vis[x]=true;
	double& res=d[x];
	int g=0, p=0;
	res=0;
	for(int i=0; i<prime_cnt&&prime[i]<=x; i++){
		p++;
		if(x%prime[i]==0){
			g++;
			res+=dp(x/prime[i]);
		}
	}
	res=(res+p)/g;
	return res;
}
int main(){
	init();
	cout<<fixed<<setprecision(7);
	cin>>T;
	for(int cs=1; cs<=T; cs++){
		cin>>N;
		cout<<"Case "<<cs<<": "<<dp(N)<<endl;
	}
	return 0;
}
