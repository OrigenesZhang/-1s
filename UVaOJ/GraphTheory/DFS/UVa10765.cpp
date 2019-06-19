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

const int maxn = 11234;

int n, m, clk;
int in[maxn], low[maxn], cut[maxn], id[maxn];
vector<int> G[maxn];

int dfs(int u, int par) {
  int lowu = in[u] = ++clk, ch = 0;
  for (auto v : G[u]) {
    if (!in[v]) {
      ch++;
      int lowv = dfs(v, u);
      chkmin(lowu, lowv);
      if (lowv >= in[u]) cut[u]++;
    } else if (in[v] < in[u] && v != par) chkmin(lowu, in[v]);
  }
  if (par == -1 && ch == 1) cut[u] = 0;
  return low[u] = lowu;
}

int main() {
  while (scanf("%d%d", &n, &m) == 2) {
    if (!n) break;
    REP(i, n) G[i].clear();
    fill(in, in + n, 0);
    fill(low, low + n, 0);
    fill(cut, cut + n, 0);
    iota(id, id + n, 0);
    clk = 0;
    int u, v;
    while (scanf("%d%d", &u, &v)) {
      if (u == -1) break;
      G[u].eb(v);
      G[v].eb(u);
    }
    dfs(0, -1);
    sort(id, id + n, [](int a, int b) { return cut[a] != cut[b] ? cut[a] > cut[b] : a < b;});
    REP(i, m) printf("%d %d\n", id[i], cut[id[i]] + 1);
    putchar('\n');
  }
}
