// 这题uDebug的标程有问题
// 错误数据在代码后
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
#define FOR(i, a, b) for(int (i)=(a); (i)<=(b); (i)++)
#define REP(i, n) FOR(i, 0, (n)-1)
const int maxn=213;
const int maxd=10;
struct Player{
	int p, id;
	bool operator < (const Player& rhs) const{
		return p>rhs.p;
	}
}match[maxn][maxn], d[maxn][maxd];
int dp[maxn][maxd][maxd][maxd][maxd];
int T, n, m, g;
bool check(int pos, int p0, int p1, int p2, int p3, int p4){
	int id=d[pos][p0].id;
	if(pos>1){
		if(id==d[pos-1][p1].id) return false;
	}else return true;
	if(pos>2){
		if(id==d[pos-2][p2].id) return false;
	}else return true;
	if(pos>3){
		if(id==d[pos-3][p3].id) return false;
	}else return true;
	return id!=d[pos-4][p4].id;
}
int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d%d%d", &n, &m, &g);
		FOR(i, 1, m){
			FOR(j, 1, n){
				scanf("%d", &match[i][j].p);
				match[i][j].id=j;
			}
			sort(match[i]+1, match[i]+n+1);
		}
		g+=10;
		memset(d, 0, sizeof(d));
		int upp=min(n+1, maxd);
		FOR(i, 1, g){
			int u;
			scanf("%d", &u);
			FOR(j, 1, upp) d[i][j]=match[u][j];
		}
		memset(dp, 0xc0, sizeof(dp));
		dp[0][0][0][0][0]=0;
		FOR(i, 1, g) REP(p1, upp) REP(p2, upp) REP(p3, upp) REP(p4, upp){
							if(!d[i][1].id) dp[i][0][p1][p2][p3]=max(dp[i][0][p1][p2][p3], dp[i-1][p1][p2][p3][p4]);
							else{
								FOR(p0, 1, upp-1) if(check(i, p0, p1, p2, p3, p4))
										dp[i][p0][p1][p2][p3]=max(dp[i][p0][p1][p2][p3],
																  dp[i-1][p1][p2][p3][p4]+d[i][p0].p);
							}
						}
		int ans=0xc0c0c0c0;
		REP(p1, upp) REP(p2, upp) REP(p3, upp) REP(p4, upp) ans=max(ans, dp[g][p1][p2][p3][p4]);
		printf("%.2lf\n", double(ans)/100);
	}
	return 0;
}
/*
 * 1
 * 6 6 6
 * 90 0 0 0 0 0
 * 0 90 0 0 0 0
 * 0 0 90 0 0 0
 * 0 0 0 90 0 0
 * 89 89 89 89 90 88
 * 0 0 0 0 100 0
 * 1
 * 2
 * 3
 * 4
 * 5
 * 6
 * 0
 * 0
 * 0
 * 0
 * 0
 * 0
 * 0
 * 0
 * 0
 * 0
 */
