// 贪心地只染两种颜色是错误的 错误数据在代码后
// 容易证明所用颜色数量不会超过ceil(sqrt(n)) 所以算法复杂度不超过O(n*sqrt(n)) 对于本题的数据已经足够优秀
// 但是这个上界其实远远超过所需要的颜色数量
// 在给定的n但不确定的图的布局下保证正确的最小颜色数应该是一个有趣[同时也有难度]的数学问题

#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
#define FOR(i, a, b) for(int (i)=(a); (i)<=(b); (i)++)
#define REP(i, n) FOR(i, 0, (n)-1)
const int maxn=12345;
const int inf=0x3f3f3f3f;
vector<int> G[maxn];
int dp[maxn][int(sqrt(maxn))], n;
int dfs(int u, int p, int c){
	if(dp[u][c]!=inf) return dp[u][c];
	int& ans=dp[u][c];
	ans=c;
	for(int v:G[u]){
		if(v==p) continue;
		int mmin=inf;
		FOR(cc, 1, 100) if(cc!=c) mmin=min(mmin, dfs(v, u, cc));
		ans+=mmin;
	}
	return ans;
}
int main(){
	while(scanf("%d", &n)==1){
		if(!n) break;
		REP(i, n) G[i].clear();
		REP(i, n){
			int u;
			scanf("%d:", &u);
			while(getchar()==' '){
				int v;
				scanf("%d", &v);
				G[u].push_back(v);
				G[v].push_back(u);
			}
		}
		memset(dp, 0x3f, sizeof(dp));
		int ans=inf;
		FOR(i, 1, 100) ans=min(ans, dfs(0, -1, i));
		printf("%d\n", ans);
	}
	return 0;
}

//18
//0: 1 2 3 4
//1: 5 6 7 8
//2:
//3:
//4: 9 10 11 12
//5: 13 14 15 16 17
//6:
//7:
//8:
//9:
//10:
//11:
//12:
//13:
//14:
//15:
//16:
//17:
