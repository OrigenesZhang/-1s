// 真的难
// 用map维护状态的散列值
// 维护连通分量以及连通分量个数
// 特判消去连通分量的可行情况
// 一开始用vector<char>记的状态结果是Segmentation Trap
// std::__bad_alloc() orz

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
const int maxn = 8;
using vec = char[maxn];
const char enc[] = {'o', '#'};
char G[maxn][maxn], ans[maxn][maxn], now[maxn][maxn];
int n, m, T;
bool sol;

struct State {
    vec colour, cc;
    bool p;
    char cnt_cc, cnt_blk[2];

    void init() {
        vec cur;
        memset(cur, -1, sizeof(cur));
        cnt_cc = cnt_blk[0] = cnt_blk[1] = 0;
        REP(i, n) {
            if (cur[cc[i]] < 0) {
                cur[cc[i]] = cnt_cc++;
                cnt_blk[colour[i]]++;
            }
            cc[i] = cur[cc[i]];
        }
    }

    void merge(char a, char b) {
        if (a == b) return;
        REP(i, n) if (cc[i] == b) cc[i] = a;
    }

    unsigned hash() {
        unsigned val = 0;
        REP(i, n) val = val * 16 + colour[i] * 8 + cc[i];
        return val;
    }
};

map<unsigned, int> dp[maxn][maxn][2];

int dfs(int row, int col, State &s, int c) {
    if (col == n) {
        col = 0;
        row++;
    }
    s.init();
    if (row == m) {
        if (s.cnt_blk[0] > 1 || s.cnt_blk[1] > 1) return 0;
        if (!sol) {
            sol = true;
            REP(r, m) REP(c, n) ans[r][c] = now[r][c];
        }
        return 1;
    }
    if (row && col && s.colour[col] != s.colour[col - 1]) s.p = false;
    if (c < 0) {
        unsigned h_code = s.hash();
        if (dp[row][col][s.p].find(h_code) != dp[row][col][s.p].end())
            return dp[row][col][s.p][h_code];
    }
    int ret = 0;
    REP(clr, 2) {
        if ((c ^ 1) == clr) continue;
        if (G[row][col] == enc[clr ^ 1]) continue;
        if (row && col && s.colour[col - 1] == clr && s.colour[col] == clr && s.p == clr) continue;
        State curs = s;
        curs.p = s.colour[col];
        curs.colour[col] = char(clr);
        curs.cc[col] = (row && s.colour[col] == clr) ? s.cc[col] : s.cnt_cc;
        if (col && curs.colour[col - 1] == clr) curs.merge(curs.cc[col - 1], curs.cc[col]);
        now[row][col] = enc[clr];
        if (row && s.colour[col] == (clr ^ 1)) {
            if (find(curs.cc, curs.cc + n, s.cc[col]) == curs.cc + n) {
                if (s.cnt_blk[1 ^ clr] > 1 || row < m - 2) continue;
                ret += dfs(row, col + 1, curs, clr);
                continue;
            }
        }
        ret += dfs(row, col + 1, curs, c);
    }
    if (c < 0) {
        unsigned h_code = s.hash();
        dp[row][col][s.p][h_code] = ret;
    }
    return ret;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &m, &n);
        REP(r, m) scanf("%s", G[r]);
        State s;
        memset(&s, 0, sizeof(s));
        s.init();
        REP(i, maxn) REP(j, maxn) REP(k, 2) dp[i][j][k].clear();
        sol = false;
        printf("%d\n", dfs(0, 0, s, -1));
        if (sol) {
            REP(r, m) {
                REP(c, n) printf("%c", ans[r][c]);
                puts("");
            }
        }
        puts("");
    }
    return 0;
}
