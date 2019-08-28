#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define ROF(i, a, b) for (int i = (a); i >= (b); i--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x)*(x))
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end())
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)
 
const int maxn = 212;
 
vector<int> G[maxn];
int dfn[maxn], low[maxn], comp[maxn];
int n, e, clk, cnt;
stack<int> s;
 
void dfs(int u) {
    dfn[u] = low[u] = ++clk;
    s.emplace(u);
    for (auto v : G[u]) {
        if (!dfn[v]) {
            dfs(v);
            chkmin(low[u], low[v]);
        } else if (!comp[v]) {
            chkmin(low[u], dfn[v]);
        }
    }
    if (low[u] == dfn[u]) {
        cnt++;
        for (;;) {
            auto x = s.top(); s.pop();
            comp[x] = cnt;
            if (x == u) break;
        }
    }
}
 
void solve() {
    scanf("%d", &n);
    REP(i, n) G[i].clear();
    clk = cnt = 0;
    scanf("%d", &e);
    while (e--) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].eb(v);
    }
    fill(dfn, dfn + n, 0);
    fill(comp, comp + n, 0);
    REP(i, n) if (!dfn[i]) dfs(i);
    printf("%d\n", cnt);
}
 
int main() {
    int T; scanf("%d", &T);
    while (T--) solve();
}