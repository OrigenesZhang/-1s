#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;
#define FOR(i, a, b) for(int (i)=(a); (i)<=(b); (i)++)
#define REP(i, n) FOR(i, 0, (n)-1)
const int maxn=12;
const int maxt=1234;
const int mult=210;
const double inf=1e14;
const double eps=1e-8;
double dp[maxn][maxn][maxt*mult];
int L, v[2][maxn];
int T, n, xs, ys, xt, yt, tl, tr, sx, sy;
inline double fuel(int L, int v){
	return L/(80-0.03*v*v);
}
void dfs(int x, int y, int t, double f){
	if(f>dp[x][y][t]-eps) return;
	dp[x][y][t]=f;
	if((xt-x)*sx>0){
		for(int u=v[0][y]; u>=5; u-=5){
			int nt=t+L*60*mult/u;
			if(nt>tr) break;
			dfs(x+sx, y, nt, f+fuel(L, u));
		}
	}
	if((yt-y)*sy>0){
		for(int u=v[1][x]; u>=5; u-=5){
			int nt=t+L*60*mult/u;
			if(nt>tr) break;
			dfs(x, y+sy, nt, f+fuel(L, u));
		}
	}
}
int main(){
	scanf("%d", &T);
	FOR(cs, 1, T){
		scanf("%d%d", &n, &L);
		FOR(i, 1, n) scanf("%d", &v[0][i]);
		FOR(i, 1, n) scanf("%d", &v[1][i]);
		scanf("%d%d%d%d%d%d", &xs, &ys, &xt, &yt, &tl, &tr);
		sx=xt<xs?-1:1;
		sy=yt<ys?-1:1;
		tl*=mult, tr*=mult;
		FOR(i, 1, n) FOR(j, 1, n) REP(t, maxt*mult) dp[i][j][t]=1e15;
		dfs(xs, ys, 0, 0);
		printf("Scenario %d:\n", cs);
		int ans[]={-1, -1};
		FOR(t, tl, tr){
			if(dp[xt][yt][t]>inf) continue;
			if(ans[0]<0) ans[0]=ans[1]=t;
			else if(dp[xt][yt][t]<dp[xt][yt][ans[1]]-eps) ans[1]=t;
		}
		if(ans[0]<0){
			puts("IMPOSSIBLE");
			continue;
		}
		printf("The earliest  arrival: %.0lf minutes, fuel %.2lf gallons\n", ceil(double(ans[0])/mult), dp[xt][yt][ans[0]]);
		printf("The economical travel: %.0lf minutes, fuel %.2lf gallons\n", ceil(double(ans[1])/mult), dp[xt][yt][ans[1]]);
	}
	return 0;
}
