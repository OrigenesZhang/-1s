// KM算法求出的最佳完美匹配顶标最小
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
const int inf = 0x3f3f3f3f;

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
int N;

int main() {
    while (scanf("%d", &N) == 1) {
        solver.init(N);
        FOR(i, 1, N) FOR(j, 1, N) {
                int w;
                scanf("%d", &w);
                solver.addEdge(i, j, w);
            }
        int ans = solver.solve();
        FOR(i, 1, N - 1) printf("%d ", solver.Lx[i]);
        printf("%d\n", solver.Lx[N]);
        FOR(i, 1, N - 1) printf("%d ", solver.Ly[i]);
        printf("%d\n", solver.Ly[N]);
        printf("%d\n", ans);
    }
    return 0;
}
