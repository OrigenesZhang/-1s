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

int n, m;
ll num, k;

int main() {
    scanf("%d%d", &n, &m);
    while (m--) {
        scanf("%lld%lld", &num, &k);
        k %= n;
        int sft1 = n - k, sft2 = k;
        ll mask = (1LL << sft1) - 1;
//        BUG(mask);
        ll ans = ((num & mask) << sft2) + ((num & (~mask)) >> sft1);
        printf("%lld\n", ans);
    }
    return 0;
}