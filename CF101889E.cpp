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

int n, rem[1100], dp[1100][1100];
string s;

int main() {
  cin >> s >> n;
  rem[0] = 1;
  FOR (i, 1, s.size())  rem[i] = (rem[i - 1] * 10) % n;
  reset(dp, -1);
  dp[0][0] = 0;

  FOR (i, 1, s.size()) REP (j, n) {
    char c = s[s.size() - i];
    if (c == '?') {
      REP (k, 10) {
        if (!k && i == s.size()) continue;
        int prem = (n + j - (k * rem[i - 1]) % n) % n;
        if (dp[i - 1][prem] != -1) {
          dp[i][j] = k;
          break;
        }
      }
    } else {
      int prem = (n + j - ((c - '0') * rem[i - 1]) % n) % n;
      if (dp[i - 1][prem] != -1) dp[i][j] = c - '0';
    }
    //cout << i << ' ' << j << ' ' << dp[i][j] << endl;
  }
  
  if (dp[s.size()][0] == -1) cout << '*';
  else {
    int cur = 0;
    FORD (i, s.size(), 1) {
      int digit = dp[i][cur];
      cout << digit;
      cur -= digit * rem[i - 1];
      cur %= n;
      cur += n;
      cur %= n;
    }
  }
}