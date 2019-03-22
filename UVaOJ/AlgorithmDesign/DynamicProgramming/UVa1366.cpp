#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
const int maxn=511;
ll sumy[maxn][maxn], sumb[maxn][maxn], dp[maxn][maxn][2];
int n, m;
int main(){
	while(scanf("%d%d", &n, &m)==2){
		if(!n&&!m) break;
		for(int i=1; i<=n; i++){
			for(int j=1; j<=m; j++){
				int cur;
				scanf("%d", &cur);
				sumy[i][j]=sumy[i][j-1]+cur;
			}
		}
		for(int i=1; i<=n; i++){
			for(int j=1; j<=m; j++){
				int cur;
				scanf("%d", &cur);
				sumb[i][j]=sumb[i-1][j]+cur;
			}
		}
		memset(dp, 0, sizeof(dp));
		for(int i=1; i<=n; i++){
			for(int j=1; j<=m; j++){
				dp[i][j][0]=max(dp[i-1][j][0], dp[i-1][j][1])+sumy[i][j];
				dp[i][j][1]=max(dp[i][j-1][0], dp[i][j-1][1])+sumb[i][j];
			}
		}
		printf("%lld\n", max(dp[n][m][0], dp[n][m][1]));
	}
	return 0;
}
