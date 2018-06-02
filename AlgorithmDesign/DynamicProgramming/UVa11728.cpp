#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
#define FOR(i, a, b) for(int (i)=(a); (i)<=(b); (i)++)
const int maxn=(1<<21)+15;
const int inf=0xc0c0c0c0;
int H, K, W[maxn], dp[maxn][21];
bool vis[maxn][21];
vector<int> G[maxn];
void init(){
	memset(vis, false, sizeof(vis));
	FOR(i, 1, 1<<H) G[i].clear();
}
void build(int u, int& p, int d){
	if(d==H){
		p=u+1;
		return;
	}
	G[u].push_back(u+1);
	int v;
	build(u+1, v, d+1);
	G[u].push_back(v);
	build(v, p, d+1);
}
int dfs(int u, int k){
	if(vis[u][k]) return dp[u][k];
	vis[u][k]=true;
	int& ans=dp[u][k];
	ans=inf;
	if(k==1) return ans=W[u];
	if(G[u].empty()) return ans;
	int v1=G[u][0], v2=G[u][1];
	FOR(i, 1, k-1) ans=max(ans, dfs(v1, i)+dfs(v2, k-i));
	return ans;
}
int main(){
	while(scanf("%d", &H)==1){
		if(H==-1) break;
		H++;
		scanf("%d", &K);
		FOR(i, 1, (1<<H)-1) scanf("%d", &W[i]);
		init();
		int p;
		build(1, p, 1);
		int ans=inf;
		FOR(i, 1, K) ans=max(ans, dfs(1, i));
		printf("%d\n", ans);
	}
	return 0;
}
