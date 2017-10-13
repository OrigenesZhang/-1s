//暴力枚举orz
#include <iostream>
#include <cstring>
using namespace std;
const int maxn=10000;
int prime[maxn+100], fac[maxn+100], p, f, n, res, cs=1;
bool vis[maxn+100];
void init(){
	prime[p++]=2;
	for(int i=3; i<=maxn; i+=2){
		if(vis[i]) continue;
		prime[p++]=i;
		for(int j=i*i; j<=maxn; j+=2*i)
			vis[j]=true;
	}
}
bool judge(int s){
	for(int i=0; i<p&&prime[i]*prime[i]<=s; i++)
		if(!(s%prime[i])) return false;
	for(int i=0; i<f; i++)
		if(vis[i]&&fac[i]==s) return false;
	return true;
}
void dfs(int cur, int s, int tot){
	if(cur==f){
		if(s==1) res=min(res, tot);
		else if(judge(s+1)){
			tot*=s+1;
			res=min(res, tot);
		}
		return;
	}
	dfs(cur+1, s, tot);
	if(s%(fac[cur]-1)) return;
	vis[cur]=true;
	s/=fac[cur]-1;
	tot*=fac[cur];
	dfs(cur+1, s, tot);
	while(!(s%fac[cur])){
		s/=fac[cur];
		tot*=fac[cur];
		dfs(cur+1, s, tot);
	}
	vis[cur]=false;
}
int main(){
	init();
	while(cin>>n){
		if(!n) break;
		f=0;
		res=200000000;
		for(int i=0; i<p&&(prime[i]-1)*(prime[i]-1)<=n; i++){
			if(n%(prime[i]-1)) continue;
			fac[f++]=prime[i];
		}
		memset(vis, false, sizeof(vis));
		dfs(0, n, 1);
		cout<<"Case "<<cs++<<": "<<n<<' '<<res<<endl;
	}
	return 0;
}
