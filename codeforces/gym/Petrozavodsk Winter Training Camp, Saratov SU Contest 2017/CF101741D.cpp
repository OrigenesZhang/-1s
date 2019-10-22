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

const int maxn = 212345;

int n;
ll f[maxn];
int t[maxn], a[maxn];

ll solve() {
  vector<int> v;
  ROF(i, n, 1) if (v.empty() || a[i] > a[v.back()]) v.eb(i);
  reverse(all(v));
  n = v.size();
  int j = 0;
  set<pair<ll, int>> q;
  REP(i, n) {
    while (j < i && f[j] <= t[v[i]]) j++;
    f[i] = 2LL * a[v[j]] + t[v[i]];
    while (!q.empty()) {
      auto now = *q.begin();
      ll val = now._1;
      int k = now._2;
      if (f[k] <= t[v[i]]) q.erase(now);
      else {
        chkmin(f[i], val);
        break;
      }
    }
    if (i < n - 1) q.emplace(f[i] + 2 * a[v[i + 1]], i);
  }
  return f[n - 1];
}

int main() {
  while (~scanf("%d", &n)) {
    FOR(i, 1, n) scanf("%d%d", t + i, a + i);
    printf("%lld\n", solve());
  }
}