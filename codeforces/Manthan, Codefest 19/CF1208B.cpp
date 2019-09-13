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
 
const int maxn = 2123;
 
int a[maxn], n, ans;
 
int main() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%d", a + i);
  set<int> s;
  FOR(i, 1, n) {
    int j;
    for (j = n; ; j--) {
      chkmax(ans, i + n - 1 - j);
      if (!j || s.count(a[j])) break;
      s.emplace(a[j]);
    }
    for (j++; j <= n; j++) s.erase(a[j]);
    if (s.count(a[i])) break;
    s.emplace(a[i]);
  }
  printf("%d", n - ans);
}