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
    int n1, n2, n3, nm, x1, x2, x3;
    scanf("%d%d%d", &n1, &n2, &n3);
    scanf("%d%d%d", &x1, &x2, &x3);
    nm = min(min(n1, n2), n3);
    REP(i, nm) {
        long long p = ll(i) * i * i;
        if (p % n1 == x1 && p % n2 == x2 && p % n3 == x3) {
            printf("%d\n", i);
            return;
        }
    }
}
 
int main() {
    int T;
    scanf("%d", &T);
    while (T--) solve();
}