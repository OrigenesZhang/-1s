#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define mp make_pair
#define _1 first
#define _2 second

const int MOD = int(1e9) + 7;

LL n, m, c;

LL qpow(LL pw, LL base) {
    if (pw == 0) return 1;
    LL cur = qpow(pw / 2, base);
    cur = cur * cur % MOD;
    if (pw % 2 == 1) cur = cur * base % MOD;
    return cur;
}

LL gcd(LL a, LL b) { return !b ? a : gcd(b, a % b); }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> c;
    LL ans = 0;
    for (int i = 0; i < m; i++) {
        LL pw = (LL)n * n * gcd(i, m);
        ans = (ans + qpow(pw, c)) % MOD;
    }
    ans = ans * qpow(MOD - 2, m) % MOD;
    cout << ans << '\n';
    return 0;
}