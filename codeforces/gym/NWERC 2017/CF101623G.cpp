#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(int)(a)-1)
#define reset(a,b) memset(a,b,sizeof(a))
#define all(x) x.begin(), x.end()
#define uni(x) x.erase(unique(all(x)), x.end());
#define BUG(x) cout << #x << " = " << x << endl
#define BUGP(x) cout << #x << " = " << x._1 << ", " << x._2 << endl
#define PR(x,a,b) {cout << #x << " = "; FOR (_,a,b) cout << x[_] << ' '; cout << endl;}
#define CON(x) {cout << #x << " = "; for(auto _i:x) cout << _i << ' '; cout << endl;}
#define mod 1000000007
#define pi acos(-1)
#define eps 1e-7
#define pb push_back
#define sqr(x) (x) * (x)
#define _1 first
#define _2 second

struct Point {
  double x, y;
  // Point() {} // this line causes compilation problem
  Point(double x = 0.0, double y = 0.0) : x(x), y(y) {}

  Point operator + (const Point& a) const { return Point(x+a.x, y+a.y); }
  Point operator - (const Point& a) const { return Point(x-a.x, y-a.y); }
  Point operator * (double k) const { return Point(x*k, y*k); }
  Point operator / (double k) const { return Point(x/k, y/k); }

  // dot product
  double operator * (const Point& a) const { return x*a.x + y*a.y; } 
  // cross product
  double operator % (const Point& a) const { return x*a.y - y*a.x; } 

  Point conj() { return Point(x, -y); }
  double norm() { return x*x + y*y; }
  double len() { return sqrt(norm()); }

  Point rotate(double alpha) {
    double cosa = cos(alpha), sina = sin(alpha);
    return Point(x * cosa - y * sina, x * sina + y * cosa);
  }
};

double angle(Point a, Point o, Point b) { // min of directed angle AOB & BOA
  a = a - o; b = b - o;
  return acos((a * b) / sqrt(a.norm()) / sqrt(b.norm()));
}

double directed_angle(Point a, Point o, Point b) { // angle AOB, in range [0, 2*PI)
  double t = -atan2(a.y - o.y, a.x - o.x)
    + atan2(b.y - o.y, b.x - o.x);
  while (t < 0) t += 2*pi;
  return t;
}

int n, x, y, ans;
vector<Point> points;
double ansr;

bool isInside(Point p, double length, int edge) {
  Point O = Point(0, 0);
  Point A = Point(length, 0);
  double alpha = 2 * pi / edge;
  Point B = A.rotate(alpha);
  while (directed_angle(A, O, p) > alpha) p = p.rotate(-alpha);
  return angle(p, B, O) <= angle(A, B, O);
}

int main() {
  ios::sync_with_stdio(0);
  cin >> n;
  REP (i, n) cin >> x >> y, points.pb(Point(x, y));
  FOR (edge, 3, 8) {
    double low = 0.0, high = 100000000.0;
    while (high - low > eps) {
      double chs = (high + low) / 2;
      bool flag = false;
      for (auto p: points) if (isInside(p, chs, edge)) {
        flag = true;
        break;
      }
      if (flag) high = chs;
      else low = chs;
    }
    double inner = high;
    low = 0.0; high = 100000000.0;
    while (high - low > eps) {
      double chs = (high + low) / 2;
      double flag = false;
      for (auto p: points) if (!isInside(p, chs, edge)) {
        flag = true;
        break;
      }
      if (flag) low = chs;
      else high = chs;
    }
    double outer = high;
    double tmp = sqr(inner / outer);
    if (tmp > ansr) ansr = tmp, ans = edge;
  }
  cout << ans << ' ' << ansr;
}
