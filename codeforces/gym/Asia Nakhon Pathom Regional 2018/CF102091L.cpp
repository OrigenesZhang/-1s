#include <bits/stdc++.h>
using namespace std;
 
const int N = 1123;
 
int n, m;
int sum[N][N], a[N][N], f[N][N];
 
int gech() {
    int c;
    for (;;) {
        c = getchar();
        if (isdigit(c)) return c - '0';
    }
}
 
inline int my_sum(int i, int j, int len) {
    int ii = i + len - 1, jj = j + len - 1;
    return sum[ii][jj] - sum[i - 1][jj] - sum[ii][j - 1] + sum[i - 1][j - 1];
}
 
int main() {
    int T;
    scanf("%d", &T);
 
    while (T--) {
        scanf("%d%d", &n, &m);
 
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) a[i][j] = gech();
        }
 
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
            }
        }
 
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int len = 1;
                len = max(len, f[i - 1][j] - 1);
                len = max(len, f[i][j - 1] - 1);
 
                while (i + len <= n && j + len <= m && my_sum(i, j, len + 1) <= 1) ++len;
 
                f[i][j] = len;
                ans = max(ans, len);
            }
        }
 
        printf("%d\n", ans);
    }
    return 0;
}