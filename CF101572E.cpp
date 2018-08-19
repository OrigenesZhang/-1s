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
using namespace std;

long long n, m, grid[555][555], r, c, vst[555][555], ans;
set<pair<long long, pair<int, int>>> s;

int main() {
  cin >> n >> m;
  REP (i, n) REP (j, m) cin >> grid[i][j];
  cin >> r >> c;
  r--; c--;
  s.insert({grid[r][c], {r, c}});

  while (s.size()) {
    auto it = s.begin();
    r = (it->_2)._1;
    c = (it->_2)._2;
    long long lvl = it->_1;
    s.erase(it);
    if (vst[r][c]) continue;
    vst[r][c] = 1;
    ans -= lvl;

    FOR (dr, -1, 1) FOR (dc, -1, 1) if (dr || dc) {
      int nr = r + dr;
      int nc = c + dc;
      if (nr < 0 || nc < 0 || nr >= n || nc >= m || vst[nr][nc] || grid[nr][nc] >= 0) continue;
      s.insert({max(grid[nr][nc], lvl), {nr, nc}});
    }
  }

  cout << ans;
}