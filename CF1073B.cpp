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

const int maxn = 212345;

int n, a[maxn], b;
set<int> s;

int main() {
    scanf("%d", &n);
    FOR(i, 1, n) scanf("%d", a + i);
    int now = 1;
    FOR(i, 1, n) {
        scanf("%d", &b);
        if (s.count(b)) {
            printf("0 ");
            continue;
        }
        FOR(j, now, n) {
            s.insert(a[j]);
            if (a[j] == b) {
                printf("%d ", j - now + 1);
                now = j + 1;
                break;
            }
        }
    }
    return 0;
}
