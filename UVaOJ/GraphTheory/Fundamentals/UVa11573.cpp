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

const int maxn = 1123;
const int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

int r, c, n;
char mat[maxn][maxn];
int dis[maxn][maxn];

inline bool check(int x, int y) {
  return x > 0 && x <= r && y > 0 && y <= c;
}

int main() {
  scanf("%d%d", &r, &c);
  FOR(i, 1, r) {
    scanf("%s", mat[i] + 1);
    FOR(j, 1, c) mat[i][j] -= '0';
  }
  scanf("%d", &n);
  while (n--) {
    pii st, en;
    scanf("%d%d%d%d", &st._1, &st._2, &en._1, &en._2);
    reset(dis, 0x3f);
    dis[st._1][st._2] = 0;
    set<pair<int, pii>> q;
    q.emplace(0, st);
    while (!q.empty()) {
      auto _ = *q.begin(); q.erase(q.begin());
      int d = _._1, x = _._2._1, y = _._2._2;
      if (dis[x][y] < d) continue;
      if (mp(x, y) == en) break;
      REP(i, 8) {
        int nx = x + dx[i], ny = y + dy[i], nd = d + (mat[x][y] != i);
        if (check(nx, ny) && dis[nx][ny] > nd) {
          dis[nx][ny] = nd;
          q.emplace(nd, mp(nx, ny));
        }
      }
    }
    printf("%d\n", dis[en._1][en._2]);
  }
}
