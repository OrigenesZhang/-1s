#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
const int maxn=1000001;
bool vis[maxn+100];
int prime[maxn+100], tot[maxn+100], h, cnt;
void init(){
	int upp=sqrt(maxn)+0.5;
	for(int i=5; i<=upp; i+=4){
		if(vis[i]) continue;
		for(int j=i*i; j<=maxn; j+=4*i)
			vis[j]=true;
	}
	for(int i=5; i<=maxn; i+=4)
		if(!vis[i]) prime[cnt++]=i;
	memset(vis, false, sizeof(vis));
	for(int i=0; i<cnt; i++){
		for(int j=i; j<cnt; j++){
			long long cur=(long long)prime[i]*(long long)prime[j];
			if(cur>(long long)maxn) break;
			vis[cur]=true;
		}
	}
	for(int i=25; i<=maxn; i+=4)
		tot[i]=tot[i-4]+vis[i];
}
int main(){
	init();
	while(cin>>h){
		if(!h) break;
		cout<<h<<' '<<tot[h]<<endl;
	}
	return 0;
}
