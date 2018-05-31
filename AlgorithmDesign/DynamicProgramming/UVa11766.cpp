// 写法要简洁代码要短txtx
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define FOR(i, a, b) for(int (i)=(a); (i)<=(b); (i)++)
#define REP(i, n) FOR(i, 0, (n)-1)
const int maxn=1234;
int n, cs=1, cnt[maxn][maxn], dp[maxn];
int main(){
	while(scanf("%d", &n)==1){
		if(!n) break;
		memset(cnt, 0, sizeof(cnt));
		int a, b;
		REP(i, n){
			scanf("%d%d", &a, &b);
			cnt[a+1][n-b]++;
		}
		FOR(i, 1, n){
			dp[i]=0;
			REP(j, i) dp[i]=max(dp[i], dp[j]+min(cnt[j+1][i], i-j));
		}
		printf("Case %d: %d\n", cs++, n-dp[n]);
	}
	return 0;
}
