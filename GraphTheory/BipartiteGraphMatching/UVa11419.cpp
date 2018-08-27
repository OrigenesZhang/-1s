// Konig定理: 最小覆盖 = 最大匹配
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define sqr(x) ((x) * (x))
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define mp make_pair
#define _1 first
#define _2 second

const int maxn = 1234;

vector<int> G[2 * maxn];
int num_left;
int check[2 * maxn], match[2 * maxn], pre[2 * maxn];
bool vis[2 * maxn];

int hungarian() {
    int ans = 0;
    reset(check, -1);
    reset(match, -1);
    REP(i, num_left) {
        queue<int> q;
        q.push(i);
        pre[i] = -1;
        while (!q.empty() && match[i] == -1) {
            int u = q.front(); q.pop();
            for (int v : G[u]) {
                if (match[i] != -1) break;
                if (check[v] != i) {
                    check[v] = i;
                    if (match[v] != -1) {
                        q.push(match[v]);
                        pre[match[v]] = u;
                    } else {
                        int d = u, e = v;
                        while (d != -1) {
                            int t = match[d];
                            match[d] = e;
                            match[e] = d;
                            d = pre[d];
                            e = t;
                        }
                    }
                }
            }
        }
        if (match[i] != -1) ans++;
    }
    return ans;
}

void dfs(int u, bool left) {
    vis[u] = true;
    if (left) {
        for (int v : G[u])
            if (!vis[v] && match[v] != -1 && match[v] != u)
                dfs(v, false);
    } else {
        dfs(match[u], true);
    }
}

int R, C, N;

int main() {
    while (scanf("%d%d%d", &R, &C, &N) == 3) {
        if (!R) break;
        map<int, int> mmap;
        map<int, int> mat;
        num_left = 0;
        REP(i, R) G[i].clear();
        REP(i, N) {
            int x, y;
            scanf("%d%d", &x, &y);
            x--, y--;
            if (!mmap.count(x)) {
                mmap[x] = num_left;
                mat[num_left++] = x;
            }
            G[mmap[x]].pb(y + maxn);
            G[y + maxn].pb(mmap[x]);
        }
        int ans = hungarian();
        reset(vis, 0);
        REP(i, R) {
            if (match[i] != -1) continue;
            dfs(i, true);
        }
        printf("%d", ans);
        REP(i, num_left) if (!vis[i]) printf(" r%d", mat[i] + 1);
        REP(i, C) if (vis[i + maxn]) printf(" c%d", i + 1);
        puts("");
    }
    return 0;
}
