#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;

const int N = 1000 + 10;
const int MOD = int(1e9) + 7;
typedef long long LL;

int n, m;
LL dp[N][N][2];
string a;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> a;
    reverse(a.begin(), a.end());
    a.push_back('0');
    if (a[0] == '0') dp[0][0][0] = dp[0][1][0] = 1;
    else dp[0][1][0] = dp[0][0][1] = 1;

    for (int i = 1; i < n; i++)
        for (int j = 0; j <= m; j++) {
            if (a[i] == '0') {
                dp[i][j][0] += dp[i - 1][j][0];
                if (j) dp[i][j][0] += dp[i - 1][j - 1][1] + dp[i - 1][j - 1][0];
                dp[i][j][1] += dp[i - 1][j][1];
            } else {
                if (j) dp[i][j][0] += dp[i - 1][j - 1][0];
                dp[i][j][1] += dp[i - 1][j][0] + dp[i - 1][j][1];
                if (j) dp[i][j][1] += dp[i - 1][j - 1][1];
            }
            dp[i][j][0] %= MOD;
            dp[i][j][1] %= MOD;
        }
    LL ans = dp[n - 1][m][0];
    if (m) ans = (ans + dp[n - 1][m - 1][1]) % MOD;
    cout << ans << '\n';
    return 0;
}