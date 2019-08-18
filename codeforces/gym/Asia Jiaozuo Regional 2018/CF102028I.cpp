#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REP(i, n) FOR(i, 0, (n) - 1)
typedef long long ll;
using namespace std;
 
const int maxn = 112345;
 
ll a[maxn];
int n;
 
void solve() {
    scanf("%d", &n);
    FOR(i, 1, n - 1) scanf("%lld", a + i);
    FOR(i, 1, n - 1) a[i] = a[i - 1] + a[i];
    int l = 0, r = 0;
    ll ans = 0, L = 0, R = 0;
    REP(k, n) {
        if (l == r) {
            ans += R - r * a[l];
            ans += l * a[l] - L;
            L += a[l];
            l++;
        } else {
            ans += R - r * a[n - 1 - r];
            ans += l * a[n - 1 - r] - L;
            R += a[n - 1 - r];
            r++;
        }
        printf("%lld%c", ans, k == n - 1 ? '\n' : ' ');
    }
}
 
int main() {
    int T;
    scanf("%d", &T);
    while (T--) solve();
}