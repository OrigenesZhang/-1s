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
const int MOD = 888887;

ll p[maxn];
int a[maxn], c[maxn], s[maxn];
int tbl[maxn][maxn], n, m;
pair<ll, ll> dp[maxn];

pair<ll, ll> operator+(const pair<ll, ll> &lhs, const pair<ll, ll> &rhs) {
  return {lhs._1 + rhs._1, lhs._2 + rhs._2};
};

int main() {
  scanf("%d%d", &n, &m);
  FOR(i, 1, n) scanf("%d", a + i);
  FOR(i, 1, n) scanf("%d", s + i);
  FOR(i, 1, n) scanf("%d", c + i);
  FOR(i, 1, n) FOR(j, 1, n) if (i != j)
        tbl[i][j] = (ll(a[j]) * s[i] + 2 * min(s[i], s[j])) % MOD;
  set<pair<ll, int>> q;
  FOR(i, 1, n) {
    p[i] = c[i];
    q.emplace(p[i], i);
  }
  while (!q.empty()) {
    auto now = *q.begin(); q.erase(q.begin());
    ll d = now._1;
    int u = now._2;
    if (d > p[u]) continue;
    FOR(v, 1, n) if (v != u) if (d + tbl[u][v] < p[v]) {
          p[v] = d + tbl[u][v];
          q.emplace(p[v], v);
        }
  }
  pair<ll, ll> ans;
  ROF(i, m, 1) FOR(j, 1, n) if (i >= s[j]) {
        chkmax(dp[i - s[j]], dp[i] + mp(a[j], -p[j]));
        chkmax(ans, dp[i - s[j]]);
      }
  printf("%lld %lld", ans._1, -ans._2);
}