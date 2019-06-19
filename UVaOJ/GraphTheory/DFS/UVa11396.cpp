#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end())
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

const int maxn = 312;

int n, vis[maxn];
bool G[maxn][maxn];;

bool dfs(int u, int c) {
  vis[u] = c;
  FOR(v, 1, n) if (G[u][v]) {
    if (vis[v] && vis[v] != 3 - c) return false;
    if (!vis[v] && !dfs(v, 3 - c)) return false;
  }
  return true;
}

int main() {
  while (scanf("%d", &n) == 1) {
    if (!n) break;
    reset(G, false);
    reset(vis, 0);
    int u, v;
    while (scanf("%d%d", &u, &v) == 2) {
      if (!u) break;
      G[u][v] = true;
      G[v][u] = true;
    }
    bool ans = true;
    FOR(i, 1, n) if (!vis[i] && !dfs(i, 1)) {
      ans = false;
      break;
    }
    puts(ans ? "YES" : "NO");
  }
}
