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

const int maxn = 1123456;
const int MOD = 1e9 + 7;

vector<pii> adj[maxn];

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

  SA(const int *s, int n) {
    build(s, n, 11234);
    getHeight(s, n);
    FOR(i, 2, n) adj[height[i]].eb(sa[i], sa[i - 1]);
  }
};

int n, len, Q;
int s[maxn], seg[maxn], h[maxn], par[maxn], idx[maxn], val[maxn], ans[maxn];
char tmp[maxn];
set<int> segs[maxn];

int Find(int x) {
  return par[x] == x ? x : par[x] = Find(par[x]);
}

inline int add(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}

inline int mul(int a, int b) {
  return ll(a) * b % MOD;
}

int pow_mod(int a, int pw) {
  int ret = 1;
  while (pw) {
    if (pw & 1) ret = mul(ret, a);
    a = mul(a, a);
    pw >>= 1;
  }
  return ret;
}

int main() {
  scanf("%d", &n);
  REP(i, n) {
    scanf("%s", tmp);
    int tot = strlen(tmp);
    REP(j, tot) {
      seg[len] = i;
      adj[tot - j].eb(len, len);
      s[len++] = tmp[j];
    }
    s[len++] = i + 'z' + 1;
  }
  static SA sa(s, len + 1);
  REP(i, n) scanf("%d", h + i);
  int sum = 0;
  ROF(i, len, 1) {
    for (auto it : adj[i]) {
      int u = it._1, v = it._2;
      if (u == v) {
        val[u] = h[seg[u]];
        par[u] = idx[u] = u;
        sum = add(sum, val[u]);
        segs[u].emplace(seg[u]);
      } else {
        u = Find(u), v = Find(v);
        sum = add(sum, MOD - add(val[u], val[v]));
        if (segs[idx[u]].size() > segs[idx[v]].size()) {
          swap(idx[u], idx[v]);
          swap(val[u], val[v]);
        }
        par[u] = v;
        for (auto cur : segs[idx[u]]) if (!segs[idx[v]].count(cur)) {
          segs[idx[v]].emplace(cur);
          val[v] = mul(val[v], h[cur]);
        }
        sum = add(sum, val[v]);
      }
    }
    ans[i] = sum;
  }
  FOR(i, 1, 1000000) ans[i] = add(ans[i - 1], ans[i]);
  int now = 0;
  FOR(i, 1, 1000000) {
    now = mul(add(now, 1), 26);
    ans[i] = mul(ans[i], pow_mod(now, MOD - 2));
  }
  scanf("%d", &Q);
  while (Q--) {
    int m;
    scanf("%d", &m);
    printf("%d\n", ans[m]);
  }
}

/*
 2
 zybnb
 ybyb
 3 5
 4
 1
 2
 3
 4
 */