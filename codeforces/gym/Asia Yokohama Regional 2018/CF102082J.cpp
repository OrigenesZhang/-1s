#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define ROF(i, a, b) for (int i = (a); i >= (b); i--)
#define eb emplace_back
#define _1 first
#define _2 second
typedef pair<int, int> pii;
 
const int maxn = 112345;
 
vector<int> G[maxn];
int c[maxn], dis[maxn], anc[maxn][20], dep[maxn], dfn[maxn];
set<pii> s[maxn];
int n, m, clk;
char op[5];
 
void dfs(int u, int par) {
  dep[u] = dep[par] + 1;
  dfn[u] = ++clk;
  anc[u][0] = par;
  FOR(i, 1, 17) anc[u][i] = anc[anc[u][i - 1]][i - 1];
  for (auto v : G[u]) if (v != par) dfs(v, u);
}
 
int get(int u, int v) {
  if (dep[u] > dep[v]) swap(u, v);
  int x = u, y = v;
  ROF(i, 17, 0) if (dep[anc[y][i]] >= dep[x]) y = anc[y][i];
  if (x == y) return dep[u] + dep[v] - 2 * dep[x];
  ROF(i, 17, 0) if (anc[x][i] != anc[y][i]) x = anc[x][i], y = anc[y][i];
  x = anc[x][0];
  return dep[u] + dep[v] - 2 * dep[x];
}
 
void ins(int col, int idx) {
  pii now = {dfn[idx], idx};
  if (s[col].empty()) {
    s[col].emplace(now);
    return;
  }
  if (s[col].size() == 1) {
    int pre = s[col].begin()->_2;
    dis[col] = 2 * get(idx, pre);
    s[col].emplace(now);
    return;
  }
  auto nxt = s[col].lower_bound(now);
  int a, b;
  if (nxt == s[col].end()) {
    --nxt;
    a = nxt->_2;
    b = s[col].begin()->_2;
  } else if (nxt == s[col].begin()) {
    b = nxt->_2;
    a = s[col].rbegin()->_2;
  } else {
    b = nxt->_2;
    --nxt;
    a = nxt->_2;
  }
  dis[col] += get(a, idx) + get(idx, b) - get(a, b);
  s[col].emplace(now);
}
 
void del(int col, int idx) {
  pii now = {dfn[idx], idx};
  s[col].erase(now);
  if (s[col].size() <= 1) {
    dis[col] = 0;
    return;
  }
  auto nxt = s[col].lower_bound(now);
  int a, b;
  if (nxt == s[col].end()) {
    --nxt;
    a = nxt->_2;
    b = s[col].begin()->_2;
  } else if (nxt == s[col].begin()) {
    b = nxt->_2;
    a = s[col].rbegin()->_2;
  } else {
    b = nxt->_2;
    --nxt;
    a = nxt->_2;
  }
  dis[col] += get(a, b) - get(a, idx) - get(idx, b);
}
 
int main() {
  scanf("%d", &n);
  FOR(i, 1, n - 1) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].eb(v);
    G[v].eb(u);
  }
  FOR(i, 1, n) scanf("%d", c + i);
  dfs(1, 0);
  FOR(i, 1, n) ins(c[i], i);
  scanf("%d", &m);
  while (m--) {
    scanf("%s", op);
    if (op[0] == 'U') {
      int x, y;
      scanf("%d%d", &x, &y);
      del(c[x], x);
      ins(y, x);
      c[x] = y;
    } else {
      int x;
      scanf("%d", &x);
      if (s[x].empty()) puts("-1");
      else printf("%d\n", dis[x] / 2);
    }
  }
}
/*
5
1 2
2 3
3 4
2 5
1 2 1 2 3
11
Q 1
Q 2
Q 3
Q 4
U 5 1
Q 1
U 3 2
Q 1
Q 2
U 5 4
Q 1
 */