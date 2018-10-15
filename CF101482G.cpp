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

long long n, d, x[100500], y[100500], edge[4], ans;
vector<long long> vx, vy;
map<long long, long long> mx, my;
set<pair<long long, long long>> sx, sy;

long long findx(long long x) {
  auto it = sx.lower_bound({x, -1});
  if (it == sx.end()) {
    it--;
    long long xx = it->_1;
    return mx[xx] + n * (x - xx);
  }
  long long xx = it->_1;
  long long i = it->_2;
  return mx[xx] + (xx - x) * (n - i * 2);
}

long long findy(long long y) {
  auto it = sy.lower_bound({y, -1});
  if (it == sy.end()) {
    it--;
    long long yy = it->_1;
    return my[yy] + n * (y - yy);
  }
  long long yy = it->_1;
  long long i = it->_2;
  return my[yy] + (yy - y) * (n - i * 2);
}

void consider(long long x, long long y) {
  if (y - x > edge[0]) return;
  if (y - x < edge[2]) return;
  if (y + x > edge[1]) return;
  if (y + x < edge[3]) return;
  long long tmp = findx(x) + findy(y);
  //cout << x << ' ' << y << ' ' << tmp << endl;
  if (ans == -1) ans = tmp;
  else ans = min(ans, tmp);
}

int main() {
  cin >> n;
  REP (i, n) cin >> x[i] >> y[i];
  cin >> d;

  REP (i, n) vx.pb(x[i]);
  sort(all(vx));
  long long cur = 0;
  for (auto i: vx) cur += i - vx[0];
  mx[vx[0]] = cur;
  sx.insert({vx[0], 0});
  FOR (i, 1, n - 1) {
    cur += (vx[i] - vx[i - 1]) * (i * 2 - n);
    mx[vx[i]] = cur;
    sx.insert({vx[i], i});
  }

  REP (i, n) vy.pb(y[i]);
  sort(all(vy));
  cur = 0;
  for (auto i: vy) cur += i - vy[0];
  my[vy[0]] = cur;
  sy.insert({vy[0], 0});
  FOR (i, 1, n - 1) {
    cur += (vy[i] - vy[i - 1]) * (i * 2 - n);
    my[vy[i]] = cur;
    sy.insert({vy[i], i});
  }

  edge[0] = y[0] - x[0] + d;
  edge[2] = y[0] - x[0] - d;
  edge[1] = y[0] + x[0] + d;
  edge[3] = y[0] + x[0] - d;
  FOR (i, 1, n - 1) {
    edge[0] = min(edge[0], y[i] - x[i] + d);
    edge[2] = max(edge[2], y[i] - x[i] - d);
    edge[1] = min(edge[1], y[i] + x[i] + d);
    edge[3] = max(edge[3], y[i] + x[i] - d);
  }
  ans = -1;

  consider(vx[n / 2], vy[n / 2]);

  long long tmpy = (edge[0] + edge[1]) / 2;
  long long tmpx = tmpy - edge[0];
  consider(tmpx, tmpy);
  tmpy = (edge[0] + edge[3] + 1) / 2;
  tmpx = tmpy - edge[0];
  consider(tmpx, tmpy);
  for (auto tmpx: vx) tmpy = tmpx + edge[0], consider(tmpx, tmpy);
  for (auto tmpy: vy) tmpx = tmpy - edge[0], consider(tmpx, tmpy);

  tmpy = (edge[0] + edge[1]) / 2;
  tmpx = edge[1] - tmpy;
  consider(tmpx, tmpy);
  tmpy = (edge[1] + edge[2] + 1) / 2;
  tmpx = edge[1] - tmpy;
  consider(tmpx, tmpy);
  for (auto tmpx: vx) tmpy = edge[1] - tmpx, consider(tmpx, tmpy);
  for (auto tmpy: vy) tmpx = edge[1] - tmpy, consider(tmpx, tmpy);

  tmpy = (edge[1] + edge[2]) / 2;
  tmpx = tmpy - edge[2];
  consider(tmpx, tmpy);
  tmpy = (edge[2] + edge[3] + 1) / 2;
  tmpx = tmpy - edge[2];
  consider(tmpx, tmpy);
  for (auto tmpx: vx) tmpy = tmpx + edge[2], consider(tmpx, tmpy);
  for (auto tmpy: vy) tmpx = tmpy - edge[2], consider(tmpx, tmpy);

  tmpy = (edge[2] + edge[3] + 1) / 2;
  tmpx = edge[3] - tmpy;
  consider(tmpx, tmpy);
  tmpy = (edge[3] + edge[0]) / 2;
  tmpx = edge[3] - tmpy;
  consider(tmpx, tmpy);
  for (auto tmpx: vx) tmpy = edge[3] - tmpx, consider(tmpx, tmpy);
  for (auto tmpy: vy) tmpx = edge[3] - tmpy, consider(tmpx, tmpy);

  if (ans == -1) cout << "impossible";
  else cout << ans;
}