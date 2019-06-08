#include <bits/stdc++.h>

using namespace std;

int N;
int ducks[5123];
int dp[5123][5123];

int main() {
  while (cin >> N) {
    for (int num = 1; num <= N; ++num) {
      cin >> ducks[num];
    }

    for (int i = 1; i < N; i++) dp[i][i + 1] = ducks[i] == ducks[i + 1];
    for (int dis = 2; dis < N; dis++) for (int i = 1; i + dis <= N; i++) {
      int j = i + dis;
      if (ducks[i] == ducks[j]) dp[i][j] = dp[i + 1][j - 1] + 1;
      else dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
    }

    cout << dp[1][N] << '\n';
  }

  return 0;
}