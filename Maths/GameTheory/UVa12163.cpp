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

const int maxn = 123;
const int ALL = 1 << 15;

vector<int> G[maxn];
int sg[maxn], T, V, E, R, k[maxn], bits[ALL];
bool vis[maxn];

int cnt_true(int x) {
    int cnt = 0;
    for (int now = 1; now < ALL; now <<= 1)
        cnt += (x & now) > 0;
    return cnt;
}

void init() {
    REP(i, V) G[i].clear();
    memset(vis, false, sizeof(vis));
}

int dfs(int u) {
    if (vis[u]) return sg[u];
    vis[u] = true;
    int &ret = sg[u];
    if (G[u].empty()) return ret = 0;
    for (int v : G[u]) dfs(v);
    int s = 1 << G[u].size();
    set<int> mex;
    REP(i, s) {
        if (bits[i] > k[u]) continue;
        if ((bits[i] ^ k[u]) & 1) continue;
        int now = 0;
        REP(j, G[u].size()) if (i & (1 << j)) now ^= sg[G[u][j]];
        mex.insert(now);
    }
    int p = -1;
    for (int now : mex) {
        if (now > p + 1) return ret = p + 1;
        p = now;
    }
    return ret = p + 1;
}

int main() {
    scanf("%d", &T);
    REP(i, ALL) bits[i] = cnt_true(i);
    FOR(g, 1, T) {
        scanf("%d%d", &V, &E);
        init();
        REP(i, E) {
            int u, v;
            scanf("%d%d", &u, &v);
            G[u].pb(v);
        }
        REP(i, V) scanf("%d", &k[i]);
        scanf("%d", &R);
        printf("Game#%d:\n", g);
        FOR(r, 1, R) {
            int sum = 0, now;
            REP(i, V) {
                scanf("%d", &now);
                if (now & 1) sum ^= dfs(i);
            }
            printf("Round#%d: %s\n", r, sum ? "WINNING" : "LOSING");
        }
        puts("");
    }
    return 0;
}
