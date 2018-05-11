#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pli;
const int maxn=123;
const int maxm=12345;
int n, m, K;
deque<pli> q;
ll dp[maxn][maxm][3], dist[maxn][maxm], cost[maxn][maxm][2], G[maxn][maxm], s[maxn][maxm][2];
int main(){
	while(scanf("%d%d%d", &n, &m, &K)==3){
		if(!n&&!m&&!K) break;
		for(int i=0; i<=n; i++)
			for(int j=1; j<=m; j++)
				scanf("%lld", &G[i][j]);
		for(int i=0; i<=n; i++)
			for(int j=1; j<=m; j++)
				scanf("%lld", &dist[i][j]);
		for(int i=0; i<=n; i++){
			s[i][0][0]=cost[i][0][0]=0;
			for(int j=1; j<=m; j++){
				s[i][j][0]=s[i][j-1][0]+G[i][j];
				cost[i][j][0]=cost[i][j-1][0]+dist[i][j];
			}
			s[i][m][1]=cost[i][m][1]=0;
			for(int j=m-1; j>=0; j--){
				s[i][j][1]=s[i][j+1][1]+G[i][j+1];
				cost[i][j][1]=cost[i][j+1][1]+dist[i][j+1];
			}
		}
		for(int i=0; i<=n; i++){
			if(i>0){
				for(int j=0; j<=m; j++)
					dp[i][j][2]=dp[i-1][j][2];
			}else{
				for(int j=0; j<=m; j++)
					dp[i][j][2]=0;
			}
			if(!q.empty()){
				deque<pli> tmp;
				swap(tmp, q);
			}
			q.push_back(make_pair(dp[i][0][2], 0));
			for(int j=1; j<=m; j++){
				while(!q.empty()&&cost[i][j][0]-cost[i][q.front().second][0]>K) q.pop_front();
				while(!q.empty()&&s[i][j][0]-s[i][q.back().second][0]+dp[i][q.back().second][2]<=dp[i][j][2]) q.pop_back();
				q.push_back(make_pair(dp[i][j][2], j));
				dp[i][j][0]=q.front().first+s[i][j][0]-s[i][q.front().second][0];
			}
			if(!q.empty()){
				deque<pli> tmp;
				swap(tmp, q);
			}
			q.push_back(make_pair(dp[i][m][2], m));
			for(int j=m-1; j>=0; j--){
				while(!q.empty()&&cost[i][j][1]-cost[i][q.front().second][1]>K) q.pop_front();
				while(!q.empty()&&s[i][j][1]-s[i][q.back().second][1]+dp[i][q.back().second][2]<=dp[i][j][2]) q.pop_back();
				q.push_back(make_pair(dp[i][j][2], j));
				dp[i][j][1]=q.front().first+s[i][j][1]-s[i][q.front().second][1];
			}
			for(int j=0; j<=m; j++)
				dp[i][j][2]=max(max(dp[i][j][1], dp[i][j][0]), dp[i][j][2]);
		}
		ll ans=0;
		for(int i=0; i<=m; i++)
			ans=max(ans, dp[n][i][2]);
		printf("%lld\n", ans);
	}
	return 0;
}
