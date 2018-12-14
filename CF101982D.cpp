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

const int maxk = 1123;
const int MOD = 1e9 + 9;
const int maxb = 130;

bool vis[maxb][maxk][maxb][2];
int dp[maxb][maxk][maxb][2];
int k, b, tot[maxb];

int dfs(int pos, int rem, int cnt, bool flag) {
    if (pos >= b) return rem % k ? 0 : cnt;
    if (vis[pos][rem][cnt][flag]) return dp[pos][rem][cnt][flag];
    vis[pos][rem][cnt][flag] = true;
    int &ret = dp[pos][rem][cnt][flag];
    if (flag) REP(i, 2) ret = (ret + dfs(pos + 1, (rem % k + i * tot[b - 1 - pos] % k) % k, cnt + i, true)) % MOD;
    else {
        ret = (ret + dfs(pos + 1, rem % k, cnt, true)) % MOD;
        ret = (ret + dfs(pos + 1, (rem % k + tot[b - 1 - pos] % k) % k, cnt + 1, false)) % MOD;
    }
    return ret;
}

int main() {
    scanf("%d%d", &k, &b);
    tot[0] = 1 % k;
    FOR(i, 1, maxb - 1) tot[i] = tot[i - 1] * 2 % k;
    printf("%d\n", dfs(0, 0, 0, false));
}