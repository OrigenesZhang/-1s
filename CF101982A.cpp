#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second

const int maxn = 1234;

char s[maxn], t[maxn];
int n, k, dp[maxn][maxn];

int main() {
    scanf("%d", &k);
    scanf("%s%s", s + 1, t + 1);
    n = strlen(s + 1);
    reset(dp, -1);
    dp[0][0] = 0;
    FOR(i, 1, n) REP(j, k + 1) {
            if (s[i] == t[i]) {
                if (dp[i - 1][j] >= 0) dp[i][j] = dp[i - 1][j];
                if (j && dp[i - 1][j - 1] >= 0) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
            } else {
                if (dp[i - 1][j] >= 0) dp[i][j] = dp[i - 1][j] + 1;
                if (j && dp[i - 1][j - 1] >= 0) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
            }
        }
    printf("%d\n", dp[n][k]);
}