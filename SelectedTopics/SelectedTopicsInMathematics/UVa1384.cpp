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

const int MOD = 10000;
ll N, P;
int cs = 1;

int main() {
    while (scanf("%lld%lld", &P, &N) == 2) {
        if (!P) break;
        ll ans = 1;
        while (N) {
            ll cur = N % P + 1;
            N /= P;
            ans = ans * cur % MOD;
        }
        printf("Case %d: %04lld\n", cs++, ans);
    }
    return 0;
}
