#include <bits/stdc++.h>
using namespace std;

const long long maxn = 5123;

long long n, MOD;
long long pw[maxn], f[maxn], g[maxn], C[maxn][maxn];

signed main() {
    cin >> n >> MOD;
    pw[0] = 1;
    for (long long i = 1; i <= n; i++) pw[i] = pw[i - 1] * 4 % MOD;
    long long ans = pw[n] * (n + 1) % MOD;
    C[0][0] = 1;
    for (long long i = 1; i <= n; i++) {
        C[i][0] = 1;
        for (long long j = 1; j <= i; j++) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
    }
    for (long long i = 2; i <= n; i += 2) {
        for (long long j = 0; j <= i; j += 2) {
            long long now = C[j][j / 2] * C[i - j][i - j >> 1] % MOD * C[i][j] % MOD;
            f[i] = (f[i] + now) % MOD;
        }
        g[i] = f[i];
        for (long long j = 0; j < i; j += 2) {
            g[i] = (g[i] - f[i - j] * g[j]) % MOD;
            if (g[i] < 0) g[i] += MOD;
        }
    }
    for (long long i = 2; i <= n; i += 2) {
        ans = ans - pw[n - i] * (n - i + 1) % MOD * g[i] % MOD;
        if (ans < 0) ans += MOD;
    }
    cout << ans;
}