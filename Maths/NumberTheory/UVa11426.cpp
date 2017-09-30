#include <iostream>
#include <cstring>
using namespace std;
const int maxn=4000000;
int phi[maxn+100];
void phi_table(int n){
	memset(phi, 0, sizeof(phi));
	phi[1]=1;
	for(int i=2; i<=n; i++){
		if(!phi[i]){
			for(int j=i; j<=n; j+=i){
				if(!phi[j]) phi[j]=j;
				phi[j]=phi[j]/i*(i-1);
			}
		}
	}
}
long long S[maxn+100], f[maxn+100];
int main(){
	phi_table(maxn);
	memset(f, 0, sizeof(f));
	for(int i=1; i<=maxn; i++)
		for(int n=i*2; n<=maxn; n+=i)
			f[n]+=i*phi[n/i];
	S[2]=f[2];
	for(int n=3; n<=maxn; n++)
		S[n]=S[n-1]+f[n];
	int n;
	while(cin>>n){
		if(!n) break;
		cout<<S[n]<<endl;
	}
	return 0;
}
