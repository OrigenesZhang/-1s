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

const int maxn = 19;

bool vis[1 << maxn];
int sg[1 << maxn], T, n, s;
vector<pii> G[1 << maxn];

int dfs(int u) {
//    BUG(u);
    if (vis[u]) return sg[u];
    int &ret = sg[u];
    vis[u] = true;
    set<int> mex;
    FOR(i, 2, 20) {
        if (u & (1 << i - 2)) {
            int v = u ^ (1 << i - 2);
            FOR(j, 2, 20) {
                if (i + j > 20) break;
                if (v & (1 << j - 2)) continue;
                v &= ~(1 << i + j - 2);
            }
            G[u].pb(mp(i, v));
            mex.insert(dfs(v));
        }
    }
//    BUG(u);
    int p = -1;
    for (int s : mex) {
        if (s > p + 1) return ret = p + 1;
        p = s;
    }
    return ret = p + 1;
}

int main() {
    vis[0] = true;
    scanf("%d", &T);
    FOR(cs, 1, T) {
        s = 0;
        scanf("%d", &n);
        REP(i, n) {
            int a;
            scanf("%d", &a);
            s ^= 1 << a - 2;
        }
        printf("Scenario #%d:\n", cs);
        if (!dfs(s)) puts("There is no winning move.");
        else {
            printf("The winning moves are:");
            for (auto it : G[s]) if (!sg[it._2]) printf(" %d", it._1);
            puts(".");
        }
        puts("");
    }
    return 0;
}
