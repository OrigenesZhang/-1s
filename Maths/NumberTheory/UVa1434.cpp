//威尔逊定理: p为素数的充要条件为 (p-1)! == -1 (mod p)
#include <iostream>
#include <cmath>
using namespace std;
const int maxn=3*1000000+7;
int t, n, res[1000000+100];
bool vis[maxn+100];
void init(){
	int upp=sqrt(maxn)+0.5;
	for(int i=2; i<=upp; i++){
		if(vis[i]) continue;
		for(int j=i*i; j<=maxn; j+=i)
			vis[j]=true;
	}
	for(int i=1; i<=1000000; i++)
		res[i]=res[i-1]+(!vis[3*i+7]);
}
int main(){
	init();
	cin>>t;
	while(t--){
		cin>>n;
		cout<<res[n]<<endl;
	}
	return 0;
}
