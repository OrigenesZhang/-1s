// 欧拉回路存在充要条件为图强连通且各点入度 = 出度
// 判定: a. 节点出度入度  b. 连通性
// c. 把无向边作X集点作Y集跑最大匹配
// 构造: dfs
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
const int maxm = 512;

struct Edge {
    int from, to;
    bool dir;
};

int T, V, E;
vector<int> G[maxn], ans;
int match[maxm], diff[maxn], deg[maxn];
bool check[maxn], cc[maxn][maxn];
vector<Edge> e;

bool dfs(int u) {
    if (check[u]) return false;
    check[u] = true;
    for (int v : G[u]) {
        if (match[v] == -1 || dfs(match[v])) {
            match[v] = u;
            return true;
        }
    }
    return false;
}

bool hungarian() {
    FOR(i, 1, V) for ( ; diff[i]; diff[i]--) {
            reset(check, 0);
            if (!dfs(i)) return false;
        }
    return true;
}

void euler_tour(int u) {
    while (G[u].size()) {
        int v = G[u].back();
        G[u].pop_back();
        euler_tour(v);
    }
    ans.pb(u);
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &V, &E);
        e.clear();
        e.resize(E);
        REP(i, E) {
            scanf("%d%d", &e[i].from, &e[i].to);
            char tmp[3];
            scanf("%s", tmp);
            if (tmp[0] == 'D') e[i].dir = true;
        }
        FOR(i, 1, V) G[i].clear();
        reset(cc, 0);
        reset(deg, 0);
        REP(i, E) {
            cc[e[i].from][e[i].to] = cc[e[i].to][e[i].from] = true;
            deg[e[i].from]++;
            deg[e[i].to]++;
            if (!e[i].dir) {
                G[e[i].from].pb(i);
                G[e[i].to].pb(i);
            }
        }
        bool ok = false;
        FOR(i, 1, V) if (deg[i] & 1) goto NO;
        FOR(i, 1, V) cc[i][i] = true;
        FOR(k, 1, V) FOR(i, 1, V) if (cc[i][k]) FOR(j, 1, V) cc[i][j] |= cc[k][j];
        FOR(i, 1, V) FOR(j, 1, V) if (!cc[i][j]) goto NO;
        FOR(i, 1, V) diff[i] = deg[i] >> 1;
        reset(match, -1);
        REP(i, E) if (e[i].dir) {
                match[i] = e[i].to;
                if (!diff[e[i].to]) goto NO;
                diff[e[i].to]--;
            }
        if (!hungarian()) goto NO;
        ok = true;
        FOR(i, 1, V) G[i].clear();
        REP(i, E)
            if(e[i].dir || match[i] == e[i].to)
                G[e[i].from].pb(e[i].to);
            else G[e[i].to].pb(e[i].from);
        ans.clear();
        euler_tour(1);
        reverse(all(ans));
        printf("%d", ans[0]);
        FOR(i, 1, ans.size() - 1) printf(" %d", ans[i]);
        puts("");
        NO: if (!ok) puts("No euler circuit exist");
        if (T) puts("");
    }
    return 0;
}
