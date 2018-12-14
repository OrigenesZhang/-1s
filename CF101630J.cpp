#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#define pb push_back
using namespace std;

typedef long long LL;
typedef pair<int, int> pii;
const int N = 3000 + 10;
const LL INF = LL(1e15);

vector<pii> G[N], G2[N];
vector<int> val;

int n, m, k;
LL d[N];

struct Node {
    int u;
    LL d;
    bool operator < (const Node& rhs) const {
        return d > rhs.d;
    }
};

LL Dijkstra() {
    for (int i = 2; i <= n; i++) d[i] = INF;
    priority_queue<Node> pq;
    pq.push({ 1, 0 });
    while (!pq.empty()) {
        Node u = pq.top(); pq.pop();
        if (d[u.u] < u.d) continue;
        for (int i = 0; i < G[u.u].size(); i++) {
            int v = G[u.u][i].first, w = G[u.u][i].second;
            if (u.d + w < d[v]) {
                d[v] = u.d + w;
                pq.push({ v, d[v] });
            }
        }
    }
    return d[n];
}

LL deal(int val) {
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < G[i].size(); j++) G[i][j].second = max(0, G[i][j].second - val);
    LL ret = Dijkstra() + (LL)val * k;
    for (int i = 1; i <= n; i++) G[i] = G2[i];
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].pb({ v, w });
        G[v].pb({ u, w });
        G2[u].pb({ v, w });
        G2[v].pb({ u, w });
        val.pb(w);
    }

    LL minm = Dijkstra();

    for (int i = 0; i < m; i++) minm = min(minm, deal(val[i]));
    cout << minm << '\n';
    return 0;
}