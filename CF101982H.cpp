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

const int maxn = 1e6;

bool vis[maxn + 123];
vector<int> p;
int x;

int solve(int x) {
    if (x < 4) return 0;
    if (x == 4) return 1;
    for (int now : p) {
        if (now == 2) continue;
        if (!vis[x - now]) return solve(x - now - now) + 1;
    }
}

int main() {
    FOR(i, 2, maxn) if (!vis[i]) {
            p.pb(i);
            for (ll j = ll(i) * i; j <= maxn; j += i) vis[j] = true;
        }
    cin >> x;
    cout << solve(x);
}

[close]
