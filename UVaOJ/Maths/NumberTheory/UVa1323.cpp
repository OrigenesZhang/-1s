//欧几里德-欧拉定理: 每一个偶完全数都可以写成M*(M+1)/2的形式,其中M为梅森素数
//主要思路是逆用定理, 如果若干梅森素数之积为一个数, 那么其所有因子可以被写为2**n的形式
#include <iostream>
using namespace std;
const int pw[]={2, 3, 5, 7, 13, 17, 19, 31};//2**31以内的梅森素数有且仅有8个
int N, res, state[100+10], K;
long long mprime[10], p;
inline void init(){
	for(int i=0; i<8; i++)
		mprime[i]=((long long)1<<pw[i])-1;
}
void add(long long cur){
	state[N]=0;
	for(int i=0; i<8; i++){
		if(!(cur%mprime[i])){
			state[N]|=(1<<i);
			cur/=mprime[i];
			if(!(cur%mprime[i])) return;
		}
	}
	if(cur==1) N++;
}
void dfs(int d, int cur){//位压dp
	int tmp=0;
	for(int i=0; i<8; i++)
		if(cur&(1<<i)) tmp+=pw[i];
	res=max(res, tmp);
	for(int i=d; i<N; i++)
		if(!(cur&state[i])) dfs(i+1, cur|state[i]);
}
int main(){
	init();
	while(cin>>K){
		N=0;
		for(int i=0; i<K; i++){
			cin>>p;
			add(p);
		}
		if(!N){
			cout<<"NO"<<endl;
			continue;
		}
		res=0;
		dfs(0, 0);
		cout<<res<<endl;
	}
	return 0;
}
