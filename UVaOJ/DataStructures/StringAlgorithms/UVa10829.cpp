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

namespace suffix_array {
    int sa[maxn], t[maxn], t2[maxn], c[maxn], rank[maxn], height[maxn];

    void build_sa(char *s, int n, int m) {
        int *x = t, *y = t2;
        REP(i, m) c[i] = 0;
        REP(i, n) c[x[i] = s[i]]++;
        FOR(i, 1, m - 1) c[i] += c[i - 1];
        ROF(i, n - 1, 0) sa[--c[x[i]]] = i;
        for (int k = 1; k <= n; k <<= 1) {
            int p = 0;
            FOR(i, n - k, n - 1) y[p++] = i;
            REP(i, n) if (sa[i] >= k) y[p++] = sa[i] - k;
            REP(i, m) c[i] = 0;
            REP(i, n) c[x[y[i]]]++;
            REP(i, m) c[i] += c[i - 1];
            ROF(i, n - 1, 0) sa[--c[x[y[i]]]] = y[i];
            swap(x, y);
            p = 1, x[sa[0]] = 0;
            FOR(i, 1, n - 1)
                x[sa[i]] = y[sa[i - 1]] == y[sa[i]] && y[sa[i - 1] + k] == y[sa[i] + k] ? p - 1 : p++;
            if (p >= n) break;
            m = p;
        }
    }

    void get_height(char *s, int n) {
        FOR(i, 1, n) rank[sa[i]] = i;
        int k = 0;
        REP(i, n) {
            if (k) k--;
            int j = sa[rank[i] - 1];
            while (s[i + k] == s[j + k]) k++;
            height[rank[i]] = k;
        }
    }
}

char s[maxn];
int T, g, st[maxn][18];

void rmq_init(int n) {
    FOR(i, 1, n) st[i][0] = suffix_array::height[i];
    FOR(i, 1, n) FOR(j, 1, 17) {
            st[i][j] = st[i][j - 1];
            int val = i - (1 << j - 1);
            if (val > 0) st[i][j] = min(st[i][j], st[val][j - 1]);
        }
}

int rmq(int l, int r) {
    int val = floor(log(r - l + 1) / log(2));
    return min(st[l + (1 << val) - 1][val], st[r][val]);
}

int lcp(int l, int r) {
    l = suffix_array::rank[l], r = suffix_array::rank[r];
    if (l > r) swap(l, r);
    return rmq(l + 1, r);
}

int main() {
    scanf("%d", &T);
    FOR(cs, 1, T) {
        scanf("%d%s", &g, s);
        int n = strlen(s), ans = 0;
        s[n] = 127;
        REP(i, n) s[n + i + 1] = s[n - i - 1];
        s[n << 1 | 1] = 0;
        suffix_array::build_sa(s, 2 * n + 2, 128);
        suffix_array::get_height(s, 2 * n + 1);
        rmq_init(n << 1 | 1);
        FOR(len, 1, n / 2 - 1) for (int now = 0; now < n; now += len) {
                int cur = now + len + g, tot = 0;
                if (cur < n) tot += min(lcp(now, cur), len);
                if (now) tot += min(lcp(2 * n - now + 1, 2 * n - cur + 1), len - 1);
                ans += max(tot - len + 1, 0);
            }
        printf("Case %d: %d\n", cs, ans);
    }
}
