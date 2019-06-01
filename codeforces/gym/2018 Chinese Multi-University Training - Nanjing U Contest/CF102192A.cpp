#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int maxn = 112345;
const int MOD = 998244353;

int fac[maxn * 2], ifac[maxn * 2];

inline int mul(int a, int b) {
    return ll(a) * b % MOD;
}

inline int add(int a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
    return a;
}

int C(int n, int m) {
    if (m > n || m < 0) return 0;
    return mul(mul(fac[n], ifac[m]), ifac[n - m]);
}

int pow_mod(int a, int pw) {
    int ret = 1;
    while (pw) {
        if (pw & 1) ret = mul(ret, a);
        a = mul(a, a);
        pw >>= 1;
    }
    return ret;
}

int T, n, m, k;

int main() {
    fac[0] = 1;
    for (int i = 1; i <= 200000; i++) fac[i] = mul(fac[i - 1], i);
    ifac[0] = 1;
    for (int i = 1; i <= 200000; i++) ifac[i] = pow_mod(fac[i], MOD - 2);
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &n, &m, &k);
        if (ll(n - 1) * m < k) {
            puts("0");
            continue;
        }
        int ans = 0;
        for (int i = 0; i <= k / n; i++) {
            int now = mul(C(m, i), C(m + k - n * i - 1, m - 1));
            if (i & 1) ans = add(ans, MOD - now);
            else ans = add(ans, now);
        }
        printf("%d\n", ans);
    }
}