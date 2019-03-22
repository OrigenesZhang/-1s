#include <iostream>
using namespace std;
bool vis[10000+100];
int prime[3000], tot, n;
void init(){
	prime[tot++]=2;
	for(int i=3; i<=10000; i+=2){
		if(vis[i]) continue;
		prime[tot++]=i;
		for(int j=i*i; j<=10000; j+=2*i)
			vis[j]=true;
	}
}
int main(){
	init();
	while(cin>>n){
		int res=0, f=0, r=tot-1;
		while(prime[r]>n) r--;
		while(f<=r){
			int cur=prime[r];
			while(cur*prime[f]<=n) cur*=prime[f++];
			res++;
			r--;
		}
		cout<<res<<endl;
	}
	return 0;
}
