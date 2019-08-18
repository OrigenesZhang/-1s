#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REP(i, n) FOR(i, 0, (n) - 1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;
typedef pair<int, int> pii;
 
const int maxn = 112345;
 
ll tot[maxn];
 
void solve() {
    string sa, sb;
    ll hpa, hpb, atka, atkb;
    scanf("%lld%lld%lld%lld", &hpa, &hpb, &atka, &atkb);
    int last = lower_bound(tot, tot + int(1e5) + 10, hpa + hpb) - tot;
    int brk = lower_bound(tot, tot + int(1e5) + 10, hpa) - tot;
    ll ansa = last * atkb + brk * atka, lo;
    if (tot[last] - tot[brk] >= hpb)
        REP(i, brk) sa += 'A';
    else {
        lo = tot[brk] - hpa;
        FOR(i, 1, brk) sa += i == lo ? 'B' : 'A';
    }
    FOR(i, brk + 1, last) sa += 'B';
    brk = lower_bound(tot, tot + int(1e5) + 10, hpb) - tot;
    ll ansb = atkb * brk + atka * last;
    lo = tot[brk] - hpb;
    ll hi = upper_bound(tot, tot + int(1e5) + 10, lo) - tot - 1;
    if (tot[last] - tot[brk] + tot[hi] >= hpa) {
        FOR(i, 1, hi) sb += 'A';
        FOR(i, hi + 1, brk) sb += 'B';
    } else {
        ll L = hpa - tot[last] + tot[brk];
        FOR(i, 1, brk) {
            if (L - i > i || L == i) sb += 'A', L -= i;
            else sb += 'B';
        }
    }
    FOR(i, brk + 1, last) sb += 'A';
    if (ansa < ansb) {
        printf("%lld ", ansa);
        cout << sa << '\n';
    } else if (ansb < ansa) {
        printf("%lld ", ansb);
        cout << sb << '\n';
    } else if (sa < sb) {
        printf("%lld ", ansa);
        cout << sa << '\n';
    } else {
        printf("%lld ", ansb);
        cout << sb << '\n';
    }
}
 
int main() {
    FOR(i, 1, 1e5 + 10) tot[i] = tot[i - 1] + i;
    int T;
    scanf("%d", &T);
    while (T--) solve();
}