// 另解 最小瓶颈路
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

const int maxn = 212;

vector<int> tab;
vector<pii> G[maxn];
bool vis[maxn];
int n, m, es, et, k, s, t;

void bfs(int lo, int hi) {
  queue<int> q;
  vis[s] = true;
  q.emplace(s);
  while (!q.empty()) {
    auto u = q.front(); q.pop();
    for (auto _ : G[u]) {
      int v = _._1, w = _._2;
      if (vis[v] || w < lo || w > hi) continue;
      vis[v] = true;
      if (v == t) return;
      q.emplace(v);
    }
  }
}

bool check(int diff) {
  for (auto lo : tab) {
    int hi = lo + diff;
    reset(vis, false);
    bfs(lo, hi);
    if (vis[t]) return true;
  }
  return false;
}

int main() {
  while (scanf("%d%d", &n, &m) == 2) {
    tab.clear();
    FOR(i, 1, n) G[i].clear();
    while (m--) {
      int u, v, w;
      scanf("%d%d%d", &u, &v, &w);
      G[u].eb(v, w);
      G[v].eb(u, w);
      tab.eb(w);
    }
    scanf("%d%d%d", &es, &et, &k);
    sort(all(tab));
    uni(tab);
    while (k--) {
      scanf("%d%d", &s, &t);
      int hi = tab.back() - tab.front(), lo = 0;
      while (lo < hi) {
        int mi = lo + (hi - lo) / 2;
        if (check(mi)) hi = mi;
        else lo = mi + 1;
      }
      printf("%d\n", es + et + lo);
    }
  }
}
