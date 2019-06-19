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

  void dfs(int u) {
    in[u] = lowlink[u] = ++clk;
    s.emplace(u);
    for (auto v : G[u]) {
      if (!in[v]) {
        dfs(v);
        chkmin(lowlink[u], lowlink[v]);
      } else if (sccno[v] == -1) {
        chkmin(lowlink[u], in[v]);
      }
    }
    if (lowlink[u] == in[u]) {
      int v;
      do {
        v = s.top();
        s.pop();
        sccno[v] = scc_cnt;
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

int T, m, s, a;

int main() {
  scanf("%d", &T);
  FOR(cs, 1, T) {
    scanf("%d%d%d", &s, &a, &m);
    solver = TwoSat(s + a);
    while (m--) {
      int x1, y1, x2, y2;
      scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
      x1--, y1--, x2--, y2--;
      y1 += s, y2 += s;
      if (x1 == x2) solver.add_constraint(x1, y2 > y1, x1, y2 > y1);
      else if (y1 == y2) solver.add_constraint(y1, x2 > x1, y1, x2 > x1);
      else {
        bool x_val = y2 > y1, y_val = x2 > x1;
        solver.add_constraint(x1, x_val, x2, x_val);
        solver.add_constraint(y1, y_val, y2, y_val);
        solver.add_constraint(x1, x_val, y1, y_val);
        solver.add_constraint(x2, x_val, y2, y_val);
      }
    }
    puts(solver.solve() ? "Yes" : "No");
  }
}
/*
3
6 6 2
1 1 6 6
6 6 1 1
7 7 4
1 1 1 6
6 1 6 6
6 6 1 1
4 3 5 1
9 8 6
2 2 4 4
4 5 3 2
3 4 2 2
3 2 4 4
4 5 2 2
2 1 3 4
 */