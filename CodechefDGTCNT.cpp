// 状态有趣
// 复杂度 O(digit^2*sigma_size^3)
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

int a[maxn], T, pcnt[maxn];
ll C[maxn][maxn];

void init() {
    REP(i, maxn - 3) {
        C[i][0] = C[i][i] = 1;
        FOR(j, 1, i - 1)
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
    }
}

ll cal(int n, bool flag) {
    if (!n && !flag) return 0;
    vector<ll> tot(n + 1, 0);
    tot[0] = 1;
    REP(d, 10) ROF(cur, n, 0) {
            ll now = tot[cur];
            tot[cur] = 0;
            REP(cnt, n - cur + 1) REP(pv, cnt + 1) {
                    if ((flag || d) && pcnt[d] + cnt == a[d]) continue;
                    if (!flag && !d && pcnt[d] + cnt - pv == a[d]) continue;
                    if (n - cur == pv) tot[cur + cnt] += now;
                    else if (n - cur - pv >= 1) tot[cur + cnt] += now * C[n - cur - pv - 1][cnt - pv];
                }
        }
    return tot[n];
}

ll solve(ll upp) {
    reset(pcnt, 0);
    vector<int> num;
    while (upp) {
        num.pb(upp % 10);
        upp /= 10;
    }
    reverse(all(num));
    ll ret = 0;
    REP(pos, int(num.size())) {
        REP(i, num[pos] + (pos == int(num.size()) - 1)) {
            if (pos || i) pcnt[i]++;
            ret += cal(int(num.size()) - pos - 1, pos || i);
            if (pos || i) pcnt[i]--;
        }
        pcnt[num[pos]]++;
    }
    return ret;
}

int main() {
    init();
    scanf("%d", &T);
    while (T--) {
        ll L, R;
        scanf("%lld%lld", &L, &R);
        REP(i, 10) scanf("%d", &a[i]);
        printf("%lld\n", solve(R) - solve(L - 1));
    }
    return 0;
}
