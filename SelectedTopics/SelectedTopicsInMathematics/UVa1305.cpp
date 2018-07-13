// 玄学题
// 这个解法在UVa上过不了POJ上能过
// POJ有SPJ应该是针对母函数的 据说是e的精度问题
// 题目中的小数点后三位可以把N缩小到1000 or 1001然后dp的复杂度可以承受

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

int N, M, C;
double c[maxn][maxn];

void init() {
    REP(i, maxn) c[i][0] = 1;
    FOR(i, 1, maxn - 1) FOR(j, 1, i) c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
}

int main() {
    init();
    while (scanf("%d", &C) == 1) {
        if (!C) break;
        scanf("%d%d", &N, &M);
        if (M > C || M > N || M + N & 1) {
            puts("0.000");
            continue;
        }
        double ans = 0;
        REP(i, M + 1) REP(j, C - M + 1) {
                double cur = (i + j << 1) - C;
                if (M + i & 1) ans -= pow(cur / C, N) * c[M][i] * c[C - M][j];
                else ans += pow(cur / C, N) * c[M][i] * c[C - M][j];
            }
        ans /= pow(2.0, C);
        ans *= c[C][M];
        printf("%.3lf\n", ans);
    }
    return 0;
}
