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

const int maxn = 1123;
const double eps = 1e-9;

int n, m;
int o[maxn], u[maxn * 2], v[maxn * 2], w[maxn * 2];
bool fix[maxn];
char s[15];
double ans[maxn];
vector<pair<int, double>> G[maxn];

bool check(double T) {
  FOR(i, 1, n) G[i].clear();
  FOR(i, 1, m) G[v[i]].eb(u[i], T - w[i]);
  FOR(i, 1, n) ans[i] = fix[i] ? o[i] : 1e9;
  queue<int> q;
  vector<char> inq(n + 1, 1);
  vector<int> vis(n + 1, 0);
  FOR(i, 1, n) q.emplace(i);
  while (!q.empty()) {
    auto x = q.front(); q.pop();
    for (auto _ : G[x]) {
      int y = _._1;
      double d = _._2;
      if (ans[x] + d + eps < ans[y]) {
        ans[y] = ans[x] + d;
        if (!inq[y]) {
          inq[y] = 1;
          if (++vis[y] > 3005) return false;
          q.emplace(y);
        }
      }
    }
    inq[x] = 0;
  }
  FOR(i, 1, n) {
    if (ans[i] + eps < -1e9) return false;
    if (fix[i] && abs(ans[i] - o[i]) > eps) return false;
  }
  return true;
}

void solve() {
  fill(fix + 1, fix + n + 1, true);
  FOR(i, 1, n) {
    scanf("%s", s);
    if (s[0] == '?') fix[i] = false;
    else sscanf(s, "%d", o + i);
  }
  FOR(i, 1, m) scanf("%d%d%d", u + i, v + i, w + i);
  double lo = 0, hi = 1e9;
  REP(_, 100) {
    double mi = (lo + hi) / 2;
    if (check(mi)) hi = mi;
    else lo = mi;
  }
  check(lo);
  printf("%.10lf\n", lo);
  FOR(i, 1, n) printf("%.10lf ", ans[i]);
  putchar('\n');
}

int main() {
  while (~scanf("%d%d", &n, &m)) solve();
}