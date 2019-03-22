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

int T, N, a;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        int cnt = 0;
        REP(i, N) {
            scanf("%d", &a);
            if (cnt < 2) a > 1 ? cnt = 2 : cnt ^= 1; // 多组testcase要记得冲马桶的
        }
        puts(cnt ? "poopi" : "piloop");
    }
    return 0;
}
