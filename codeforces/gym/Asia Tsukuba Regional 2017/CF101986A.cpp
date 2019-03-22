#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(int)(a)-1)
#define pb push_back
#define _1 first
#define _2 second

long long l, k, ans, dp[111];

int main() {
  cin >> l >> k;
  FOR (i, 1, l) {
    if (i == 1 || i == k) dp[i] = 1;
    if (i > 2) dp[i] += dp[i - 2];
    if (i > 1 + k) dp[i] += dp[i - 1 - k];
    ans += dp[i];
  }
  cout << ans;
}