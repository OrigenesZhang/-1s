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

const int maxn = 112345;
const int A = 60;
const int B = 10;
const int tries = 30;

ll f[5], K, fcnt;

ll mul(ll a, ll b, ll p) {
  a %= p;
  b %= p;
  ll res = 0;
  while (b > 0) {
    if (b & 1) {
      res += a;
      if (res >= p) res -= p;
    }
    a <<= 1;
    if (a >= p) a -= p;
    b >>= 1;
  }
  return res;
}

ll fast_pow(ll x, ll k, ll p) {
  ll res = 1;
  while (k) {
    if (k & 1) res = mul(res, x, p);
    x = mul(x, x, p);
    k >>= 1;
  }
  return res;
}

bool check(ll a, ll n, ll x, ll t) {
  ll res = fast_pow(a, x, n), last = res;
  for (int i = 1; i <= t; i++) {
    res = mul(res, res, n);
    if (res == 1 && last != 1 && last != n - 1)
      return true;
    last = res;
  }
  return res != 1;
}

bool miller_rabin(ll n) {
  ll x = n - 1, t = 0;
  while (!(x & 1)) {
    x >>= 1;
    t++;
  }
  bool flag = true;
  if (t >= 1 && (x & 1)) {
    for (int i = 0; i < tries; i++) {
      ll a = rand() % (n - 1) + 1;
      if (check(a, n, x, t)) {
        flag = true;
        break;
      }
      flag = false;
    }
  }
  return flag && n != 2;
}

ll g(ll x, ll n) {
  return (mul(x, x, n) + K) % n;
}

ll gcd(ll a, ll b) {
  return b ? gcd(b, a % b) : a;
}

ll rho(ll n) {
  ll x = 2, y = x, upp = 2, d = 1;
  K = rand() % (n - 1) + 1;
  while (d == 1) {
    for (int i = 1; i <= upp && d <= 1; i++) {
      x = g(x, n);
      d = gcd(abs(x - y), n);
    }
    upp <<= 1;
    y = x;
  }
  return d;
}

void fac(ll n) {
  if (!miller_rabin(n)) {
    f[fcnt++] = n;
    return;
  }
  ll p = n;
  while (p >= n) p = rho(p);
  fac(p);
  fac(n / p);
}

int n, k;
ll a[maxn];
bool vis[1123456];
vector<int> primes;
map<ll, int> cnt;

void get(int m, int lo) {
  FOR(i, 1, m) {
    vector<pair<ll, int>> fac;
    for (auto p : primes) if (a[i] % p == 0) {
      int cur = 0;
      while (a[i] % p == 0) cur++, a[i] /= p;
      fac.eb(p, cur);
    }
    if (a[i] != 1) {
      if (a[i] < 1e12) fac.eb(a[i], 1);
      else if (!miller_rabin(a[i])) fac.eb(a[i], 1);
      else {
        fcnt = 0;
        ::fac(a[i]);
        assert(fcnt == 2);
        fac.eb(f[0], 1);
        fac.eb(f[1], 1);
      }
    }
    queue<pair<ll, int>> q;
    q.emplace(1, 0);
    while (!q.empty()) {
      auto _ = q.front();
      q.pop();
      ll num = _._1;
      int pos = _._2;
      if (pos == fac.size()) {
        cnt[num]++;
        continue;
      }
      ll now = 1;
      q.emplace(num * now, pos + 1);
      FOR(pw, 1, int(fac[pos]._2)) {
        now *= fac[pos]._1;
        q.emplace(num * now, pos + 1);
      }
    }
  }
  map<ll, int> tmp;
  for (auto _ : cnt) if (_._2 >= lo) tmp.emplace(_);
  swap(tmp, cnt);
}

int main() {
  srand(time(NULL));
  scanf("%d%d", &n, &k);
  FOR(i, 1, n) scanf("%lld", a + i);
  FOR(i, 2, int(1e6)) if (!vis[i]) {
      primes.eb(i);
      for (ll j = ll(i) * i; j <= 1e6; j += i) vis[j] = true;
    }
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  shuffle(a + 1, a + n + 1, rng);
  if (n <= A) {
    get(n, n - k);
    printf("%lld", cnt.rbegin()->_1);
    return 0;
  } else get(A, B);
  for (auto it = cnt.rbegin(); it != cnt.rend(); it++) {
    if (A - it->_2 > k) continue;
    int allowed = k - A + it->_2;
    bool ok = true;
    FOR(i, A + 1, n) {
      if (a[i] % it->_1) allowed--;
      if (allowed < 0) {
        ok = false;
        break;
      }
    }
    if (ok) {
      printf("%lld\n", it->_1);
      return 0;
    }
  }
}