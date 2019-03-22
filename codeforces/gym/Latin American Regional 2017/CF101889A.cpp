#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (long long i = (a); i <= (b); i++)
#define FORD(i,a,b) for (long long i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(long long)(a)-1)
#define reset(a,b) memset(a,b,sizeof(a))
#define all(x) x.begin(), x.end()
#define uni(x) x.erase(unique(all(x)), x.end());
#define BUG(x) cout << #x << " = " << x << endl
#define BUGP(x) cout << #x << " = " << x._1 << ", " << x._2 << endl
#define PR(x,a,b) {cout << #x << " = "; FOR (_,a,b) cout << x[_] << ' '; cout << endl;}
#define CON(x) {cout << #x << " = "; for(auto _i:x) cout << _i << ' '; cout << endl;}
#define mod 1000000007
#define pi acos(-1)
#define eps 1e-8
#define pb push_back
#define sqr(x) (x) * (x)
#define _1 first
#define _2 second
using namespace std;

struct Point {
  long long x, y;
  Point (long long _x = 0, long long _y = 0): x(_x), y(_y) {}
  void debug() {
    cout << "point = " << x << ' ' << y << endl;
  }
};

long long n, k, x, y, minx[14], maxx[14], height[14], base[14], total;
vector<Point> polygon[14], frontP[14], backP[14];
double dp[1 << 14][14], save[14][14];

double dis(Point a, Point b, Point c, long long shift) {
  a.x += shift;
  if (!(a.y >= b.y && a.y <= c.y)) {
    a.debug();
    b.debug();
    c.debug();
    assert(false);
  }
  return abs(b.x - a.x + (a.y - b.y) * 1.0 * (c.x - b.x) / (c.y - b.y));
}

int main() {
  cin >> n;
  REP (i, n) {
    cin >> k;
    REP (j, k) {
      cin >> x >> y;
      polygon[i].pb(Point(x, y));
      minx[i] = min(x, minx[i]);
      maxx[i] = max(x, maxx[i]);
      height[i] = max(height[i], y);
    }
    base[i] = polygon[i][1].x - polygon[i][0].x;
    FOR (j, 1, k - 1) {
      frontP[i].pb(polygon[i][j]);
      if (frontP[i].back().y == height[i]) break;
    }
    backP[i].pb(polygon[i][0]);
    FORD (j, k - 1, 1) {
      backP[i].pb(polygon[i][j]);
      if (backP[i].back().y == height[i]) break;
    }
    total += maxx[i] - minx[i];
  }
  
  REP (i, n) REP (j, n) if (i - j) {
    long long shift = maxx[i] - minx[j];
    double tmp = shift;
    int pt = 0;
    for (auto a: frontP[i]) {
      while (backP[j][pt + 1].y < a.y) pt++;
      tmp = min(tmp, dis(a, backP[j][pt], backP[j][pt + 1], -shift));
    }
    pt = 0;
    for (auto a: backP[j]) {
      while (frontP[i][pt + 1].y < a.y) pt++;
      tmp = min(tmp, dis(a, frontP[i][pt], frontP[i][pt + 1], shift));
    }
    save[i][j] = tmp;
    //cout << i << ' ' << j << ' ' << save[i][j] << endl;
  }

  FOR (mask, 1, (1 << n) - 1) REP (i, n) if (mask & (1 << i)) {
    dp[mask][i] = 0;
    if (mask == (1 << i)) continue;
    int submask = mask ^ (1 << i);
    REP (j, n) if (submask & (1 << j)) dp[mask][i] = max(dp[mask][i], dp[submask][j] + save[i][j]);
  }

  double ans = 0;
  REP (i, n) ans = max(ans, dp[(1 << n) - 1][i]);
  printf("%.3f", total - ans);
}