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
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int T, R, C;
char mat[maxn][maxn];
int dis1[maxn][maxn], dis2[maxn][maxn];

bool check(int x, int y) {
  return x > 0 && x <= R && y > 0 && y <= C && mat[x][y] != '#';
}

int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &R, &C);
    FOR(i, 1, R) scanf("%s", mat[i] + 1);
    reset(dis1, 0x3f);
    queue<pii> q;
    FOR(i, 1, R) FOR(j, 1, C) if (mat[i][j] == 'F') {
      q.emplace(i, j);
      dis1[i][j] = 0;
    }
    while (!q.empty()) {
      auto x = q.front()._1, y = q.front()._2; q.pop();
      REP(i, 4) {
        int nx = x + dx[i], ny = y + dy[i];
        if (check(nx, ny) && dis1[nx][ny] > dis1[x][y] + 1) {
          dis1[nx][ny] = dis1[x][y] + 1;
          q.emplace(nx, ny);
        }
      }
    }
    reset(dis2, 0x3f);
    int ans = 0x3f3f3f3f;
    pii st;
    FOR(i, 1, R) FOR(j, 1, C) if (mat[i][j] == 'J') {
      st = {i, j};
      break;
    }
    dis2[st._1][st._2] = 0;
    q.emplace(st);
    while (!q.empty()) {
      auto x = q.front()._1, y = q.front()._2; q.pop();
      REP(i, 4) {
        int nx = x + dx[i], ny = y + dy[i];
        if (!nx || !ny || nx == R + 1 || ny == C + 1) {
          chkmin(ans, dis2[x][y] + 1);
          continue;
        }
        if (mat[nx][ny] != '#' && dis1[nx][ny] > dis2[x][y] + 1 && dis2[nx][ny] > dis2[x][y] + 1) {
          dis2[nx][ny] = dis2[x][y] + 1;
          q.emplace(nx, ny);
        }
      }
    }
    if (ans > 1e9) puts("IMPOSSIBLE");
    else printf("%d\n", ans);
  }
}
