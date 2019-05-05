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
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

int deg[7], n, cnt;
bool done[212];
vector<pii> G[7];
stack<pair<int, char>> ans;

void dfs1(int u, vector<bool> &vis) {
  vis[u] = true;
  for (auto _ : G[u]) {
    int v = _._1;
    if (!vis[v]) dfs1(v, vis);
  }
}

bool check() {
  vector<bool> vis(7);
  int cc = 0;
  REP(i, 7) if (deg[i] && !vis[i]) {
    cc++;
    dfs1(i, vis);
  }
  return cc == 1;
}

void dfs2(int u) {
  for (auto _ : G[u]) {
    int v = _._1, e = _._2;
    if (!done[e]) {
      done[e] = done[e ^ 1] = true;
      dfs2(v);
      ans.emplace(e >> 1, e & 1 ? '-' : '+');
    }
  }
}

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].eb(v, i << 1);
    G[v].eb(u, i << 1 | 1);
    deg[u]++;
    deg[v]++;
  }
  REP(i, 7) if (deg[i] & 1) cnt++;
  if (cnt == 1 || cnt > 2 || !check()) {
    puts("No solution");
    return 0;
  }
  if (!cnt) {
    REP(i, 7) if (deg[i]) {
      dfs2(i);
      break;
    }
  } else {
    REP(i, 7) if (deg[i] & 1) {
      dfs2(i);
      break;
    }
  }
  while (!ans.empty()) {
    printf("%d %c\n", ans.top()._1, ans.top()._2);
    ans.pop();
  }
}