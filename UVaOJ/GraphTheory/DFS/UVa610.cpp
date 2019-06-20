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

vector<int> G[maxn];
vector<char> bridge, dir;
vector<pii> edges;
int in[maxn];
int n, m, clk, cs;

int dfs(int u, int par) {
  int lowu = in[u] = ++clk, ch = 0;
  for (auto idx : G[u]) {
    auto v = edges[idx]._1 ^ edges[idx]._2 ^ u;
    if (!in[v]) {
      ch++;
      int lowv = dfs(v, u);
      chkmin(lowu, lowv);
      if (lowv > in[u]) bridge[idx] = true;
    } else if (in[v] < in[u] && v != par) chkmin(lowu, in[v]);
  }
  return lowu;
}

void dfs(int u) {
  in[u] = 1;
  for (auto idx : G[u]) if (!bridge[idx] && dir[idx] == 2) {
    auto v = edges[idx]._1 ^ edges[idx]._2 ^ u;
    dir[idx] = u == edges[idx]._1;
    if (!in[v]) dfs(v);
  }
}

int main() {
  while (scanf("%d%d", &n, &m) == 2 && n) {
    FOR(i, 1, n) G[i].clear();
    bridge = vector<char>(m);
    dir = vector<char>(m, 2);
    edges = vector<pii>(m);
    fill(in + 1, in + n + 1, 0);
    clk = 0;
    REP(i, m) {
      int u, v;
      scanf("%d%d", &u, &v);
      edges[i] = {u, v};
      G[u].eb(i); G[v].eb(i);
    }
    FOR(i, 1, n) if (!in[i]) dfs(i, -1);
    fill(in + 1, in + n + 1, 0);
    FOR(i, 1, n) if (!in[i]) dfs(i);
    printf("%d\n\n", ++cs);
    REP(i, m) {
      int u = edges[i]._1, v = edges[i]._2;
      if (bridge[i]) printf("%d %d\n%d %d\n", u, v, v, u);
      else {
        if (!dir[i]) swap(u, v);
        printf("%d %d\n", u, v);
      }
    }
    puts("#");
  }
}
/*
7 8
1 2
2 3
3 4
2 4
1 5
5 6
6 7
7 5

0 0
 */