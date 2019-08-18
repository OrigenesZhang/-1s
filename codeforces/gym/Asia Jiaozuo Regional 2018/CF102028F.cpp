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
 
const int maxn = 6123;
const int dx[] = {-1, -1, 1, 1, -2, 2};
const int dy[] = {-3, 3, -3, 3, 0, 0};
 
char G[maxn][maxn];
bool vis[maxn][maxn];
 
int solve() {
  int r, c;
  scanf("%d%d", &r, &c);
  getchar();
  r = 4 * r + 3, c = 6 * c + 3;
  pii st, en;
  REP(i, r) {
    fgets(G[i], c + 5, stdin);
    REP(j, c) {
      if (G[i][j] == 'S') st = {i, j};
      else if (G[i][j] == 'T') en = {i, j};
      vis[i][j] = false;
    }
  }
  queue<pair<pii, int>> q;
  q.emplace(st, 1);
  vis[st._1][st._2] = true;
  while (!q.empty()) {
    auto _ = q.front(); q.pop();
    int x = _._1._1, y = _._1._2, d = _._2;
    if (mp(x, y) == en) return d;
    REP(i, 6) {
      int nx = x + dx[i], ny = y + dy[i];
      if (G[nx][ny] == '\\' || G[nx][ny] == '/' || G[nx][ny] == '-' || vis[nx + dx[i]][ny + dy[i]]) continue;
      q.emplace(mp(nx + dx[i], ny + dy[i]), d + 1);
      vis[nx + dx[i]][ny + dy[i]] = true;
    }
  }
  return -1;
}
 
int main() {
  int T;
  scanf("%d", &T);
  while (T--) printf("%d\n", solve());
}