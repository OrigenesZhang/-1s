// 编号不影响期望所以用map记状态
// 想不到会这么快因为实际上dfs2是拷贝了map的
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
using namespace std;
const int maxn=35;
typedef map<int, int> vec;
map<pair<int, vec>, double> dp;
bool vis[maxn];
int cnt[maxn];
vector<int> G[maxn];
int T, N, M;
void dfs1(int u){
	vis[u]=true;
	cnt[u]=1;
	for(int v:G[u]){
		if(vis[v]) continue;
		dfs1(v);
		cnt[u]+=cnt[v];
	}
}
double dfs2(int i, const vec& s){
	if(i==N) return 0;
	if(dp.count(make_pair(i, s))>0) return dp[make_pair(i, s)];
	vec nxt=s;
	double cur=1;
	for(auto& it:nxt){
		if(!it.second) continue;
		it.second--;
		cur+=(it.second+1)*(it.first)*dfs2(i+it.first, nxt)/(N-1);
		it.second++;
	}
	cur/=(1-double(i-1)/(N-1));
	return dp[make_pair(i, s)]=cur;
}
int main(){
	scanf("%d", &T);
	for(int cs=1; cs<=T; cs++){
		scanf("%d%d", &N, &M);
		for(int i=1; i<=N; i++) G[i].clear();
		while(M--){
			int u, v;
			scanf("%d%d", &u, &v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		vec v;
		memset(vis, false, sizeof(vis));
		for(int i=1; i<=N; i++){
			if(!vis[i]){
				dfs1(i);
				if(i>1) v[cnt[i]]++;
			}
		}
		dp.clear();
		printf("Case %d: %.10lf\n", cs, dfs2(cnt[1], v));
	}
	return 0;
}
