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

const int maxn = 1234;
const int inf = 0x3f3f3f3f;

bool inq[maxn][maxn];
int dp[maxn][maxn];
vector<int> G[maxn];
pii a[maxn];

int n, m, x, t;

int main() {
    scanf("%d", &x);
    scanf("%d%d%d", &n, &m, &t);
    REP(i, m) {
        int a, b;
        scanf("%d%d", &a, &b);
        G[a].pb(b);
        G[b].pb(a);
    }
    FOR(i, 1, n)
        scanf("%d%d", &a[i]._1, &a[i]._2);
    reset(dp, 0x3f);
    dp[1][a[1]._1] = a[1]._2;
    queue<pii> q;
    q.push({1, a[1]._1});
    inq[1][a[1]._1] = true;
    while (!q.empty()) {
        pii s = q.front(); q.pop();
        int u = s._1, now = s._2;
        inq[u][now] = false;
        for (int v : G[u]) {
            if (now + t + a[v]._1 > x) continue;
            if (dp[v][now + t + a[v]._1] > dp[u][now] + a[v]._2) {
                dp[v][now + t + a[v]._1] = dp[u][now] + a[v]._2;
                if (!inq[v][now + t + a[v]._1]) {
                    q.push({v, now + t + a[v]._1});
                    inq[v][now + t + a[v]._1] = true;
                }
            }
        }
        if (now + a[u]._1 <= x) {
            if (dp[u][now + a[u]._1] > dp[u][now] + a[u]._2) {
                dp[u][now + a[u]._1] = dp[u][now] + a[u]._2;
                if (!inq[u][now + a[u]._1]) {
                    q.push({u, now + a[u]._1});
                    inq[u][now + a[u]._1] = true;
                }
            }
        }
    }
    if (dp[1][x] == inf) puts("It is a trap.");
    else printf("%d\n", dp[1][x]);
    return 0;
}