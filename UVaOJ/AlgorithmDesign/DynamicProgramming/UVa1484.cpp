#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
#define FOR(i, a, b) for(int (i)=(a); (i)<=(b); (i)++)
#define REP(i, n) FOR(i, 0, (n)-1)
const int maxn=512345;
struct Edge{
	int u, v, w;
};
vector<Edge> e;
vector<int> G[maxn];
int dp[maxn];
int N, L, R;
void upd(int& a, int b, int c){
	if(b==-1) return;
	if(a==-1){
		a=b;
		return;
	}
	if(c<0) a=min(a, b);
	else a=max(a, b);
}
int dfs(int u, int c, int path){
	if(path>R) return dp[u]=-1;
	for(int _e:G[u]){
		int v=e[_e].v, w=e[_e].w;
		upd(dp[u], dfs(v, -c, path+w), c);
	}
	if(G[u].empty()) dp[u]=path;
	if(dp[u]<L) dp[u]=-1;
	return dp[u];
}
int main(){
	while(scanf("%d%d%d", &N, &L, &R)==3){
		memset(dp, -1, sizeof(dp));
		e.clear();
		REP(i, N) G[i].clear();
		FOR(i, 1, N-1){
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			G[u].push_back(e.size());
			e.push_back({u, v, w});
		}
		int ans=dfs(0, 1, 0);
		if(ans==-1) puts("Oh, my god!");
		else printf("%d\n", ans);
	}
	return 0;
}
