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

const int maxn = 212345;

int a[maxn], b[maxn], need[maxn];
int n, m;

bool check(int m) {
  if (m == 1) return true;
  int have = 1;
  reset(need, 0);
  FOR(i, 1, m) need[b[i]]++;
  if (need[0]) return false;
  int lvl = 0;
  for (int i = 1; i <= n && have; ) {
    int tmp = 0;
    while (have && i <= n) {
      tmp += a[i];
      if (tmp >= m) return true;
      have--;
      i++;
    }
    have += tmp;
    if (have >= m) return true;
    if (have < need[++lvl]) return false;
    have -= need[lvl];
  }
  FOR(i, lvl + 1, 2e5 + 10) have -= need[i];
  return have >= 0;
}

int main() {
  scanf("%d%d", &n, &m);
  FOR(i, 1, n) scanf("%d", a + i);
  FOR(i, 1, m) scanf("%d", b + i);
  sort(a + 1, a + n + 1, greater<>());
  sort(b + 1, b + m + 1, greater<>());
  int lo = 1, hi = m;
  while (lo < hi) {
    int mi = lo + hi + 1 >> 1;
    if (check(mi)) lo = mi;
    else hi = mi - 1;
  }
  printf("%d", lo);
}