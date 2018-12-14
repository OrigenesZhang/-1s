#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second

const int inf = 1e9;
const int maxn = 30 * 30 * 2 + 15;
const int maxm = 35;

struct Dinic {
    struct Edge {
        int from, to, cap, flow;
        Edge(int from, int to, int cap, int flow): from(from), to(to), cap(cap), flow(flow) {}
    };

    int n, m, s, t;
    vector<Edge> edges;
    vector<int> G[maxn];
    bool vis[maxn];
    int d[maxn], cur[maxn];

    void init(int n) {
        this->n = n;
        REP(i, n) G[i].clear();
        edges.clear();
    }

    void addEdge(int from, int to, int cap) {
        edges.pb({from, to, cap, 0});
        edges.pb({to, from, 0, 0});
        m = edges.size();
        G[to].pb(m - 1);
        G[from].pb(m - 2);
    }

    bool bfs() {
        reset(vis, 0);
        queue<int> q;
        q.push(s);
        d[s] = 0;
        vis[s] = true;
        while (!q.empty()) {
            int x = q.front(); q.pop();
            REP(i, G[x].size()) {
                Edge &e = edges[G[x][i]];
                if (!vis[e.to] && e.cap > e.flow) {
                    vis[e.to] = true;
                    d[e.to] = d[x] + 1;
                    q.push(e.to);
                }
            }
        }
        return vis[t];
    }

    int dfs(int x, int a) {
        if (x == t || a == 0) return a;
        int flow = 0, f;
        for (int &i = cur[x]; i < G[x].size(); i++) {
            Edge &e = edges[G[x][i]];
            if (d[x] + 1 == d[e.to] && (f = dfs(e.to, min(a, e.cap - e.flow))) > 0) {
                e.flow += f;
                edges[G[x][i] ^ 1].flow -= f;
                flow += f;
                a -= f;
                if (a == 0) break;
            }
        }
        return flow;
    }

    int maxFlow(int s, int t) {
        this->s = s, this->t = t;
        int flow = 0;
        while (bfs()) {
            reset(cur, 0);
            flow += dfs(s, inf);
        }
        return flow;
    }
};

Dinic solver;
char mat[maxm][maxm];
int n, m, c;
map<char, int> cost;

int main() {
    scanf("%d%d%d", &n, &m, &c);
    FOR(i, 1, m) scanf("%s", mat[i] + 1);
    FOR(i, 1, c) {
        int now;
        scanf("%d", &now);
        cost['a' + i - 1] = now;
    }
    solver.init(n * m * 2 + 2);
    FOR(i, 1, m) FOR(j, 1, n) {
            int idx = (i - 1) * n + j - 1;
            if (i > 1) solver.addEdge(idx + n * m, (i - 2) * n + j - 1, inf);
            if (i < n) solver.addEdge(idx + n * m, i * n + j - 1, inf);
            if (j > 1) solver.addEdge(idx + n * m, (i - 1) * n + j - 2, inf);
            if (j < n) solver.addEdge(idx + n * m, (i - 1) * n + j, inf);
            if (i == 1 || i == n || j == 1 || j == n) solver.addEdge(idx + n * m, n * m * 2 + 1, inf);
            if (mat[i][j] == 'B') {
                solver.addEdge(n * m * 2, idx + n * m, inf);
                solver.addEdge(idx, idx + n * m, inf);
            }
            else if (mat[i][j] == '.') solver.addEdge(idx, idx + n * m, inf);
            else solver.addEdge(idx, idx + n * m, cost[mat[i][j]]);
        }
    int ans = solver.maxFlow(n * m * 2, n * m * 2 + 1);
    if (ans >= inf) ans = -1;
    printf("%d\n", ans);
}