#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int N = 212345;
const int SZ = 18;
const int INF = int(1e9);
typedef pair<int, int> P;


vector<int> tree[N];
int n, m, q;

int uf[N];
int find(int u) { return uf[u] == u ? u : uf[u] = find(uf[u]); }
int u[N], v[N], w[N];

int anc[N][SZ], maxcost[N][SZ], L[N];  //sparse table

map<P, int> weight;

// MST
bool cmp(int a, int b) { return w[a] < w[b]; }
int order[N];
int Kruskal() {
    for (int i = 0; i < m; i++) order[i] = i;
    sort(order, order + m, cmp);
    for (int i = 1; i <= n; i++ ) uf[i] = i;

    int ans = 0;
    for (int i = 0; i < m; i++) {
        int l = u[order[i]], r = v[order[i]];
        int x = find(l), y = find(r);
        if (x != y) {
            ans += w[order[i]];
            tree[l].pb(order[i]);
            tree[r].pb(order[i]);
            uf[x] = y;
        }
    }
    return ans;
}

// tree with root
void dfs(int cur, int last, int level) {
    L[cur] = level;
    anc[cur][0] = last;
    for (int e : tree[cur]) {
        int rhs = u[e];
        if (rhs == cur) rhs = v[e];
        if (rhs == last) continue;
        maxcost[rhs][0] = w[e];
        dfs(rhs, cur, level + 1);
    }
}

void preprocess() {
    for (int j = 1; (1 << j) < n; j++)
        for (int i = 1; i <= n; i++)
            if (anc[i][j - 1]) {
                int a = anc[i][j - 1];
                anc[i][j] = anc[a][j - 1];
                maxcost[i][j] = max(maxcost[a][j - 1], maxcost[i][j - 1]);
            }
}

int query(int p, int q) {
    int log, ans = -INF;
    if (L[p] < L[q]) swap(p, q);
    for (log = 1; (1 << log) <= L[p]; log++); log--;

    //cout << log << endl;

    //cout << p << ' ' << q << endl;
    for (int i = log; i >= 0; i--)
        if (L[p] - (1 << i) >= L[q]) {
            ans = max(ans, maxcost[p][i]);
            p = anc[p][i];
        }
    //cout << p << ' ' << q << endl;
    if (p == q) return ans;

    for (int i = log; i >= 0; i--)
        if (anc[p][i] && anc[p][i] != anc[q][i]) {
            ans = max(ans, maxcost[p][i]); p = anc[p][i];
            ans = max(ans, maxcost[q][i]); q = anc[q][i];
        }
    ans = max(ans, maxcost[p][0]);
    ans = max(ans, maxcost[q][0]);
    return ans;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u[i] >> v[i] >> w[i];
        weight[P(u[i], v[i])] = w[i];
        weight[P(v[i], u[i])] = w[i];
    }
    int mst = Kruskal();
    //cout << mst << endl;
    dfs(1, 0, 0);

    preprocess();

    //for (int i = 1; i <= n; i++) cout << L[i] << ' ';
    //cout << endl;
    //for (int i = 1; i <= n; i++) cout << maxcost[i][0] << ' ';
    //cout << endl;

    cin >> q;
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        //cout << query(x, y) << ' ' << weight[P(x, y)] << endl;
        cout << mst - query(x, y) + weight[P(x, y)] << '\n';
    }
    return 0;
}