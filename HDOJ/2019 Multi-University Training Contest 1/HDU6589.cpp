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

const int MOD = 998244353;
const int maxn = 412345;
const int maxm = 1123456;

int inv[maxm], fac[maxm], ifac[maxm];

ll pow_mod(ll x, ll k) {
  ll ret = 1;
  while (k) {
    if (k & 1) ret = ret * x % MOD;
    x = x * x % MOD;
    k >>= 1;
  }
  return ret;
}

struct NTT {
  int A[maxn], B[maxn], b[maxn], c[maxn];

  void FFT(int *a, int n, int f) {
    for (int i = 1, j = n >> 1, k; i < n - 1; i++, j ^= k) {
      if (i < j) swap(a[i], a[j]);
      for (k = n >> 1; j & k; j ^= k, k >>= 1);
    }
    for (int k = 1; k < n; k <<= 1) {
      int gn = pow_mod(3, (MOD - 1) / (k << 1));
      if (f == -1) gn = pow_mod(gn, MOD - 2);
      for (int i = 0; i < n; i += k << 1) {
        int g = 1;
        for (int j = i; j < i + k; j++, g = (ll) g * gn % MOD) {
          int x = a[j], y = (ll) g * a[j + k] % MOD;
          a[j] = ((ll) x + y) % MOD, a[j + k] = ((ll) x - y + MOD) % MOD;
        }
      }
    }
    if (!~f) REP(i, n) a[i] = (ll) a[i] * inv[n] % MOD;
  }

  void mul(int *a, int *b, int *c, int n) {
    REP(i, n) A[i] = a[i], B[i] = b[i], A[i + n] = B[i + n] = 0;
    n <<= 1;
    FFT(A, n, 1), FFT(B, n, 1);
    REP(i, n) c[i] = (ll) A[i] * B[i] % MOD;
    FFT(c, n, -1);
  }
} ntt;

inline int C(int n, int m) {
  if (m < 0 || m > n) return 0;
  return ll(fac[n]) * ifac[m] % MOD * ifac[n - m] % MOD;
}

void raise(int *v, int n, int x, int pw) {
  fill(v, v + n, 0);
  if (!pw) v[0] = 1;
  else for (int i = 0; i < n; i += x) v[i] = C(i / x + pw - 1, pw - 1);
}

int w[3][maxn], a[maxn];

void solve() {
  int n, m;
  scanf("%d%d", &n, &m);
  REP(i, n) {
    scanf("%d", a + i);
    if (a[i] >= MOD) a[i] -= MOD;
  }
  int cnt[3] = {};
  while (m--) {
    int x;
    scanf("%d", &x);
    x--;
    cnt[x]++;
  }
  int N = 1;
  while (N < n) N <<= 1;
  REP(i, 3) raise(w[i], N, i + 1, cnt[i]);
  REP(i, 3) ntt.mul(a, w[i], a, N);
  ll ans = 0;
  REP(i, n) ans ^= (i + 1) * ll(a[i]);
  printf("%lld\n", ans);
}

int main() {
  int T;
  scanf("%d", &T);
  fac[0] = ifac[0] = inv[1] = 1;
  FOR(i, 2, maxm - 1) inv[i] = ll(MOD - MOD / i) * inv[MOD % i] % MOD;
  FOR(i, 1, maxm - 1) fac[i] = fac[i - 1] * ll(i) % MOD, ifac[i] = ifac[i - 1] * ll(inv[i]) % MOD;
  while (T--) solve();
}