#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
const int maxn=1234;
bool vis[maxn];
pii dp[maxn][2];		// dp[u][selected] = <lamppost, singly-lighted>
int T, N, M;
vector<int> G[maxn];
void init(){
	for(int i=0; i<N; i++)
		G[i].clear();
	memset(vis, false, sizeof(vis));
}
void dfs(int u){
	vis[u]=true;
	dp[u][0]=make_pair(0, 0);
	dp[u][1]=make_pair(1, 0);
	for(int v:G[u]){
		if(vis[v]) continue;
		dfs(v);
		dp[u][0].first+=dp[v][1].first;
		dp[u][0].second+=dp[v][1].second+1;
		if(dp[v][0]<dp[v][1]){
			dp[u][1].first+=dp[v][0].first;
			dp[u][1].second+=dp[v][0].second+1;
		}else{
			dp[u][1].first+=dp[v][1].first;
			dp[u][1].second+=dp[v][1].second;
		}
	}
}
int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &N, &M);
		init();
		for(int i=0; i<M; i++){
			int u, v;
			scanf("%d%d", &u, &v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		pii ans=make_pair(0, 0);
		for(int i=0; i<N; i++){
			if(!vis[i]){
				dfs(i);
				pii cur=min(dp[i][0], dp[i][1]);
				ans.first+=cur.first;
				ans.second+=cur.second;
			}
		}
		printf("%d %d %d\n", ans.first, M-ans.second, ans.second);
	}
	return 0;
}
