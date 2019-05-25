#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

const int N = 1123;


int n, m;
vector<pii> G[N];

int dp[N];

int dfs(int u) {
    if (dp[u] > -1) return dp[u];
    dp[u] = 0;
    for (auto it : G[u]) {
        dp[u] = max(dp[u], dfs(it.first) + it.second);
    }
    return dp[u];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        G[x].push_back({ y, z });
    }

    memset(dp, -1, sizeof(dp));
    int maxm = 0;
    for (int i = 1; i <= n; i++) {
        if (dp[i] == -1) maxm = max(maxm, dfs(i));
    }

    cout << maxm << '\n';
    return 0;
}