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

const int maxn = 312;
const int inf = 0x3f3f3f3f;

vector<pii> G[maxn];
bool ini[maxn];
int r[maxn], t[maxn][2], dis[maxn], pre[maxn];
int n, m, st, en;
char op[5];

inline int get(int u, int clk) {
  if (clk < r[u]) return r[u];
  int rem = (clk - r[u]) % (t[u][0] + t[u][1]);
  if (rem < t[u][1 - ini[u]]) return clk + t[u][1 - ini[u]] - rem;
  rem -= t[u][1 - ini[u]];
  return clk + t[u][ini[u]] - rem;
}

bool now(int u, int clk) {
  if (clk < r[u]) return ini[u];
  clk = (clk - r[u]) % (t[u][0] + t[u][1]);
  return clk < t[u][1 - ini[u]] != ini[u];
}

int get(int u, int v, int clk) {
  if (now(u, clk) == now(v, clk)) return 0;
  int cnt = 3, tu = clk, tv = clk;
  while (cnt--) {
    tu = get(u, tu); tv = get(v, tv);
    if (tu != tv) return min(tu, tv) - clk;
  }
  return inf;
}

int main() {
  scanf("%d%d%d%d", &st, &en, &n, &m);
  FOR(i, 1, n) {
    scanf("%s%d%d%d", op, r + i, &t[i][0], &t[i][1]);
    ini[i] = op[0] == 'P';
  }
  while (m--) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    G[u].eb(v, w);
    G[v].eb(u, w);
  }
  reset(dis, 0x3f);
  dis[st] = 0;
  set<pii> q;
  q.emplace(0, st);
  while (!q.empty()) {
    auto now = *q.begin(); q.erase(now);
    int u = now._2, d = now._1;
    if (d > dis[u]) continue;
    if (u == en) break;
    for (auto _ : G[u]) {
      int v = _._1, w = _._2, need = get(u, v, d);
      if (need == inf) continue;
      w += need;
      if (dis[u] + w < dis[v]) {
        dis[v] = dis[u] + w;
        pre[v] = u;
        q.emplace(dis[v], v);
      }
    }
  }
  if (dis[en] == inf) puts("0");
  else {
    printf("%d\n", dis[en]);
    vector<int> vec;
    for (int u = en; u; u = pre[u]) vec.eb(u);
    reverse(all(vec));
    for (auto it : vec) printf("%d ", it);
  }
}