#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define pb push_back
using namespace std;

const int maxn = 1234567;

int n, cnt[maxn], dp[maxn];
vector<int> G[maxn];

int dfs(int u, int p) {
	if (dp[u] != 0) return dp[u];
	for (int v : G[u]) {
		if (v == p) continue;
		dp[u] += dfs(v, u);
	}
	dp[u]++;
	// cout << u << ' ' << dp[u] << endl;
	return dp[u];
}

bool check(int k) {
	k++;
	if (n % k) return false;
	int now = n / k, bls = 0;
	for (int i = now; i <= n; i += now) bls += cnt[i];
	// cout << now << ' ' << bls << endl;
	return bls == k; 
}

int main() {
	scanf("%d", &n);
	FOR(i, 1, n - 1) {
		int u, v;
		scanf("%d%d", &u, &v);
		G[u].pb(v);
		G[v].pb(u);
	}
	dfs(1, -1);
	FOR(i, 1, n) cnt[dp[i]]++;
	// FOR(i, 1, n) cout << i << ' ' << cnt[i] << endl;
	FOR(i, 1, n - 1) if (check(i)) printf("%d ", i);
	puts("");
	return 0;
}