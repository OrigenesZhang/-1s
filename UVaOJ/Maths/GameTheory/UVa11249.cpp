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

const int maxn = 123456;

int lose[maxn], T, a, b, k, q;

void init() {
    lose[1] = k + 2;
    lose[k + 2] = 1;
    int p = 1;
    FOR(i, 2, 100000) {
        if (lose[i]) continue;
        int now = lose[p] + i - p + k + 1;
        if (now > 100000) break;
        p = i;
        lose[i] = now;
        lose[now] = i;
    }
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &k, &q);
        reset(lose, 0);
        init();
        while (q--) {
            scanf("%d%d", &a, &b);
            if (a > b) swap(a, b);
            puts(lose[a] == b ? "LOSING" : "WINNING");
        }
        puts("");
    }
    return 0;
}
