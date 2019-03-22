// 模板题
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

const int maxn = 123;
const int maxm = 123;
const double inf = 1e20;
const double eps = 1e-10;

struct Simplex {
    int n, m;
    double a[maxm][maxn];
    int B[maxm], N[maxn];

    void pivot(int r, int c) {
        swap(N[c], B[r]);
        a[r][c] = 1 / a[r][c];
        REP(j, n + 1) if (j != c) a[r][j] *= a[r][c];
        REP(i, m + 1) if (i != r) {
                REP(j, n + 1) if (j != c) a[i][j] -= a[i][c] * a[r][j];
                a[i][c] = -a[i][c] * a[r][c];
            }
    }

    bool feasible() {
        while (true) {
            int r, c;
            double p = inf;
            REP(i, m) if (a[i][n] < p) p = a[r = i][n];
            if (p > -eps) return true;
            p = 0;
            REP(i, n) if (a[r][i] < p) p = a[r][c = i];
            if (p > -eps) return false;
            p = a[r][n] / a[r][c];
            FOR(i, r + 1, m - 1) if (a[i][c] > eps) {
                    double v = a[i][n] / a[i][c];
                    if (v < p) {
                        r = i;
                        p = v;
                    }
                }
            pivot(r, c);
        }
    }

    int solve(int n, int m, double x[maxn], double &ret) {
        this -> n = n;
        this -> m = m;
        REP(i, n) N[i] = i;
        REP(i, m) B[i] = n + i;
        if (!feasible()) return 0;
        while (true) {
            int r, c;
            double p = 0;
            REP(i, n) if (a[m][i] > p) p = a[m][c = i];
            if (p < eps) {
                REP(i, n) if (N[i] < n) x[N[i]] = 0;
                REP(i, m) if (B[i] < n) x[B[i]] = a[i][n];
                ret = -a[m][n];
                return 1;
            }
            p = inf;
            REP(i, m) if (a[i][c] > eps) {
                    double v = a[i][n] / a[i][c];
                    if (v < p) {
                        r = i;
                        p = v;
                    }
                }
            if (p > inf - 1) return -1;
            pivot(r, c);
        }
    }
}solver;

int n, m;

double x[maxm];

int main() {
    while (scanf("%d%d", &n, &m) == 2) {
        REP(i, n) scanf("%lf", &solver.a[m][i]);
        solver.a[m][n] = 0;
        REP(i, m) REP(j, n + 1) scanf("%lf", &solver.a[i][j]);
        double ans;
        solver.solve(n, m, x, ans);
        ans *= m;
        printf("Nasa can spend %d taka.\n", int(floor(ans + 1 - eps)));
    }
    return 0;
}
