#include <bits/stdc++.h>
using namespace std;

const int maxn = 2123;
const int MOD = 1e9 + 7;

int n;
int fac[maxn * 2], ifac[maxn * 2], s[maxn], t[maxn], dp[maxn][maxn], C[maxn];

inline int add(int a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
    return a;
}

inline int mul(int a, int b) {
    return (long long) a * b % MOD;
}

int inv(int a) {
    int pw = MOD - 2, ret = 1;
    while (pw) {
        if (pw & 1) ret = mul(ret, a);
        a = mul(a, a);
        pw >>= 1;
    }
    return ret;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", s + i);
    for (int i = 1; i <= n; i++) scanf("%d", t + i);
    fac[0] = ifac[0] = 1;
    for (int i = 1; i <= 2 * n; i++) fac[i] = mul(fac[i - 1], i);
    for (int i = 1; i <= 2 * n; i++) ifac[i] = inv(fac[i]);
    for (int i = 0; i <= n; i++) C[i] = mul(mul(fac[2 * i], ifac[i]), ifac[i + 1]);
    dp[0][0] = 1;
    for (int i = 0; i <= n; i++) for (int j = 0; j <= n; j++) {
        if (i == 0 && j == 0) continue;
        if (i) dp[i][j] = add(dp[i][j], dp[i - 1][j]);
        if (j) dp[i][j] = add(dp[i][j], dp[i][j - 1]);
        for (int k = 1; k <= min(i, j) && s[i - k + 1] == t[j - k + 1]; k++)
            dp[i][j] = add(dp[i][j], MOD - mul(C[k - 1], dp[i - k][j - k]));
    }
    printf("%d", dp[n][n]);
}