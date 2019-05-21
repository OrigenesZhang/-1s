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

const int maxn = 251234;

vector<pii> G[maxn];
int n, k;
ll dp[maxn][2], ans;
int dp2[maxn][2];

void dfs(int u, int par, ll val) {
  dp2[u][1] = 1;
  ll diff = -1e18;
  int cnt = 0;
  for (auto _ : G[u]) {
    int v = _._1;
    ll w = _._2 - val;
    if (v == par) continue;
    dfs(v, u, val);
    dp[u][0] += max(dp[v][0], dp[v][1]);
    dp[u][1] += max(dp[v][0], dp[v][1]);
    int now;
    if (dp[v][0] > dp[v][1]) now = dp2[v][0];
    else if (dp[v][1] > dp[v][0]) now = dp2[v][1];
    else now = min(dp2[v][0], dp2[v][1]);
    dp2[u][0] += now, dp2[u][1] += now;
    ll d = w - max(dp[v][0], dp[v][1]) + dp[v][0];
    if (d > diff) diff = d, cnt = dp2[v][0] - now;
    else if (d == diff) chkmin(cnt, dp2[v][0] - now);
  }
  dp[u][1] += diff;
  dp2[u][1] += cnt;
}

int go(ll val) {
  reset(dp, 0);
  reset(dp2, 0);
  dfs(1, 0, val);
  if (dp[1][0] > dp[1][1]) return dp2[1][0];
  if (dp[1][0] < dp[1][1]) return dp2[1][1];
  return min(dp2[1][0], dp2[1][1]);
}

int main() {
  scanf("%d%d", &n, &k);
  FOR(i, 1, n - 1) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    G[u].eb(v, w);
    G[v].eb(u, w);
  }
  ll lo = -1e12, hi = 1e12;
  while (lo + 1 < hi) {
    ll mi = lo + hi >> 1;
    int match = go(mi);
    if (match > k) lo = mi;
    else hi = mi;
  }
  go(hi);
  ans = max(dp[1][0], dp[1][1]) + ll(k) * hi;
  FOR(i, 1, n) for (auto &it : G[i]) it._2 = 1;
  if (go(0) < k) puts("Impossible");
  else printf("%lld", ans);
}