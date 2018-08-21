// 把每个石子看成一个独立的游戏
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define mp make_pair
#define _1 first
#define _2 second

const int maxn = 24;
const int maxs = 123;  // sg的异或和可能超过maxn

bool vis[maxs];
int sg[maxs], s[maxn], n, cs = 1;

void init() {
    REP(i, maxn) {
        reset(vis, 0);
        REP(j, i) FOR(k, j, i - 1) vis[sg[j] ^ sg[k]] = true;
        REP(j, maxs) if (!vis[j]) {
                sg[i] = j;
                break;
            }
    }
}

int main() {
    init();
    while (scanf("%d", &n) == 1) {
        if (!n) break;
        int sum = 0;
        REP(i, n) {
            scanf("%d", &s[i]);
            if (s[i] & 1) sum ^= sg[n - i - 1];
        }
        printf("Game %d: ", cs++);
        if (!sum) puts("-1 -1 -1");
        else {
            REP(i, n) {
                if (!s[i]) continue;
                FOR(j, i + 1, n - 1) FOR(k, j, n - 1)
                        if (!(sum ^ sg[n - i - 1] ^ sg[n - j - 1] ^ sg[n - k - 1])) {
                            printf("%d %d %d\n", i, j, k);
                            goto label;
                        }
            }
        }
        label:;
    }
    return 0;
}
