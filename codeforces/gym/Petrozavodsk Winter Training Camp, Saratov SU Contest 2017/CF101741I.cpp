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

const int maxn = 412345;

struct SA {
  int sa[maxn], rank[maxn], height[maxn], t[maxn], t2[maxn], c[maxn];
  int st[maxn][20], bits[maxn], _n;

  void build(const int *s, int n, int m) {
    _n = n;
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
    REP(i, n - 1) {
      if (k) k--;
      int j = sa[rank[i] - 1];
      while (s[i + k] == s[j + k]) k++;
      height[rank[i]] = k;
    }
  }

  void rmq_init(int n) {
    REP(i, n) st[i][0] = height[i];
    for (int i = 1; 1 << i < n; i++) bits[1 << i] = 1;
    FOR(i, 1, n - 1) bits[i] = bits[i - 1] + bits[i];
    FOR(j, 1, 19) for (int i = 0; i + (1 << j) - 1 < n; i++) st[i][j] = min(st[i][j - 1], st[i + (1 << j - 1)][j - 1]);
  }

  SA(const int *s, int n) {
    build(s, n, 256);
    getHeight(s, n);
    rmq_init(n);
  }

  int rmq(int l, int r) {
    int k = bits[r - l + 1];
    return min(st[l][k], st[r - (1 << k) + 1][k]);
  }

  int lcp(int l, int r) {
    if (l == r) return _n - l;
    l = rank[l], r = rank[r];
    if (l > r) swap(l, r);
    return rmq(l + 1, r);
  }
};

inline int add(int a, int b, int m) {
  a += b;
  if (a >= m) a -= m;
  return a;
}

inline int mul(int a, int b, int m) {
  return ll(a) * b % m;
}

char tmp[maxn];
int n, q, s[maxn], rev[maxn], cnt[maxn], f[maxn];
vector<int> G[maxn];

void dfs(int u, int m) {
  f[u] = 1;
  for (auto v : G[u]) {
    dfs(v, m);
    f[u] = mul(f[u], f[v], m);
  }
  cnt[u] %= m;
  f[u] = add(f[u], cnt[u], m);
}

int main() {
  scanf("%d%d", &n, &q);
  scanf("%s", tmp);
  REP(i, n) s[i] = tmp[i];
  static SA sa(s, n + 1);
  REP(i, n + 1) rev[sa.sa[i]] = i;
  while (q--) {
    int k, m;
    scanf("%d%d", &k, &m);
    vector<pii> query(k);
    for (auto &x : query) {
      scanf("%d%d", &x._1, &x._2);
      x._1--, x._2--;
    }
    sort(all(query), [&](pii a, pii b) { return sa.lcp(a._1, b._1) >= min(a._2 - a._1 + 1, b._2 - b._1 + 1) ?
                                                a._2 - a._1 + 1 < b._2 - b._1 + 1 : rev[a._1] < rev[b._1];} );
    stack<int> stk;
    REP(i, k + 1) G[i].clear();
    cnt[k] = 1;

    auto same = [&] (pii x, pii y) {
      if (x._2 - x._1 != y._2 - y._1) return false;
      return sa.lcp(x._1, y._1) >= x._2 - x._1 + 1;
    };

    auto prefix = [&] (pii x, pii y) {
      if (x._2 - x._1 > y._2 - y._1) return false;
      return sa.lcp(x._1, y._1) >= x._2 - x._1 + 1;
    };

    REP(i, k) {
      if (!stk.empty() && same(query[stk.top()], query[i])) {
        cnt[stk.top()]++;
        continue;
      }
      while (!stk.empty() && !prefix(query[stk.top()], query[i])) stk.pop();
      int u = stk.empty() ? k : stk.top();
      G[u].eb(i);
      stk.emplace(i);
      cnt[i] = 1;
    }
    dfs(k, m);
    printf("%d\n", add(f[k], m - 1, m));
  }
}

/*
10 6
aabbaacaba
4 30 1 2 5 6 10 10 10 10
5 20 1 2 3 4 5 6 7 8 9 10
1 2 1 10
3 20 9 9 7 7 8 8
5 20 6 6 7 7 8 8 9 9 10 10
4 20 1 1 2 2 3 3 4 4
*/