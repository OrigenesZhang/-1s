// 题意恶心
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int maxn=51234;
const int inf=0x3f3f3f3f;
vector<int> G[maxn];
int dp[maxn][3];
bool traps[maxn], vis[maxn];
int N, M;
int dfs(int u, int s){  // 如果查过一遍发现dp还是inf要把dp更新为inf-1不然会t
	if(dp[u][s]!=inf) return dp[u][s];
	vis[u]=true;
	int& ans=dp[u][s];
	if(traps[u]){
		vis[u]=false;
		if(!s) ans=0;
		else ans--;
		return ans;
	}
	vector<int> vec;
	if(u==1) vec.push_back(G[1][0]);
	else{
		int cnt=1;
		bool found=false;
		for(int i=0; cnt<G[u].size(); i=(i+1)%G[u].size()){
			int v=G[u][i];
			if(vis[v]){
				if(!found) found=true;
				continue;
			}
			if(!found) continue;
			vec.push_back(v);
			cnt++;
		}
	}
	if(vec.empty()){
		ans=(s==0);
	}else if(vec.size()==1){
		ans=dfs(vec[0], s);
	}else{
		int lson=vec[0], rson=vec[1];
		dp[u][2]=min(inf-1, min(min(dfs(lson, 2)+dfs(rson, 1), dfs(lson, 1)+dfs(rson, 2)), min(dfs(lson, 1)+dfs(rson, 0), dfs(lson, 0)+dfs(rson, 1))));
		dp[u][1]=min(inf-1, dfs(lson, 1)+dfs(rson, 1));
		dp[u][0]=min(inf-1, min(dfs(lson, 0)+dfs(rson, 0), min(dp[u][1], dp[u][2])+1));
	}
	vis[u]=false;
	return ans;
}
int main(){
	while(scanf("%d%d", &N, &M)==2){
		if(!N&&!M) break;
		for(int i=1; i<=N; i++){
			G[i].clear();
			int n;
			scanf("%d", &n);
			while(n--){
				int v;
				scanf("%d", &v);
				G[i].push_back(v);
			}
		}
		memset(traps, false, sizeof(traps));
		memset(vis, false, sizeof(vis));
		memset(dp, 0x3f, sizeof(dp));
		while(M--){
			int u;
			scanf("%d", &u);
			if(u!=1) traps[u]=true;
		}
		printf("%d\n", dfs(1, 0));
	}
	return 0;
}
