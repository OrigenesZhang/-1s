// 这个题真的恶心
// 三进制但是用四进制表示
// 然而空状态必须跳过
// 现在这种写法的复杂度是O(n*m^2*3^(m+1))
// 可以继续优化为O(n*m*3^(m+1)) [打表记录下一个合法状态]

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
const int maxn = 22;
const int inf = 0x3f3f3f3f;
int dp[2][1 << maxn], n, m, mask;
int G[maxn][maxn];

inline int LSB(int s) {
    return s & 3;
}

inline int MSB(int s) {
    return s >> 2 * m;
}

inline int shift(int s) {
    return (s & (~(3 << 2 * m))) >> 2;
}

inline void upd(int &a, int b) {
    a = min(a, b);
}

void update(int &s) {
    if ((s & 3) != 2) {
        s++;
        return;
    }
    FOR(d, 1, m + 2) if (((s >> 2 * d) & 3) != 2) {
            s &= ~((1 << 2 * d) - 1);
            s += 1 << 2 * d;
            return;
        }
}

int main() {
    while (scanf("%d%d", &n, &m) == 2) {
        if (!n && !m) break;
        REP(i, n) REP(j, m) scanf("%d", &G[i][j]);
        memset(dp, 0x3f, sizeof(dp));
        int cur = 0;
        dp[0][0] = 0;
        mask = 1 << 2 * (m + 1);
        REP(row, n) REP(col, m) {
                int p = cur, s = 0;
                cur ^= 1;
                while (s < mask) {
                    dp[cur][s] = inf;
                    update(s);
                }
                s = 0;
                if (G[row][col] == 1) {
                    while (s < mask) {
                        if (!LSB(s) && !MSB(s))
                            upd(dp[cur][shift(s)], dp[p][s]);
                        update(s);
                    }
                } else if (G[row][col] >= 2) {
                    int c = G[row][col] - 1;
                    while (s < mask) {
                        if (MSB(s) == c && !LSB(s)) upd(dp[cur][shift(s)], dp[p][s] + 1);
                        else if (LSB(s) == c && !MSB(s)) upd(dp[cur][shift(s)], dp[p][s] + 1);
                        else if (!LSB(s) && !MSB(s)) {
                            if (col != m - 1) upd(dp[cur][shift(s) | (c << 2 * m)], dp[p][s] + 1);
                            if (row != n - 1) upd(dp[cur][shift(s) | (c << 2 * (m - 1))], dp[p][s] + 1);
                        }
                        update(s);
                    }
                } else {
                    while (s < mask) {
                        int c1 = MSB(s), c2 = LSB(s);
                        if (c1) {
                            if (c2) {
                                if (c1 != c2) {
                                    update(s);
                                    continue;
                                }
                                upd(dp[cur][shift(s)], dp[p][s] + 2);
                            } else {
                                if (row != n - 1) upd(dp[cur][shift(s) | (c1 << 2 * (m - 1))], dp[p][s] + 2);
                                if (col != m - 1) upd(dp[cur][shift(s) | (c1 << 2 * m)], dp[p][s] + 2);
                            }
                        } else {
                            if (c2) {
                                if (col != m - 1) upd(dp[cur][shift(s) | (c2 << 2 * m)], dp[p][s] + 2);
                                if (row != n - 1) upd(dp[cur][shift(s) | (c2 << 2 * (m - 1))], dp[p][s] + 2);
                            } else {
                                upd(dp[cur][shift(s)], dp[p][s]);
                                if (row != n - 1 && col != m - 1) {
                                    upd(dp[cur][shift(s) | (5 << 2 * (m - 1))], dp[p][s] + 2);
                                    upd(dp[cur][shift(s) | (10 << 2 * (m - 1))], dp[p][s] + 2);
                                }
                            }
                        }
                        update(s);
                    }
                }
            }
        if (dp[cur][0] == inf) puts("0");
        else printf("%d\n", dp[cur][0] / 2);
    }
    return 0;
}
