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

const int maxn = 1e7;

bool vis[maxn + 123];
int mo[maxn + 123], primes[maxn + 123], pcnt;

void mobius() {
    mo[1] = 1;
    FOR(i, 2, maxn) {
        if (!vis[i]) mo[i] = -1, primes[pcnt++] = i;
        for (int j = 0; j < pcnt && ll(i) * primes[j] <= maxn; j++) {
            vis[i * primes[j]] = true;
            if (i % primes[j]) mo[i * primes[j]] = -mo[i];
            else {
                mo[i * primes[j]] = 0;
                break;
            }
        }
    }
    FOR(i, 2, maxn) mo[i] += mo[i - 1];
}

ll solve(int n, int m) {
    if (n > m) swap(n, m);
    ll ret = 0;
    for (int i = 1, j = 1; i <= n; i = j + 1) {
        j = min(n / (n / i), m / (m / i));
        ret += ll(mo[j] - mo[i - 1]) * (n / i) * (m / i);
    }
    return ret;
}

int a, b, c, d;

int main() {
    cin >> a >> b >> c >> d;
    mobius();
    cout << solve(b, d) - solve(a - 1, d) - solve(c - 1, b) + solve(a - 1, c - 1);
}