// 几何模型下的区间dp
// 和之前一题比较像
// 这题海伦公式不用eps都能过真是友善
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define FOR(i, a, b) for(int (i)=(a); (i)<=(b); (i)++)
#define REP(i, n) FOR(i, 0, (n)-1)
const int maxn=45;
const double pi=4*atan(1);
double dist[maxn][maxn], p[maxn], dp[maxn][maxn][maxn], s[maxn][maxn][maxn];
int n, m;
inline double d(int u, int v){
	double diff=p[v]-p[u];
	if(diff>0.5) diff=1-diff;
	return 2*sin(pi*diff);
}
inline double area(double a, double b, double c){
	double p=(a+b+c)/2;
	return sqrt(p*(p-a)*(p-b)*(p-c));
}
int main(){
	while(scanf("%d%d", &n, &m)==2){
		if(!n) break;
		REP(i, n) scanf("%lf", &p[i]);
		REP(i, n) FOR(j, i+1, n-1) dist[i][j]=dist[j][i]=d(i, j);
		REP(i, n) FOR(j, i+1, n-1) FOR(k, j+1, n-1){
					double a=area(dist[i][j], dist[i][k], dist[j][k]);
					s[i][j][k]=s[i][k][j]=s[j][i][k]=s[j][k][i]=s[k][i][j]=s[k][j][i]=a;
				}
		memset(dp, 0, sizeof(dp));
		FOR(l, 3, m) REP(i, n) FOR(j, i+1, n-1) FOR(k, j+1, n-1) dp[i][k][l]=max(dp[i][k][l], dp[i][j][l-1]+s[i][j][k]);
		double ans=0;
		REP(i, n) FOR(j, i+1, n-1) ans=max(ans, dp[i][j][m]);
		printf("%.6lf\n", ans);
	}
	return 0;
}
