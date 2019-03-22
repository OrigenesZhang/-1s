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

const int maxn = 55;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int dp[maxn][maxn][maxn], n, m, len;
char mat[maxn][maxn], cmd[maxn];

typedef pair<pii, pii> Node;

int main() {
  scanf("%d%d", &n, &m);
  FOR(i, 1, n) scanf("%s", mat[i] + 1);
  scanf("%s", cmd + 1);
  len = strlen(cmd + 1);
  reset(dp, 0x3f);
  int sx, sy, tx, ty;
  FOR(i, 1, n) FOR(j, 1, m) {
      if (mat[i][j] == 'R') sx = i, sy = j;
      if (mat[i][j] == 'E') tx = i, ty = j;
    }
  dp[sx][sy][1] = 0;
  set<Node> s;
  s.insert(mp(mp(0, 1), mp(sx, sy)));
  while (!s.empty()) {
    auto now = *s.begin(); s.erase(now);
    int used = now._1._1, pos = now._1._2, x = now._2._1, y = now._2._2;
    if (used > dp[x][y][pos]) continue;
    if (x == tx && y == ty) {
      printf("%d", used);
      return 0;
    }
    if (pos != len + 1) {
      int nx = x, ny = y, np = pos + 1;
      if (cmd[pos] == 'U' && nx != 1 && mat[nx - 1][ny] != '#') nx--;
      if (cmd[pos] == 'D' && nx != n && mat[nx + 1][ny] != '#') nx++;
      if (cmd[pos] == 'L' && ny != 1 && mat[nx][ny - 1] != '#') ny--;
      if (cmd[pos] == 'R' && ny != m && mat[nx][ny + 1] != '#') ny++;
      if (dp[nx][ny][np] > used) {
        dp[nx][ny][np] = used;
        s.insert(mp(mp(used, np), mp(nx, ny)));
      }
      if (dp[x][y][np] > used + 1) {
        dp[x][y][np] = used + 1;
        s.insert(mp(mp(used + 1, np), mp(x, y)));
      }
    }
    REP(i, 4) {
      int nx = x + dx[i], ny = y + dy[i];
      if (!nx) nx++;
      if (nx == n + 1) nx--;
      if (!ny) ny++;
      if (ny == m + 1) ny--;
      if (mat[nx][ny] == '#') nx -= dx[i], ny -= dy[i];
      if (dp[nx][ny][pos] > used + 1) {
        dp[nx][ny][pos] = used + 1;
        s.insert(mp(mp(used + 1, pos), mp(nx, ny)));
      }
    }
  }
}