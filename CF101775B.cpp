#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(int)(a)-1)
#define BUG(x) cout << #x << " = " << x << endl;
#define BUGP(x) cout << #x << " = " << x._1 << ", " << x._2 << endl;
#define pb push_back
#define _1 first
#define _2 second
#define PR(x,a,b) { cout << #x << " = "; FOR(_,a,b) cout << x[_] << ' '; cout << endl; }
#define CON(x) { cout << #x << " = "; for (auto i: x) cout << i << ' '; cout << endl; }
#define eps 1e-9
#define sqr(x) ((x) * (x))
#define all(x) x.begin(), x.end()
#define mod 1000000007

long long t, n, m, tot, lis[200500], cnt[200500];
set<pair<double, int>> s;

int main() {
  ios::sync_with_stdio(0);
  cin >> t;
  FOR (cas, 1, t) {
    cout << "Case #" << cas << ": ";
    cin >> n >> m;
    s.clear();
    tot = 0;
    REP (i, n) cnt[i] = 1, cin >> lis[i], tot += lis[i];
    double mean = tot * 1.0 / m;
    REP (i, n) {
      double delta = 2 * sqr(lis[i] / 2.0 - mean) - sqr(lis[i] - mean);
      s.insert({delta, i});
    }
    REP (z, m - n) {
      auto it = s.begin();
      int i = it -> _2;
      s.erase(it);
      cnt[i]++;
      double delta = (cnt[i] + 1) * sqr(lis[i] * 1.0 / (cnt[i] + 1) - mean) - cnt[i] * sqr(lis[i] * 1.0 / cnt[i] - mean);
      s.insert({delta, i});
    }
    double ans = 0;
    REP (i, n) ans += cnt[i] * sqr(lis[i] * 1.0 / cnt[i] - mean);
    cout << setprecision(11) << ans / m << endl;
  }
}