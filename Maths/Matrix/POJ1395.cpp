#include <iostream>
#include <cstring>
using namespace std;
const int maxm=12345;
const int maxn=31;
int c[maxn], n, m, t, tot, fac[maxm];
bool vis[maxm];
int gcd(int a, int b){
	return !b?a:gcd(b, a%b);
}
bool judge(int a, int b){
	int mmax=max(a, b);
	for(int i=1; i*mmax<=10000; i++)
		if(vis[i*a]&&vis[i*b]) return true;
	return false;
}
int main(){
	cin>>t;
	for(int cs=1; cs<=t; cs++){
		memset(vis, false, sizeof(vis));
		cin>>n;
		for(int i=0; i<n; i++)
			cin>>c[i];
		tot=0;
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(i==j) continue;
				if(!(c[i]%c[j])) fac[tot++]=c[i]/c[j];
			}
		}
		vis[1]=true;
		for(int i=0; i<tot; i++){
			for(int j=1; j<maxm; j++){
				if(vis[j]){
					int tmp=j*fac[i];
					if(tmp<maxm) vis[tmp]=true;
				}
			}
		}
		cin>>m;
		cout<<"Scenario #"<<cs<<":"<<endl;
		while(m--){
			int a, b;
			cin>>a>>b;
			cout<<"Gear ratio "<<a<<":"<<b;
			int d=gcd(a, b);
			a/=d;
			b/=d;
			if(judge(a, b)) cout<<" can be realized."<<endl;
			else cout<<" cannot be realized."<<endl;
		}
		if(cs!=t) cout<<endl;
	}
	return 0;
}
