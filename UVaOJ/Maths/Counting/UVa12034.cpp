#include <iostream>
using namespace std;
const int MOD=10056;
int T, n, C[1025][1025], dp[1025];
int main(){
	C[0][0]=1;
	for(int i=1; i<=1000; i++){
		C[i][0]=1;
		for(int j=1; j<=i; j++)
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
	}
	dp[0]=1;
	for(int i=1; i<=1000; i++)
		for(int j=1; j<=i; j++)
			dp[i]=(dp[i]+dp[i-j]*C[i][j])%MOD;
	cin>>T;
	for(int cs=1; cs<=T; cs++){
		cin>>n;
		cout<<"Case "<<cs<<": "<<dp[n]<<endl;
	}
	return 0;
}
