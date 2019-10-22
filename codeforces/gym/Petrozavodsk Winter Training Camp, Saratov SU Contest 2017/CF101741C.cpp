#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define ROF(i, a, b) for (int i = (a); i >= (b); --i)
#define REP(i, a) FOR(i, 0, int(a) - 1)
#define reset(a, b) memset(a, b, sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define pb push_back
#define _1 first
#define _2 second

#define all(x) (x).begin(), (x).end()
#define uni(x) x.erase(unique(all(x)), x.end())
#define sqr(x) ((x) * (x))
using LL = long long;

const int N = 112345;

vector<int> t[N];
set<int> s[N];
vector<int> G[N];
bool dead[N];
int n, m, h[N], fa[N][18];

void dfs(int u, int pa, int height) {
  h[u] = height;
  fa[u][0] = pa;
  for (int v : G[u]) {
    if (v == pa) continue;
    dfs(v, u, height + 1);
  }
}

int lca(int x, int y) {
  if (h[x] < h[y]) swap(x, y);

  for (int i = 17; i >= 0; --i) {
    if (h[x] - (1 << i) >= h[y]) x = fa[x][i];
  }

  if (x == y) return x;

  for (int i = 17; i >= 0; --i) {
    if (fa[x][i] != fa[y][i]) {
      x = fa[x][i];
      y = fa[y][i];
    }
  }

  return fa[x][0];
}

void solve(int u, int pa, vector<int> &ans) {
  for (int v : G[u]) {
    if (v == pa) continue;
    solve(v, u, ans);
    if (s[v].size() > s[u].size()) {
      swap(s[u], s[v]);
    }
    for (auto it : s[v]) s[u].insert(it);
  }

  for (int x : t[u]) {
    if (!dead[x]) {
      ans.push_back(u);
      for (auto it : s[u]) {
        dead[it] = true;
      }
      s[u].clear();
      break;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n - 1; ++i) {
    int x, y;
    cin >> x >> y;
    G[x].pb(y);
    G[y].pb(x);
  }

  dfs(1, 0, 1);
  for (int j = 1; j < 18; ++j) {
    for (int i = 1; i <= n; ++i) fa[i][j] = fa[fa[i][j - 1]][j - 1];
  }

  cin >> m;
  for (int i = 1; i <= m; ++i) {
    int x, y;
    cin >> x >> y;
    int z = lca(x, y);
    //cerr << x << ' ' << y << ' ' << z << endl;
    s[x].insert(i);
    s[y].insert(i);
    t[z].push_back(i);
  }

  vector<int> ans;
  solve(1, 0, ans);

  cout << ans.size() << '\n';
  for (auto it : ans) cout << it << ' ';
  cout << '\n';
  return 0;
}