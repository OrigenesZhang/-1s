#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
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
 
const int maxn = 222;
 
int a[maxn], f[maxn][3];
 
void solve() {
    int n;
    scanf("%d", &n);
    reset(f, 0);
    FOR(i, 1, n) {
        scanf("%d", a + i);
        a[i] += 10;
    }
    sort(a + 1, a + n + 1);
    FOR(i, 1, n) {
        int now = a[i];
        ROF(j, 2, 1) f[now + 1][j] = max(f[now + 1][j - 1], max(f[now][j - 1], f[now - 1][j - 1])) + 1;
        ROF(j, 2, 0) f[now][j] = max(f[now][j], max(f[now - 1][j], f[now - 2][j])) + 1;
        ROF(j, 2, 1) f[now - 1][j] = max(max(f[now - 1][j - 1], f[now - 2][j - 1]), f[now - 3][j - 1]) + 1;
    }
    int ans = 0;
    FOR(i, 1, 215) REP(j, 3) chkmax(ans, f[i][j]);
    printf("%d\n", ans);
}
 
/*
 5
 10
 2 1 7 4 3 8 9 12 13 20
 3
 1 2 3
 4
 1 2 7 8
 3
 10 30 20
 2
 5 5
 */
 
int main() {
    int T;
    scanf("%d", &T);
    FOR(cs, 1, T) {
        printf("Case %d: ", cs);
        solve();
    }
}