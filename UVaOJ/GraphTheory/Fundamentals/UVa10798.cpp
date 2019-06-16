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

const int maxn = 22;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

int n, ans;
char mat[maxn][maxn];
int dp[maxn][maxn][11][11][11][11];

inline bool check(int x, int y) {
  return x > 0 && x <= n && y > 0 && y <= n;
}

int main() {
  while (scanf("%d", &n) == 1) {
    if (!n) break;
    FOR(i, 1, n) scanf("%s", mat[i] + 1);
    reset(dp, 0x3f);
    set<pair<int, pair<pii, vector<int>>>> q;
    q.emplace(0, mp(mp(n / 2 + 1, n / 2 + 1), vector<int>(4)));
    ans = 1e9;
    dp[n / 2 + 1][n / 2 + 1][0][0][0][0] = 0;
    while (!q.empty()) {
      auto _ = *q.begin(); q.erase(q.begin());
      int dis = _._1, x = _._2._1._1, y = _._2._1._2;
      int l = _._2._2[0], r = _._2._2[1], d = _._2._2[2], u = _._2._2[3];
      if (dp[x][y][l][r][d][u] < dis) continue;
      bool flag = false;
      REP(i, 4) {
        int nx = x + dx[i], ny = y + dy[i];
        if (!check(nx, ny)) {
          chkmin(ans, dis);
          flag = true;
          break;
        }
        int nl = l, nr = r, nd = d, nu = u;
        if (mat[nx][ny] == 'R') nl++;
        if (mat[n - nx + 1][n - ny + 1] == 'R') nr++;
        if (mat[n - ny + 1][nx] == 'R') nd++;
        if (mat[ny][n - nx + 1] == 'R') nu++;
        vector<int> nxt{nl, nr, nd, nu};
        int ndis = *max_element(all(nxt));
        if (dp[nx][ny][nl][nr][nd][nu] > ndis) {
          dp[nx][ny][nl][nr][nd][nu] = ndis;
          q.emplace(ndis, mp(mp(nx, ny), nxt));
        }
      }
      if (flag) break;
    }
    printf("At most %d rose(s) trampled.\n", ans);
  }
}
