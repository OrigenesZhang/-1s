#include <bits/stdc++.h>

using namespace std;

const int maxn = 312345;

long long fen[maxn];
int c[maxn], d[maxn];
int n;
vector<int> G[maxn];

inline int lowbit(int x) {
    return x & -x;
}

void upd(int x, long long val) {
    while (x > 0) {
        fen[x] = max(fen[x], val);
        x -= lowbit(x);
    }
}

long long query(int x) {
    long long ret = 0;
    while (x <= n) {
        ret = max(fen[x], ret);
        x += lowbit(x);
    }
    return ret;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", c + i);
        if (i >= c[i] && c[i] != 1) G[i - c[i] + 1].emplace_back(i);
    }
    for (int i = 1; i <= n; i++) scanf("%d", d + i);
    for (int i = 1; i <= n; i++) {
        for (int j = int(G[i].size()) - 1; j >= 0; j--) {
            int u = G[i][j];
            upd(u - 1, query(u) + d[u]);
        }
        printf("%lld ", query(i) + (c[i] == 1 ? d[i] : 0));
        if (i + c[i] - 1 <= n) upd(i + c[i] - 1, query(i + c[i] - 1) + d[i]);
    }
}