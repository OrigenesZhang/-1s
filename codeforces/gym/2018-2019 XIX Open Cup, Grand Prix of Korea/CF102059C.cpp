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

const int maxn = 5123;
const int MOD = 1e9 + 7;

inline int add(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}

inline int mul(int a, int b) {
  return ll(a) * b % MOD;
}

inline int inv(int a) {
  int pw = MOD - 2, ret = 1;
  while (pw) {
    if (pw & 1) ret = mul(ret, a);
    a = mul(a, a);
    pw >>= 1;
  }
  return ret;
}

int dp[maxn][maxn], dp2[maxn][maxn];
int n, r, h, a, b, ans;
char s[maxn];

int main() {
  scanf("%d%d%d", &n, &r, &h);
  scanf("%s%d%d", s + 1, &a, &b);
  int pl = mul(r, inv(r + h)), pr = add(1, MOD - pl);
  dp[0][b] = 1;
  FOR(i, 1, n) {
    if (s[i] == 'R') FOR(j, 1, n) dp[i][j] = add(mul(dp[i - 1][j], pl), mul(dp[i][j - 1], pr));
    else REP(j, n) dp[i][j] = dp[i - 1][j + 1];
  }
  dp2[n + 1][a] = 1;
  ROF(i, n, 1) {
    if (s[i] == 'H') FOR(j, 1, n) dp2[i][j] = add(mul(dp2[i + 1][j], pr), mul(dp2[i][j - 1], pl));
    else REP(j, n) dp2[i][j] = dp2[i + 1][j + 1];
  }
  REP(i, n + 1) ans = add(ans, mul(dp[i][0], dp2[i + 1][0]));
  printf("%d", ans);
}