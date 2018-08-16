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

int c, dis[133][133], m, ans;
char a, b;
string s, t;

int main() {
  ios::sync_with_stdio(false);
  cin >> s >> t >> m;
  reset(dis, 55);
  REP (i, 133) dis[i][i] = 0;
  while (m--) {
    cin >> a >> b >> c;
    dis[a][b] = min(dis[a][b], c);
  }
  REP (k, 130) REP (i, 130) REP (j, 130) dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
  REP (i, s.size()) {
    int x = dis[s[i]][t[i]];
    if (x > 1000000) {
      cout << -1;
      return 0;
    }
    ans += x;
  }

  cout << ans;
}