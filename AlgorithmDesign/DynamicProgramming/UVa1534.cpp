#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
#define FOR(i, a, b) for(int (i)=(a); (i)<=(b); (i)++)
const int maxn=511;
double w1[maxn], w2[maxn], dp[maxn][maxn];
int n1, n2, T;
double solve(double* w1, double* w2, int n1, int n2){
	FOR(i, 1, n1){
		dp[i][i]=dp[i-1][i-1]+fabs(w1[i]-w2[i]);
		FOR(j, i+1, n2) dp[i][j]=min(dp[i-1][j-1]+fabs(w1[i]-w2[j]), dp[i][j-1]);
	}
	return dp[n1][n2];
}
int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &n1, &n2);
		FOR(i, 1, n1) scanf("%lf", &w1[i]);
		FOR(i, 1, n2) scanf("%lf", &w2[i]);
		sort(w1+1, w1+n1+1);
		sort(w2+1, w2+n2+1);
		printf("%.1lf\n", (n1>n2)?solve(w2, w1, n2, n1):solve(w1, w2, n1, n2));
	}
	return 0;
}
