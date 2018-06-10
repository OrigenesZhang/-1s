// 三进制
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
const int maxm = 9;
const int maxn = 55;
const int maxmask = 1 << (2 * maxm);
const int inf = 0x3f3f3f3f;
int dp[2][maxmask][3], G[maxn][maxm];
int n, m, cs = 1, upp;
vector<int> path;

void update(int& s) {
    if ((s & 3) != 2) {
        s++;
        return;
    }
    FOR(d, 1, maxm + 1) {
        if (((s >> 2 * d) & 3) != 2) {
            s &= ~((1 << 2 * d) - 1);
            s += 1 << 2 * d;
            return;
        }
    }
}

void init() {
    int s = 0;
    while (s < maxmask) {
        path.pb(s);
        update(s);
    }
    path.pb(s);
}

inline int bit(int s, int b) {
    return (s >> 2 * b) & 3;
}

void upd(int& a, int b) {
    a = min(a, b);
}

inline int setv(int s, int b, int d) {
    s &= ~(3 << 2 * b);
    s |= (d << 2 * b);
    return s;
}

int main() {
    init();
    while (scanf("%d%d", &n, &m) == 2) {
        if (!n && !m) break;
        REP(i, n) REP(j, m) scanf("%d", &G[i][j]);
        memset(dp, 0x3f, sizeof(dp));
        upp = 1 << (2 * m);
        dp[0][0][0] = 0;
        int cur = 0;
        REP(row, n) {
            REP(col, m) {
                int p = cur;
                cur ^= 1;
                for (int _s = 0; path[_s] < upp; _s++)
                    memset(dp[cur][path[_s]], 0x3f, sizeof(dp[cur][path[_s]]));
                if (!G[row][col]) {
                    for (int _s = 0; path[_s] < upp; _s++) {
                        int s = path[_s];
                        if (bit(s, col)) continue;
                        upd(dp[cur][s][0], dp[p][s][0]);
                    }
                } else {
                    for (int _s = 0; path[_s] < upp; _s++) {
                        int s = path[_s], d = bit(s, col);
                        if (!d) {
                            if (row != n - 1) {
                                upd(dp[cur][setv(s, col, 1)][0], dp[p][s][0]);
                                upd(dp[cur][setv(s, col, 2)][0], dp[p][s][0]);
                            }
                            if (col != m - 1) {
                                upd(dp[cur][s][1], dp[p][s][0]);
                                if (col != 0 && G[row][col] > G[row][col - 1])
                                    upd(dp[cur][s][1], dp[p][s][1]);
                                upd(dp[cur][s][2], dp[p][s][0]);
                                if (col != 0 && G[row][col] < G[row][col - 1])
                                    upd(dp[cur][s][2], dp[p][s][2]);
                            }
                            upd(dp[cur][s][0], dp[p][s][0] + 1);
                            if (col != 0) {
                                if (G[row][col] > G[row][col - 1]) upd(dp[cur][s][0], dp[p][s][1] + 1);
                                if (G[row][col] < G[row][col - 1]) upd(dp[cur][s][0], dp[p][s][2] + 1);
                            }
                        } else if (d == 1) {
                            if (row && G[row][col] > G[row - 1][col]) {
                                upd(dp[cur][setv(s, col, 0)][0], dp[p][s][0] + 1);
                                if (row != n - 1) upd(dp[cur][s][0], dp[p][s][0]);
                            }
                        } else {
                            if (row && G[row][col] < G[row - 1][col]) {
                                upd(dp[cur][setv(s, col, 0)][0], dp[p][s][0] + 1);
                                if (row != n - 1) upd(dp[cur][s][0], dp[p][s][0]);
                            }
                        }
                    }
                }
            }
        }
        printf("Case %d: %d\n", cs++, dp[cur][0][0]);
    }
    return 0;
}
