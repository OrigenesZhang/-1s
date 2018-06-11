// 矩阵构图的写法有提升空间
// 对于带障碍物的列转移用这种暴力法可能还不如插头dp
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
const ll MOD = 10000007;
const int maxr = 4;
typedef vector<vector<ll>> Matrix;
int R, C, N, cs = 1, mask;
ll dp[2][1 << maxr];

Matrix mul(const Matrix &a, const Matrix &b) {
    unsigned n = a.size();
    Matrix c(n);
    REP(i, n) {
        c[i].resize(n);
        fill(all(c[i]), 0);
    }
    REP(i, n) REP(j, n) REP(k, n) c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD;
    return c;
}

Matrix pow(Matrix a, int n) {
    unsigned m = a.size();
    Matrix ret(m);
    REP(i, m) {
        ret[i].resize(m);
        fill(all(ret[i]), 0);
        ret[i][i] = 1;
    }
    while (n) {
        if (n & 1) ret = mul(ret, a);
        a = mul(a, a);
        n >>= 1;
    }
    return ret;
}

void build(Matrix &G, int state) {
    REP(i, mask) {
        G[i].resize(mask);
        fill(all(G[i]), 0);
    }
    REP(m1, mask) {
        if (state & m1) continue;
        REP(m2, mask) {
            if (state & m2) continue;
            bool flag = false;
            REP(row, R) {
                if (m1 & (1 << row)) {
                    if (m2 & (1 << row)) goto skip;
                } else {
                    if (m2 & (1 << row)) continue;
                    if (state & (1 << row)) {
                        if (flag) goto skip;
                        continue;
                    }
                    if (row == R - 1 && !flag) goto skip;
                    if (flag) {
                        flag = false;
                        continue;
                    }
                    if ((m1 | m2) & (1 << row + 1)) goto skip;
                    if (state & (3 << row)) goto skip;
                    flag = true;
                }
            }
            G[m1][m2] = 1;
            skip:;
        }
    }
}

int main() {
    while (scanf("%d%d%d", &R, &C, &N) == 3) {
        if (!R && !C) break;
        map<int, vector<int>> pts;
        REP(i, N) {
            int r, c;
            scanf("%d%d", &c, &r);
            if (pts.find(r) != pts.end()) pts[r].pb(c);
            else pts[r] = {c};
        }
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        mask = 1 << R;
        Matrix G(mask);
        build(G, 0);
        int cur = 0;
        for (const auto &it : pts) {
            Matrix now = pow(G, it.first - cur);
            memset(dp[1], 0, sizeof(dp[1]));
            REP(s, mask) REP(tmp, mask) dp[1][s] = (dp[1][s] + now[s][tmp] * dp[0][tmp]) % MOD;
            int state = 0;
            for (auto p : it.second) state |= (1 << p);
            Matrix g(mask);
            build(g, state);
            memset(dp[0], 0, sizeof(dp[0]));
            REP(s, mask) REP(tmp, mask) dp[0][s] = (dp[0][s] + g[s][tmp] * dp[1][tmp]) % MOD;
            cur = it.first + 1;
        }
        if (cur < C) {
            Matrix now = pow(G, C - cur);
            memset(dp[1], 0, sizeof(dp[1]));
            REP(s, mask) REP(tmp, mask) dp[1][s] = (dp[1][s] + now[s][tmp] * dp[0][tmp]) % MOD;
        } else dp[1][0] = dp[0][0];
        printf("Case %d: %lld\n", cs++, dp[1][0]);
    }
    return 0;
}
