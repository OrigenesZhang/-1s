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
 
vector<int> G[maxn][20];
bool human[maxn], mil[maxn], vis[maxn][maxn];
int n, w, c, h, m;
 
int main() {
  scanf("%d%d%d%d%d", &n, &w, &c, &h, &m);
  while (h--) {
    int x;
    scanf("%d", &x);
    human[x] = true;
  }
  while (m--) {
    int x;
    scanf("%d", &x);
    mil[x] = true;
  }
  while (w--) {
    int u, v, now;
    scanf("%d%d%d", &u, &now, &v);
    now--;
    G[v][now].eb(u);
  }
  queue<pii> q;
  REP(i, n) if (mil[i]) FOR(j, i, n - 1) if (mil[j]) q.emplace(i, j);
  bool good = false;
  while (!q.empty()) {
    auto now = q.front(); q.pop();
    int u = now._1, v = now._2;
    if (human[u] ^ human[v]) {
      good = true;
      break;
    }
    if (vis[u][v]) continue;
    vis[u][v] = vis[v][u] = true;
    REP(k, c) for (auto i : G[u][k]) for (auto j : G[v][k]) {
      if (vis[i][j]) continue;
      q.emplace(i < j ? mp(i, j) : mp(j, i));
    }
  }
  puts(good ? "YES" : "NO");
}
/*
 4 6 2 1 2
 0
 1 3
 0 1 0
 0 2 1
 0 1 2
 1 2 0
 2 2 1
 2 1 3
 
 5 6 2 1 1
 0
 4
 0 1 1
 1 1 2
 2 2 3
 2 2 1
 3 1 4
 4 1 4
 
 5 4 2 2 2
 1 3
 2 4
 0 2 1
 1 1 2
 3 2 3
 3 1 4
 */