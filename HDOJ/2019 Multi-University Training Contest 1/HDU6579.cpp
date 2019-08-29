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

struct LinearBasis {
  int bit;
  vector<int> f, g;

  explicit LinearBasis(int bit) : bit(bit) {
    f = vector<int>(bit);
    g = vector<int>(bit);
  }

  void insert(int x, int pos) {
    ROF(i, bit - 1, 0) if (x & (1 << i)) {
      if (f[i]) {
        if (g[i] <= pos) {
          x ^= f[i];
          f[i] ^= x;
          swap(g[i], pos);
        } else x ^= f[i];
      } else {
        f[i] = x;
        g[i] = pos;
        break;
      }
    }
  }

  int query(int l) {
    int ret = 0;
    ROF(i, bit - 1, 0) if (g[i] >= l) chkmax(ret, ret ^ f[i]);
    return ret;
  }
};

void solve() {
  int n, m, lastans = 0;
  scanf("%d%d", &n, &m);
  vector<LinearBasis> base(n, LinearBasis(30));
  vector<int> a(n);
  for (auto &x : a) scanf("%d", &x);
  REP(i, n) {
    if (i) base[i] = base[i - 1];
    base[i].insert(a[i], i);
  }
  while (m--) {
    int op;
    scanf("%d", &op);
    if (!op) {
      int l, r;
      scanf("%d%d", &l, &r);
      l = (l ^ lastans) % n + 1, r = (r ^ lastans) % n + 1;
      if (l > r) swap(l, r);
      l--, r--;
      printf("%d\n", lastans = base[r].query(l));
    } else {
      int x;
      scanf("%d", &x);
      base.eb(base.back());
      base[n].insert(x ^ lastans, n);
      n++;
    }
  }
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) solve();
}