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

const int maxn = 212345;

ll tbl[maxn][19], tmp[maxn];
char s[maxn];
int n, T;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%s", &n, s);
        REP(i, n) s[i + n] = s[i];
        map<ll, vector<int>> cur;
        REP(i, 2 * n) cur[s[i]].eb(i);
        int cnt = 0, len;
        bool fi = true, ok = false;
        for (const auto &it : cur) {
            if (fi && it._2.size() == 1) {
                ok = true;
                printf("%d\n", it._2[0]);
                break;
            }
            for (auto pos : it._2) tbl[pos][0] = cnt;
            cnt++;
            fi = false;
        }
        if (ok) continue;
        FOR(i, 1, 18) {
            len = 1 << i;
            if (len > n) break;
            cur.clear();
            cnt = 0;
            REP(j, 2 * n + 1 - len) cur[tbl[j][i - 1] * (2 * n) + tbl[j + (len >> 1)][i - 1]].eb(j);
            fi = true;
            for (const auto &it : cur) {
                if (fi && it._2.size() == 1) {
                    ok = true;
                    printf("%d\n", it._2[0]);
                    break;
                }
                for (auto pos : it._2) tbl[pos][i] = cnt;
                cnt++;
                fi = false;
            }
            if (ok) break;
        }
        if (ok) continue;
        len >>= 2;
        int bit = 0;
        while (len) len >>= 1, bit++;
        int need = n - len;
        len = 1 << bit;
        REP(i, n) tmp[i] = tbl[i][bit];
        ROF(i, bit - 1, 0) if (need & (1 << i)) {
                cur.clear();
                REP(j, n) cur[tmp[j] * (2 * n) + tbl[j + len][i]].eb(j);
                cnt = 0;
                fi = true;
                for (const auto &it : cur) {
                    if (fi && it._2.size() == 1) {
                        ok = true;
                        printf("%d\n", it._2[0]);
                        break;
                    }
                    for (auto pos : it._2) tmp[pos] = cnt;
                    cnt++;
                    fi = false;
                }
                if (ok) break;
                len += 1 << i;
            }
        if (ok) continue;
        assert(len == n);
        int ans = 0;
        FOR(i, 1, n - 1) if (tmp[i] < tmp[ans]) ans = i;
        printf("%d\n", ans);
    }
}
