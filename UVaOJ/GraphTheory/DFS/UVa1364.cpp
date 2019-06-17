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

const int maxn = 1123;

int n, m, clk, bcc_cnt;
int in[maxn], bccno[maxn], col[maxn];
bool G[maxn][maxn], cut[maxn], good[maxn];
stack<pii> s;
vector<int> bcc[maxn];

int dfs(int u, int par) {
  int lowu = in[u] = ++clk, ch = 0;
  FOR(v, 1, n) if (G[u][v]) {
    if (!in[v]) {
      ch++;
      s.emplace(u, v);
      int lowv = dfs(v, u);
      chkmin(lowu, lowv);
      if (lowv >= in[u]) {
        cut[u] = true;
        bcc_cnt++;
        bcc[bcc_cnt].clear();
        pii now;
        do {
          now = s.top(); s.pop();
          if (bccno[now._1] != bcc_cnt) {
            bccno[now._1] = bcc_cnt;
            bcc[bcc_cnt].eb(now._1);
          }
          if (bccno[now._2] != bcc_cnt) {
            bccno[now._2] = bcc_cnt;
            bcc[bcc_cnt].eb(now._2);
          }
        } while (now._1 != u || now._2 != v);
      }
    } else if (in[v] < in[u] && v != par) {
      s.emplace(u, v);
      chkmin(lowu, in[v]);
    }
  }
  if (par < 0 && ch == 1) cut[u] = false;
  return lowu;
}

bool dfs(const vector<vector<int>> &adj, int u, int c) {
  col[u] = c;
  int nc = 3 - c;
  for (auto v : adj[u]) {
    if (col[v] && col[v] != nc) return false;
    if (!col[v] && !dfs(adj, v, nc)) return false;
  }
  return true;
}

int main() {
  while (scanf("%d%d", &n, &m) == 2) {
    if (!n) break;
    FOR(i, 1, n) fill(G[i] + 1, G[i] + n + 1, true);
    while (m--) {
      int u, v;
      scanf("%d%d", &u, &v);
      G[u][v] = G[v][u] = false;
    }
    FOR(i, 1, n) G[i][i] = false;
    fill(cut + 1, cut + n + 1, false);
    fill(bccno + 1, bccno + n + 1, 0);
    fill(in + 1, in + n + 1, 0);
    fill(good + 1, good + n + 1, false);
    bcc_cnt = clk = 0;
    FOR(i, 1, n) if (!in[i]) dfs(i, -1);
    FOR(i, 1, bcc_cnt) {
      vector<vector<int>> adj(n + 1);
      for (auto u : bcc[i]) col[u] = 0;
      REP(j, int(bcc[i].size())) FOR(k, j + 1, int(bcc[i].size()) - 1) {
        int u = bcc[i][j], v = bcc[i][k];
        if (G[u][v]) {
          adj[u].eb(v);
          adj[v].eb(u);
        }
      }
      if (!dfs(adj, bcc[i].front(), 1))
        for (auto it : bcc[i]) good[it] = true;
    }
    int ans = n;
    FOR(i, 1, n) if (good[i]) ans--;
    printf("%d\n", ans);
  }
}
