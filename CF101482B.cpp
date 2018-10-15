#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(int)(a)-1)
#define BUG(x) cout << #x << " = " << x << endl
#define BUGP(x) cout << #x << " = " << x._1 << ' ' << x._2 << endl
#define PR(x,a,b) { cout << #x << " = "; FOR(_,a,b) cout << x[_] << ' '; cout << endl; }
#define CON(x) { cout << #x << " = "; for (auto i:x) cout << i << ' '; cout << endl; }
#define all(x) x.begin(), x.end()
#define uni(x) x.erase(unique(all(x)), x.end());
#define mod 1000000007
#define eps 1e-8
#define pb push_back
#define sqr(x) ((x) * (x))
#define _1 first
#define _2 second
#define x1 asdfas
#define y1 asdfasj
#define x2 asdfask
#define y2 asdfasl

double vwalk, vbike, xlow, ylow, xhigh, yhigh, x1, y1, x2, y2, x[1111], y[1111], ans;
int n;

double dis(double x1, double y1, double x2, double y2) {
  return sqrt(sqr(x1 - x2) + sqr(y1 - y2));
}

double rent(double x1, double y1, double xbike1, double ybike1, double xbike2, double ybike2) {
  return dis(x1, y1, xbike1, ybike1) / vwalk + dis(xbike1, ybike1, xbike2, ybike2) / vbike;
}

double f(double xx1, double yy1, double xbike, double ybike) {
  double low = min(xx1, xbike), high = max(xx1, xbike);
  low = min(yy1, ybike); high = max(yy1, ybike);
  while (high - low > eps) {
    double mid1 = (high + low) / 2, mid2 = (high + mid1) / 2;
    if (rent(xx1, yy1, xlow, mid1, xbike, ybike) > rent(xx1, yy1, xlow, mid2, xbike, ybike)) low = mid1;
    else high = mid2;
  }
  double ans = rent(xx1, yy1, xlow, high, xbike, ybike);

  low = min(yy1, ybike); high = max(yy1, ybike);
  while (high - low > eps) {
    double mid1 = (high + low) / 2, mid2 = (high + mid1) / 2;
    if (rent(xx1, yy1, xhigh, mid1, xbike, ybike) > rent(xx1, yy1, xhigh, mid2, xbike, ybike)) low = mid1;
    else high = mid2;
  }
  ans = min(ans, rent(xx1, yy1, xhigh, high, xbike, ybike));

  low = min(xx1, xbike); high = max(xx1, xbike);
  while (high - low > eps) {
    double mid1 = (high + low) / 2, mid2 = (high + mid1) / 2;
    if (rent(xx1, yy1, mid1, ylow, xbike, ybike) > rent(xx1, yy1, mid2, ylow, xbike, ybike)) low = mid1;
    else high = mid2;
  }
  ans = min(ans, rent(xx1, yy1, high, ylow, xbike, ybike));

  low = min(xx1, xbike); high = max(xx1, xbike);
  while (high - low > eps) {
    double mid1 = (high + low) / 2, mid2 = (high + mid1) / 2;
    if (rent(xx1, yy1, mid1, yhigh, xbike, ybike) > rent(xx1, yy1, mid2, yhigh, xbike, ybike)) low = mid1;
    else high = mid2;
  }
  ans = min(ans, rent(xx1, yy1, high, yhigh, xbike, ybike));
  return ans;
}

int main() {
  cin >> vwalk >> vbike >> xlow >> ylow >> xhigh >> yhigh >> x1 >> y1 >> x2 >> y2 >> n;
  REP (i, n) cin >> x[i] >> y[i];

  ans = dis(x1, y1, x2, y2) / vwalk;
  REP (i, n) REP (j, n) ans = min(ans, rent(x1, y1, x[i], y[i], x[j], y[j]) + dis(x[j], y[j], x2, y2) / vwalk);

  REP (i, n) ans = min(ans, f(x1, y1, x[i], y[i]) + dis(x[i], y[i], x2, y2) / vwalk);
  swap(x1, x2); swap(y1, y2);
  REP (i, n) ans = min(ans, f(x1, y1, x[i], y[i]) + dis(x[i], y[i], x2, y2) / vwalk);
  swap(x1, x2); swap(y1, y2);

  double ohigh = xhigh, olow = xlow;
  while (ohigh - olow > eps) {
    double mid1 = (ohigh + olow) / 2, mid2 = (mid1 + ohigh) / 2;
    if (f(x1, y1, mid1, yhigh) + dis(mid1, yhigh, x2, y2) / vwalk > f(x1, y1, mid2, yhigh) + dis(mid2, yhigh, x2, y2) / vwalk) olow = mid1;
    else ohigh = mid2;
  }
  ans = min(ans, f(x1, y1, ohigh, yhigh) + dis(ohigh, yhigh, x2, y2) / vwalk);

  ohigh = xhigh; olow = xlow;
  while (ohigh - olow > eps) {
    double mid1 = (ohigh + olow) / 2, mid2 = (mid1 + ohigh) / 2;
    if (f(x1, y1, mid1, ylow) + dis(mid1, ylow, x2, y2) / vwalk > f(x1, y1, mid2, ylow) + dis(mid2, ylow, x2, y2) / vwalk) olow = mid1;
    else ohigh = mid2;
  }
  ans = min(ans, f(x1, y1, ohigh, ylow) + dis(ohigh, ylow, x2, y2) / vwalk);

  ohigh = yhigh, olow = ylow;
  while (ohigh - olow > eps) {
    double mid1 = (ohigh + olow) / 2, mid2 = (mid1 + ohigh) / 2;
    if (f(x1, y1, xlow, mid1) + dis(xlow, mid1, x2, y2) / vwalk > f(x1, y1, xlow, mid2) + dis(xlow, mid2, x2, y2) / vwalk) olow = mid1;
    else ohigh = mid2;
  }
  ans = min(ans, f(x1, y1, xlow, ohigh) + dis(xlow, ohigh, x2, y2) / vwalk);

  ohigh = yhigh, olow = ylow;
  while (ohigh - olow > eps) {
    double mid1 = (ohigh + olow) / 2, mid2 = (mid1 + ohigh) / 2;
    if (f(x1, y1, xhigh, mid1) + dis(xhigh, mid1, x2, y2) / vwalk > f(x1, y1, xhigh, mid2) + dis(xhigh, mid2, x2, y2) / vwalk) olow = mid1;
    else ohigh = mid2;
  }
  ans = min(ans, f(x1, y1, xhigh, ohigh) + dis(xhigh, ohigh, x2, y2) / vwalk);

  cout << setprecision(11) << ans;
}