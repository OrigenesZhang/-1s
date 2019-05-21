#include <bits/stdc++.h>

using namespace std;

const long long inf = 0x3f3f3f3f3f3f3f3f;

long long dp[2][10][10][2][2], ans = inf;
int n, K, w[251234];

inline void upd(long long &a, long long b) {
    a = min(a, b);
}

int main() {
    scanf("%d%d", &n, &K);
    for (int i = 1; i <= n; i++) scanf("%d", w + i);
    memset(dp[0], 0x3f, sizeof(dp[0]));
    dp[0][0][0][0][1] = 0;
    for (int i = 1; i <= n; i++) {
        int now = i & 1, pre = 1 - now;
        memset(dp[now], 0x3f, sizeof(dp[now]));
        for (int j = 0; j <= K; j++) for (int k = 0; k <= K; k++)
            for (int u = 0; u <= 1; u++) for (int v = 0; v <= 1; v++) {
                upd(dp[now][j][k][1][u], dp[pre][j][k][u][v] + w[i]);
                if (u || v) upd(dp[now][j][k][0][u], dp[pre][j][k][u][v]);
                if (j < K && (u || v)) upd(dp[now][j + 1][k][0][u], dp[pre][j][k][u][v] + w[i]);
                if (k < K) upd(dp[now][j][k + 1][1][u], dp[pre][j][k][u][v]);
            }
    }
    for (int i = 0; i <= K; i++) for (int j = 0; j <= 1; j++) for (int k = 0; k <= 1; k++) if (j || k)
        upd(ans, dp[n & 1][i][i][j][k]);
    printf("%lld", ans);
}