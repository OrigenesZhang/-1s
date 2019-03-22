#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define FOR(i, a, b) for(int (i)=(a); (i)<=(b); (i)++)
const int maxn=1234;
const int maxc=11;
const int inf=0x3f3f3f3f;
struct Lamp{
	int v, k, l, c;
	bool operator < (const Lamp& rhs) const{
		return v>rhs.v;
	}
}lamps[maxn];
int dp[maxn][maxc], n;
int main(){
	while(scanf("%d", &n)==1){
		if(!n) break;
		FOR(i, 1, n) scanf("%d%d%d%d", &lamps[i].v, &lamps[i].k, &lamps[i].c, &lamps[i].l);
		sort(lamps+1, lamps+n+1);
		memset(dp, 0x3f, sizeof(dp));
		dp[1][lamps[1].c]=lamps[1].k+lamps[1].c*lamps[1].l;
		FOR(i, 2, n){
			FOR(j, 1, maxc-1){
				if(dp[i-1][j]!=inf) dp[i][j]=dp[i-1][j]+lamps[i].l*j;
				if(j==lamps[i].c)
					FOR(k, 1, maxc-1)
						dp[i][j]=min(dp[i][j], dp[i-1][k]+lamps[i].k+lamps[i].c*lamps[i].l);
			}
		}
		int ans=inf;
		FOR(i, 1, maxc-1) ans=min(ans, dp[n][i]);
		printf("%d\n", ans);
	}
	return 0;
}
