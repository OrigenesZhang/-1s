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

const int maxn = 112345;
const char dir[] = "UDLR";
const int dx[] = {0, 0, -1, 1};
const int dy[] = {1, -1, 0, 0};

int n;
int x[maxn], y[maxn], d[maxn], nxt[maxn][4];
bool vis[maxn][4];
ll dis[maxn][4], T;
map<int, vector<pii>> tab_x, tab_y;

int main() {
  scanf("%d%lld", &n, &T);
  FOR(i, 1, n) {
    char tmp[5];
    scanf("%d%d%s", x + i, y + i, tmp);
    tab_x[x[i]].eb(y[i], i);
    tab_y[y[i]].eb(x[i], i);
    REP(j, 4) if (tmp[0] == dir[j]) {
      d[i] = j;
      break;
    }
  }
  reset(nxt, -1);
  for (auto &_ : tab_x) {
    auto &vec = _._2;
    sort(all(vec));
    REP(i, int(vec.size()) - 1) {
      int u = vec[i]._2, v = vec[i + 1]._2;
      nxt[u][0] = v;
      nxt[v][1] = u;
    }
  }
  for (auto &_ : tab_y) {
    auto &vec = _._2;
    sort(all(vec));
    REP(i, int(vec.size()) - 1) {
      int u = vec[i]._2, v = vec[i + 1]._2;
      nxt[u][3] = v;
      nxt[v][2] = u;
    }
  }
  reset(dis, 0x3f);
  set<pair<ll, pii>> q;
  dis[1][d[1]] = 0;
  q.emplace(0, mp(1, d[1]));
  while (!q.empty()) {
    auto now = *q.begin(); q.erase(q.begin());
    ll curdis = now._1;
    int u = now._2._1, curdir = now._2._2;
    if (vis[u][curdir]) continue;
    vis[u][curdir] = true;
    if (curdis < dis[u][d[u]]) {
      dis[u][d[u]] = curdis;
      q.emplace(curdis, mp(u, d[u]));
    }
    if (nxt[u][curdir] != -1) {
      int v = nxt[u][curdir];
      ll ndis = curdis + abs(x[u] - x[v]) + abs(y[u] - y[v]);
      if (ndis < dis[v][curdir]) {
        dis[v][curdir] = ndis;
        q.emplace(ndis, mp(v, curdir));
      }
    }
  }
  FOR(i, 1, n) {
    ll clk = 0;
    if (dis[i][d[i]] < T) clk = T - dis[i][d[i]];
    printf("%lld %lld\n", x[i] + dx[d[i]] * clk, y[i] + dy[d[i]] * clk);
  }
}
/*
5 10
1 0 U
3 1 U
1 2 R
1 1 L
0 1 R
 */