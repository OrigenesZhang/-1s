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
#define y1 asdfasd
#define y0 ajajaj

long long n, m, y1, y0, x, y, region, area, cur;
vector<pair<long long, pair<long long, long long> > > v;

int main() {
  ios::sync_with_stdio(0);
  cin >> n >> m >> y0;
  REP (i, n) cin >> x >> y, v.pb({x, {0, y}});
  cin >> y1;
  REP (i, m) cin >> x >> y, v.pb({x, {1, y}});
  sort(all(v));
  bool flag = y1 > y0;
  bool forbidden = true;
  int pre = -1;
  for (auto p: v) {
    x = p._1;
    int line = p._2._1;
    y = p._2._2;
    if (flag) cur += (y1 - y0) * (x - pre);
    pre = x;
    if (line) y1 = y;
    else y0 = y;
    if (y1 > y0 && !flag) forbidden = false, cur = 0;
    if (y0 > y1 && flag) {
      if (!forbidden) area += cur, region++;
    }
    flag = y1 > y0;
  }
  cout << region << ' ' << area;
}
