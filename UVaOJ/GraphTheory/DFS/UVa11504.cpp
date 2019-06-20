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

int T, n, m, scc_cnt, clk;
int in[maxn], sccno[maxn], lowlink[maxn];
vector<int> G[maxn];
stack<int> s;

void dfs(int u) {
  in[u] = lowlink[u] = ++clk;
  s.emplace(u);
  for (auto v : G[u]) {
    if (!in[v]) {
      dfs(v);
      chkmin(lowlink[u], lowlink[v]);
    } else if (!sccno[v]) chkmin(lowlink[u], in[v]);
  }
  if (lowlink[u] == in[u]) {
    int v;
    scc_cnt++;
    do {
      v = s.top(); s.pop();
      sccno[v] = scc_cnt;
    } while (v != u);
  }
}

int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &m);
    fill(in + 1, in + n + 1, 0);
    fill(sccno + 1, sccno + n + 1, 0);
    fill(lowlink + 1, lowlink + n + 1, 0);
    FOR(i, 1, n) G[i].clear();
    clk = scc_cnt = 0;
    while (m--) {
      int u, v;
      scanf("%d%d", &u, &v);
      G[u].eb(v);
    }
    FOR(i, 1, n) if (!in[i]) dfs(i);
    vector<char> source(scc_cnt + 1, 1);
    FOR(i, 1, n) for (auto j : G[i]) if (sccno[i] != sccno[j]) source[sccno[j]] = false;
    int ans = 0;
    FOR(i, 1, scc_cnt) ans += source[i];
    printf("%d\n", ans);
  }
}
