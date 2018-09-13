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

long long n, l[100500], r[100500], prop[100500], dp[100500][2][2];

int nand(int x, int y) {
  if (x && y) return 0;
  return 1;
}

int combine(int a, int b, int prop) {
  if (prop == -1) return nand(a, b);
  return prop;
}

void solve(int x) {
  if (l[x]) solve(l[x]);
  if (r[x]) solve(r[x]);
  REP (lwant, 2) REP (lreal, 2) REP (rwant, 2) REP (rreal, 2) {
    int want = combine(lwant, rwant, -1);
    int real_ = combine(lreal, rreal, prop[x]);
    dp[x][want][real_] += dp[l[x]][lwant][lreal] * dp[r[x]][rwant][rreal];
    dp[x][want][real_] %= mod;
  }
  //BUG(x);
  //REP (i, 2) REP (j, 2) cout << i << ' ' << j << ' ' << dp[x][i][j] << endl;
}


int main() {
  cin >> n;
  FOR (i, 1, n) cin >> l[i] >> r[i] >> prop[i];
  dp[0][0][0] = 1;
  dp[0][1][1] = 1;
  solve(1);
  cout << (dp[1][0][1] + dp[1][1][0]) % mod;
}