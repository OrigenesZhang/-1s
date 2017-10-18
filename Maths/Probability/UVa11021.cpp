#include <iostream>
#include <cmath>
using namespace std;
const int maxn=1024;
int n, k, m, N;
double P[maxn+1], dp[maxn+1];
int main(){
	cin>>N;
	for(int cs=1; cs<=N; cs++){
		cin>>n>>k>>m;
		for(int i=0; i<n; i++)
			cin>>P[i];
		dp[0]=0;
		dp[1]=P[0];
		for(int i=2; i<=m; i++){
			dp[i]=0;
			for(int j=0; j<n; j++)
				dp[i]+=P[j]*pow(dp[i-1], j);
		}
		cout<<"Case #"<<cs<<": "<<pow(dp[m], k)<<endl;
	}
	return 0;
}
