#include <iostream>
using namespace std;
const int maxn=30;
unsigned long long f[maxn][maxn];
int main(){
	f[1][0]=1;
	for(int i=2; i<=21; i++)
		for(int j=0; j<i; j++){
			f[i][j]=f[i-1][j];
			if(j>0) f[i][j]+=f[i-1][j-1]*(i-1);
		}
	int n, k;
	while(cin>>n>>k){
		if(!n) break;
		cout<<f[n][k]<<endl;
	}
	return 0;
}
