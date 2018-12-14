#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(int)(a)-1)
#define BUG(x) cout << #x << " = " << x << endl
#define BUGP(x) cout << #x << " = " << x._1 << ' ' << x._2 << endl
#define reset(a,b) memset(a,b,sizeof(a))
#define PR(x,a,b) { cout << #x << " = "; FOR(_,a,b) cout << x[_] << ' '; cout << endl; }
#define CON(x) { cout << #x << " = "; for(auto _i: x) cout << _i << ' '; cout << endl; }
#define all(x) x.begin(), x.end()
#define uni(x) x.erase(unique(all(x)), x.end())
#define mod 1000000007
#define eps 1e-9
#define sqr(x) ((x) * (x))
#define pi acos(-1)
#define pb push_back
#define _1 first
#define _2 second

struct Point {
  double x, y;
  Point(double x = 0, double y = 0): x(x), y(y) {}
  Point operator+ (const Point& a) const { return Point(x+a.x, y+a.y); }
  Point operator- (const Point& a) const { return Point(x-a.x, y-a.y); }
  Point operator* (double k) const { return Point(k * x, k * y); }
  double operator* (const Point& a) const { return x*a.x + y*a.y; }
  double norm() { return x * x + y * y; }
  double len() { return sqrt(norm()); }
  bool operator< (const Point& a) const { return x < a.x || abs(x - a.x) < eps && y < a.y; }
};

bool same(Point a, Point b) {
  return abs(a.x - b.x) < eps && abs(a.y - b.y) < eps;
}

Point distLine (Point p, Point a, Point b) {
  Point ap = p - a, ab = b - a;
  double u = (ap * ab) / ab.norm();
  Point c = (a + ab * u);
  return (p - c);
}

int n, ans, dp[1 << 16];
Point lis[22];
vector<pair<Point, int>> v;
vector<int> lines;

int linemask(int lmask) {
  int res = 0;
  REP (i, lines.size()) if ((1 << i) & lmask) res |= lines[i];
  return res;
}

int main() {
  cin >> n;
  REP (i, n) cin >> lis[i].x >> lis[i].y;

  FOR (mask, 3, (1 << n) - 1) if (__builtin_popcount(mask) % 2 == 0) {
    int i = -1;
    REP (j, n) if ((1 << j) & mask) {
      i = j;
      break;
    }

    REP (j, n) if ((1 << j) & mask) if (i != j) {
      int submask = mask ^ (1 << i) ^ (1 << j);
      v.clear();
      lines.clear();
      REP (k, n) if ((1 << k) & submask) v.pb({distLine(lis[k], lis[i], lis[j]), k});
      sort(all(v));

      while (v.size() > 1) {
        auto p = v.back(); v.pop_back();
        if (!same(v.back()._1, p._1)) continue;
        int line = (1 << p._2) | (1 << v.back()._2);
        v.pop_back();
        lines.pb(line);
      }

      REP (lmask, (1 << lines.size())) {
        int premask = submask ^ linemask(lmask);
        int grp = __builtin_popcount(lmask);
        dp[mask] = max(dp[mask], dp[premask] + grp * (grp + 1) / 2);
      }
    }
    ans = max(ans, dp[mask]);
  }

  cout << ans;
}