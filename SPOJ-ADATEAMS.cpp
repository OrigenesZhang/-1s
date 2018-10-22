#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second

const int maxn = 1e6;
const ll MOD = 1e9 + 7;

ll fac[maxn + 123];

ll pow_mod(ll a, ll k) {
    ll ret = 1;
    while (k) {
        if (k & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        k >>= 1;
    }
    return ret;
}

ll inv(ll a) {
    return pow_mod(a, MOD - 2);
}

ll C(ll n, ll m) {
    return fac[n] * inv(fac[m]) % MOD * inv(fac[n - m]) % MOD;
}

ll n, a, b, d;

int main() {
    fac[0] = 1;
    FOR(i, 1, maxn) fac[i] = fac[i - 1] * i % MOD;
    while (scanf("%lld%lld%lld%lld", &n, &a, &b, &d) == 4)
        printf("%lld\n", pow_mod(C(b, d), a) * C(n, a) % MOD);
    return 0;
}
