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

const int maxn = 5123;

vector<int> G[maxn];
int n, k, st, en;
int dep[maxn], dp[maxn], dp2[maxn];
pii ans;

void dfs(int u, int par) {
  dep[u] = par == -1 ? 0 : dep[par] + 1;
  dp[u] = dp2[u] = 0;
  for (auto v : G[u]) if (v != par) {
    dfs(v, u);
    chkmax(dp[u], dp[v]);
    chkmax(dp[u], dp2[u] + dp2[v] + 1);
    chkmax(dp2[u], dp2[v] + 1);
  }
}

void dfs(int u, int par, int dia, int chain) {
  if (dep[u] > k) return;
  int now = max(dp[u], max(dia, chain + dp2[u]));
  if (mp(now, dep[u]) < ans) {
    ans = {now, dep[u]};
    st = u, en = -1;
  }
  vector<int> nowd(2), nowc(3, -1);
  for (auto v : G[u]) if (v != par) {
    chkmax(nowd[0], dp[v]);
    chkmax(nowc[0], dp2[v]);
    sort(all(nowd));
    sort(all(nowc));
  }
  for (auto v : G[u]) if (v != par) {
    int tmp = nowc[1] + nowc[2];
    if (dp2[v] == nowc[2]) tmp = tmp - nowc[2] + nowc[0];
    else if (dp2[v] == nowc[1]) tmp = tmp - nowc[1] + nowc[0];
    int nchain = dp2[v] == nowc[2] ? nowc[1] : nowc[2];
    int subdia = dp[v] == nowd[1] ? nowd[0] : nowd[1];
    dfs(v, u, max(max(subdia, tmp + 2), max(dia, chain + 1 + nchain)), max(chain, nchain + 1));
  }
}

int main() {
  scanf("%d%d", &n, &k);
  FOR(i, 1, n - 1) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].eb(v);
    G[v].eb(u);
  }
  ans._1 = maxn;
  REP(i, n) {
    dfs(i, -1);
    dfs(i, -1, 0, 0);
    if (en == -1) en = i;
  }
  printf("%d\n%d\n", ans._1, ans._2);
  if (ans._2) printf("%d %d", st, en);
}
