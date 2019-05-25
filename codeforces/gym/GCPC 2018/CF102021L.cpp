#include <bits/stdc++.h>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REP(i, n) FOR(i, 0, (n) - 1)

const int maxn = 112;

int h, w;
int c[maxn][maxn];
char ans[maxn][maxn];

int main() {
    scanf("%d%d", &h, &w);
    REP(i, h + 2) REP(j, w + 2) scanf("%d", &c[i][j]);
    memset(ans, '.', sizeof(ans));
    FOR(i, 1, h) FOR(j, 1, w) if (c[i - 1][j - 1] > 0) {
        ans[i][j] = 'X';
        FOR(ii, -1, 1) FOR(jj, -1, 1) c[i + ii][j + jj]--;
    }
    REP(i, h + 2) REP(j, w + 2) if (c[i][j]) {
        puts("impossible");
        return 0;
    }
    FOR(i, 1, h) {
        FOR(j, 1, w) putchar(ans[i][j]);
        puts("");
    }
}