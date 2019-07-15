#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define chkmax(a, b) a = max(a, b)
using namespace std;
 
const int maxn = 512;
const int inf = 0x3f3f3f3f;
 
int G[maxn][maxn], pref[maxn];
int m, n;
 
int main() {
  scanf("%d%d", &m, &n);
  FOR(i, 1, n) {
    FOR(j, 1, m) {
      scanf("%d", pref + j);
      if (!pref[j]) pref[j] = inf;
    }
    FOR(j, 1, m) FOR(k, j + 1, m) {
      if (pref[j] < pref[k]) G[j][k]++;
      else if (pref[j] > pref[k]) G[k][j]++;
    }
  }
  FOR(i, 1, m) FOR(j, i + 1, m) {
    if (G[i][j] == G[j][i]) G[i][j] = G[j][i] = 0;
    else if (G[i][j] < G[j][i]) G[i][j] = 0;
    else G[j][i] = 0;
  }
  FOR(k, 1, m) FOR(i, 1, m) FOR(j, 1, m) if (i != j) chkmax(G[i][j], min(G[i][k], G[k][j]));
  vector<int> ans;
  FOR(i, 1, m) {
    bool ok = true;
    FOR(j, 1, m) if (G[i][j] < G[j][i]) ok = false;
    if (ok) ans.emplace_back(i);
  }
  for (auto now : ans) printf("%d ", now);
}