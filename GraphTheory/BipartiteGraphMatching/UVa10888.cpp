// 挺像那个五子棋的题
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

const int maxn = 20;
const int inf = 0x3f3f3f3f;
const int maxw = 55;
const pii dir[] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

struct KM {
    int n;  // number of vertices on each side (tot = 2 * n)
    int W[maxn][maxn];  // weight of the edges
    int Lx[maxn], Ly[maxn];     // potential of each point, indexing from 1 onwards
    int left[maxn];     // left[v] = the index of the vertex which vertex v of the right is matching to
    int slack[maxn];    // if v is not in T and u is in S, slack[v] = min(Lx[u] + Ly[v] - w[u][v])
    bool S[maxn], T[maxn];  // Whether vertex is in an alternating path

    void init(int n) {
        this->n = n;
        FOR(i, 1, n) FOR(j, 1, n) W[i][j] = -inf;
    }

    void addEdge(int u, int v, int w) {
        W[u][v] = max(W[u][v], w);
    }

    bool match(int u) {
        S[u] = true;
        FOR(v, 1, n) if (!T[v]) {
                if (Lx[u] + Ly[v] == W[u][v]) {
                    T[v] = true;
                    if (!left[v] || match(left[v])) {
                        left[v] = u;
                        return true;
                    }
                } else {
                    slack[v] = min(slack[v], Lx[u] + Ly[v] - W[u][v]);
                }
            }
        return false;
    }

    void update() {
        int a = inf;
        FOR(i, 1, n) if (!T[i]) a = min(a, slack[i]);
        FOR(i, 1, n) {
            if (S[i]) Lx[i] -= a;
            if (T[i]) Ly[i] += a;
        }
    }

    int solve() {
        FOR(i, 1, n) {
            left[i] = Lx[i] = Ly[i] = 0;
            FOR(j, 1, n) Lx[i] = max(Lx[i], W[i][j]);
        }
        FOR(i, 1, n) {
            FOR(j, 1, n) slack[j] = inf;
            for (;;) {
                FOR(j, 1, n) S[j] = T[j] = false;
                if (match(i)) break;
                update();
            }
        }
        FOR(i, 1, n) if (!left[i] || W[left[i]][i] == -inf) return -1;
        int ans = 0;
        FOR(i, 1, n) ans += Lx[i] + Ly[i];
        return ans;
    }
};

KM solver;
char mat[maxw][maxw];
bool vis[maxw][maxw];
int dist[maxw][maxw];
int T, h, w;

pii a[maxn], b[maxn];

void bfs(pii cur) {
    reset(vis, 0);
    reset(dist, 0x3f);
    vis[cur._1][cur._2] = true;
    dist[cur._1][cur._2] = 0;
    queue<pii> q;
    q.push(cur);
    while (!q.empty()) {
        pii u = q.front();
        q.pop();
        int x = u._1, y = u._2;
        for (auto &diff : dir) {
            int nx = x + diff._1, ny = y + diff._2;
            if (nx < 1 || nx > h || ny < 1 || ny > w || vis[nx][ny] || mat[nx][ny] == '#') continue;
            vis[nx][ny] = true;
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }
}

int main() {
    scanf("%d", &T);
    while (T--){
        scanf("%d%d", &h, &w);
        FOR(i, 1, h) scanf("%s", mat[i] + 1);
        int n = 0, m = 0;
        FOR(i, 1, h) FOR(j, 1, w) {
                if (mat[i][j] == 'B') a[++n] = {i, j};
                else if (mat[i][j] == 'X') b[++m] = {i, j};
            }
        assert(n == m);
        solver.init(m);
        FOR(i, 1, n) {
            bfs(a[i]);
            FOR(j, 1, m) solver.addEdge(i, j, -dist[b[j]._1][b[j]._2]);
        }
        int ans = -solver.solve();
        printf("%d\n", ans);
    }
    return 0;
}
