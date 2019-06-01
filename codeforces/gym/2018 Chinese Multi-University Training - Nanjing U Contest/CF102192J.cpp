#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define ROF(i, a, b) for (int i = (a); i >= (b); i--)
#define chkmax(a, b) a = max(a, b)

using namespace std;

const int maxn = 112345;

int st[maxn][17], h[maxn], pre[maxn], suf[maxn], bit[maxn];
int T, n, m;

inline int query(int lo, int hi) {
    if (hi < lo) return 0;
    int k = bit[hi - lo + 1];
    return h[st[lo][k]] >= h[st[hi - (1 << k) + 1][k]] ? st[lo][k] : st[hi - (1 << k) + 1][k];
}

int get(int idx, int lo) {
    if (idx > n) return n + 1;
    if (h[query(idx, n)] <= lo) return n + 1;
    int l = idx, r = n;
    while (l < r) {
        int mi = l + r >> 1;
        if (h[query(idx, mi)] > lo) r = mi;
        else l = mi + 1;
    }
    return l;
}

int main() {
    scanf("%d", &T);
    {
        int j = 0;
        FOR(i, 1, 100000) {
            while (1 << j + 1 <= i) j++;
            bit[i] = j;
        }
    }
    while (T--) {
        scanf("%d%d", &n, &m);
        FOR(i, 1, n) scanf("%d", h + i);
        FOR(i, 1, n) st[i][0] = i;
        FOR(j, 1, 16) for (int i = 1; i + (1 << j) - 1 <= n; i++)
                st[i][j] = h[st[i][j - 1]] >= h[st[i + (1 << j - 1)][j - 1]] ? st[i][j - 1] : st[i + (1 << j - 1)][j - 1];
        int now = h[1];
        pre[1] = 1;
        FOR(i, 2, n) {
            pre[i] = pre[i - 1] + (h[i] > now);
            chkmax(now, h[i]);
        }
        suf[n + 1] = 0;
        ROF(i, n, 1) suf[i] = 1 + suf[get(i + 1, h[i])];
        while (m--) {
            int p, q;
            scanf("%d%d", &p, &q);
            int en = h[query(1, p - 1)];
            int ans = pre[p - 1] + (en < q) + suf[get(p + 1, max(en, q))];
            printf("%d\n", ans);
        }
    }
}