#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define all(x) (x).begin(), (x).end()
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cout << #x << " = " << (x) << endl
#define pb push_back
#define mp make_pair
#define _1 first
#define _2 second
const int maxs = 1234;
ll dp[2][maxs];
int n, m, mask;

int main() {
    while (scanf("%d%d", &n, &m) == 2) {
        if (n > m) swap(n, m);
        mask = 1 << n;
        memset(dp, 0, sizeof(dp));
        int cur = 0;
        dp[0][mask - 1] = 1;
        REP(row, m) REP(col, n) {
                int p = cur;
                cur ^= 1;
                memset(dp[cur], 0, sizeof(dp[cur]));
                REP(s, mask) {
                    if (s & 1) dp[cur][s >> 1] += dp[p][s];
                    if (row && !(s & 1)) dp[cur][(s >> 1) | (1 << n - 1)] += dp[p][s];
                    if (col && (s & 1) && !(s & (1 << n - 1))) dp[cur][(s >> 1) | (3 << n - 2)] += dp[p][s];
                }
            }
        printf("%lld\n", dp[cur][mask - 1]);
    }
    return 0;
}
