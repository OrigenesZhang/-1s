#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define ROF(i, a, b) for (int i = (a); i >= (b); i--)
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define _1 first
#define _2 second

using namespace std;
using ll = long long;

const int maxn = 51234;

int T, n;
int c[maxn], d[maxn], m[maxn], p[maxn], e[maxn], R[maxn], E[maxn];
ll cost[maxn], Es[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        FOR(i, 1, n) scanf("%d%d%d%d", c + i, d + i, m + i, p + i);
        FOR(i, 1, n - 1) scanf("%d%d%d", e + i, R + i, E + i);
        Es[n] = 0;
        ROF(i, n - 1, 1) Es[i] = Es[i + 1] + E[i];
        int pre = 1e5;
        FOR(i, 1, n) {
            chkmin(pre, c[i]);
            cost[i] = m[i] + pre + Es[i];
            pre += R[i];
        }
        map<ll, int> cnt;
        ll ans = 0;
        int tot = 0;
        FOR(i, 1, n) {
            cnt[cost[i]] += p[i];
            tot += p[i];
            if (tot < d[i]) {
                ans = -1;
                break;
            }
            int tmp = d[i];
            while (!cnt.empty()) {
                auto now = *cnt.begin(); cnt.erase(cnt.begin());
                if (d[i] == now._2) {
                    ans += (now._1 - Es[i]) * d[i];
                    break;
                }
                if (d[i] < now._2) {
                    ans += (now._1 - Es[i]) * d[i];
                    cnt[now._1] = now._2 - d[i];
                    break;
                }
                ans += (now._1 - Es[i]) * now._2;
                d[i] -= now._2;
            }
            tot -= tmp;
            if (i != n) {
                int diff = tot - e[i];
                while (diff > 0) {
                    auto now = *cnt.rbegin(); cnt.erase(now._1);
                    if (now._2 > diff) {
                        cnt[now._1] = now._2 - diff;
                        break;
                    }
                    if (now._2 == diff) break;
                    diff -= now._2;
                }
                chkmin(tot, e[i]);
            }
        }
        printf("%lld\n", ans);
    }
}