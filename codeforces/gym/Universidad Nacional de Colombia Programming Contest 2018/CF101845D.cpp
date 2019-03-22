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
#define BLK 316

struct Point {
  double x, y;
  Point (double _x = 0, double _y = 0): x(_x), y(_y) {}

  Point operator+(const Point &a) const { return Point(x + a.x, y + a.y); }
  Point operator-(const Point &a) const { return Point(x - a.x, y - a.y); }
  double operator*(const Point& a) const { return x * a.x + y * a.y; }

  double norm() { return sqr(x) + sqr(y); }
  double len() { return sqrt(norm()); }
};

double area(Point a, Point b, Point c) {
  Point ab = b - a;
  Point ac = c - a;
  return abs(ab.x * ac.y - ab.y * ac.x) / 2.0;
}

int n, m, x, y, l, r;
pair<int, int> query[100500];
Point point[100500];
double total, cur, ans;

bool compare(pair<int, int> p1, pair<int, int> p2) {
  return p1._1 / BLK < p2._1 / BLK || p1._1 / BLK == p2._1 / BLK && p1._2 > p2._2;
}

int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  REP (i, n) cin >> x >> y, point[i] = Point(x, y);
  REP (i, m) cin >> l >> r, l--, r--, query[i] = {min(l, r), max(l, r)};
  sort(query, query + m, compare);

  FOR (i, 1, n - 2) total += area(point[0], point[i], point[i + 1]);

  l = query[0]._1;
  r = query[0]._2;
  for (int i = (l + 1) % n; i != r; i = (i + 1) % n) cur += area(point[l], point[i], point[(i + 1) % n]);
  ans = min(cur, total - cur);

  FOR (q, 1, m - 1) {
    l = query[q]._1;
    r = query[q]._2;
    int prel = query[q - 1]._1;
    int prer = query[q - 1]._2;

    if (l < prel) FOR (i, l, prel - 1) cur += area(point[prer], point[i], point[i + 1]);
    else FOR (i, prel, l - 1) cur -= area(point[prer], point[i], point[i + 1]);

    if (r > prer) FOR (i, prer, r - 1) cur += area(point[l], point[i], point[i + 1]);
    else FOR (i, r, prer - 1) cur -= area(point[l], point[i], point[i + 1]);

    ans = max(ans, min(cur, total - cur));
  }

  cout << setprecision(11) << ans;
}