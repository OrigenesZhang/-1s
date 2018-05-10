#include <cstdio>
#include <vector>
using namespace std;
const int maxn=123;
int dp[2][maxn], a[maxn<<1];
vector<int> G[maxn];
int T, n1, n2, n;
int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &n1, &n2);
		for(int i=1; i<=n1; i++)
			G[i].clear();
		while(n2--){
			int u, v;
			scanf("%d%d", &u, &v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		scanf("%d", &n);
		for(int i=0; i<n; i++)
			scanf("%d", &a[i]);
		for(int i=1; i<=n1; i++)
			dp[0][i]=(i!=a[0]);
		for(int i=1; i<n; i++){
			for(int u=1; u<=n1; u++){
				dp[i&1][u]=dp[(i^1)&1][u]+(u!=a[i]);
				for(int v:G[u])
					dp[i&1][u]=min(dp[i&1][u], dp[(i^1)&1][v]+(u!=a[i]));
			}
		}
		int ans=0x3f3f3f3f;
		for(int i=1; i<=n1; i++)
			ans=min(ans, dp[(n-1)&1][i]);
		printf("%d\n", ans);
	}
	return 0;
}
