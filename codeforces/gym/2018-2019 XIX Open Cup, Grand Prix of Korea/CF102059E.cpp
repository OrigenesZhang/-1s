#include <bits/stdc++.h>

using namespace std;

const int maxn = 112345;

int n, m, have;
bool vis[maxn];
set<int> G[maxn];

void dfs(int u) {
    if (G[u].size() == 2) {
        int v = *G[u].begin(), w = *G[u].rbegin();
        G[u].clear();
        G[v].erase(u); G[w].erase(u);
        G[v].emplace(w); G[w].emplace(v);
        have--;
        vis[u] = true;
        if (!vis[v]) dfs(v);
        if (!vis[w]) dfs(w);
    }
}

int main() {
    scanf("%d%d", &n, &m);
    while (m--) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].emplace(v);
        G[v].emplace(u);
    }
    have = n;
    for (int i = 1; i <= n; i++) if (!vis[i]) dfs(i);
    puts(have == 2 ? "Yes" : "No");
}