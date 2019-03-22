// 最小权匹配
// 可能费用流复杂度更优 【不确定】
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
int n, m, d[15], cs = 1;
vector<pii> res[15];

int main() {
    while (scanf("%d%d", &m, &n) == 2) {
        if (!n) break;
        solver.init(m * n);
        FOR(i, 1, m) scanf("%d", &d[i]);
        FOR(i, 1, n) {
            int k, s[15], t[15];
            scanf("%d", &k);
            REP(_k, k) scanf("%d%d", &s[_k], &t[_k]);
            s[k] = inf;
            t[k] = t[k - 1];
            FOR(j, 1, m) {
                if (d[j] < s[0]) continue;
                REP(now, k) {
                    if (d[j] < s[now + 1]) {
                        // count from the end
                        FOR(seq, 1, n) solver.addEdge((j - 1) * n + seq, i, -seq * t[now]);
                        break;
                    }
                }
            }
        }
        FOR(i, n + 1, n * m) FOR(j, 1, m * n) solver.addEdge(j, i, 0);
        int ans = -solver.solve();
        printf("Case %d\n", cs++);
        printf("Average turnaround time = %.2lf\n", double(ans) / n);
        FOR(disk, 1, m) res[disk].clear();
        FOR(i, 1, n) {
            int disk = solver.left[i] / n + 1, seq = solver.left[i] % n;
            if (!seq) {
                disk--;
                seq = n;
            }
            if (res[disk].size() < seq) res[disk].resize(seq);
            res[disk][seq - 1] = mp(i, -solver.W[solver.left[i]][i] / seq);
        }
        FOR(i, 1, m) reverse(all(res[i]));
        vector<pair<pii, pii>> vec;
        FOR(i, 1, m) {
            int t = 0;
            for (pii now : res[i]) {
                vec.pb(mp(mp(now._1, i), mp(t, t + now._2)));
                t += now._2;
            }
        }
        sort(all(vec));
        FOR(i, 1, n) {
            assert(i == vec[i - 1]._1._1);
            printf("Program %d runs in region %d from %d to %d\n", i, vec[i - 1]._1._2, vec[i - 1]._2._1,
                   vec[i - 1]._2._2);
        }
        puts("");
    }
    return 0;
}
