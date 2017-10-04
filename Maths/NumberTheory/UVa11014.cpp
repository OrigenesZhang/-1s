#include <iostream>
using namespace std;
const int maxn=200000;
long long prime[maxn+100], mo[maxn+100], tot, N, C=1, res;
bool vis[maxn+100];
void moebius(){//莫比乌斯反演...目瞪口呆
	mo[1]=1;
	for(int i=2; i<=maxn; i++){
		if(!vis[i]){
			mo[i]=-1;
			prime[tot++]=i;
		}
		for(int j=0; j<tot&&prime[j]*i<=maxn; j++){
			vis[i*prime[j]]=true;
			if(i%prime[j]) mo[i*prime[j]]=-mo[i];
			else{
				mo[i*prime[j]]=0;
				break;
			}
		}
	}
	for(int i=2; i<=maxn; i++)
		mo[i]+=mo[i-1];
}
int main(){
	moebius();
	while(cin>>N){
		if(!N) break;
		N>>=1;
		res=6;
		for(long long i=1, j; i<=N; i=j+1){
			long long tmp=N/i;
			j=N/tmp;
			res+=((tmp*tmp*tmp<<3)+tmp*tmp*12)*(mo[j]-mo[i-1]);
		}
		cout<<"Crystal "<<C++<<": "<<res<<endl;
	}
	return 0;
}
