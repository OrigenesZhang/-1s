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
 
const int maxn = 212345;
const int inf = 0x3f3f3f3f;
 
struct SA {
  int sa[maxn], rank[maxn], height[maxn], t[maxn], t2[maxn], c[maxn];
 
  void build(const int *s, int n, int m) {
    int *x = t, *y = t2;
    REP(i, m) c[i] = 0;
    REP(i, n) c[x[i] = s[i]]++;
    FOR(i, 1, m - 1) c[i] += c[i - 1];
    ROF(i, n - 1, 0) sa[--c[x[i]]] = i;
    for (int k = 1; k <= n; k <<= 1) {
      int p = 0;
      FOR(i, n - k, n - 1) y[p++] = i;
      REP(i, n) if (sa[i] >= k) y[p++] = sa[i] - k;
      REP(i, m) c[i] = 0;
      REP(i, n) c[x[y[i]]]++;
      FOR(i, 1, m - 1) c[i] += c[i - 1];
      ROF(i, n - 1, 0) sa[--c[x[y[i]]]] = y[i];
      swap(x, y);
      p = 1; x[sa[0]] = 0;
      FOR(i, 1, n - 1)
        x[sa[i]] = y[sa[i - 1]] == y[sa[i]] && y[sa[i - 1] + k] == y[sa[i] + k] ? p - 1 : p++;
      if (p >= n) break;
      m = p;
    }
  }
 
  void getHeight(const int *s, int n) {
    REP(i, n) rank[sa[i]] = i;
    int k = 0;
    REP(i, n) {
      if (k) k--;
      int j = sa[rank[i] - 1];
      while (s[i + k] == s[j + k]) k++;
      height[rank[i]] = k;
    }
  }
};
 
int bit[maxn], a[maxn], id[maxn], nxt[maxn], f[maxn][20];
ll sum[maxn];
 
void solve() {
  int n;
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%d", a + i);
  memcpy(id + 1, a + 1, n * sizeof(int));
  sort(id + 1, id + n + 1);
  int tot = unique(id + 1, id + n + 1) - id - 1;
  FOR(i, 1, n) a[i] = lower_bound(id + 1, id + tot + 1, a[i]) - id;
  a[n + 1] = inf;
  stack<int> s;
  s.emplace(n + 1);
  ROF(i, n, 1) {
    while (a[i] >= a[s.top()]) s.pop();
    nxt[i] = f[i][0] = s.top();
    s.emplace(i);
  }
  f[n + 1][0] = n + 1;
  for (int j = 1; (1 << j) <= n + 1; j++) FOR(i, 1, n + 1) f[i][j] = f[f[i][j - 1]][j - 1];
  sum[n] = id[a[n]], sum[n + 1] = 0;
  ROF(i, n - 1, 1) sum[i] = ll(id[a[i]]) * (nxt[i] - i) + sum[nxt[i]];
  FOR(i, 1, n) a[i - 1] = a[i];
  a[n] = 0;
  static SA sa;
  sa.build(a, n + 1, tot + 2);
  sa.getHeight(a, n + 1);
  ll ans = 0;
  FOR(i, 1, n) {
    int h = sa.height[i];
    if (!h) {
      ans += sum[sa.sa[i] + 1];
      continue;
    }
    int last = sa.sa[i] + h, lo = bit[n - sa.sa[i]], pos = sa.sa[i] + 1;
    ROF(j, lo, 0) if (f[pos][j] <= last) pos = f[pos][j];
    ans += ll(id[a[pos - 1]]) * (f[pos][0] - last - 1) + sum[f[pos][0]];
  }
  printf("%lld\n", ans);
}
 
int main() {
  for (int i = 1; (1 << i) < maxn; i++) bit[1 << i] = 1;
  FOR(i, 1, maxn - 1) bit[i] += bit[i - 1];
  int T;
  scanf("%d", &T);
  while (T--) solve();
}