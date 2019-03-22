#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

typedef long long LL;
const int N = 50 + 5;
const LL INF = LL(1e15);


int gcd(int a, int b) { return !b ? a : gcd(b, a % b); }
int lcm(int a, int b) { return a/ gcd(a, b) * b; }

struct Edge {
    int from, g;
    Edge(int from, int g): from(from), g(g) {}
};

int n, m, p, h[5][N], aim[5];
LL d[5][N][N * N * N];
bool vis[5][N][N * N * N];
vector<int> G[5][N];
vector<Edge> edges;
int maxn;

LL dp(int idx, int pos, int t) {
    if (t == 0 && pos == 1) return 0;
    if (t == 0) return INF;
    LL& ans = d[idx][pos][t];
    //if (ans > -1) return ans;
    if (vis[idx][pos][t]) return ans;
    vis[idx][pos][t] = true;
    ans = INF;
    ans = min(ans, dp(idx, pos, t - 1) + h[idx][pos]);
    for (int u : G[idx][pos]) {
        Edge& e = edges[u];
        ans = min(ans, dp(idx, e.from, t - 1) + e.g);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> p;
    maxn = 1;
    for (int i = 0; i < p; i++) {
        cin >> n >> m;
        //maxn = lcm(maxn, n);
        maxn *= n;
        for (int j = 1; j <= n; j++) cin >> h[i][j];
        for (int k = 0; k < m; k++) {
            int u, v, x;
            cin >> u >> v >> x;
            G[i][v].push_back(edges.size());
            edges.push_back(Edge(u, x));
        }
        cin >> aim[i];
    }
    //memset(d, -1, sizeof(d));


    LL ans = INF;
    for (int i = 0; i <= maxn; i++) {
        LL cur = 0;
        for (int j = 0; j < p; j++) cur += dp(j, aim[j], i);
        ans = min(ans, cur);
    }
    cout << ans << '\n';
    return 0;
}
