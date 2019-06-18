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

struct TwoSat {
  int n, scc_cnt, clk;
  vector<vector<int>> G;

  vector<int> sccno, in, lowlink;
  stack<int> s;

  TwoSat() = default;

  TwoSat(int n) {
    this->n = 2 * n;
    G = vector<vector<int>>(2 * n);
  }

  // x == x_val or y == y_val
  // odd: true, even: false
  void add_constraint(int x, bool x_val, int y, bool y_val) {
    int u = 2 * x + x_val, v = 2 * y + y_val;
    G[u ^ 1].eb(v);
    G[v ^ 1].eb(u);
  }

  void dfs(int u, bool debug = false) {
    in[u] = lowlink[u] = ++clk;
    s.emplace(u);
    for (auto v : G[u]) {
      if (!in[v]) {
        dfs(v, debug);
        chkmin(lowlink[u], lowlink[v]);
      } else if (sccno[v] == -1) {
        chkmin(lowlink[u], in[v]);
      }
    }
    if (lowlink[u] == in[u]) {
      int v;
      do {
        v = s.top(); s.pop();
        sccno[v] = scc_cnt;
        if (debug) cout << v << ' ' << sccno[v] << endl;
      } while (v != u);
      scc_cnt++;
    }
  }

  bool solve() {
    scc_cnt = clk = 0;
    while (!s.empty()) s.pop();
    sccno = vector<int>(n, -1);
    lowlink = vector<int>(n);
    in = vector<int>(n);
    for (auto &it : G) {
      sort(all(it));
      uni(it);
    }
    REP(i, n) if (sccno[i] == -1) dfs(i);
    for (int i = 0; i < n; i += 2) if (sccno[i] == sccno[i ^ 1]) return false;
    return true;
  }

  vector<char> print() {
    vector<char> ret(n / 2);
    for (int i = 0; i < n; i += 2) ret[i >> 1] = (sccno[i] > sccno[i ^ 1]);
    return ret;
  }
} solver;

const int maxn = 112345;

int n, m, tot;
int age[maxn];
bool cat[maxn];

int main() {
  while (scanf("%d%d", &n, &m) == 2) {
    if (!n) break;
    tot = 0;
    REP(i, n) {
      scanf("%d", age + i);
      tot += age[i];
    }
    REP(i, n) cat[i] = (age[i] * n >= tot);
    solver = TwoSat(2 * n);
    while (m--) {
      int u, v;
      scanf("%d%d", &u, &v);
      u--, v--;
      if (cat[u] == cat[v]) solver.add_constraint(2 * u, false, 2 * v, false);
      solver.add_constraint(2 * u + 1, false, 2 * v + 1, false);
    }
    REP(i, n) {
      solver.add_constraint(2 * i, true, 2 * i + 1, true);
      solver.add_constraint(2 * i, false, 2 * i + 1, false);
    }
    if (!solver.solve()) {
      puts("No solution.");
      continue;
    }
    auto way = solver.print();
    REP(i, n) {
      if (way[2 * i + 1]) puts("C");
      else puts(cat[i] ? "A" : "B");
    }
  }
}
