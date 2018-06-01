// 状态不满的dp
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
using namespace std;
#define FOR(i, a, b) for(int (i)=(a); (i)<=(b); (i)++)
#define REP(i, n) FOR(i, 0, (n)-1)
typedef long long ll;
typedef vector<int> State;
const State target(8, 0);
const int inf=0x3f3f3f3f;
const int maxn=8;
int cnt[maxn], K, N;
map<State, int> dp[maxn];
int dfs(int d){
	State cur(begin(cnt), end(cnt));
	if(cur==target) return 0;
	if(dp[d].find(cur)!=dp[d].end()) return dp[d][cur];
	int ans=inf;
	FOR(i, 1, 7){
		if(cnt[i]>0){
			cnt[i]--;
			ans=min(ans, dfs(max(i-d-1, 0))+max(i-d, 1));
			cnt[i]++;
		}
	}
	return dp[d][cur]=ans;
}
int main(){
	scanf("%d", &N);
	while(N--){
		scanf("%d", &K);
		memset(cnt, 0, sizeof(cnt));
		REP(i, maxn) dp[i].clear();
		REP(i, K){
			int D;
			scanf("%d", &D);
			cnt[D]++;
		}
		printf("%d\n", dfs(0));
	}
	return 0;
}
