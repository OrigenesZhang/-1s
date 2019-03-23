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

int n, a, k;

int get(int a) {
  int ret = 0;
  while (a) {
    ret += a % 10;
    a /= 10;
  }
  return ret;
}

int main() {
  scanf("%d", &n);
  while (n--) {
    scanf("%d%d", &a, &k);
    k--;
    while (k) {
      a = a + get(a);
      k--;
    }
    printf("%d\n", a);
  }
}