#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define ROF(i, a, b) for (int i = (a); i >= (b); i--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x)*(x))
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end())
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)
 
const int MOD = 1e9 + 7;
const int maxn = 55;
 
inline int add(int a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
    return a;
}
 
inline int mul(int a, int b) {
    return ll(a) * b % MOD;
}
 
int a[maxn], pw7[maxn], pw28[maxn];
 
void solve() {
    ll n;
    scanf("%lld", &n);
    ll tmp = n;
    reset(a, 0);
    while (tmp) {
        a[++a[0]] = tmp % 7;
        tmp /= 7;
    }
    int ans = 0, b = 0, c = 1;
    ROF(i, a[0], 1) {
        REP(j, a[i]) {
            ans = add(ans, mul(mul(add(mul(b, 7), j), pw7[i - 1]), pw7[i - 1]));
            ans = add(ans, mul(mul(pw7[i - 1], pw7[i - 1] + 1), (MOD + 1) / 2));
            ans = add(ans, MOD - mul(mul(c, j + 1), pw28[i - 1]));
        }
        b = add(mul(b, 7), a[i]);
        c = mul(c, a[i] + 1);
    }
    int cnt = 1;
    FOR(i, 1, a[0]) cnt = mul(cnt, a[i] + 1);
    printf("%d\n", add(add(add(ans, n % MOD), 1), MOD - cnt));
}
 
int main() {
    int T;
    scanf("%d", &T);
    pw7[0] = pw28[0] = 1;
    FOR(i, 1, maxn - 1) {
        pw7[i] = mul(pw7[i - 1], 7);
        pw28[i] = mul(pw28[i - 1], 28);
    }
    FOR(cs, 1, T) {
        printf("Case %d: ", cs);
        solve();
    }
}