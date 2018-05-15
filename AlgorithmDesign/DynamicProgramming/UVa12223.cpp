// 第一想法是维护200个点是否在子树中的状态LOL
// 应该是过不了的
// 优化很重要
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;
typedef long long ll;
const int maxn=51234;
struct Edge{
	int u, v, w;
};
vector<Edge> e;
vector<int> G[maxn], ans;
set<int> s;
map<int, int> pts;
ll dp[maxn], mmin;
int cnt[maxn], T, n, m;
bool vis[maxn];
void init(){
	memset(dp, 0x3f, sizeof(dp));
	memset(cnt, 0, sizeof(cnt));
	memset(vis, false, sizeof(vis));
	s.clear();
	ans.clear();
	pts.clear();
	for(int i=1; i<=n; i++) G[i].clear();
	e.clear();
}
void dfs1(int u){
	vis[u]=true;
	for(int _e:G[u]){
		int v=e[_e].v;
		if(vis[v]) continue;
		dfs1(v);
		cnt[u]+=cnt[v];
	}
}
void dfs2(int u, ll path, int p){
	if(!cnt[u]) return;
	if(s.find(u)!=s.end())
		dp[1]+=2*path*pts[u];
	for(int _e:G[u]){
		int v=e[_e].v, w=e[_e].w;
		if(v==p) continue;
		dfs2(v, path+w, u);
	}
}
void dfs3(int u, int p){
	for(int _e:G[u]){
		int v=e[_e].v, w=e[_e].w;
		if(v==p) continue;
		dp[v]=dp[u]+2*(ll(cnt[1]-cnt[v])*w-ll(cnt[v])*w);
		if(dp[v]<mmin){
			mmin=dp[v];
			ans={v};
		}else if(dp[v]==mmin)
			ans.push_back(v);
		dfs3(v, u);
	}
}
int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		init();
		for(int i=1; i<n; i++){
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			G[u].push_back(e.size());
			e.push_back({u, v, w});
			G[v].push_back(e.size());
			e.push_back({v, u, w});
		}
		scanf("%d", &m);
		for(int i=0; i<m; i++){
			int a, f;
			scanf("%d%d", &a, &f);
			cnt[a]=f;
			s.insert(a);
			pts[a]=f;
		}
		dfs1(1);
		dp[1]=0;
		dfs2(1, 0, -1);
		mmin=dp[1];
		ans.push_back(1);
		dfs3(1, -1);
		sort(ans.begin(), ans.end());
		printf("%lld\n", mmin);
		bool fst=true;
		for(int idx:ans){
			if(!fst) printf(" ");
			printf("%d", idx);
			fst=false;
		}
		puts("");
	}
	return 0;
}
