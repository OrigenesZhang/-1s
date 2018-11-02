#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;

const int N = 10;
const double eps = 5e-8;

//double dp[N][N][N][N];

const int dr[] = { -2, -2, -1, -1, 1, 1, 2, 2 };
const int dc[] = { -1, 1, -2, 2, -2, 2, -1, 1 };
int ans[N][N][N][N];

double dfs(int r1, int c1, int r2, int c2, double cur) {
    if (r1 == r2 && c1 == c2) return 0;
    if (cur < eps) return 0.5;
    int tot = 0;
    for (int i = 0; i < 8; i++) {
        int rr = r1 + dr[i], cc = c1 + dc[i];
        if (rr >= 1 && rr <= 8 && cc >= 1 && cc <= 8) tot++;
    }

    double p = (double)1 / tot;
    double ans = 0;
    for (int i = 0; i < 8; i++) {
        int rr = r1 + dr[i], cc = c1 + dc[i];
        if (rr >= 1 && rr <= 8 && cc >= 1 && cc <= 8) ans += p * (1 - dfs(r2, c2, rr, cc, cur * p));
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    double cur = dfs(r1, c1, r2, c2, 1);
    double rhs = 1 - cur;
    if (abs(cur - rhs) < 1e-6) cout << "draw\n";
    else if (cur > rhs) cout << "white\n";
    else cout << "black\n";
    return 0;
}