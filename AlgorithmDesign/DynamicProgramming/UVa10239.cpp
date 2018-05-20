// 精度
#include <cstdio>
#include <algorithm>
using namespace std;
#define FOR(i, a, b) for(int (i)=(a); (i)<=(b); (i)++)
#define REP(i, n) FOR(i, 0, (n)-1)
#define ROF(i, a, b) for(int (i)=(a); (i)>=(b); (i)--)
const int maxn=1234;
const double eps=1e-8;
int N;
double W, s[maxn], h[maxn], w[maxn], dp[maxn][maxn], mmax[maxn][maxn];
int main(){
	while(scanf("%d", &N)==1){
		if(!N) break;
		scanf("%lf", &W);
		FOR(i, 1, N) scanf("%lf%lf", &h[i], &w[i]);
		FOR(i, 1, N) s[i]=s[i-1]+w[i];
		REP(i, N+1) REP(j, N+1) dp[i][j]=1e15;
		FOR(i, 1, N) FOR(j, i, N) mmax[i][j]=max(mmax[i][j-1], h[j]);
		dp[1][1]=h[1];
		FOR(i, 2, N){
			ROF(j, i-1, 1){
				if(s[i-1]-s[j-1]>W+eps) break;
				dp[i][i]=min(dp[i][i], dp[i-1][j]+h[i]);
				if(s[i]-s[j-1]<W+eps){
					double cur=dp[i-1][j];
					if(h[i]>mmax[j][i-1]) cur+=h[i]-mmax[j][i-1];
					dp[i][j]=min(dp[i][j], cur);
				}
			}
		}
		double ans=1e15;
		FOR(i, 1, N) ans=min(ans, dp[N][i]);
		printf("%.4lf\n", ans);
	}
	return 0;
}
