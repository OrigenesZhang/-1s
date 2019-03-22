#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(int)(a)-1)
#define BUG(x) cout << #x << " = " << x << endl;
#define BUGP(x) cout << #x << " = " << x._1 << ' ' << x._2 << endl;
#define PR(x,a,b) { cout << #x << " = "; FOR(i,a,b) cout << x[i] << ' '; cout << endl; }
#define all(x) x.begin(), x.end()
#define pb push_back
#define _1 first
#define _2 second

int a, b, c, ans[3], vst[111][111];
vector<pair<int, int>> v;

int main() {
  REP (i, 3) cin >> a, v.pb({a, i});
  //FORD (i, 2, 0) cin >> a, v.pb({a, i});
  sort(all(v));
  reverse(all(v));
  a = v[0]._1;
  b = v[1]._1;
  c = v[2]._1;

  if (a > b * c) {
    cout << -1;
    return 0;
  }

  cout << a << endl;
  REP (i, c) vst[i][i] = 1;
  REP (i, b - c) vst[i + c][c - 1] = 1;
  int need = a - b;
  REP (i, b) REP (j, c) if (!vst[i][j]) {
    if (!need) break;
    need--;
    vst[i][j] = 1;
  }

  //for (auto p: v) BUGP(p);

  REP (i, b) REP (j, c) if (vst[i][j]) {
    ans[2] = i; ans[1] = j; ans[0] = 0;
    FORD (ii, 2, 0) REP (jj, 3) if (v[jj]._2 == ii) cout << ans[jj] << ' ';
    cout << endl;
  }
}