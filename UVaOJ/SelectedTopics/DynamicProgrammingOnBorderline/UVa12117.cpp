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
const int maxs = 9;
const int maxn = 2134;
const ll MOD = 1000000000000;
ll dp[maxs][maxn];
int cs = 1, n;

// 7
void upd0(int col) {
    dp[0][col + 1] += dp[0][col];
    if (col < n - 1) {
        dp[2][col + 1] += dp[0][col];
        dp[5][col + 2] += dp[0][col];
        dp[6][col + 1] += dp[0][col];
        dp[3][col + 1] += dp[0][col];
        dp[1][col + 2] += dp[0][col];
        dp[4][col + 2] += dp[0][col];
    }
}

// 3
void upd1(int col) {
    dp[4][col + 1] += dp[1][col];
    dp[0][col + 1] += dp[1][col];
    if (col < n - 1) dp[8][col + 2] += dp[1][col];
}

// 1
void upd2(int col) {
    if (col < n - 1) dp[0][col + 2] += dp[2][col];
}

// 3
void upd3(int col) {
    if (col < n - 1) {
        dp[0][col + 2] += dp[3][col];
    }
    dp[6][col + 1] += dp[3][col];
    if (col < n - 2) {
        dp[7][col + 1] += dp[3][col];
    }
}

// 2
void upd4(int col) {
    dp[0][col + 1] += dp[4][col];
    if (col < n - 1) {
        dp[3][col + 1] += dp[4][col];
    }
}

// 2
void upd5(int col) {
    if (col < n - 1) {
        dp[2][col + 1] += dp[5][col];
    }
    dp[0][col + 1] += dp[5][col];
}

// 2
void upd6(int col) {
    if (col < n - 1) {
        dp[0][col + 2] += dp[6][col];
    }
    if (col < n - 2) {
        dp[1][col + 3] += dp[6][col];
    }
}

// 1
void upd7(int col) {
    if (col < n - 2) dp[6][col + 2] += dp[7][col];
}

// 1
void upd8(int col) {
    dp[4][col + 1] += dp[8][col];
}

void update(int s, int col) {
    dp[s][col] %= MOD;
    switch (s) {
        case 0:
            upd0(col);
            break;
        case 1:
            upd1(col);
            break;
        case 2:
            upd2(col);
            break;
        case 3:
            upd3(col);
            break;
        case 4:
            upd4(col);
            break;
        case 5:
            upd5(col);
            break;
        case 6:
            upd6(col);
            break;
        case 7:
            upd7(col);
            break;
        case 8:
            upd8(col);
            break;
        default:
            exit(-1);
    }
}

int main() {
    while (scanf("%d", &n) == 1) {
        if (!n) break;
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        REP(i, n) {
            REP(s, maxs) {
                if (!dp[s][i]) continue;
                update(s, i);
            }
        }
        printf("Case %d: %lld\n", cs++, dp[0][n] % MOD);
    }
    return 0;
}
