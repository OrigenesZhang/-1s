// Jakarta 2014
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

const int maxn = 8;
const int MOD = 1e9 + 7;

ll dp[2][maxn * maxn + 1][1 << maxn], C[maxn * maxn + 1][maxn * maxn + 1];
int T, n, m, K;

inline void upd(ll &a, ll b) {
    (a += b) >= MOD ? a -= MOD : 1;
}

int main() {
    scanf("%d", &T);
    REP(i, maxn * maxn + 1) {
        C[i][0] = 1;
        FOR(j, 1, i) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
    }
    FOR(cs, 1, T) {
        reset(dp[0], 0);
        scanf("%d%d%d", &n, &m, &K);
        int now = 0, nxt = 1;
        dp[now][0][1] = 1;
        REP(i, n) REP(j, m) {
                reset(dp[nxt], 0);
                REP(k, K + 1) REP(mask, 1 << m) {
                        if (!dp[now][k][mask]) continue;
                        if (k < K) {
                            int diff = mask & (1 << j);
                            upd(dp[nxt][k + 1][mask - diff], dp[now][k][mask]);
                        }
                        if ((mask >> j & 1) || (j && ((mask >> j - 1) & 1)))
                            upd(dp[nxt][k][mask | (1 << j)], dp[now][k][mask]);
                        else upd(dp[nxt][k][mask], dp[now][k][mask]);
                    }
                swap(now, nxt);
            }
        ll ans = 0;
        REP(i, K + 1) upd(ans, C[n * m][i]);
        REP(i, K + 1) REP(mask, 1 << m) if ((mask >> m - 1) & 1) upd(ans, MOD - dp[now][i][mask]);
        printf("Case #%d: %lld\n", cs, ans);
    }
    return 0;
}
