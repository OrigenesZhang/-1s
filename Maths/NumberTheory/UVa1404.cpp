#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
const int inf=2*1e9;
const int maxn=sqrt(inf)+0.5;
const int MAXN=10000000;//题目中间的b-a不超过10000000但是大于1000000
int prime[maxn], p, a, b, k, s, res, T, cnt, pre;
bool vis[maxn+100], local[MAXN+100];
vector<int> buff;
void init(){
	prime[p++]=2;
	for(int i=3; i<=maxn; i+=2){
		if(vis[i]) continue;
		prime[p++]=i;
		for(int j=i*i; j<=maxn; j+=2*i)
			vis[j]=true;
	}
}
int main(){
	init();
	cin>>T;
	while(T--){
		cin>>a>>b>>k>>s;
		memset(local, false, sizeof(local));
		buff.clear();
		for(int i=0; i<p&&prime[i]<=b; i++){
			int tmp=a/prime[i]*prime[i];
			if(tmp<a) tmp+=prime[i];
			if(tmp==prime[i]) tmp+=prime[i];
			for(int j=tmp; j<=b; j+=prime[i])
				local[j-a]=true;
		}
		for(int i=a; i<=b; i++)
			if(!local[i-a]) buff.push_back(i);
		int sz=buff.size();
		if(!sz){
			cout<<0<<endl;
			continue;
		}
		res=cnt=pre=0;
		for(int i=0; i<sz; i++){
			cnt++;
			if(cnt>=k||buff[i]-buff[pre]>=s){
				if(cnt==k&&buff[i]-buff[pre]==s) res++;
				while(cnt>=k||buff[i]-buff[pre]>=s){
					pre++;
					cnt--;
				}
			}
		}
		cout<<res<<endl;
	}
	return 0;
}
