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

int n, perm[maxn];
double a[maxn];

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%lf", a + i);
  sort(a + 1, a + n + 1);
  iota(perm + 1, perm + n + 1, 1);
  for (int i = 2, j = n - 1; i < j; i += 2, j -= 2) swap(perm[i], perm[j]);
  perm[n + 1] = perm[1];
  double tot = 0;
  FOR(i, 1, n) tot += sqrt(a[perm[i]] * a[perm[i + 1]]);
  tot *= 2;
  double ans = a[perm[1]] + a[perm[n]] + tot - 2 * sqrt(a[perm[1]] * a[perm[n]]);
  FOR(i, 1, n - 1) chkmin(ans, a[perm[i]] + a[perm[i + 1]] + tot - 2 * sqrt(a[perm[i]] * a[perm[i + 1]]));
  printf("%.10lf", ans);
}
