// 打印路径好难写
// 这题似乎是WF签到难度
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

ll dp[maxn][2][2], pw[maxn];
pair<pii, pii> pre[maxn][2][2];

int n;
vector<int> a, b, ans;

ll dfs(int, bool, bool, bool);

void update(ll &ret, pair<pii, pii> &pre, int pos, bool lb, bool ub, bool zero, int dig) {
    bool flag = zero && !dig;
    if (!flag) {
        if (ret < dfs(pos, lb, ub, false) * dig) {
            ret = dfs(pos, lb, ub, false) * dig;
            pre = mp(mp(pos, dig), mp(lb, ub));
        }
    } else {
        if (ret < dfs(pos, lb, ub, true)) {
            ret = dfs(pos, lb, ub, true);
            pre = mp(mp(pos, 0), mp(lb, ub));
        }
    }
}

ll dfs(int pos, bool lb, bool ub, bool zero) {
    if (pos == n - 1) {
        int ret = ub ? 9 : b[n - 1];
        pre[pos][lb][ub] = mp(mp(n, ret), mp(-1, -1));
        return ret;
    }
    ll &ret = dp[pos][lb][ub];
    if (ret != -1) return ret;
    if (lb && ub) return ret = pw[n - pos];
    int lmtl = a[pos], lmth = b[pos];
    if (lb) lmtl = 0;
    if (ub) lmth = 9;
    if (lmth - 1 >= lmtl + 1)
        update(ret, pre[pos][lb][ub], pos + 1, true, true, zero, lmth - 1);
    update(ret, pre[pos][lb][ub], pos + 1, lb, (lmth > lmtl) || ub, zero, lmtl);
    update(ret, pre[pos][lb][ub], pos + 1, (lmth > lmtl) || lb, ub, zero, lmth);
    return ret;
}

void print(int pos, bool lb, bool ub) {
    if (pre[pos][lb][ub] == mp(mp(-1, -1), mp(-1, -1))) {
        while (pos < n) {
            ans.pb(9);
            pos++;
        }
        return;
    }
    ans.pb(pre[pos][lb][ub]._1._2);
    print(pre[pos][lb][ub]._1._1, pre[pos][lb][ub]._2._1, pre[pos][lb][ub]._2._2);
}

int main() {
    ll A, B;
    scanf("%lld%lld", &A, &B);
    while (B) {
        b.pb(B % 10);
        B /= 10;
    }
    reverse(all(b));
    while (A) {
        a.pb(A % 10);
        A /= 10;
    }
    while (a.size() < b.size()) a.pb(0);
    reverse(all(a));
    n = a.size();
    reset(dp, -1);
    reset(pre, -1);
    pw[0] = 1;
    FOR(i, 1, maxn - 1) pw[i] = pw[i - 1] * 9;
    dfs(0, false, false, true);
    print(0, false, false);
    bool flag = false;
    for (int u : ans) {
        if (u) flag = true;
        if (flag) printf("%d", u);
    }
    puts("");
    return 0;
}
