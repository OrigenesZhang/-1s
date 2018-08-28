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

const int maxn = 512;

vector<int> G[2 * maxn];
int num_left, num_right;
int check[2 * maxn], match[2 * maxn], pre[2 * maxn];

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

pii p[2][maxn];
int T, c, d, v;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d\n", &c, &d, &v);
        num_left = num_right = 0;
        REP(i, v) {
            char ch[2];
            int x, y;
            ch[0] = getchar();
            scanf("%d ", &x);
            ch[1] = getchar();
            scanf("%d", &y);
            getchar();
            if (ch[0] == 'C') p[0][num_left++] = mp(x, y);
            else p[1][num_right++] = mp(x, y);
        }
        REP(i, num_left) G[i].clear();
        REP(i, num_right) G[i + maxn].clear();
        REP(i, num_left) REP(j, num_right)
                if (p[0][i]._1 == p[1][j]._2 || p[0][i]._2 == p[1][j]._1) {
                    G[i].pb(j + maxn);
                    G[j + maxn].pb(i);
                }
        printf("%d\n", v - hungarian());
    }
    return 0;
}
