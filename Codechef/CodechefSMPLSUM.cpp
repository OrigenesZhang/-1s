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
#define uni(x) (x).erase(unique(all(x)), (x).end())
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

const int maxn = 11234567;

int vis[maxn];
ll f[maxn], g[maxn];
vector<int> primes;

int main() {
  f[1] = 1;
  FOR(i, 2, 1e7 + 5) {
    if (!vis[i]) {
      primes.eb(i);
      f[i] = ll(i) * (i - 1) + 1;
      g[i] = ll(i) * i * i;
      vis[i] = i;
    }
    for (auto j : primes) {
      if (i * ll(j) > 1e7 + 5) break;
      vis[i * j] = j;
      if (vis[i] == j) {
        f[i * j] = f[i] * (j + 1) / (g[i] + 1) * (g[i] * j * j + 1) / (j + 1);
        g[i * j] = g[i] * j * j;
        break;
      }
      f[i * j] = f[i] * f[j];
      g[i * j] = g[j];
    }
  }
  int T, n;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    printf("%lld\n", f[n]);
  }
}
