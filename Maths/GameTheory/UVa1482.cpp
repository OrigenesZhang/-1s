#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define all(x) (x).begin(), (x).end()
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define mp make_pair
#define _1 first
#define _2 second

ll sg(ll x) {
    return x & 1 ? sg(x >> 1) : x >> 1;
}

int T, N;
ll a, sum;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        sum = 0;
        REP(i, N) {
            scanf("%lld", &a);
            sum ^= sg(a);
        }
        puts(sum ? "YES" : "NO");
    }
    return 0;
}
