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

const int maxn = 123;
const double inf = 1e15;
const double eps = 1e-9;

int dcmp(double x) {
    return abs(x) > eps ? (x > 0 ? 1 : -1) : 0;
}

struct KM {
    int n;  // number of vertices on each side (tot = 2 * n)
    double W[maxn][maxn];  // weight of the edges
    double Lx[maxn], Ly[maxn];     // potential of each point, indexing from 1 onwards
    int left[maxn];     // left[v] = the index of the vertex which vertex v of the right is matching to
    double slack[maxn];    // if v is not in T and u is in S, slack[v] = min(Lx[u] + Ly[v] - w[u][v])
    bool S[maxn], T[maxn];  // Whether vertex is in an alternating path

    void init(int n) {
        this->n = n;
        FOR(i, 1, n) FOR(j, 1, n) W[i][j] = -inf;
    }

    void addEdge(int u, int v, double w) {
        W[u][v] = max(W[u][v], w);
    }

    bool match(int u) {
        S[u] = true;
        FOR(v, 1, n) if (!T[v]) {
                if (dcmp(Lx[u] + Ly[v] - W[u][v]) == 0) {
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
        double a = inf;
        FOR(i, 1, n) if (!T[i]) a = min(a, slack[i]);
        FOR(i, 1, n) {
            if (S[i]) Lx[i] -= a;
            if (T[i]) Ly[i] += a;
        }
    }

    int solve() {
        FOR(i, 1, n) {
            left[i] = 0;
            Lx[i] = Ly[i] = 0;
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
        FOR(i, 1, n) if (!left[i] || W[left[i]][i] < -inf / 2) return inf;
        int ans = 0;
        FOR(i, 1, n) ans += Lx[i] + Ly[i];
        return ans;
    }
};

pii l[maxn], r[maxn];
KM solver;
int n;

double dist(pii a, pii b) {
    return sqrt(sqr(a._1 - b._1) + sqr(a._2 - b._2));
}

int main() {
    while (scanf("%d", &n) == 1) {
        solver.init(n);
        FOR(i, 1, n) scanf("%d%d", &r[i]._1, &r[i]._2);
        FOR(i, 1, n) scanf("%d%d", &l[i]._1, &l[i]._2);
        FOR(i, 1, n) FOR(j, 1, n)
                solver.addEdge(i, j, -dist(l[i], r[j]));
        solver.solve();
        FOR(i, 1, n)
            printf("%d\n", solver.left[i]);
        puts("");
    }
    return 0;
}
