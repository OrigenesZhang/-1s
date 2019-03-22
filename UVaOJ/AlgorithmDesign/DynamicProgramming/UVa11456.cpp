// 和12002类似但是更简单
#include <cstdio>
#include <iostream>
using namespace std;
#define FOR(i, a, b) for(int (i)=(a); (i)<=(b); (i)++)
#define ROF(i, a, b) for(int (i)=(a); (i)>=(b); (i)--)
const int maxn=2134;
int dp[2][maxn], a[maxn], T, n;
int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		FOR(i, 1, n) scanf("%d", &a[i]);
		int ans=0;
		ROF(i, n, 1){
			dp[0][i]=dp[1][i]=1;
			ROF(j, n, i+1){
				if(a[i]>a[j]) dp[0][i]=max(dp[0][j]+1, dp[0][i]);
				else dp[1][i]=max(dp[1][j]+1, dp[1][i]);
			}
			ans=max(ans, dp[0][i]+dp[1][i]-1);
		}
		printf("%d\n", ans);
	}
	return 0;
}
