#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define ROF(i, a, b) for (int i = (a); i >= (b); i--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x)*(x))
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end())
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)
 
const double p = 1e-15;
const double pw = -2.0 / 3;
 
int lo, hi;
 
void solve() {
    double ans = 0;
    FOR(i, lo, hi) {
        auto tmp = pow(i, pw);
        ans += tmp - tmp / (3 * i) * p;
    }
    printf("%.5E\n", ans * p / 3);
}
 
int main() {
    while (scanf("%d%d", &lo, &hi) == 2 && lo) solve();
}