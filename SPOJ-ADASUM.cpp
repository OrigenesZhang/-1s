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

const int maxn = 2123456;
const ll MOD = 1e9 + 7;

char s[maxn];

int main() {
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    ll ans = 0, acc = 0;
    acc = s[1] - '0';
    FOR(i, 2, n) {
        ans = (ans + acc) % MOD;
        acc = (acc * 10 + (s[i] - '0') * i) % MOD;
    }
    printf("%lld\n", (ans + acc) % MOD);
    return 0;
}
