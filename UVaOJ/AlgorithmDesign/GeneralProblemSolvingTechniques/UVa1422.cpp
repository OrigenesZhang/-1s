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

const int maxt = 21234;
const double eps = 1e-9;

int T;
vector<pii> G[maxt];

inline int dcmp(double x) {
  if (abs(x) < eps) return 0;
  return x > 0 ? 1 : -1;
}

bool check(int v) {
  multiset<pair<int, double>> q;
  FOR(i, 1, 20001) {
    for (auto it : G[i]) q.emplace(it._1, it._2);
    if (q.empty()) continue;
    auto now = *q.begin(); q.erase(q.begin());
    if (now._1 <= i) return false;
    double clk = 1, need = now._2 / v;
    while (dcmp(clk - need) > 0 && !q.empty()) {
      clk -= need;
      now = *q.begin(); q.erase(q.begin());
      need = now._2 / v;
    }
    now._2 -= clk * v;
    if (dcmp(now._2) > 0) q.emplace(now);
  }
  return true;
}

int main() {
  scanf("%d", &T);
  while (T--) {
    FOR(i, 1, 20000) G[i].clear();
    int n;
    scanf("%d", &n);
    FOR(i, 1, n) {
      int r, d, w;
      scanf("%d%d%d", &r, &d, &w);
      G[r].eb(d, w);
    }
    int lo = 1, hi = 1e7 + 10;
    while (lo < hi) {
      int mi = lo + hi >> 1;
      if (check(mi)) hi = mi;
      else lo = mi + 1;
    }
    printf("%d\n", lo);
  }
}
