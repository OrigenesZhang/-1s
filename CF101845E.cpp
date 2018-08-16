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
//#define double long double

struct Point {
  double x, y;
  Point (double _x = 0, double _y = 0): x(_x), y(_y) {}
  Point operator-(const Point& a) const { return Point(x - a.x, y - a.y); }
  double operator*(const Point& a) const { return x * a.x + y * a.y; }
  double operator%(const Point& a) const { return x * a.y - y * a.x; }
  double norm() { return sqr(x) + sqr(y); }
  void debug() { cout << "point = " << x << ' ' << y << endl; }
};

bool check(Point a, Point o, Point b) {
  a = a - o; b = b - o;
  double angle = acos((a * b) / sqrt(a.norm()) / sqrt(b.norm()));
  return abs(sqrt(a.norm() * b.norm()) + (a * b)) < eps;
  //return abs(angle - pi) < 1e-6;
}

bool line(Point a, Point b, Point c) {
  a = a - b; c = c - b;
  return abs(a % c) < eps;
}

vector<Point> v;
double edge = sqrt(3);
long long ans = 0;
int res[] = {0, 3, 12, 33, 69, 132, 225, 360, 546, 801, 1128, 1551, 2073, 2718, 3507, 4464, 5592, 6927, 8472, 10263, 12327, 14700, 17385, 20430, 23850, 27687, 31968, 36741, 42009, 47838, 54231, 61236, 68892, 77253, 86352, 96261, 106983, 118578, 131091, 144594, 159090, 174669, 191334, 209157, 228201, 248538, 270171, 293196, 317634, 343575};

int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  cout << res[n - 1];
  return 0;

  v.pb(Point(0, 0));
  FOR (ii, 1, 50) {
    REP (jj, ii + 1) {
      Point cur = Point(edge * ii / 2 - jj * edge, ii);
      REP (i, v.size()) {
        bool flag = false;
        REP (j, v.size()) if (i - j) if (check(cur, v[j], v[i])) {
          flag = true;
          break;
        }
        if (flag) ans++;
      }
      v.pb(cur);
    }
    cout << ans << ", ";
    cout.flush();
  }
}