// 预处理 + 查询
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int maxn=511;
const int inf=0x3f3f3f3f;
struct Edge{
	int u, v, w;
};
int dp[maxn][maxn][2];
int cnt[maxn];
vector<int> G[maxn];
vector<Edge> e;
int n, q, cs=1;
void dfs(int u, int p){
	cnt[u]=1;
	for(int nxt:G[u]){
		int v=e[nxt].v, w=e[nxt].w;
		if(v==p) continue;
		dfs(v, u);
		cnt[u]+=cnt[v];
	}
	dp[u][0][0]=dp[u][0][1]=dp[u][1][0]=dp[u][1][1]=0;
	for(int nxt:G[u]){
		int v=e[nxt].v, w=e[nxt].w;
		if(v==p) continue;
		for(int i=cnt[u]; i>=2; i--){
			for(int j=0; j<=cnt[v]&&j<i; j++){
				dp[u][i][0]=min(dp[u][i][0], dp[u][i-j][0]+dp[v][j][0]+2*w);
				dp[u][i][1]=min(dp[u][i][1], dp[u][i-j][0]+dp[v][j][1]+w);
				dp[u][i][1]=min(dp[u][i][1], dp[u][i-j][1]+dp[v][j][0]+2*w);
			}
		}
	}
}
int main(){
	while(scanf("%d", &n)==1){
		if(!n) break;
		e.clear();
		for(int i=0; i<n; i++)
			G[i].clear();
		for(int i=1; i<n; i++){
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			G[u].push_back(e.size());
			e.push_back({u, v, w});
			G[v].push_back(e.size());
			e.push_back({v, u, w});
		}
		memset(dp, 0x3f, sizeof(dp));
		dfs(0, -1);
		printf("Case %d:\n", cs++);
		scanf("%d", &q);
		while(q--){
			int x;
			scanf("%d", &x);
			int ans=n;
			for(int i=1; i<=n; i++)
				if(dp[0][i][1]>x){
					ans=i-1;
					break;
				}
			printf("%d\n", ans);
		}
	}
	return 0;
}
