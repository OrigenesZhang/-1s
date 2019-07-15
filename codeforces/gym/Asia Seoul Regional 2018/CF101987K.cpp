#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REP(i, n) FOR(i, 0, (n) - 1)
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define uni(x) x.erase(unique(all(x)), x.end())
using namespace std;
 
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
 
int k, n;
int id[5];
char val[5][5];
 
int main() {
  scanf("%d%d", &k, &n);
  solver = TwoSat(k);
  FOR(i, 1, n) {
    FOR(j, 1, 3) {
      scanf("%d%s", id + j, val[j]);
      id[j]--;
      val[j][0] = val[j][0] == 'B';
    }
    solver.add_constraint(id[1], val[1][0], id[2], val[2][0]);
    solver.add_constraint(id[1], val[1][0], id[3], val[3][0]);
    solver.add_constraint(id[2], val[2][0], id[3], val[3][0]);
  }
  bool ret = solver.solve();
  if (!ret) {
    puts("-1");
    return 0;
  }
  auto ans = solver.print();
  for (auto now : ans) printf("%c", now ? 'B' : 'R');
}