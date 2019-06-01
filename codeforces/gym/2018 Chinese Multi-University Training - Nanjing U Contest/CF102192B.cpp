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

const double pi = acos(-1);
const double eps = 1e-9;

inline double dcmp(double x) {
  if (abs(x) < eps) return 0;
  return x > 0 ? 1 : -1;
}

pii operator - (pii a, pii b) {
  return {a._1 - b._1, a._2 - b._2};
}

double cross(pii a, pii b) {
  return abs(a._1 * b._2 - b._1 * a._2);
}

int T, w;
pii p[3];
double dis[3];

double go(double a, double b, double c) {
  double C = acos((sqr(a) + sqr(b) - sqr(c)) / (2 * a * b));
  if (dcmp(C - pi / 2) > 0) return 1e9;
  double th1 = 0, th2, h1, h2;
  if (dcmp(a - w) > 0) th1 = acos(w / a);
  th2 = C + th1;
  if (dcmp(th2 - pi / 2) > 0) return 1e9;
  if (dcmp(b * cos(th2) - w) <= 0) h1 = b * sin(th2);
  else h1 = sqrt(sqr(b) - sqr(w));
  h2 = a * sin(th1);
  return max(h1, h2);
}

int main() {
  scanf("%d", &T);
  while (T--) {
    REP(i, 3) scanf("%d%d", &p[i]._1, &p[i]._2);
    scanf("%d", &w);
    REP(i, 3) dis[i] = sqrt(sqr((p[i] - p[(i + 1) % 3])._1) + sqr((p[i] - p[(i + 1) % 3])._2));
    sort(dis, dis + 3);
    double h = cross(p[2] - p[0], p[1] - p[0]) / dis[2];
    if (dcmp(h - w) > 0) {
      puts("impossible");
      continue;
    }
    double ans = dis[2];
    do {
      chkmin(ans, go(dis[0], dis[1], dis[2]));
    } while (next_permutation(dis, dis + 3));
    printf("%.10lf\n", ans);
  }
}