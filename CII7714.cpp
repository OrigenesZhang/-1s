// Jakarta 2016
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

const int maxn = 1123456;
const int MOD = 1e9 + 7;

ll fac[maxn], ifac[maxn];
int T, n, m;

ll pow_mod(ll a, ll k) {
    ll ret = 1;
    while (k) {
        if (k & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        k >>= 1;
    }
    return ret;
}

ll inv(ll x) {
    return pow_mod(x, MOD - 2);
}

inline ll C(int m, int n) {
    if (n < 0 || n > m) return 0;
    return fac[m] * ifac[n] % MOD * ifac[m - n] % MOD;
}

int main() {
    fac[0] = ifac[0] = 1;
    FOR(i, 1, 1000000) fac[i] = fac[i - 1] * i % MOD, ifac[i] = inv(fac[i]);
    scanf("%d", &T);
    FOR(cs, 1, T) {
        scanf("%d%d", &n, &m);
        printf("Case #%d: %lld\n", cs, C(m - 1, n - 1));
        int c, v;
        REP(i, n) {
            scanf("%d", &c);
            REP(j, c) scanf("%d", &v);
        }
    }
    return 0;
}
