#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 100 + 10;
const int M = 500 + 10;
const int INF = int(1e9);

struct Dinic { // 不能有负cap
    struct Edge {
        int from, to, cap, flow;
        Edge(int from, int to, int cap, int flow): from(from), to(to), cap(cap), flow(flow) {}
    };

    int n, m, s, t;
    vector<Edge> edges;
    vector<int> G[N];
    bool vis[N];         // BFS使用，是否访问过
    int d[N];            // 从s到当前点的距离，用于构建层次图
    int cur[N];          // 当前弧优化，避免重复计算

    void init(int n) {
        this->n = n;
        for(int i = 0; i < n; i++) G[i].clear();
        edges.clear();
    }

    void AddEdge(int from, int to, int cap) {
        edges.push_back(Edge(from, to, cap, 0));
        edges.push_back(Edge(to, from, 0, 0));
        m = edges.size();
        G[to].push_back(m - 1);
        G[from].push_back(m - 2);
    }

    bool BFS() {       // 构建层次图
        memset(vis, false, sizeof(vis));
        queue<int> Q;
        Q.push(s);
        d[s] = 0;
        vis[s] = true;
        while(!Q.empty()) {
            int x = Q.front(); Q.pop();
            for(int i = 0; i < G[x].size(); i++) {
                Edge& e = edges[G[x][i]];
                if(!vis[e.to] && e.cap > e.flow) {  // 只考虑残量网络中的弧
                    vis[e.to] = true;
                    d[e.to] = d[x] + 1;
                    Q.push(e.to);
                }
            }
        }
        return vis[t];
    }

    int DFS(int x, int a) {  // 沿阻塞流增广  a: 目前为止所有弧的最小残量
        if(x == t || a == 0) return a;
        int flow = 0, f;
        for(int& i = cur[x]; i < G[x].size(); i++) {  //多路增广
            Edge& e = edges[G[x][i]];
            if(d[x] + 1 == d[e.to] && (f = DFS(e.to, min(a, e.cap - e.flow))) > 0) {
                e.flow += f;
                edges[G[x][i] ^ 1].flow -= f;
                flow += f;
                a -= f;
                if(a == 0) break;
            }
        }
        return flow;
    }

    int Maxflow(int s, int t) {
        this->s = s; this->t = t;
        int flow = 0;
        while(BFS()) {
            memset(cur, 0, sizeof(cur));
            flow += DFS(s, INF);
        }
        return flow;
    }

    void Mincut(vector<int>& ans) {  // 调用完最大流后使用
    BFS();
    for(int i = 0; i < m; i++) {
        Edge& e = edges[i];
        if(vis[e.from] && !vis[e.to] && e.cap > 0) ans.push_back(i);
    }
}
};

struct Edge {
    int u, v, w;
    Edge(int u = 0, int v = 0, int w = 0): u(u), v(v), w(w) {}
    bool operator < (const Edge& rhs) const {
        return w < rhs.w;
    }
};

Edge edges[M];
Dinic solver;

int main() {
    ios_base::sync_with_stdio();
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) cin >> edges[i].u >> edges[i].v >> edges[i].w;
    sort(edges, edges + m);

    int ans = 0;
    for (int i = 0; i < m; i++) {
        solver.init(n + 5);
        for (int j = 0; j < m; j++)
            if (edges[j].w < edges[i].w) {
                solver.AddEdge(edges[j].u, edges[j].v, 1);
                solver.AddEdge(edges[j].v, edges[j].u, 1);
            }
        ans += solver.Maxflow(edges[i].u, edges[i].v);
    }
    cout << ans << '\n';
    return 0;
}
