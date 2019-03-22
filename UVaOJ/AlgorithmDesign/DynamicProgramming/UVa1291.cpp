// 好恶心
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
const int opp[]={0, 3, 4, 1, 2};
const int inf=0x3f3f3f3f;
int dp[2][5][5], n, p;
map<pii, vector<pii>> G;
inline int dist(int x, int y){
	if(x>y) swap(x, y);
	if(x==y) return 1;
	if(!x) return 2;
	if(opp[x]==y) return 4;
	return 3;
}
int dist(const pii& x, const pii& y){
	if(x==y) return 1;
	if(x.first==y.first)
		return dist(x.second, y.second);
	if(x.first==y.second)
		return dist(x.second, y.first);
	if(x.second==y.first)
		return dist(x.first, y.second);
	if(x.second==y.second)
		return dist(x.first, y.first);
	return inf;
}
void init(){
	G.clear();
	for(int i=1; i<5; i++)
		G[make_pair(0, 0)].push_back(make_pair(0, i));
	for(int i=0; i<5; i++){
		for(int j=i+1; j<5; j++){
			pii p1=make_pair(i, j);
			for(int u=0; u<5; u++){
				for(int v=u+1; v<5; v++){
					pii p2=make_pair(u, v);
					if(dist(p1, p2)!=inf){
						G[p1].push_back(p2);
						G[p2].push_back(p1);
					}
				}
			}
		}
	}
}
int main(){
	init();
	while(scanf("%d", &p)==1){
		if(!p) break;
		memset(dp, 0x3f, sizeof(dp));
		dp[0][0][0]=0;
		n=0;
		do{
			memset(dp[n^1], 0x3f, sizeof(dp[n^1]));
			for(int i=0; i<5; i++){
				for(int j=i; j<5; j++){
					pii u=make_pair(i, j);
					for(const auto& v:G[u]){
						if(v.first!=p&&v.second!=p) continue;
            // if the current state meets the requirement, transition is restricted only to the stall case
						if((i==p||j==p)&&u!=v) continue;
						dp[n^1][v.first][v.second]=min(dp[n^1][v.first][v.second], dp[n][i][j]+dist(u, v));
					}
				}
			}
			n^=1;
		}while(scanf("%d", &p)==1&&p);
		int ans=inf;
		for(int i=0; i<5; i++)
			for(int j=i+1; j<5; j++)
				ans=min(ans, dp[n][i][j]);
		printf("%d\n", ans);
	}
	return 0;
}
