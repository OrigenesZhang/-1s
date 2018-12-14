#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second

const int maxn = 112345;

struct Segment {
    int l, r, h, sign;
    bool operator < (const Segment &rhs) const {
        return h < rhs.h;
    }
};

Segment s[maxn << 1];
int n;

ll sum[maxn << 3], rec[maxn << 3], lazy[maxn << 3];

void pushdown(int o, int l, int r) {
    int m = l + r >> 1;
    if (lazy[o]) {
        if (lazy[o] & 1) {
            sum[o << 1] = rec[m + 1] - rec[l] - sum[o << 1];
            sum[o << 1 | 1] = rec[r + 1] - rec[m + 1] - sum[o << 1 | 1];
        }
        lazy[o << 1] += lazy[o];
        lazy[o << 1 | 1] += lazy[o];
        lazy[o] = 0;
    }
}

inline void maintain(int o) {
    sum[o] = sum[o << 1] + sum[o << 1 | 1];
}

void update(int L, int R, int v, int l, int r, int o) {
    if (L <= l && r <= R) {
        sum[o] = rec[r + 1] - rec[l] - sum[o];
        lazy[o]++;
        return;
    }
    pushdown(o, l, r);
    int m = l + r >> 1;
    if (L <= m) update(L, R, v, l, m, o << 1);
    if (R > m) update(L, R, v, m + 1, r, o << 1 | 1);
    maintain(o);
}

int main() {
    scanf("%d", &n);
    FOR(i, 1, n) {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        s[i] = {x1, x2, y1, 1}, s[i + n] = {x1, x2, y2, -1};
        rec[i] = x1, rec[i + n] = x2;
    }
    n <<= 1;
    sort(s + 1, s + n + 1);
    sort(rec + 1, rec + n + 1);
    int m = unique(rec + 1, rec + n + 1) - rec - 1;
    ll ans = 0;
    FOR(i, 1, n - 1) {
        int l = lower_bound(rec + 1, rec + m + 1, s[i].l) - rec;
        int r = lower_bound(rec + 1, rec + m + 1, s[i].r) - rec;
        if (l < r) update(l, r - 1, s[i].sign, 1, m, 1);
        ans += sum[1] * (s[i + 1].h - s[i].h);
    }
    printf("%lld\n", ans);
}

[close]
