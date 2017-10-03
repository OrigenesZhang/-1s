#include <iostream>
#include <cmath>
using namespace std;
const int maxn=1000000000;
const int upp=sqrt(maxn)+0.5;
bool vis[upp+100];
int prime[upp], cnt, N, L, U, mmax, rec;
void init(){
	prime[cnt++]=2;
	for(int i=3; i<=upp; i+=2){
		if(vis[i]) continue;
		prime[cnt++]=i;
		for(int j=3*i; j<=upp; j+=2*i)
			vis[j]=true;
	}
}
int cal(int n){
	if(n==1) return 1;
	int res=1;
	for(int i=0; prime[i]<=n&&i<cnt; i++){
		int cur=0;
		while(!(n%prime[i])){
			cur++;
			n/=prime[i];
		}
		if(cur) res*=cur+1;
	}
	if(n!=1) res<<=1;
	return res;
}
int main(){
	init();
	cin>>N;
	while(N--){
		cin>>L>>U;
		mmax=cal(L);
		rec=L;
		for(int i=L+1; i<=U; i++){
			int loc=cal(i);
			if(mmax<loc){
				mmax=loc;
				rec=i;
			}
		}
		cout<<"Between "<<L<<" and "<<U<<", "<<rec<<" has a maximum of "<<mmax<<" divisors."<<endl;
	}
	return 0;
}
