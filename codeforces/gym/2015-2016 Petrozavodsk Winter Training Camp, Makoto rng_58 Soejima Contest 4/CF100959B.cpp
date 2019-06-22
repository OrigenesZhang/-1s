#include <bits/stdc++.h>
using namespace std;

const int maxn = 112345;

int n, par[maxn];
pair<int, int> x[maxn], y[maxn];

int Find(int x) {
    return x == par[x] ? x : par[x] = Find(par[x]);
}

void Union(int u, int v) {
    u = Find(u), v = Find(v);
    par[u] = v;
}

bool check(int d) {
    iota(par, par + n, 0);
    for (int i = 0; i < n; i++) {
        if (x[i].first - x[0].first >= d) Union(x[i].second, x[0].second);
        if (x[n - 1].first - x[i].first >= d) Union(x[i].second, x[n - 1].second);
        if (y[i].first - y[0].first >= d) Union(y[i].second, y[0].second);
        if (y[n - 1].first - y[i].first >= d) Union(y[i].second, y[n - 1].second);
    }
    for (int i = 0; i < n; i++) if (Find(i) != Find(0)) return true;
    return false;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        x[i] = {u + v, i};
        y[i] = {u - v, i};
    }
    sort(x, x + n);
    sort(y, y + n);
    int lo = 0, hi = 2e9 + 5;
    while (lo < hi) {
        int mi = lo + (hi - lo >> 1);
        if (check(mi)) hi = mi;
        else lo = mi + 1;
    }
    printf("%d", lo - 1);
}