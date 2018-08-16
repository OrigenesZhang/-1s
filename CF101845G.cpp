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
#define BLK 316

long long expo(long long a, long long b) {
  long long res = 1;
  FORD (i, 30, 0) {
    res = (res * res) % mod;
    if (b & (1 << i)) res = (res * a) % mod;
  }
  return res;
}

long long inv(long long a) {
  return expo(a, mod - 2);
}

long long n, m, p, q, prob[26], dp[5500][5500];
string s;

int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m >> s;
  REP (i, 26) {
    cin >> p >> q;
    prob[i] = (p * inv(q)) % mod;
  }

  dp[0][0] = 1;
  FOR (i, 1, n) {
    dp[i][0] = 1;
    FOR (j, 1, min(i, m)) {
      p = prob[s[j - 1] - 'a'];
      dp[i][j] = (dp[i - 1][j - 1] * p + dp[i - 1][j] * (1 - p)) % mod;
    }
  }

  cout << (dp[n][m] + mod) % mod;
}