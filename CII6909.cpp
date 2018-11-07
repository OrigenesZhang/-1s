// 2014 Jakarta
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second

const int maxn = 512;
const int MOD = 1e9 + 7;

int T, n, k, p;
ll fac[maxn];

ll pow_mod(ll a, ll p) {
    ll ret = 1;
    while (p) {
        if (p & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        p >>= 1;
    }
    return ret;
}

ll inv(ll x) {
    return pow_mod(x, MOD - 2);
}

ll C(int n, int m) {
    if (m < 0 || m > n) return 0;
    return fac[n] * inv(fac[m]) % MOD * inv(fac[n - m]) % MOD;
}

int main() {
    scanf("%d", &T);
    fac[0] = 1;
    FOR(i, 1, maxn - 1) fac[i] = fac[i - 1] * i % MOD;
    FOR(cs, 1, T) {
        scanf("%d%d%d", &n, &k, &p);
        ll ans = 0;
        FOR(i, k + 1, n - 1) {
            ll now = (C(n - 1, i - k) - C(p - 1, i - k) + MOD) % MOD;
            now = now * fac[n - i + k - 1] % MOD;
            ans = (ans + now) % MOD;
        }
        ans = (ans + fac[n - 1] * inv(fac[n - k])) % MOD;
        printf("Case #%d: %lld\n", cs, ans);
    }
    return 0;
}
