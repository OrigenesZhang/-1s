// 加边补成完全匹配
// 最大匹配构造
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define sqr(x) ((x) * (x))
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define mp make_pair
#define _1 first
#define _2 second

const int maxn = 123;

vector<int> G[2 * maxn];
int num_left;
int check[2 * maxn], match[2 * maxn], pre[2 * maxn];

int hungarian() {
    int ans = 0;
    reset(check, -1);
    reset(match, -1);
    REP(i, num_left) {
        queue<int> q;
        q.push(i);
        pre[i] = -1;
        while (!q.empty() && match[i] == -1) {
            int u = q.front(); q.pop();
            for (int v : G[u]) {
                if (match[i] != -1) break;
                if (check[v] != i) {
                    check[v] = i;
                    if (match[v] != -1) {
                        q.push(match[v]);
                        pre[match[v]] = u;
                    } else {
                        int d = u, e = v;
                        while (d != -1) {
                            int t = match[d];
                            match[d] = e;
                            match[e] = d;
                            d = pre[d];
                            e = t;
                        }
                    }
                }
            }
        }
        if (match[i] != -1) ans++;
    }
    return ans;
}

int T, N, out[maxn][maxn];
char mat[maxn][maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        REP(i, N) scanf("%s", mat[i]);
        num_left = N;
        REP(i, N) {
            G[i].clear();
            G[i + maxn].clear();
        }
        REP(i, N) REP(j, N) if (mat[i][j] == '*') {
                    G[i].pb(j + maxn);
                    G[j + maxn].pb(i);
                }
        int ans = 0;
        REP(i, N) ans = max(ans, int(max(G[i].size(), G[i + maxn].size())));
        REP(i, N) {
            int p = 0;
            while (G[i].size() < ans && p < N) {
                while (G[i].size() < ans && G[p + maxn].size() < ans) {
                    G[i].pb(p + maxn);
                    G[p + maxn].pb(i);
                }
                p++;
            }
        }
        reset(out, 0);
        FOR(c, 1, ans) {
            hungarian();
            REP(i, num_left) {
                if (match[i] == -1) continue;
                if (mat[i][match[i] - maxn] == '*') out[i][match[i] - maxn] = c;
                REP(j, G[i].size()) if (G[i][j] == match[i]) {
                        G[i].erase(G[i].begin() + j);
                        break;
                    }
            }
        }
        printf("%d\n", ans);
        REP(i, N) {
            printf("%d", out[i][0]);
            FOR(j, 1, N - 1) printf(" %d", out[i][j]);
            puts("");
        }
    }
    return 0;
}
