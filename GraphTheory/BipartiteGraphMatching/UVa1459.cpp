// 玄学剪枝题
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

const int maxn = 213;

int N, M, K, T;
int match[maxn], tot, ans[maxn], tmp[maxn];
bool check[maxn], mat[maxn][maxn], sel[maxn];
vector<int> G[maxn];

bool dfs(int u, int pos) {
    if (u <= pos) return false;
    for (int v : G[u]) {
        if (!check[v]) {
            check[v] = true;
            if (match[v] == -1 || dfs(match[v], pos)) {
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}

int hungarian() {
    int ans = 0;
    reset(match, -1);
    REP(u, N) {
        reset(check, 0);
        if (dfs(u, -1)) ans++;
    }
    return ans;
}

bool judge(int pos, int flower) {
    if (match[flower] == pos) return true;
    int t = -1;
    REP(i, N) {
        tmp[i] = match[i];
        check[i] = false;
        if (match[i] == pos) t = i;
    }
    int no = match[flower];
    match[flower] = pos;
    if(t != -1) match[t] = -1;
    if (dfs(no, pos)) return true;
    REP(i, N) match[i] = tmp[i];
    return false;
}

bool go(int pos) {
    if (pos == N) return ++tot == K;
    for (int u : G[pos])
        if (!sel[u] && judge(pos, u)) {
            sel[u] = true;
            ans[pos] = u;
            if (go(pos + 1)) return true;
            sel[u] = false;
        }
    return false;
}

int main() {
    scanf("%d", &T);
    FOR(cs, 1, T) {
        scanf("%d%d%d", &N, &M, &K);
        REP(i, N) G[i].clear();
        reset(mat, 0);
        REP(i, M) REP(j, N) {
                int now;
                scanf("%d", &now);
                mat[j][now - 1] = true;
            }
        REP(i, N) REP(j, N) if (!mat[i][j]) G[i].pb(j);
        printf("Case #%d: ", cs);
        if (hungarian() != N) {
            puts("-1");
            continue;
        }
        reset(sel, 0);
        tot = 0;
        if (go(0)) {
            printf("%d", ans[0] + 1);
            FOR(i, 1, N - 1) printf(" %d", ans[i] + 1);
            puts("");
        } else puts("-1");
    }
    return 0;
}
