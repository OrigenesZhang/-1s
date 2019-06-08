#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REP(i, n) FOR(i, 0, (n) - 1)
#define reset(x, y) memset(x, y, sizeof(x))
#define mp(x, y) make_pair(x, y)
#define eb emplace_back
#define _1 first
#define _2 second
#define all(x) (x).begin(), (x).end()
#define uni(x) (x).erase(unique(all(x)), (x).end())
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using Set = set<int, greater<>>;

const int maxn = 112345;

int n;
int x[maxn], y[maxn];

int main() {
  while (scanf("%d", &n) == 1) {
    map<int, Set> mx, my;
    FOR(i, 1, n) {
      scanf("%d%d", x + i, y + i);
      mx[x[i]].emplace(y[i]);
      my[y[i]].emplace(x[i]);
    }
    int ans = 0;
    FOR(i, 1, n) {
      if (mx[x[i]].size() < my[y[i]].size()) {
        for (auto en : mx[x[i]]) if (en != y[i]) {
          int dis = en - y[i];
          if (dis <= ans) break;
          if (mx[x[i] + dis].count(y[i]) && mx[x[i] + dis].count(en)) {
            chkmax(ans, dis);
            break;
          }
        }
      } else {
        for (auto en : my[y[i]]) if (en != x[i]) {
          int dis = en - x[i];
          if (dis <= ans) break;
          if (my[y[i] + dis].count(x[i]) && my[y[i] + dis].count(en)) {
            chkmax(ans, dis);
            break;
          }
        }
      }
    }
    printf("%d\n", ans);
  }
}