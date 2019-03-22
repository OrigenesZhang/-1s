#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

const int N = 3123456;
const double INF = 1e15;
const double eps = 1e-13;

int n, m;

struct Node {
    int id, num;
    double val, dp;

    bool operator < (const Node& rhs) const {
        return dp > rhs.dp;
    }

    Node(int id, int num, double val, double dp): id(id), num(num), val(val), dp(dp) {}
};

bool equal(double a, double b) { return abs(a - b) < eps; }

vector<int> G[N];
int deg[N], num[N];
double dp[N], val[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
        deg[a]++; deg[b]++;
    }

    fill(dp + 1, dp + n + 1, INF);
    dp[n] = 0;
    priority_queue<Node> pq;
    pq.push(Node(n, 0, 0, 0));

    while (!pq.empty()) {
        Node u = pq.top(); pq.pop();
        //if (!equal(u.dp, dp[u.id])) continue;
        if (dp[u.id] < u.dp) continue;
        for (int v : G[u.id])
            if (dp[v] > u.dp) {
                num[v]++;
                val[v] += (u.dp + 1);
                dp[v] = (val[v] + deg[v] - num[v]) / num[v];
                pq.push(Node(v, num[v], val[v], dp[v]));
            }
    }

    cout << fixed;
    cout.precision(10);
    cout << dp[1] << '\n';
    return 0;
}