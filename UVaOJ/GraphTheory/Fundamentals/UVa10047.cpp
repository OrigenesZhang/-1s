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

const int maxn = 30;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

char mat[maxn][maxn];
int dp[maxn][maxn][5][4];
int n, m, cs;

inline bool check(int x, int y) {
  return x > 0 && x <= m && y > 0 && y <= n && mat[x][y] != '#';
}

int main() {
  while (scanf("%d%d", &m, &n) == 2) {
    if (!m) break;
    if (cs++) putchar('\n');
    FOR(i, 1, m) scanf("%s", mat[i] + 1);
    reset(dp, 0x3f);
    pii st, en;
    FOR(i, 1, m) FOR(j, 1, n) {
      if (mat[i][j] == 'S') st = {i, j};
      else if (mat[i][j] == 'T') en = {i, j};
    }
    queue<pair<pii, pii>> q;
    dp[st._1][st._2][0][0] = 0;
    q.emplace(st, mp(0, 0));
    while (!q.empty()) {
      auto now = q.front(); q.pop();
      int x = now._1._1, y = now._1._2, c = now._2._1, d = now._2._2;
      int nx = x + dx[d], ny = y + dy[d], nc = (c + 1) % 5;
      if (check(nx, ny) && dp[nx][ny][nc][d] > dp[x][y][c][d] + 1) {
        dp[nx][ny][nc][d] = dp[x][y][c][d] + 1;
        q.emplace(mp(nx, ny), mp(nc, d));
      }
      int nd = (d + 1) % 4;
      if (dp[x][y][c][nd] > dp[x][y][c][d] + 1) {
        dp[x][y][c][nd] = dp[x][y][c][d] + 1;
        q.emplace(mp(x, y), mp(c, nd));
      }
      nd = (d + 3) % 4;
      if (dp[x][y][c][nd] > dp[x][y][c][d] + 1) {
        dp[x][y][c][nd] = dp[x][y][c][d] + 1;
        q.emplace(mp(x, y), mp(c, nd));
      }
    }
    int ans = 0x3f3f3f3f;
    REP(i, 4) chkmin(ans, dp[en._1][en._2][0][i]);
    printf("Case #%d\n", cs);
    if (ans > 1e9) puts("destination not reachable");
    else printf("minimum time = %d sec\n", ans);
  }
}
