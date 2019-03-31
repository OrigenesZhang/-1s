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

const int maxn = 512345;
const double eps = 1e-10;

pii seg[maxn];
int n, m, id[maxn];
ll ans[maxn];

inline ll f(pii a, pii b) {
  return ll(a._1) * b._1 + ll(a._2) * b._2;
}

inline int dcmp(double x) {
  if (abs(x) < eps) return 0;
  return x > 0 ? 1 : -1;
}

vector<pii> hull;

inline double query(pii now, double pos) {
  return now._1 * pos + now._2;
}

void add(pii now) {
  while (hull.size() > 1) {
    double pos = double(hull[hull.size() - 2]._2 - now._2) / (now._1 - hull[hull.size() - 2]._1);
    if (dcmp(query(now, pos) - query(hull.back(), pos)) <= 0) hull.pop_back();
    else break;
  }
  hull.eb(now);
}

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) {
    scanf("%d%d", &seg[i]._1, &seg[i]._2);
    id[i] = i;
  }
  scanf("%d", &m);
  vector<pii> rif(m);
  REP(i, m) scanf("%d%d", &rif[i]._1, &rif[i]._2);
  sort(all(rif)); uni(rif);
  int j = 0;
  FOR(i, 1, int(rif.size()) - 1) if (rif[i]._2 < rif[j]._2) rif[++j] = rif[i];
  REP(i, j + 1) add(rif[i]);
  sort(id + 1, id + n + 1, [](int a, int b) { return ll(seg[a]._1) * seg[b]._2 > ll(seg[a]._2) * seg[b]._1; });
  j = 0;
  m = int(hull.size()) - 1;
  FOR(i, 1, n) {
    while (j < m && f(seg[id[i]], hull[j]) >= f(seg[id[i]], hull[j + 1])) j++;
    ans[id[i]] = f(seg[id[i]], hull[j]);
  }
  FOR(i, 1, n) printf("%lld ", ans[i]);
}