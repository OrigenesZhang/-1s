#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define all(x) (x).begin(), (x).end()
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define mp make_pair
#define _1 first
#define _2 second

const int maxn = 25;
const int maxs = 12345;

bool vis[maxn][maxs];
int n, s, m[maxn], dp[maxn][maxs];

int dfs(int p, int s) {
    if (vis[p][s]) return dp[p][s];
    vis[p][s] = true;
    if (!s) return dp[p][s] = 1;
    int &ret = dp[p][s];
    ret = 0;
    FOR(i, 1, m[p]) {
        if (s < i) break;
        if (!dfs((p + 1) % (2 * n), s - i)) ret = 1;
    }
    return ret;
}

int main() {
    while (scanf("%d", &n) == 1) {
        if (!n) break;
        memset(vis, false, sizeof(vis));
        scanf("%d", &s);
        REP(i, 2 * n) scanf("%d", &m[i]);
        printf("%d\n", dfs(0, s) > 0);
    }
    return 0;
}
