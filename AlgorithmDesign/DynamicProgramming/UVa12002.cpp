#include <cstdio>
#include <iostream>
using namespace std;
#define FOR(i, a, b) for(int (i)=(a); (i)<=(b); (i)++)
#define ROF(i, a, b) for(int (i)=(a); (i)>=(b); (i)--)
const int maxn=511;
int N, k[maxn], dp[2][maxn];
int main(){
	while(scanf("%d", &N)==1){
		if(!N) break;
		FOR(i, 1, N) scanf("%d", &k[i]);
		ROF(i, N, 1){
			dp[0][i]=dp[1][i]=1;
			ROF(j, N, i+1){
				if(k[i]<=k[j]) dp[0][i]=max(dp[0][i], dp[0][j]+1);
				if(k[i]>=k[j]) dp[1][i]=max(dp[1][i], dp[1][j]+1);
			}
		}
		int ans=0;
		FOR(i, 1, N){
			ans=max(ans, dp[0][i]);
			ans=max(ans, dp[1][i]);
			FOR(j, i+1, N){
				if(k[j]<k[i]) ans=max(ans, dp[0][i]+dp[1][j]);
				else if(k[j]>k[i]) ans=max(ans, dp[1][i]+dp[0][j]);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
