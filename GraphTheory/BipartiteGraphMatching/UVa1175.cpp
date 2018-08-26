#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define sqr(x) ((x) * (x))
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define mp make_pair
#define _1 first
#define _2 second

const int maxn = 1234;

int pref[maxn][maxn], order[maxn][maxn], nxt[maxn];
int future_husband[maxn], future_wife[maxn];
queue<int> q;

void engage(int man, int woman) {
    int m = future_husband[woman];
    if (m) {
        future_wife[m] = 0;
        q.push(m);
    }
    future_wife[man] = woman;
    future_husband[woman] = man;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        FOR(i, 1, n) {
            FOR(j, 1, n) scanf("%d", &pref[i][j]);
            nxt[i] = 1;
            future_wife[i] = 0;
            q.push(i);
        }
        FOR(i, 1, n) {
            FOR(j, 1, n) {
                int x;
                scanf("%d", &x);
                order[i][x] = j;
            }
            future_husband[i] = 0;
        }
        while (!q.empty()) {
            int man = q.front(); q.pop();
            int woman = pref[man][nxt[man]++];
            if (!future_husband[woman]) engage(man, woman);
            else if (order[woman][man] < order[woman][future_husband[woman]]) engage(man, woman);
            else q.push(man);
        }
        if (!q.empty()) {
            queue<int> tmp;
            swap(q, tmp);
        }
        FOR(i, 1, n) printf("%d\n", future_wife[i]);
        if (T) puts("");
    }
    return 0;
}
