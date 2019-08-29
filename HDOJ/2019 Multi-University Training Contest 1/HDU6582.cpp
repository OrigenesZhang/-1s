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
const ll inf = 1e18;

struct Dinic { // can’t have negative cap!
  struct Edge {
    int from, to;
    ll cap, flow;

    Edge(int from, int to, ll cap, ll flow) :
        from(from), to(to), cap(cap), flow(flow) {}
  };

  int n, m, s, t;
  vector<Edge> edges;
  vector<int> G[maxn];
  bool vis[maxn];
  ll d[maxn];
  ll cur[maxn];

  void init(int n) {
    this->n = n;
    for (int i = 0; i < n; i++) G[i].clear();
    edges.clear();
  }

  void addEdge(int from, int to, ll cap) {
    edges.push_back(Edge(from, to, cap, 0));
    edges.push_back(Edge(to, from, 0, 0));
    m = edges.size();
    G[to].push_back(m - 1);
    G[from].push_back(m - 2);
  }

  bool bfs() {
    memset(vis, false, sizeof(vis));
    queue<int> Q;
    Q.push(s);
    d[s] = 0;
    vis[s] = true;
    while (!Q.empty()) {
      int x = Q.front();
      Q.pop();
      for (int i = 0; i < G[x].size(); i++) {
        Edge &e = edges[G[x][i]];
        if (!vis[e.to] && e.cap > e.flow) {
          vis[e.to] = true;
          d[e.to] = d[x] + 1;
          Q.push(e.to);
        }
      }
    }
    return vis[t];
  }

  ll dfs(int x, ll a) {
    if (x == t || a == 0) return a;
    ll flow = 0, f;
    for (auto &i = cur[x]; i < G[x].size(); i++) {
      Edge &e = edges[G[x][i]];
      if (d[x] + 1 == d[e.to] && (f = dfs(e.to, min(a, e.cap - e.flow))) > 0) {
        e.flow += f;
        edges[G[x][i] ^ 1].flow -= f;
        flow += f;
        a -= f;
        if (a == 0) break;
      }
    }
    return flow;
  }

  ll maxflow(int s, int t) {
    this->s = s;
    this->t = t;
    ll flow = 0;
    while (bfs()) {
      memset(cur, 0, sizeof(cur));
      flow += dfs(s, inf);
    }
    return flow;
  }

  void mincut(vector<int> &ans) { // Use after maxflow found
    bfs();
    for (int i = 0; i < m; i++) {
      Edge &e = edges[i];
      if (vis[e.from] && !vis[e.to] && e.cap > 0) ans.push_back(i);
    }
  }
};

vector<int> G[maxn], tra[maxn];
ll f[maxn];

void solve() {
  int n, m;
  scanf("%d%d", &n, &m);
  FOR(i, 1, n) {
    G[i].clear();
    tra[i].clear();
  }
  vector<pair<pii, int>> edges(m);
  REP(i, m) {
    scanf("%d%d%d", &edges[i]._1._1, &edges[i]._1._2, &edges[i]._2);
    G[edges[i]._1._1].eb(i);
  }
  fill(f + 1, f + n + 1, inf);
  f[1] = 0;
  set<pair<ll, int>> q;
  q.emplace(0, 1);
  while (!q.empty()) {
    auto _ = *q.begin(); q.erase(q.begin());
    ll d = _._1;
    int u = _._2;
    if (f[u] < d) continue;
    for (auto i : G[u]) {
      int v = edges[i]._1._2, c = edges[i]._2;
      if (f[v] > f[u] + c) {
        f[v] = f[u] + c;
        tra[v] = {i};
        q.emplace(f[v], v);
      } else if (f[v] == f[u] + c) tra[v].eb(i);
    }
  }
  static Dinic solver;
  solver.init(n);
  FOR(u, 1, n) for (auto i : tra[u]) {
    auto e = edges[i];
    int x = e._1._1 - 1, y = e._1._2 - 1, w = e._2;
    solver.addEdge(x, y, w);
  }
  printf("%lld\n", solver.maxflow(0, n - 1));
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) solve();
}
