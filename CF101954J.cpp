#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REP(i, n) FOR(i, 0, (n) - 1)
#define reset(a, b) memset(a, b, sizeof(a))
#define pb push_back

const int maxn = 312345;

vector<int> G[maxn];
int V[maxn], n;
bool vis[maxn];

inline ll cal(ll x) {
	return x * (x + 1) / 2;
}

ll dfs(int u, int mask) {
	if (vis[u] || !(V[u] & mask)) return 0;
	vis[u] = true;
	ll ret = 1;
	for (int v : G[u]) ret += dfs(v, mask);
	return ret;
}

int main() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", V + i);
	FOR(i, 2, n) {
		int u, v;
		scanf("%d%d", &u, &v);
		G[u].pb(v);
		G[v].pb(u);
	}
	ll ans = 0;
	REP(i, 20) {
		reset(vis, 0);
		REP(j, n) ans += cal(dfs(j, 1 << i)) << i;
	}
	printf("%lld\n", ans);
	return 0;
}