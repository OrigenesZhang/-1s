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

int n, p, s;

int main() {
    while (scanf("%d", &n) == 1) {
        if (!n) break;
        s = 0;
        REP(i, n) {
            scanf("%d", &p);
            s ^= p;
        }
        puts(s ? "Yes" : "No");
    }
    return 0;
}
