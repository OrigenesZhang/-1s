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

using ull = unsigned long long;

const int maxn = 41234567;

ull phi[maxn], vis[maxn];
vector<ull> primes;
unordered_map<ull, ull> memo;

inline ull get(ull x) {
  return (x & 1u) ? ((x + 1) / 2 * x) : (x / 2 * (x + 1));
}

ull S(ull x) {
  if (x <= 4e7) return phi[x];
  if (memo.count(x)) return memo[x];
  ull ret = get(x);
  for (ull i = 2; i <= x; i++) {
    ull j = x / (x / i);
    ret -= (j - i + 1) * S(x / i);
    i = j;
  }
  return memo[x] = ret;
}

int main() {
  phi[1] = 1;
  for (ull i = 2; i <= 4e7; i++) {
    if (!vis[i]) {
      primes.eb(i);
      phi[i] = i - 1;
      vis[i] = i;
    }
    for (auto j : primes) {
      if (i * j > 4e7) break;
      vis[i * j] = j;
      if (vis[i] == j) {
        phi[i * j] = phi[i] * j;
        break;
      }
      phi[i * j] = phi[i] * phi[j];
    }
  }
  for (ull i = 2; i <= 4e7; i++) phi[i] += phi[i - 1];
  int T;
  ull n;
  scanf("%d", &T);
  while (T--) {
    scanf("%llu", &n);
    ull ans = 0;
    for (ull i = 1; i <= n; i++) {
      ull j = n / (n / i);
      ans += (S(n / i) - 1) * (get(j) - get(i - 1));
      i = j;
    }
    printf("%llu\n", ans);
  }
}
