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
 
void solve() {
    int n;
    scanf("%d", &n);
    vector<int> h(n);
    for (auto &x : h) scanf("%d", &x);
    int ans = 0, pre = -100;
    REP(i, n) {
        if (abs(h[i] - pre) > 10) {
            ans++;
            pre = h[i] + 10;
        }
    }
    printf("%d\n", ans);
}
 
int main() {
    int T; scanf("%d", &T);
    while (T--) solve();
}