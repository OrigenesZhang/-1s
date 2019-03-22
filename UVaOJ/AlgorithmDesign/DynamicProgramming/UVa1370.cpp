// 状态表示只维护时间差 + 滚动数组优化空间
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define FOR(i, a, b) for(int (i)=(a); (i)<=(b); (i)++)
#define REP(i, n) FOR(i, 0, (n)-1)
#define ROF(i, a, b) for(int (i)=a; (i)>=(b); (i)--)
#define PER(i, n) ROF(i, (n)-1, 0)
const int maxn=312;
const int maxt=123;
const int offset=105;
int dp[2][maxn][maxt<<1], f[2][maxt], u[2][maxn];
int T, n, a, b;
inline int t(int i, int j){
	return f[i][u[i][j]];
}
inline void upd(int& a, int b){
	if(b==-1) return;
	if(a==-1) a=b;
	else a=min(a, b);
}
int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		REP(i, 2) FOR(j, 1, n) scanf("%d", &f[i][j]);
		scanf("%d%d", &a, &b);
		FOR(i, 1, a) scanf("%d", &u[0][i]);
		FOR(i, 1, b) scanf("%d", &u[1][i]);
		memset(dp, -1, sizeof(dp));
		dp[0][0][offset]=0;
		int cur=0;
		FOR(i, 0, a){
			memset(dp[cur^1], -1, sizeof(dp[cur^1]));
			FOR(j, 0, b){
				FOR(k, offset-100, offset-1) upd(dp[cur][j][k+1], dp[cur][j][k]);
				ROF(k, offset+100, offset+1) upd(dp[cur][j][k-1], dp[cur][j][k]);
				FOR(k, offset-100, offset+100){
					if(dp[cur][j][k]==-1) continue;
					if(i!=a&&k<=offset){
						if(u[0][i+1]==u[1][j]) upd(dp[cur^1][j][t(0, i+1)+offset], dp[cur][j][k]+t(0, i+1));
						else upd(dp[cur^1][j][t(0, i+1)+k], dp[cur][j][k]+max(0, t(0, i+1)+k-offset));
					}
					if(j!=b&&k>=offset){
						if(u[1][j+1]==u[0][i]) upd(dp[cur][j+1][-t(1, j+1)+offset], dp[cur][j][k]+t(1, j+1));
						else upd(dp[cur][j+1][k-t(1, j+1)], dp[cur][j][k]+max(0, t(1, j+1)-k+offset));
					}
				}
			}
			cur^=1;
		}
		cur^=1;
		int ans=0x3f3f3f3f;
		FOR(i, offset-100, offset+100) upd(ans, dp[cur][b][i]);
		printf("%d\n", ans);
	}
	return 0;
}
