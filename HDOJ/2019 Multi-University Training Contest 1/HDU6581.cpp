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

int n;
int l[maxn], s[maxn], v[maxn];

void solve() {
  REP(i, n + 1) scanf("%d", l + i);
  REP(i, n + 1) scanf("%d", s + i);
  REP(i, n + 1) scanf("%d", v + i);
  double ans = double(s[0]) / v[0];
  int L = 0;
  FOR(i, 1, n) {
    L += l[i];
    chkmax(ans, double(L + s[i]) / v[i]);
  }
  printf("%.10lf\n", ans);
}

int main() {
  while (scanf("%d", &n) == 1) solve();
}