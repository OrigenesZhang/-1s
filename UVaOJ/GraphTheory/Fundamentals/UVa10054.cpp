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

const int maxn = 55;

int T, n;
int G[maxn][maxn], deg[maxn];
stack<int> ans;

void dfs(int u) {
  while (deg[u]) {
    FOR(i, 1, 50) if (G[u][i]) {
      G[u][i]--, G[i][u]--;
      deg[u]--, deg[i]--;
      dfs(i);
    }
  }
  ans.emplace(u);
}

int main() {
  scanf("%d", &T);
  FOR(cs, 1, T) {
    if (cs != 1) putchar('\n');
    scanf("%d", &n);
    reset(G, 0);
    reset(deg, 0);
    while (n--) {
      int u, v;
      scanf("%d%d", &u, &v);
      G[u][v]++, G[v][u]++;
      deg[u]++, deg[v]++;
    }
    printf("Case #%d\n", cs);
    bool flag = true;
    FOR(i, 1, 50) if (deg[i] & 1) {
      puts("some beads may be lost");
      flag = false;
      break;
    }
    if (!flag) continue;
    FOR(i, 1, 50) if (deg[i]) {
      dfs(i);
      break;
    }
    FOR(i, 1, 50) if (deg[i]) {
      puts("some beads may be lost");
      flag = false;
      break;
    }
    if (!flag) continue;
    int pre = -1, now;
    while (!ans.empty()) {
      now = ans.top(); ans.pop();
      if (pre != -1) printf("%d %d\n", pre, now);
      pre = now;
    }
  }
}
