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
 
int n, m, clk;
vector<int> G[maxn];
int h[maxn], in[maxn], out[maxn], l[maxn], r[maxn], L[maxn], R[maxn], dep[maxn], hi[maxn];
 
void dfs(int u, int d) {
  dep[u] = d;
  in[u] = ++clk;
  for (auto v : G[u]) {
    if (!in[v]) dfs(v, d + 1);
    chkmax(hi[u], hi[v] + 1);
  }
  out[u] = clk;
}
 
bool check(int u, int v) {
  return in[u] < in[v] && out[v] <= out[u];
}
 
int main() {
  scanf("%d%d", &n, &m);
  FOR(i, 1, n) scanf("%d", h + i);
  h[0] = h[n + 1] = 1e9;
  stack<int> s;
  s.emplace(0);
  FOR(i, 1, n) {
    while (!s.empty() && h[s.top()] <= h[i]) {
      if (h[s.top()] == h[i] && !l[i]) l[i] = s.top();
      s.pop();
    }
    L[i] = s.top();
    s.emplace(i);
  }
  while (!s.empty()) s.pop();
  s.emplace(0);
  ROF(i, n, 1) {
    while (!s.empty() && h[s.top()] <= h[i]) {
      if (h[s.top()] == h[i] && !r[i]) r[i] = s.top();
      s.pop();
    }
    R[i] = s.top();
    s.emplace(i);
  }
  FOR(i, 1, n) {
    if (h[L[i]] <= h[R[i]]) G[L[i]].eb(i);
    if (h[R[i]] <= h[L[i]]) G[R[i]].eb(i);
  }
  REP(i, n + 1) if (!in[i]) dfs(i, 0);
  while (m--) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (!y) {
      printf("%d\n", hi[x]);
    } else {
      if (h[x] < h[y]) swap(x, y);
      int ans = 0;
      if (check(x, y)) ans = dep[y] - dep[x];
      else if (x < y && r[x] && r[x] > y && check(r[x], y)) ans = dep[y] - dep[r[x]];
      else if (x > y && l[x] && l[x] < y && check(l[x], y)) ans = dep[y] - dep[l[x]];
      printf("%d\n", ans);
    }
  }
}
/*
12 8
2 3 4 4 4 3 3 3 1 2 5 2
3 0
4 0
5 0
7 0
7 11
7 9
11 1
9 12
 */