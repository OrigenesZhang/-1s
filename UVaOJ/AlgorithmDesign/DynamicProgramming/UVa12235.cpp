#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn=123;
const int maxm=8;
const int inf=0x3f3f3f3f;
int dp[maxn][maxn][1<<maxm][maxm+1], a[maxn], cost[maxn], m[maxn];
int N, K, n, ALL, cs=1;
void init(){
	ALL=n=0;
	memset(dp, 0x3f, sizeof(dp));
}
inline int diff_true(int mask, int ALL){
	int ret=0;
	for(int i=0; i<maxm; i++)
		if((ALL&(1<<i))&&(!(mask&(1<<i)))) ret++;
	return ret;
}
int main(){
	while(scanf("%d%d", &N, &K)==2){
		if(!N&&!K) break;
		init();
		for(int i=1; i<=N; i++) scanf("%d", &a[i]);
		int p=0;
		for(int i=1; i<=N; i++){
			if(a[i]==p) cost[n]++;
			else{
				cost[++n]=1;
				m[n]=a[i]-25;
				p=a[i];
				ALL|=1<<m[n];
			}
		}
		dp[0][K][0][8]=0;
		for(int i=0; i<n; i++){
			for(int j=K; j>=0; j--){
				for(int mask=0; mask<=ALL; mask++){
					for(int k=0; k<9; k++){
						dp[i+1][j][mask|(1<<m[i+1])][m[i+1]]=min(dp[i+1][j][mask|(1<<m[i+1])][m[i+1]], dp[i][j][mask][k]+(k!=m[i+1]));
						if(j>=cost[i+1])
							dp[i+1][j-cost[i+1]][mask][k]=min(dp[i+1][j-cost[i+1]][mask][k], dp[i][j][mask][k]);
					}
				}
			}
		}
		int ans=inf;
		for(int j=0; j<=K; j++)
			for(int mask=0; mask<=ALL; mask++)
				for(int k=0; k<9; k++)
					ans=min(ans, dp[n][j][mask][k]+diff_true(mask, ALL));
		printf("Case %d: %d\n", cs++, ans);
		puts("");
	}
	return 0;
}
