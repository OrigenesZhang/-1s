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

int n, k;
ll ans;
priority_queue<pii> lis[2];

void solve(priority_queue<pii> &q) {
  while (!q.empty()) {
    auto now = q.top(); q.pop();
    int x = now._1, m = now._2;
    ans += m / k *  ll(x) * 2;
    m -= m / k * k;
    if (!m) continue;
    ans += 2 * x;
    int rem = k - m;
    while (rem && !q.empty()) {
      auto cur = q.top(); q.pop();
      if (rem >= cur._2) {
        rem -= cur._2;
        continue;
      }
      cur._2 -= rem;
      rem = 0;
      q.push(cur);
    }
  }
}

int main() {
  scanf("%d%d", &n, &k);
  FOR(i, 1, n) {
    int x, m;
    scanf("%d%d", &x, &m);
    if (!x) continue;
    if (x < 0) lis[0].push(mp(-x, m));
    else lis[1].push(mp(x, m));
  }
  solve(lis[0]);
  solve(lis[1]);
  printf("%lld", ans);
}