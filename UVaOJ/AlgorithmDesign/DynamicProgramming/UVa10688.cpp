#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define FOR(i, a, b) for(int (i)=(a); (i)<=(b); (i)++)
const int maxn=511;
int dp[maxn][maxn];
int T, N, K;
void init(){
	memset(dp, 0x3f, sizeof(dp));
	memset(dp[0], 0, sizeof(dp[0]));
	memset(dp[1], 0, sizeof(dp[1]));
	FOR(n, 2, 500)
		FOR(k, 0, 500-n)
			FOR(i, 1, n)
				dp[n][k]=min(dp[n][k], dp[i-1][k]+n*(i+k)+dp[n-i][i+k]);
}
int main(){
	init();
	scanf("%d", &T);
	FOR(cs, 1, T){
		scanf("%d%d", &N, &K);
		printf("Case %d: %d\n", cs, dp[N][K]);
	}
	return 0;
}
