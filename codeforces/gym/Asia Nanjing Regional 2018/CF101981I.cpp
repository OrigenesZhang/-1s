#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#define pb push_back
using namespace std;

const int N = 3000;
const int INF = int(1e9);

struct Dinic {
    struct Edge {
        int from, to, cap, flow;
        Edge(int from, int to, int cap, int flow): from(from), to(to), cap(cap), flow(flow) {}
    };

    int n, m, s, t;
    vector<Edge> edges;
    vector<int> G[N];
    bool vis[N];
    int d[N];
    int cur[N];

    void init(int n) {
        this->n = n;
        for (int i = 0; i < n; i++) G[i].clear();
        edges.clear();
    }

    void AddEdge(int from, int to, int cap) {
        edges.pb({ from, to, cap, 0 });
        edges.pb({ to, from, 0, 0 });
        m = edges.size();
        G[to].pb(m - 1);
        G[from].pb(m - 2);
    }

    bool BFS() {
        memset(vis, 0, sizeof(vis));
        queue<int> Q;
        Q.push(s);
        d[s] = 0;
        vis[s] = true;
        while (!Q.empty()) {
            int x = Q.front(); Q.pop();
            for (int i = 0; i < G[x].size(); i++) {
                Edge& e = edges[G[x][i]];
                if (!vis[e.to] && e.cap > e.flow) {
                    vis[e.to] = true;
                    d[e.to] = d[x] + 1;
                    Q.push(e.to);
                }
            }
        }
        return vis[t];
    }

    int DFS(int x, int a) {
        if (x == t || a == 0) return a;
        int flow = 0, f;
        for (int& i = cur[x]; i < G[x].size(); i++) {
            Edge& e = edges[G[x][i]];
            if (d[x] + 1 == d[e.to] && (f = DFS(e.to, min(a, e.cap - e.flow))) > 0) {
                e.flow += f;
                edges[G[x][i] ^ 1].flow -= f;
                flow += f;
                a -= f;
                if (a == 0) break;
            }
        }
        return flow;
    }

    int Maxflow(int s, int t) {
        this->s = s; this->t = t;
        int flow = 0;
        while (BFS()) {
            memset(cur, 0, sizeof(cur));
            flow += DFS(s, INF);
        }
        return flow;
    }
};

Dinic solver;
int n, m, k;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> k;
    int s = 0, t = n * 2 + k + m + 1;
    for (int i = 1; i <= n; i++) {
        int sz;
        cin >> sz;
        solver.AddEdge(s, i + n, 1);
        solver.AddEdge(i, i + n, 1);
        for (int j = 0; j < sz; j++) {
            int x;
            cin >> x;
            solver.AddEdge(i + n, n * 2 + k + x, 1);
        }
    }

    for (int i = 1; i <= k; i++) {
        solver.AddEdge(s, i + n * 2, 1);
        for (int j = 1; j <= n; j++) solver.AddEdge(i + n * 2, j, 1);
    }

    for (int i = 1; i <= m; i++) solver.AddEdge(i + n * 2 + k, t, 1);
    cout << solver.Maxflow(s, t) << '\n';
    return 0;
}