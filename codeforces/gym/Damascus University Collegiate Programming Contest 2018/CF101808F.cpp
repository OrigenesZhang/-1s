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

const int maxa = 1234;
const int MOD = 7901;

int fac[maxa], cnt[maxa], n, a, T;

int main() {
    fac[0] = 1;
    FOR(i, 1, 1000) fac[i] = fac[i - 1] * i % MOD;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        reset(cnt, 0);
        FOR(i, 1, n) {
            scanf("%d", &a);
            cnt[a]++;
        }
        int ans = 1;
        FOR(i, 1, 1000) if (cnt[i] > 1) ans = ans * fac[cnt[i]] % MOD;
        printf("%d\n", ans);
    }
    return 0;
}
