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

long long n, cur[5][5], tmp[5][5], unit[5][5];

void expo(long long x) {
  FORD (ii, 60, 0) {
    REP (i, 5) REP (j, 5) {
      tmp[i][j] = 0;
      REP (k, 5) tmp[i][j] += cur[i][k] * cur[k][j], tmp[i][j] %= mod;
    }
    REP (i, 5) REP (j, 5) cur[i][j] = tmp[i][j];

    if (x & (1LL << ii)) {
      REP (i, 5) REP (j, 5) {
        tmp[i][j] = 0;
        REP (k, 5) tmp[i][j] += cur[i][k] * unit[k][j], tmp[i][j] %= mod;
      }
      REP (i, 5) REP (j, 5) cur[i][j] = tmp[i][j];
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  unit[0][0] = 16;
  unit[0][1] = 9;
  unit[0][2] = 4;
  unit[0][3] = 1;
  unit[1][0] = unit[2][1] = unit[3][2] = unit[4][3] = 1;

  REP (i, 5) cur[i][i] = 1;
  expo(n / 10);
  long long ans = 0;
  REP (i, 4) ans += cur[i][0], ans %= mod;
  if (n % 10 < 5) ans += cur[4][0], ans %= mod;
  cout << ans;
}