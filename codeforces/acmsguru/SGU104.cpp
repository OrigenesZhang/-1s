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

const int maxn = 112;

int dp[maxn][maxn], pre[maxn][maxn], a[maxn][maxn];
int f, v;

int main() {
  scanf("%d%d", &f, &v);
  FOR(i, 1, f) FOR(j, 1, v) scanf("%d", &a[i][j]);
  reset(dp, 0xc0);
  dp[0][0] = 0;
  FOR(i, 1, v) {
    dp[i][0] = 0;
    FOR(j, 1, f) {
      dp[i][j] = dp[i - 1][j];
      pre[i][j] = j;
      if (dp[i][j] < dp[i - 1][j - 1] + a[j][i]) {
        dp[i][j] = dp[i - 1][j - 1] + a[j][i];
        pre[i][j] = j - 1;
      }
    }
  }
  printf("%d\n", dp[v][f]);
  int j = f;
  stack<int> s;
  ROF(i, v, 1) if (pre[i][j] != j) {
    s.emplace(i);
    j--;
  }
  while (!s.empty()) {
    printf("%d ", s.top());
    s.pop();
  }
}