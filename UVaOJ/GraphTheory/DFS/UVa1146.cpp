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

const int maxn = 2123;

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

int n;
int early[maxn], late[maxn];

bool check(int gap) {
  solver = TwoSat(n);
  REP(i, n) FOR(j, i + 1, n - 1) {
    if (abs(early[i] - early[j]) < gap) solver.add_constraint(i, false, j, false);
    if (abs(early[i] - late[j]) < gap) solver.add_constraint(i, false, j, true);
    if (abs(late[i] - early[j]) < gap) solver.add_constraint(i, true, j, false);
    if (abs(late[i] - late[j]) < gap) solver.add_constraint(i, true, j, true);
  }
  return solver.solve();
}

int main() {
  while (scanf("%d", &n) == 1) {
    REP(i, n) scanf("%d%d", early + i, late + i);
    int lo = 0, hi = 1e7 + 1;
    while (lo < hi) {
      int mi = lo + hi + 1 >> 1;
      if (check(mi)) lo = mi;
      else hi = mi - 1;
    }
    printf("%d\n", lo);
  }
}
/*
10
44 156
153 182
48 109
160 201
55 186
54 207
55 165
17 58
132 160
87 197
 */