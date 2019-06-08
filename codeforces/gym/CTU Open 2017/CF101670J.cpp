#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REP(i, n) FOR(i, 0, (n) - 1)
#define reset(x, y) memset(x, y, sizeof(x))
#define mp(x, y) make_pair(x, y)
#define eb emplace_back

using namespace std;
using pii = pair<int, int>;

const int maxn = 2123;
const int dirx[] = {1, 0, -1, 0};
const int diry[] = {0, 1, 0, -1};

int n, now;
int x[maxn], y[maxn], match[maxn];
bool vis[maxn];
vector<int> G[maxn];
map<pii, int> tab;

bool dfs(int u) {
  if (vis[u]) return false;
  vis[u] = true;
  for (int v : G[u]) if (match[v] == -1 || dfs(match[v])) {
    match[u] = v;
    match[v] = u;
    return true;
  }
  return false;
}

int hungarian() {
  int ret = 0;
  reset(match, -1);
  FOR(u, 1, n) if (match[u] == -1) {
    reset(vis, false);
    ret += dfs(u);
  }
  return ret;
}

int main() {
  while (scanf("%d", &n) == 1) {
    now = 0;
    FOR(i, 1, n) G[i].clear();
    tab.clear();
    FOR(i, 1, n) {
      scanf("%d%d", x + i, y + i);
      tab[mp(x[i], y[i])] = ++now;
    }
    FOR(i, 1, n) {
      int u = tab[mp(x[i], y[i])];
      bool even = ((x[i] + y[i]) & 1) ^ 1;
      REP(j, 4) {
        int nx = x[i] + dirx[j], ny= y[i] + diry[j], v = tab[mp(nx, ny)];
        if (v && (nx + ny) % 2 == even) {
          G[u].eb(v);
          G[v].eb(u);
        }
      }
    }
    printf("%d\n", n - hungarian());
  }
}