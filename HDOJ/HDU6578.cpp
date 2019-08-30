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

const int maxn = 112;
const int MOD = 998244353;

vector<pii> G[maxn];
int f[2][maxn][maxn][maxn];

inline int add(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}

bool check(int x, int i, int j, int k) {
  for (auto c : G[x]) {
    int l = c._1, u = c._2;
    int cnt = 1 + (i >= l) + (j >= l) + (k >= l);
    if (cnt != u) return false;
  }
  return true;
}

void solve() {
  int n, m;
  scanf("%d%d", &n, &m);
  FOR(i, 1, n) G[i].clear();
  while (m--) {
    int l, r, x;
    scanf("%d%d%d", &l, &r, &x);
    G[r].eb(l, x);
  }
  f[0][0][0][0] = 1;
  int now = 1, pre = 0, ans = 0;
  REP(x, n + 1) {
    REP(i, x + 1) REP(j, i + 1) REP(k, j + 1) f[now][i][j][k] = 0;
    for (int i = 0; !i || i < x; i++) for (int j = 0; !j || j < i; j++) for (int k = 0; !k || k < j; k++) {
      if (!f[pre][i][j][k]) continue;
      if (!check(x, i, j, k)) {
        f[pre][i][j][k] = 0;
        continue;
      }
      if (x == n) {
        ans = add(ans, f[pre][i][j][k]);
        f[pre][i][j][k] = 0;
        continue;
      }
      f[now][i][j][k] = add(f[now][i][j][k], f[pre][i][j][k]);
      f[now][x][j][k] = add(f[now][x][j][k], f[pre][i][j][k]);
      f[now][x][i][k] = add(f[now][x][i][k], f[pre][i][j][k]);
      f[now][x][i][j] = add(f[now][x][i][j], f[pre][i][j][k]);
    }
    swap(now, pre);
  }
  printf("%d\n", ans);
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) solve();
}
