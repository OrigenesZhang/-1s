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
#define mp make_pair
#define _1 first
#define _2 second

int T, n, a, sum;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        bool flag = true;
        sum = 0;
        REP(i, n) {
            scanf("%d", &a);
            if (a > 1) flag = false;
            sum ^= a;
        }
        if (flag) sum = (n & 1) ^ 1;
        puts(sum ? "John" : "Brother");
    }
    return 0;
}
