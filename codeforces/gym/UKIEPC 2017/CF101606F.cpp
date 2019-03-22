#include <bits/stdc++.h>
using namespace std;
int N, K;
double dp[456][456], res;
int main(){
	cout<<fixed<<setprecision(10);
	cin>>N>>K;
	dp[0][0]=1;
	if(N==1){
		for(int i=1; i<=K; i++)
			dp[i][1]=dp[i][0]=0.5*dp[i-1][0]+0.5*dp[i-1][1];
	}else{
		for(int i=1; i<=K; i++){
			for(int j=0; j<=N; j++){
				if(j==0) dp[i][j]=0.5*dp[i-1][j];
				else if(j==N-1) dp[i][j]=0.5*dp[i-1][j+1]+0.5*dp[i-1][j]+0.5*dp[i-1][j-1];
				else dp[i][j]=0.5*dp[i-1][j-1]+0.5*dp[i-1][j];
			}
		}
	}
	for(int i=0; i<=N; i++)
		res+=dp[K][i]*i;
	cout<<res<<endl;
	return 0;
}
