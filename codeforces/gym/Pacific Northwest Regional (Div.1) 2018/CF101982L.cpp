#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second

const int maxn = 1234;

int n, a, b, s[maxn];

int main() {
    scanf("%d", &n);
    FOR(i, 1, n) {
        scanf("%d%d", &a, &b);
        s[a]++;
        s[b + 1]--;
    }
    int now = 0, ans = -1;
    REP(i, n + 1) {
        now += s[i];
        if (now == i) ans = max(ans, now);
    }
    printf("%d\n", ans);
}