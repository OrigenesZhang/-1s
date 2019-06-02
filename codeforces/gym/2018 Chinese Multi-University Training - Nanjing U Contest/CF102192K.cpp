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

const int maxn = 21;
const int maxm = 12;
const ll MOD = 1e18;

int T, n, m, k;
char tab[maxm][maxn];
int en[maxn];
ll dp[maxn][1 << maxm], ans[maxn], fac[maxn];

inline int lowbit(int x) {
  return x & -x;
}

int main() {
  scanf("%d", &T);
  fac[0] = 1;
  FOR(i, 1, 20) fac[i] = fac[i - 1] * i;
  while (T--) {
    scanf("%d%d%d", &m, &n, &k);
    REP(i, m) scanf("%s", tab[i]);
    reset(en, 0);
    FOR(j, 1, n) REP(i, m) if (tab[i][j - 1] == 'Q') en[j] |= 1 << i;
    reset(ans, 0);
    FOR(mask, 1, (1 << m) - 1) {
      dp[0][0] = 1;
      FOR(i, 1, n) {
        bool vis = false;
        for (int submask = mask; ; submask = (submask - 1) & mask) {
          if (dp[i - 1][submask]) {
            if ((en[i] & mask) == en[i]) {
              vis = true;
              dp[i][submask] += dp[i - 1][submask];
            }
            for (int diff = (mask ^ submask) & en[i]; diff; diff -= lowbit(diff)) {
              vis = true;
              dp[i][submask | lowbit(diff)] += dp[i - 1][submask];
            }
            dp[i - 1][submask] = 0;
          }
          if (!submask) break;
        }
        if (!vis) break;
      }
      ans[__builtin_popcount(mask)] += dp[n][mask];
      for (int submask = mask; ; submask = (submask - 1) & mask) {
        dp[n][submask] = 0;
        if (!submask) break;
      }
    }
    FOR(i, 1, k) {
      __int128 now = ans[i];
      now *= fac[i];
      if (now >= MOD) printf("%lld%018lld\n", ll(now / MOD), ll(now % MOD));
      else printf("%lld\n", ll(now));
    }
  }
}