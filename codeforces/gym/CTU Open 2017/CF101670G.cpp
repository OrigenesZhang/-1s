#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REP(i, n) FOR(i, 0, (n) - 1)
#define reset(x, y) memset(x, y, sizeof(x))
#define mp(x, y) make_pair(x, y)
#define eb emplace_back
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)

using namespace std;
using pii = pair<int, int>;
using ll = long long;

const int maxn = 1123456;

vector<int> tab[maxn * 2];
int n, k, cnt[maxn];

int main() {
  while (scanf("%d%d", &n, &k) == 2) {
    FOR(i, 1, 2 * n) tab[i].clear();
    fill(cnt + 1, cnt + k + 1, 0);
    FOR(i, 1, n) {
      int l;
      scanf("%d", &l);
      tab[i].resize(l);
      REP(j, l) scanf("%d", &tab[i][j]);
    }
    FOR(i, 1, n) tab[i + n] = tab[i];
    int j = 1, need = k, now = 0;
    while (j <= n && need) {
      for (auto it : tab[j]) {
        if (!cnt[it]) need--;
        cnt[it]++;
      }
      now += tab[j].size();
      j++;
    }
    if (need) {
      puts("-1");
      continue;
    }
    int ans = now;
    FOR(i, 2, n) {
      for (auto it : tab[i - 1]) if (!--cnt[it]) need++;
      now -= tab[i - 1].size();
      if (!need) {
        chkmin(ans, now);
        continue;
      }
      while (j - i < n && need) {
        for (auto it : tab[j]) {
          if (!cnt[it]) need--;
          cnt[it]++;
        }
        now += tab[j].size();
        j++;
      }
      if (!need) chkmin(ans, now);
    }
    printf("%d\n", ans);
  }
}