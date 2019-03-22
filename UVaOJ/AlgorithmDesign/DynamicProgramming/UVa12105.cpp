// python和Java写的高精度都T了
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define FOR(i, a, b) for(int (i)=(a); (i)<=(b); (i)++)
#define REP(i, n) FOR(i, 0, (n)-1)
#define ROF(i, a, b) for(int (i)=(a); (i)>=(b); (i)--)
const int maxn=123;
const int maxm=3123;
const int cost[]={6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int n, m, cs=1;
int dp[maxn][maxm], path[maxn][maxm];
int main(){
	while(scanf("%d", &n)==1){
		if(!n) break;
		scanf("%d", &m);
		memset(dp, -1, sizeof(dp));
		memset(path, -1, sizeof(path));
		REP(i, n+1) REP(j, m){
				if(!j) dp[i][0]=0;
				ROF(k, 9, 0){
					if(i>=cost[k]){
						if(dp[i-cost[k]][(j*10+k)%m]>=0&&dp[i-cost[k]][(j*10+k)%m]+1>dp[i][j]){
							dp[i][j]=dp[i-cost[k]][(j*10+k)%m]+1;
							path[i][j]=k;
						}
					}
				}
			}
		printf("Case %d: ", cs++);
		if(path[n][0]==-1){
			puts("-1");
			continue;
		}
		int i=n, j=0;
		for(int d=path[i][j]; d>=0; d=path[i][j]){
			printf("%d", d);
			i-=cost[d];
			j=(j*10+d)%m;
		}
		puts("");
	}
	return 0;
}
