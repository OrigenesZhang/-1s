#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (long long i = (a); i <= (b); i++)
#define FORD(i,a,b) for (long long i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(long long)(a)-1)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl;
#define BUGP(x) cout << #x << " = " << x._1 << ' ' << x._2 << endl;
#define pb push_back
#define _1 first
#define _2 second
#define mod 1000000007
#define wait asfa

int k, n, wait[33], dp[100001][301];
string s, concert;

int main() {
  ios::sync_with_stdio(0);
  cin >> k >> n;

  REP (i, 26) cin >> wait[i];
  cin >> s >> concert;

  REP (i, n) {
    if (concert[i] == s[0]) dp[i][0] = 1;
    if (i) dp[i][0] += dp[i - 1][0];
  }

  FOR (j, 1, k - 1) FOR (i, 1, n - 1) {
    if (concert[i] == s[j]) {
      int tmp = i - 1 - wait[s[j - 1] - 'A'];
      if (tmp >= 0) dp[i][j] = dp[tmp][j - 1];
    }
    dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
  }
  cout << dp[n - 1][k - 1];
}