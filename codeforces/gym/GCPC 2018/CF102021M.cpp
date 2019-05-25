#include <bits/stdc++.h>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REP(i, n) FOR(i, 0, (n) - 1)

const int maxn = 512;

struct Edge {
    int u, v, w;

    Edge(int u, int v, int w) : u(u), v(v), w(w) {}

    bool operator < (const Edge &rhs) const {
        return w < rhs.w;
    }
};

int n, m, q;
int h[maxn][maxn], par[maxn * maxn], cnt[maxn * maxn], ans[112345], idx[maxn * maxn];
set<int> query[maxn * maxn];
vector<Edge> e;

int get(int row, int col) {
    return (row - 1) * n + col;
}

int Find(int x) {
    return par[x] == x ? x : par[x] = Find(par[x]);
}

int main() {
    scanf("%d%d%d", &m, &n, &q);
    FOR(i, 1, m) FOR(j, 1, n) scanf("%d", &h[i][j]);
    FOR(i, 2, m) FOR(j, 1, n) {
        int u = get(i, j), v = get(i - 1, j), w = max(h[i][j], h[i - 1][j]);
        e.emplace_back(u, v, w);
    }
    FOR(i, 1, m) FOR(j, 2, n) {
        int u = get(i, j), v = get(i, j - 1), w = max(h[i][j], h[i][j - 1]);
        e.emplace_back(u, v, w);
    }
    sort(e.begin(), e.end());
    FOR(i, 1, q) {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        int u = get(x1, y1), v = get(x2, y2);
        if (u == v) ans[i] = h[x1][y1];
        else {
            query[u].emplace(i);
            query[v].emplace(i);
        }
    }
    int tot = n * m;
    FOR(i, 1, tot) par[i] = idx[i] = i, cnt[i] = 1;
    for (const auto &now : e) {
        int pu = Find(now.u), pv = Find(now.v);
        if (pu == pv) continue;
        int tu = idx[pu], tv = idx[pv], tt;
        if (query[tu].size() < query[tv].size()) {
            for (auto it : query[tu]) {
                if (query[tv].count(it)) {
                    ans[it] = now.w;
                    query[tv].erase(it);
                } else {
                    query[tv].emplace(it);
                }
            }
            tt = tv;
        } else {
            for (auto it : query[tv]) {
                if (query[tu].count(it)) {
                    ans[it] = now.w;
                    query[tu].erase(it);
                } else query[tu].emplace(it);
            }
            tt = tu;
        }
        if (cnt[pu] < cnt[pv]) {
            par[pu] = pv;
            cnt[pv] += cnt[pu];
            idx[pv] = tt;
        } else {
            par[pv] = pu;
            cnt[pu] += cnt[pv];
            idx[pu] = tt;
        }
    }
    FOR(i, 1, q) printf("%d\n", ans[i]);
}

/*
 * 3 5 3
1 3 2 1 3
2 4 5 4 4
2 1 3 2 2
1 1 3 2
2 4 2 2
1 4 3 4
2
3
3
 */