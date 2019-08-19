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
const int MOD = 1e9 + 7;
const int inv[] = {-1, 1, int(5e8 + 4), 333333336, 250000002};
 
inline int add(int a, int b) {
  if (b < 0) b += MOD;
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}
 
inline int mul(int a, int b) {
  return ll(a) * b % MOD;
}
 
int C(int n, int m) {
  if (n < m) return 0;
  if (m == 1) return n;
  if (m == 2) return ll(n) * (n - 1) / 2 % MOD;
  int ret = 1;
  ROF(i, n, n - 3) ret = mul(ret, i);
  FOR(i, 2, 4) ret = mul(ret, inv[i]);
  return ret;
}
 
vector<int> G[maxn];
int deg[maxn], id[maxn], rk[maxn];
 
void solve() {
  int n, m;
  scanf("%d%d", &n, &m);
  FOR(i, 1, n) G[i].clear();
  while (m--) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].eb(v);
    G[v].eb(u);
  }
  FOR(i, 1, n) deg[i] = G[i].size();
  iota(id + 1, id + n + 1, 1);
  int ans[2] = {};
  FOR(i, 1, n) {
    int pre = 0, tmp[2] = {};
    for (auto j : G[i]) {
      tmp[0] = add(tmp[0], C(deg[j] - 1, 2));
      tmp[1] = add(tmp[1], mul(pre, C(deg[j] - 1, 1)));
      pre = add(pre, deg[j] - 1);
    }
    ans[0] = add(ans[0], mul(tmp[0], C(deg[i] - 1, 1)));
    ans[0] = add(ans[0], tmp[1]);
    ans[0] = add(ans[0], C(deg[i], 4));
  }
  sort(id + 1, id + n + 1, [](int a, int b) { return deg[a] > deg[b]; });
  FOR(i, 1, n) rk[id[i]] = i;
  fill(id + 1, id + n + 1, 0);
  vector<int> occ(n + 1), s(n + 1);
  FOR(i, 1, n) {
    for (auto j : G[i]) if (rk[i] < rk[j]) id[j] = 1;
    for (auto j : G[i]) if (rk[i] <= rk[j]) for (auto k : G[j]) {
      if (rk[j] < rk[k] && id[k]) ans[1] = add(ans[1], deg[i] + deg[j] + deg[k] - 5);
      if (rk[i] < rk[k]) {
        if (occ[k] < i) {
          occ[k] = i;
          s[k] = 0;
        }
        ans[1] = add(ans[1], s[k]);
        s[k]++;
      }
    }
    for (auto j : G[i]) id[j] = 0;
  }
  ans[0] = add(ans[0], -mul(3, ans[1]));
  printf("%d\n", ans[0]);
}
 
int main() {
  int T;
  scanf("%d", &T);
  while (T--) solve();
}