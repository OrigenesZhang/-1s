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
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

const int maxn = 312345;
const int inf = 0x3f3f3f3f;

struct Seg {
  int l, r, mmin;
} T[maxn << 2];

void build(int o, int l, int r) {
  T[o].l = l, T[o].r = r, T[o].mmin = inf;
  if (l < r) {
    int mi = l + r >> 1;
    build(o << 1, l, mi);
    build(o << 1 | 1, mi + 1, r);
  }
}

void update(int o, int x, int v) {
  if (T[o].l == T[o].r) {
    T[o].mmin = v;
    return;
  }
  int mi = T[o].l + T[o].r >> 1;
  if (x <= mi) update(o << 1, x, v);
  else update(o << 1 | 1, x, v);
  T[o].mmin = min(T[o << 1].mmin, T[o << 1 | 1].mmin);
}

int query(int o, int l, int r) {
  if (l <= T[o].l && T[o].r <= r) return T[o].mmin;
  int mi = T[o].l + T[o].r >> 1;
  int ret = inf;
  if (l <= mi) chkmin(ret, query(o << 1, l, r));
  if (r > mi) chkmin(ret, query(o << 1 | 1, l, r));
  return ret;
}

int n, lis[maxn], used;

int main() {
  scanf("%d", &n);
  build(1, 1, n);
  FOR(i, 1, n) {
    int c;
    scanf("%d", &c);
    REP(j, c) {
      int now;
      scanf("%d", &now);
      if (!lis[now]) lis[now] = i + 1;
    }
    int cur;
    if (lis[i] && lis[i] <= i - 1) {
      if (query(1, 1, used) < lis[i]) {
        int lo = 1, hi = used;
        while (lo < hi) {
          int mi = lo + hi >> 1;
          if (query(1, 1, mi) < lis[i]) hi = mi;
          else lo = mi + 1;
        }
        cur = lo;
      } else cur = used + 1;
    } else cur = 1;
    chkmax(used, cur);
    printf("%d ", cur);
    update(1, cur, i);
  }
}