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

const int maxn = 1123;

int n, h, a[maxn], b[maxn];

bool check(int n) {
  reset(b, 0);
  FOR(i, 1, n) b[i] = a[i];
  sort(b + 1, b + n + 1, greater<>());
  int now = 0;
  for (int i = 1; i <= n; i += 2) {
    now += max(b[i], b[i + 1]);
    if (now > h) return false;
  }
  return true;
}

int main() {
  scanf("%d%d", &n, &h);
  FOR(i, 1, n) scanf("%d", a + i);
  int lo = 1, hi = n;
  while (lo < hi) {
    int mi = lo + hi + 1 >> 1;
    if (check(mi)) lo = mi;
    else hi = mi - 1;
  }
  printf("%d", lo);
}