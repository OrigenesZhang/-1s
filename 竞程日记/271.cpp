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

const int maxn = 1123456;

int n, k;
ll dp[maxn], a[maxn];
deque<pair<ll, int>> q[2];

void add(deque<pair<ll, int>> &q, ll now, int id) {
  while (!q.empty() && q.back()._1 <= now) q.pop_back();
  q.eb(now, id);
}

int main() {
  scanf("%d%d", &n, &k);
  FOR(i, 1, n) scanf("%lld", a + i);
  ROF(i, n, 1) a[i] = a[i + 1] + a[i];
  FOR(i, 1, k) dp[i] = a[1] - a[i + 1];
  REP(i, k + 1) {
    add(q[0], dp[i] + a[i + 2], i);
    add(q[1], dp[i] + a[i + 3], i);
  }
  ll ans = dp[k];
  FOR(i, k + 1, n) {
    while (q[0].front()._2 < i - k - 1) q[0].pop_front();
    dp[i] = q[0].front()._1 - a[i + 1];
    if (i >= k + 2) {
      while (q[1].front()._2 < i - k - 2) q[1].pop_front();
      chkmax(dp[i], q[1].front()._1 - a[i + 1]);
    }
    add(q[0], dp[i] + a[i + 2], i);
    add(q[1], dp[i] + a[i + 3], i);
    chkmax(ans, dp[i]);
  }
  printf("%lld", ans);
}