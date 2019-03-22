// 最大独立集 = 点数 - 最小覆盖
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

int T, N;
int h[2][maxn];
string music[2][maxn], sport[2][maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        num_left = num_right = 0;
        REP(i, N) {
            int x;
            char g[5];
            scanf("%d%s", &x, g);
            if (g[0] == 'M') {
                h[0][num_left] = x;
                cin >> music[0][num_left] >> sport[0][num_left];
                num_left++;
            } else {
                h[1][num_right] = x;
                cin >> music[1][num_right] >> sport[1][num_right];
                num_right++;
            }
        }
        REP(i, num_left) G[i].clear();
        REP(i, num_right) G[i + maxn].clear();
        REP(i, num_left) REP(j, num_right)
                if (abs(h[0][i] - h[1][j]) <= 40 && music[0][i] == music[1][j] && sport[0][i] != sport[1][j]) {
                    G[i].pb(j + maxn);
                    G[j + maxn].pb(i);
                }
        printf("%d\n", N - hungarian());
    }
    return 0;
}
