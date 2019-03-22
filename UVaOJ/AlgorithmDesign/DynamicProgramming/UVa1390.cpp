#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
using namespace std;
#define FOR(i, a, b) for(int (i)=(a); (i)<=(b); (i)++)
const int maxn=35;
typedef map<int, int> State;
map<State, double> dp;
int n, m, sz[maxn];
bool vis[maxn];
vector<int> G[maxn];
void dfs1(int u){
	vis[u]=true;
	for(int v:G[u]){
		if(vis[v]) continue;
		dfs1(v);
		sz[u]+=sz[v];
	}
}
double dfs2(const State& s){
	if(dp.find(s)!=dp.end()) return dp[s];
	if(s.size()==1&&s.begin()->first==n) return dp[s]=0;
	double ans=0, totp=0;
	for(auto it1=s.begin(); it1!=s.end(); ++it1){
		for(auto it2=next(it1); it2!=s.end(); ++it2){
			State s0=s;
			int sz1=it1->first, sz2=it2->first;
			double p=double(sz1)*s0[sz1]*sz2*s0[sz2]/(n*(n-1)/2);
			s0[sz1]--, s0[sz2]--;
			s0[sz1+sz2]++;
			if(!s0[sz1]) s0.erase(sz1);
			if(!s0[sz2]) s0.erase(sz2);
			ans+=p*dfs2(s0);
			totp+=p;
		}
		if(it1->second<2) continue;
		State s0=s;
		int sz1=it1->first;
		double p=double(sz1)*sz1*s0[sz1]*(s0[sz1]-1)/(n*(n-1));
		s0[sz1]-=2;
		s0[2*sz1]++;
		if(!s0[sz1]) s0.erase(sz1);
		ans+=p*dfs2(s0);
		totp+=p;
	}
	ans+=1;
	return dp[s]=ans/totp;
}
int main(){
	while(scanf("%d%d", &n, &m)==2){
		memset(vis, false, sizeof(vis));
		FOR(i, 1, n){
			G[i].clear();
			sz[i]=1;
		}
		while(m--){
			int u, v;
			scanf("%d%d", &u, &v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		dp.clear();
		State s;
		FOR(i, 1, n) if(!vis[i]){
				dfs1(i);
				s[sz[i]]++;
			}
		printf("%.6lf\n", dfs2(s));
	}
	return 0;
}
