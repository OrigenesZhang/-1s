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
const int MOD = 998244353;

vector<pii> G[maxn];
vector<int> wcc;

int T, n, st, en, dir;
bool vis[maxn];
int dp[maxn], dp2[maxn];

inline int mul(int a, int b) {
  return ll(a) * b % MOD;
}

pii check(int u) {
  vis[u] = true;
  pii ret = {1, 0};
  for (auto _ : G[u]) {
    ret._2++;
    if (!vis[_._1]) {
      auto cur = check(_._1);
      ret._1 += cur._1, ret._2 += cur._2;
    }
  }
  return ret;
}

void dfs(int u, int par) {
  vis[u] = true;
  dp2[u] = 0;
  for (auto _ : G[u]) {
    int v = _._1, rev = _._2;
    if (!vis[v]) {
      dfs(v, u);
      dp2[u] += dp2[v] + ((rev & 1) ^ 1);
    } else if (v != par) {
      st = u;
      en = v;
      dir = rev;
    }
  }
}

void dfs(int u, pii par) {
  wcc.eb(dp[u]);
  for (auto _ : G[u]) if (_ != par) {
    int v = _._1, rev = _._2;
    if (rev == dir || rev == (dir ^ 1)) continue;
    dp[v] = dp[u] + (rev & 1 ? 1 : -1);
    dfs(v, {u, rev ^ 1});
  }
}

int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    FOR(i, 1, 2 * n) {
      G[i].clear();
      vis[i] = false;
    }
    FOR(i, 1, n) {
      int x, y;
      scanf("%d%d", &x, &y);
      G[y].eb(x, 2 * i - 1);
      G[x].eb(y, 2 * i - 2);
    }
    bool good = true;
    FOR(i, 1, 2 * n) if (!vis[i]) {
      auto now = check(i);
      if (now._1 < now._2 / 2) {
        good = false;
        break;
      }
    }
    if (!good) {
      puts("-1 -1");
      continue;
    }
    FOR(i, 1, 2 * n) {
      vis[i] = false;
      dp[i] = 0;
    }
    int flip = 0, way = 1;
    FOR(i, 1, 2 * n) if (!vis[i]) {
      st = en = dir = -1;
      dfs(i, 0);
      dp[i] = dp2[i];
      wcc.clear();
      dfs(i, {0, 0});
      int cnt = 0;
      if (st == -1) {
        sort(all(wcc));
        flip += wcc[0];
        for (auto it : wcc) if (it == wcc[0]) cnt++;
        way = mul(way, cnt);
      } else {
        dir &= 1;
        cnt = 1 + (dp[st] + dir == dp[en] + (dir ^ 1));
        flip += min(dp[st] + dir, dp[en] + (dir ^ 1));
        way = mul(way, cnt);
      }
    }
    printf("%d %d\n", flip, way);
  }
}