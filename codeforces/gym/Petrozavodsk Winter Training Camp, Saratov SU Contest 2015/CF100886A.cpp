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

const int maxt = 31;
const int maxm = 4031;
const int inf = 0x3f3f3f3f;

int n;
vector<int> G[maxt], res[3];
bitset<maxm> dp[maxt][maxm];

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) {
    int t;
    scanf("%d", &t);
    G[t].eb(i);
  }
  dp[0][0][0] = true;
  int s = 0;
  FOR(t, 1, 30) {
    int lim = G[t].size();
    s += t * lim;
    vector<vector<int>> dp2(maxm, vector<int>(maxm));
    REP(i, min(maxm, s + 1)) REP(j, min(maxm, s + 1 - i)) {
      dp2[i][j] = dp[t - 1][i][j] ? lim + 1 : 0;
      if (i >= t) chkmax(dp2[i][j], dp2[i - t][j] - 1);
      if (j >= t) chkmax(dp2[i][j], dp2[i][j - t] - 1);
      dp[t][i][j] = dp2[i][j] > 0;
    }
  }
  vector<int> ans(3, inf);
  int lo = max(s / 3 - 31, 0), hi = min(lo + 62, maxm - 1);
  FOR(i, lo, min(hi, s)) FOR(j, lo, min(hi, s - i)) if (dp[30][i][j]) {
    vector<int> tmp = {i, j, s - i - j};
    int diff = *max_element(all(tmp)) - *min_element(all(tmp));
    chkmin(ans, vector<int>({diff, i, j}));
  }
  int u = ans[1], v = ans[2];
  ROF(t, 30, 1) {
    int lim = G[t].size();
    for (int i = 0; i <= lim && i * t <= u; i++)
      for (int j = 0; i + j <= lim && j * t <= v; j++)
        if (dp[t - 1][u - i * t][v - j * t]) {
          u -= i * t; v -= j * t;
          REP(k, i) {
            res[0].eb(G[t].back());
            G[t].pop_back();
          }
          REP(k, j) {
            res[1].eb(G[t].back());
            G[t].pop_back();
          }
          REP(k, lim - i - j) {
            res[2].eb(G[t].back());
            G[t].pop_back();
          }
          goto label;
        }
    label:;
  }
  printf("%d\n", ans[0]);
  REP(i, 3) {
    printf("%d", int(res[i].size()));
    for (auto it : res[i]) printf(" %d", it);
    puts("");
  }
}