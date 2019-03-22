#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int maxn=2134;
int n;
vector<int> G[maxn];
int dp[maxn][2];
bool vis[maxn];
void init(){
	for(int i=0; i<n; i++) G[i].clear();
	memset(vis, false, sizeof(vis));
}
void dfs(int u){
	vis[u]=true;
	dp[u][0]=0;
	dp[u][1]=1;
	for(int v:G[u]){
		if(vis[v]) continue;
		dfs(v);
		dp[u][0]+=dp[v][1];
		if(dp[v][0]<dp[v][1]) dp[u][1]+=dp[v][0];
		else dp[u][1]+=dp[v][1];
	}
}
int main(){
	while(scanf("%d", &n)==1){
		init();
		for(int i=0; i<n; i++){
			int u, m;
			scanf("%d:(%d)", &u, &m);
			while(m--){
				int v;
				scanf("%d", &v);
				G[u].push_back(v);
				G[v].push_back(u);
			}
		}
		dfs(0);
		printf("%d\n", min(dp[0][0], dp[0][1]));
	}
	return 0;
}
