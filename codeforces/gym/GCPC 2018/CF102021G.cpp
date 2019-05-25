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
const double rii = 6371;
const double vv = 299792.458;
const double eps = 1e-9;

struct Point {
  double x, y, z;

  Point(double x, double y, double z) : x(x), y(y), z(z) {}

  Point(double lat, double lon) {
    lat *= pi / 180, lon *= pi / 180;
    x = cos(lat) * cos(lon);
    y = cos(lat) * sin(lon);
    z = sin(lat);
  }
};

inline int dcmp(double x) {
  if (abs(x) <= eps) return 0;
  return x > 0 ? 1 : -1;
}

Point operator+(Point a, Point b) {
  a.x += b.x, a.y += b.y, a.z += b.z;
  return a;
}

Point operator-(Point a, Point b) {
  a.x -= b.x, a.y -= b.y, a.z -= b.z;
  return a;
}

Point operator*(double lambda, Point a) {
  return {lambda * a.x, lambda * a.y, lambda * a.z};
}

inline Point cross(Point a, Point b) {
  return {a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x};
}

inline double dot(Point a, Point b) {
  return a.x * b.x + a.y * b.y + a.z * b.z;
}

inline double abs(Point a) {
  return sqrt(sqr(a.x) + sqr(a.y) + sqr(a.z));
}

Point rotate(Point p, Point o, double ang) {
  return cos(ang) * p + sin(ang) * cross(o, p);
}

int s;
double lo, la;

int main() {
  scanf("%d%lf%lf", &s, &lo, &la);
  Point o(la, lo);
  while (s--) {
    double phi, psi, r, x;
    scanf("%lf%lf%lf%lf", &phi, &psi, &r, &x);
    Point now(0, phi);
    Point c = dcmp(psi - 180) <= 0 ? Point(90 - psi, phi - 90) : Point(psi - 270, phi + 90);
    now = rotate(now, c, 2 * pi * x);
    now = r / rii * now;
    if (dcmp(dot(now, o) - 1) < 0) {
      puts("no signal");
    } else {
      double dis = abs(now - o);
      printf("%.10lf\n", dis * rii / vv);
    }
  }
}