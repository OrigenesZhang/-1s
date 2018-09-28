#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second

const int maxn = 25;

ll dp[maxn][maxn][2];
int a[maxn], tmp[maxn];

int T;

ll dfs(int st, int cur, int flag, int small) {
    if (cur < 0) return flag;
    if (!small && dp[st][cur][flag] != -1) return dp[st][cur][flag];
    int maxd = small ? a[cur] + 1 : 10;
    ll ret = 0;
    REP(i, maxd) {
        tmp[cur] = i;
        if (st == cur && !i)
            ret += dfs(st - 1, cur - 1, flag, small && i == maxd - 1);
        else if (flag && cur < (st + 1) / 2)
            ret += dfs(st, cur - 1, tmp[st - cur] == i, small && i == maxd - 1);
        else
            ret += dfs(st, cur - 1, flag, small && i == maxd - 1);
    }
    if (!small) dp[st][cur][flag] = ret;
    return ret;
}

ll solve(ll now) {
    int len = 0;
    while (now) {
        a[len++] = now % 10;
        now /= 10;
    }
    a[len] = 0;
    return dfs(len - 1, len - 1, 1, 1);
}

int main() {
    scanf("%d", &T);
    reset(dp, -1);
    FOR(cs, 1, T) {
        ll i, j;
        scanf("%lld%lld", &i, &j);
        if (i > j) swap(i, j);
        printf("Case %d: %lld\n", cs, solve(j) - solve(i - 1));
    }
    return 0;
}
