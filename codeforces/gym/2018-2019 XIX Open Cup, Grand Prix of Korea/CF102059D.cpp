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
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

const int maxn = 312345;

int n, m;
int l[maxn], r[maxn], deg[maxn], ans[maxn];
bool vis[maxn];
vector<int> G[maxn];

struct Person {
  int lo, hi, id;

  Person(int lo, int hi, int id) : lo(lo), hi(hi), id(id) {}

  bool operator < (const Person &rhs) const {
    return lo > rhs.lo;
  }
};

int dfs(int u) {
  if (vis[u]) return r[u];
  vis[u] = true;
  for (int v : G[u]) chkmin(r[u], dfs(v) - 1);
  return r[u];
}

int main() {
  scanf("%d%d", &n, &m);
  FOR(i, 1, n) scanf("%d%d", l + i, r + i);
  while (m--) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].eb(v);
    deg[v]++;
  }
  set<pii> q;
  priority_queue<Person> avail;
  FOR(i, 1, n) {
    r[i] = dfs(i);
    if (!deg[i]) avail.emplace(l[i], r[i], i);
  }
  int p = 1;
  while (true) {
    while (!avail.empty() && avail.top().lo <= p) {
      auto now = avail.top();
      avail.pop();
      q.emplace(now.hi, now.id);
    }
    if (q.empty()) break;
    int u = q.begin()->_2; q.erase(q.begin());
    if (r[u] < p) {
      puts("-1");
      return 0;
    }
    ans[p++] = u;
    for (int v : G[u]) if (!--deg[v]) avail.emplace(l[v], r[v], v);
  }
  if (p <= n) {
    puts("-1");
    return 0;
  }
  FOR(i, 1, n) printf("%d\n", ans[i]);
}