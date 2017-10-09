#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=1000000;
int prime[maxn], p, fac[maxn+100], f, cnt[maxn+100], num[maxn+100], tot, cs=1;
long long N;
bool vis[maxn+100], flag;
long long gcd(long long a, long long b){
	return !b?a:gcd(b, a%b);
}
long long lcm(long long a, long long b){
	return a/gcd(a, b)*b;
}
void init(){
	prime[p++]=2;
	for(long long i=3; i<=maxn; i+=2){
		if(vis[i]) continue;
		prime[p++]=i;
		for(long long j=i*i; j<=maxn; j+=2*i)
			vis[j]=true;
	}
}
void factor(long long n){
	f=0;
	memset(cnt, 0, sizeof(cnt));
	for(int i=0; i<p; i++){
		if(!(n%prime[i])){
			fac[f]=prime[i];
			while(!(n%prime[i])){
				n/=prime[i];
				cnt[f]++;
			}
			f++;
		}
	}
	if(n>1){
		fac[f]=n;
		cnt[f++]=1;
	}
}
void dfs(int d, long long n){
	if(n>maxn) return;
	if(d==f){
		num[tot++]=n;
		return;
	}
	for(int i=0; i<=cnt[d]; i++){
		dfs(d+1, n);
		n*=fac[d];
	}
}
int main(){
	init();
	while(cin>>N){
		if(!N) break;
		tot=0;
		flag=false;
		cout<<"Scenario "<<cs++<<":"<<endl;
		factor(N);
		dfs(0, 1);
		sort(num, num+tot);
		for(int i=0; i<tot; i++){
			for(int j=i+1; j<tot; j++){
				if(num[j]-num[i]>25) break;
				long long tmp=lcm(num[i], num[j]);
				for(int k=j+1; k<tot; k++){
					if(num[k]-num[i]>25) break;
					if(lcm(tmp, num[k])==N){
						cout<<num[i]<<' '<<num[j]<<' '<<num[k]<<endl;
						flag=true;
					}
				}
			}
		}
		if(!flag) cout<<"Such bells don't exist"<<endl;
		cout<<endl;
	}
	return 0;
}
