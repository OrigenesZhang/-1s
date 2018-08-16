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

const int maxn = 1234;

bool vis[maxn];
int sg[maxn], n, m;
vector<int> G[maxn];

int dfs(int u) {
    if (vis[u]) return sg[u];
    vis[u] = true;
    int &ret = sg[u];
    ret = 0;
    vector<int> s;
    for (int v : G[u]) s.pb(dfs(v));
    sort(all(s));
    if (s.empty() || s[0]) return ret;
    REP(i, int(s.size()) - 1) if (s[i + 1] > s[i] + 1) {
            ret = s[i] + 1;
            break;
        }
    if (!ret) ret = s.back() + 1;
    return ret;
}

int main() {
    while (scanf("%d%d", &n, &m) == 2) {
        if (!n) break;
        memset(vis, false, sizeof(vis));
        REP(i, n) G[i].clear();
        REP(i, m) {
            int u, v;
            scanf("%d%d", &u, &v);
            G[u].pb(v);
        }
        REP(i, n) dfs(i);
        int sum = 0;
        REP(i, n) {
            int s;
            scanf("%d", &s);
            if (s & 1) sum ^= sg[i];
        }
        puts(sum ? "First" : "Second");
    }
    return 0;
}
