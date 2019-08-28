#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define ROF(i, a, b) for (int i = (a); i >= (b); i--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x)*(x))
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end())
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)
 
const int maxn = 5123;
 
int n, w, ans;
int h[maxn], deg[maxn], f[maxn];
vector<int> G[maxn];
 
void solve() {
    scanf("%d%d", &n, &w);
    FOR(i, 1, n) scanf("%d", h + i);
    FOR(i, 1, n) FOR(j, 1, n) if (h[i] > h[j] && abs(i - j) <= w) {
        deg[j]++;
        G[i].eb(j);
    }
    queue<int> q;
    FOR(i, 1, n) if (!deg[i]) q.emplace(i);
    while (!q.empty()) {
        auto u = q.front(); q.pop();
        for (auto v : G[u]) {
            chkmax(f[v], f[u] + 1);
            chkmax(ans, f[v]);
            if (!--deg[v]) q.emplace(v);
        }
    }
    printf("%d", ans);
}
 
int main() {
    int T = 1;
    while (T--) solve();
}