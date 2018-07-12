#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define all(x) (x).begin(), (x).end()
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define mp make_pair
#define _1 first
#define _2 second

const int maxn = 212345;

int n, w[10], W, cs = 1, q;
ll dp[maxn], P;

int gcd(int a, int b) {
    return !b ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

bool check(ll cur, int w, ll P) {
    REP(i, n) {
        if (cur < i) break;
        if (!dp[i * W + w]) continue;
        ll now = P / dp[i * W + w];
        FOR(j, 1, n - 1) now *= j;
        FOR(j, 1, n - 1) now /= j + cur - i;
        if (!now) return true;
        now = dp[i * W + w];
        FOR(j, 1, n - 1) now *= j + cur - i;
        FOR(j, 1, n - 1) now /= j;
        P -= now;
    }
    return !P;
}

int main() {
    while (scanf("%d", &n) == 1) {
        if (!n) break;
        W = 1;
        REP(i, n) {
            scanf("%d", &w[i]);
            W = lcm(W, w[i]);
        }
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        REP(i, n) {
            if (w[i] == W) continue;
            REP(ww, w[i]) {
                int k = n * W - w[i] + ww, s = 0;
                for (int j = w[i]; j < W; j += w[i])
                    s += dp[k - j];
                dp[k] += s;
                for (int j = k - w[i]; j >= 0; j -= w[i]) {
                    s -= dp[j];
                    if (j + w[i] >= W) s += dp[j + w[i] - W];
                    dp[j] += s;
                }
            }
        }
        printf("Set %d\n", cs++);
        scanf("%d", &q);
        while (q--) {
            scanf("%lld", &P);
            ll ans = P * 100 + 1;
            REP(ww, W) {
                ll l = ww ? -1 : 0, r = (ans - ww) / W + 1;
                while (r - l > 1) {
                    ll m = l + (r - l >> 1);
                    if (check(m, ww, P)) r = m;
                    else l = m;
                }
                if (ans > r * W + ww) ans = r * W + ww;
            }
            if (ans > 100 * P) puts("no candy for you");
            else printf("%lld\n", ans);
        }
    }
    return 0;
}
