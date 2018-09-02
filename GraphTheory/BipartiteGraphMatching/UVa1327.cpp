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

const int maxn = 2134;

vector<int> G[maxn * 2];
int pre[maxn * 2], lowlink[maxn * 2], sccno[maxn * 2], dfs_clock, scc_cnt, n;
stack<int> s;

// Tarjan
void dfs(int u) {
    pre[u] = lowlink[u] = ++dfs_clock;
    s.push(u);
    for (int v : G[u]) {
        if (!pre[v]) {
            dfs(v);
            lowlink[u] = min(lowlink[u], lowlink[v]);
        } else if (!sccno[v]) {
            lowlink[u] = min(lowlink[u], pre[v]);
        }
    }
    if (lowlink[u] == pre[u]) {
        scc_cnt++;
        for (;;) {
            int x = s.top();
            s.pop();
            sccno[x] = scc_cnt;
            if (x == u) break;
        }
    }
}

void find_scc(int n) {
    dfs_clock = scc_cnt = 0;
    reset(sccno, 0);
    reset(pre, 0);
    FOR(i, 1, n) if (!pre[i]) dfs(i);
    FOR(i, 1, n) if (!pre[i + maxn]) dfs(i + maxn);
}

int main() {
    while (scanf("%d", &n) == 1) {
        assert(s.empty());
        FOR(i, 1, n) {
            G[i].clear();
            G[i + maxn].clear();
        }
        FOR(i, 1, n) {
            int cnt;
            scanf("%d", &cnt);
            while (cnt--) {
                int u;
                scanf("%d", &u);
                G[i].pb(u + maxn);
            }
        }
        FOR(i, 1, n) {
            int u;
            scanf("%d", &u);
            G[u + maxn].pb(i);
        }
        find_scc(n);
        vector<int> ans;
        FOR(i, 1, n) {
            ans.clear();
            for (int j : G[i]) if (sccno[i] == sccno[j])
                    ans.pb(j - maxn);
            printf("%d", ans.size());
            for (int u : ans) printf(" %d", u);
            puts("");
        }
    }
    return 0;
}
