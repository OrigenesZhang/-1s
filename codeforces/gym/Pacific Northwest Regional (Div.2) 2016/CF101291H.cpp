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
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

char mat[maxn][maxn];
int vis[maxn][maxn], clk, n, m;
bool flag[maxn * maxn];

void dfs1(int x, int y) {
  if (vis[x][y]) return;
  vis[x][y] = clk;
  REP(i, 4) {
    int nx = x + dx[i], ny = y + dy[i];
    if (mat[nx][ny] == 'L') flag[clk] = true;
    if (mat[nx][ny] == 'C') dfs1(nx, ny);
  }
}

void dfs2(int x, int y) {
  if (vis[x][y]) return;
  vis[x][y] = 1;
  REP(i, 4) {
    int nx = x + dx[i], ny = y + dy[i];
    if (mat[nx][ny] == 'L') dfs2(nx, ny);
  }
}

int main() {
  scanf("%d%d", &n, &m);
  reset(mat, 'W');
  FOR(i, 1, n) scanf("%s", mat[i] + 1);
  FOR(i, 1, n) FOR(j, 1, m) if (mat[i][j] == 'C' && !vis[i][j]) {
        clk++;
        dfs1(i, j);
      }
  FOR(i, 1, n) FOR(j, 1, m) if (flag[vis[i][j]]) mat[i][j] = 'L';
  reset(vis, 0);
  int ans = 0;
  FOR(i, 1, n) FOR(j, 1, m) if (mat[i][j] == 'L' && !vis[i][j]) {
        ans++;
        dfs2(i, j);
      }
  printf("%d", ans);
}