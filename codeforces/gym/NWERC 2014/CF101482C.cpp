#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(int)(a)-1)
#define BUG(x) cout << #x << " = " << x << endl
#define pb push_back

int n, lis[2222], k, dp[2222][22], pre[2222];

int f(int x) {
  if (x % 10 < 5) return (x / 10) * 10;
  else return (x / 10 + 1) * 10;
}

int main() {
  cin >> n >> k; k++;
  FOR (i, 1, n) cin >> lis[i], pre[i] = pre[i - 1] + lis[i];

  FOR (i, 1, n) {
    dp[i][1] = f(pre[i]);
    FOR (j, 2, k) {
      dp[i][j] = dp[i][j - 1];
      FOR (ii, 1, i - 1) dp[i][j] = min(dp[i][j], dp[ii][j - 1] + f(pre[i] - pre[ii]));
    }
  }

  cout << dp[n][k];
}