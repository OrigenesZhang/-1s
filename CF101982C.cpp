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
const ll MOD = 998244353;

ll dp[maxn][maxn], cnt[maxn];
int n, k, tot;
map<int, int> tmp;

int main() {
    scanf("%d%d", &n, &k);
    FOR(i, 1, n) {
        int now;
        scanf("%d", &now);
        tmp[now]++;
    }
    for (const auto & it : tmp) cnt[++tot] = it._2;
    dp[0][0] = 1;
    FOR(i, 1, tot) {
        dp[i][0] = 1;
        FOR(j, 1, tot) dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1] * cnt[i]) % MOD;
    }
    printf("%lld\n", dp[tot][k]);
}