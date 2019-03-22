// 读入恶心
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
const int maxc = 8;
const int maxr = 213;
using vec = char[maxc];
bool G[2][maxr][maxc];
char buff[maxr];
int MOD, T, R, C;

struct State {
    vec cc, cnt_cc;
    char n;

    void init() {
        vec tmp;
        memset(tmp, -1, sizeof(tmp));
        n = 0;
        REP(i, C) {
            if (tmp[cc[i]] < 0) {
                tmp[cc[i]] = n++;
            }
            cc[i] = tmp[cc[i]];
        }
        memset(cnt_cc, 0, sizeof(cnt_cc));
        REP(i, C) cnt_cc[cc[i]]++;
    }

    bool merge(char a, char b) {
        if (a == b) return false;
        REP(i, C) if (cc[i] == b) cc[i] = a;
        return true;
    }

    unsigned hash() {
        unsigned val = 0;
        REP(i, C) val = val * 8 + cc[i];
        return val;
    }
};

map<unsigned, int> dp[maxr][maxc];

void update(int &a, int b) {
    if (b == -1) return;
    if (a == -1) a = 0;
    a = (a + b) % MOD;
}

void read() {
    scanf("%d %d %d\n", &R, &C, &MOD);
    memset(G, false, sizeof(G));
    REP(r, 2 * R - 1) {
        fgets(buff, maxr - 5, stdin);
        REP(c, 2 * C - 1) {
            int cur = buff[c];
            if (r & 1) {
                if ((c ^ 1) & 1) {
                    if (cur == '|') G[0][r + 1 >> 1][c >> 1] = true;
                }
            } else {
                if (c & 1) {
                    if (cur == '-') G[1][r >> 1][c + 1 >> 1] = true;
                }
            }
        }
    }
    REP(r, R) REP(c, C) dp[r][c].clear();
}

int dfs(int row, int col, State &s) {
    if (col == C) {
        row++;
        col = 0;
    }
    s.init();
    if (row == R) {
        if (s.n != 1) return -1;
        return 1;
    }
    unsigned h_code = s.hash();
    if (dp[row][col].find(h_code) != dp[row][col].end())
        return dp[row][col][h_code];
    int ans = -1;
    if (G[0][row][col]) {
        State t = s;
        if (col && t.cc[col] != t.cc[col - 1]) {
            t.merge(t.cc[col], t.cc[col - 1]);
            update(ans, dfs(row, col + 1, t));
        }
        if (!G[1][row][col]) {
            t = s;
            update(ans, dfs(row, col + 1, t));
        }
    } else if (G[1][row][col]) {
        State t = s;
        t.cc[col] = t.cc[col - 1];
        if (t.cc[col] != s.cc[col]) {
            t.merge(s.cc[col], t.cc[col]);
            update(ans, dfs(row, col + 1, t));
        }
        if (s.cnt_cc[s.cc[col]] > 1) {
            t = s;
            t.cc[col] = t.cc[col - 1];
            update(ans, dfs(row, col + 1, t));
        }
    } else {
        State t = s;
        t.cc[col] = t.n;
        if (s.cnt_cc[s.cc[col]] > 1) {
            update(ans, dfs(row, col + 1, t));
            if (col) {
                t.merge(t.cc[col - 1], t.cc[col]);
                update(ans, dfs(row, col + 1, t));
            }
        }
        t = s;
        update(ans, dfs(row, col + 1, t));
        if (col && t.cc[col] != t.cc[col - 1]) {
            t.merge(t.cc[col - 1], t.cc[col]);
            update(ans, dfs(row, col + 1, t));
        }
    }
    return dp[row][col][h_code] = ans;
}

int solve() {
    REP(i, C) G[0][0][i] = true;
    State s;
    REP(i, C) s.cc[i] = i;
    s.init();
    return dfs(0, 0, s);
}

int main() {
    scanf("%d", &T);
    while (T--) {
        read();
        int ans = solve();
        if (ans < 0) puts("Impossible");
        else printf("%d\n", ans);
    }
    return 0;
}
