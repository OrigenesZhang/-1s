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
#define mp make_pair
#define _1 first
#define _2 second

const int maxn = 18;
const int maxs = 1 << maxn;

pii dp[maxs][maxn], pre[maxs][maxn];
bool inq[maxs][maxn];
int len[maxn], ALL, match[maxn][maxn];
char ans[maxn + 5][maxn + 5];
string s[maxn];

int h, w, n;

queue<pii> q;

void init() {
    reset(dp, 0x3f);
    reset(ans, 'A');
//    find duplicates
    bool vis[maxn] = {false};
    REP(i, n) REP(j, n) {
            if (s[i].length() > s[j].length() && !vis[j]) {
                REP(k, s[i].length() - s[j].length() + 1) {
                    if (s[i].substr(k, s[j].length()) == s[j]) {
                        vis[j] = true;
                        break;
                    }
                }
            }
        }
    int m = 0;
    REP(i, n) if (!vis[i]) s[m++] = s[i];
    n = m;
    REP(i, n) len[i] = s[i].length();
//    match(i, j) = k <=> s[i][-k :] = s[j][: k]
    REP(i, n) REP(j, n) {
            if (i == j) continue;
            int llen = min(len[i], len[j]);
            ROF(k, llen, 1) if (s[i].substr(len[i] - k, k) == s[j].substr(0, k)) {
                    match[i][j] = k;
                    break;
                }
        }
//    BUG(n);
    ALL = (1 << n) - 1;
    REP(i, n) {
        dp[1 << i][i] = {1, len[i]};
        q.push({1 << i, i});
        inq[1 << i][i] = true;
    }
}

void update(int mask, int last, int row, int col, int s, int pv) {
    assert(col <= w);
    if (dp[mask][last] > mp(row, col)) {
        dp[mask][last] = {row, col};
        pre[mask][last] = {s, pv};
        if (!inq[mask][last]) {
            q.push({mask, last});
            inq[mask][last] = true;
        }
    }
}

void print(int mask, int last) {
    if (!mask) return;
    int r = dp[mask][last]._1, c = dp[mask][last]._2 - len[last] + 1;
    assert(r <= h && c + len[last] <= w + 1 && c >= 1);
    REP(i, len[last])
        ans[r][c + i] = s[last][i];
    print(pre[mask][last]._1, pre[mask][last]._2);
}

int main() {
    scanf("%d%d%d", &h, &w, &n);
    REP(i, n) {
        cin >> s[i];
        if (s[i].length() > w) {
            puts("impossible");
            return 0;
        }
    }
    init();
    while (!q.empty()) {
        pii u = q.front();
        q.pop();
        int mask = u._1, last = u._2;
        inq[mask][last] = false;
        REP(i, n) {
            if (mask & (1 << i)) continue;
            int now = mask | (1 << i);
            if (w - dp[mask][last]._2 >= len[i] - match[last][i])
                update(now, i, dp[mask][last]._1, dp[mask][last]._2 + len[i] - match[last][i], mask, last);
            else
                update(now, i, dp[mask][last]._1 + 1, len[i], mask, last);
        }
    }
    bool flag = false;
    REP(i, n) if (dp[ALL][i]._1 <= h && dp[ALL][i]._2 <= w) {
            print(ALL, i);
            flag = true;
            break;
        }
    if (!flag) puts("impossible");
    else {
        FOR(i, 1, h) {
            FOR(j, 1, w) putchar(ans[i][j]);
            puts("");
        }
    }
    return 0;
}