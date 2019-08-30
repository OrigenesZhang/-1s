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

template <class T>
void read(T &x) {
  static char ch;static bool neg;
  for(ch=neg=0;ch<'0' || '9'<ch;neg|=ch=='-',ch=getchar());
  for(x=0;'0'<=ch && ch<='9';(x*=10)+=ch-'0',ch=getchar());
  x=neg?-x:x;
}

const int MOD = 998244353;
const int maxn = 11234567;
const int inv6 = 166374059;

__int128 n;
int phi[maxn];
bool vis[maxn];
vector<int> primes;

void init() {
  phi[1] = 1;
  FOR(i, 2, maxn - 1) {
    if (!vis[i]) {
      phi[i] = i - 1;
      primes.eb(i);
    }
    for (auto j : primes) {
      if (ll(j) * i > maxn - 1) break;
      vis[i * j] = true;
      if (i % j == 0) {
        phi[i * j] = phi[i] * j;
        break;
      }
      phi[i * j] = phi[i] * (j - 1);
    }
  }
}

int sqrt3() {
  int lo = 1, hi = maxn - 1;
  while (lo < hi - 1) {
    int mi = lo + hi >> 1;
    if (__int128(mi) * mi * mi <= n) lo = mi;
    else hi = mi - 1;
  }
  return __int128(hi) * hi * hi <= n ? hi : lo;
}

inline int add(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}

inline int two(ll x) {
  return x * (x + 1) / 2 % MOD;
}

inline int three(ll x) {
  return x * (x + 1) % MOD * (2 * x + 1) % MOD * inv6 % MOD;
}

int solve1(int r, __int128 m) {
  int ret = r;
  for (int i = 1; sqr(i) <= r; i++) if (r % i == 0) {
      ret = add(ret, m / i * phi[i] % MOD);
      if (sqr(i) != r) ret = add(ret, m / (r / i) * phi[r / i] % MOD);
    }
  return ret;
}

int solve2(int r) {
  int ret = 0;
  FOR(i, 1, r)
    ret = add(ret, phi[i] * (3LL * i * three(r / i) % MOD + 3LL * two(r / i) % MOD + r / i) % MOD);
  return ret;
}

int main() {
  init();
  int T;
  scanf("%d", &T);
  while (T--) {
    read(n);
    int r = sqrt3();
    printf("%d\n", add(solve1(r, n - __int128(r) * r * r), solve2(r - 1)));
  }
}
