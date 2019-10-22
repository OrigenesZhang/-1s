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

const int maxn = 212345;

vector<int> G[maxn], adj[maxn];
vector<pii> T[maxn];
vector<int> lis[maxn];
int n, m;
int u[maxn], v[maxn], w[maxn], pre[maxn], deg[maxn], ans[maxn], dep[maxn];
int anc[maxn][20];
ll f[maxn];

int lca(int a, int b) {
  if (dep[a] > dep[b]) swap(a, b);
  ROF(i, 18, 0) if (dep[anc[b][i]] >= dep[a]) b = anc[b][i];
  if (a == b) return a;
  ROF(i, 18, 0) if (anc[a][i] != anc[b][i]) a = anc[a][i], b = anc[b][i];
  return anc[a][0];
}

int dfs(int x, int i) {
  int tot = 0;
  for (auto _ : T[x]) {
    int j = _._1, y = _._2;
    tot += dfs(y, j);
  }
  tot++;
  return ans[i] = tot;
}

int main() {
  scanf("%d%d", &n, &m);
  FOR(i, 1, m) {
    scanf("%d%d%d", u + i, v + i, w + i);
    G[u[i]].eb(i);
    G[v[i]].eb(i);
  }
  reset(f, 0x3f);
  f[1] = 0;
  set<pair<ll, int>> q;
  q.emplace(f[1], 1);
  while (!q.empty()) {
    auto now = *q.begin(); q.erase(q.begin());
    ll d = now._1;
    int x = now._2;
    if (f[x] != d) continue;
    for (auto i : G[x]) {
      int y = u[i] ^ v[i] ^ x, c = w[i];
      if (f[y] > f[x] + c) {
        pre[y] = i;
        f[y] = f[x] + c;
        q.emplace(f[y], y);
      }
    }
  }
  set<int> s;
  FOR(i, 1, n) if (pre[i]) {
    int j = u[pre[i]] ^ v[pre[i]] ^ i;
    adj[j].eb(pre[i]);
    deg[i]++;
    s.emplace(pre[i]);
  }
  FOR(i, 1, m) if (!s.count(i)) {
    int x = u[i], y = v[i], c = w[i];
    if (f[x] > f[y]) swap(x, y);
    if (f[y] == f[x] + c) {
      adj[x].eb(i);
      deg[y]++;
    }
  }
  queue<int> que;
  que.emplace(1);
  dep[1] = 1;
  while (!que.empty()) {
    int x = que.front(); que.pop();
    for (auto i : adj[x]) {
      int y = u[i] ^ v[i] ^ x;
      lis[y].eb(x);
      if (!--deg[y]) {
        if (lis[y].size() == 1) {
          T[x].eb(i, y);
          anc[y][0] = x;
          dep[y] = dep[x] + 1;
        }
        else {
          int a = lca(lis[y][0], lis[y][1]);
          FOR(j, 2, int(lis[y].size()) - 1) a = lca(a, lis[y][j]);
          T[a].eb(0, y);
          anc[y][0] = a;
          dep[y] = dep[a] + 1;
        }
        FOR(j, 1, 18) anc[y][j] = anc[anc[y][j - 1]][j - 1];
        que.emplace(y);
      }
    }
  }
  dfs(1, 0);
  FOR(i, 1, m) printf("%d\n", ans[i]);
}