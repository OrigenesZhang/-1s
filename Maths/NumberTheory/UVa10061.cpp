#include <iostream>
#include <cmath>
#include <map>
using namespace std;
bool notprime[850];
int prime[850], tot, N, B;
map<int, int> f, cnt;
int main(){
	prime[tot++]=2;
	for(int i=3; i<=800; i+=2){
		if(notprime[i]) continue;
		prime[tot++]=i;
		for(int j=3*i; j<=800; j+=2*i)
			notprime[i]=true;
	}
	while(cin>>N>>B){
		if(!N){
			cout<<"0 1"<<endl;
			continue;
		}
		f.clear();
		cnt.clear();
		int tmp=B;
		for(int i=0; i<tot&&prime[i]<=tmp; i++){
			while(!(tmp%prime[i])){
				f[prime[i]]++;
				tmp/=prime[i];
			}
		}
		for(int i=2; i<=N; i++){
			tmp=i;
			for(auto it=f.begin(); it!=f.end(); ++it){
				while(!(tmp%(*it).first)){
					cnt[(*it).first]++;
					tmp/=(*it).first;
				}
			}
		}
		long long mmin=(long long)1<<31;
		for(auto it=f.begin(); it!=f.end(); it++)
			mmin=min((long long)cnt[(*it).first]/(*it).second, mmin);
		cout<<mmin<<' ';
		double t=0;
		for(int i=2; i<=N; i++)
			t+=log10(i);
		t/=log10(B);
		cout<<(int)(floor(t+1e-9)+1)<<endl;//floor是一个double转int的函数但是输出如果位数高默认转成double...
	}
	return 0;
}
