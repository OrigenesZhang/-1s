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

const int maxn = 112;

int n, m, c;
int tab[maxn][maxn];
bool vis[maxn], G[maxn][maxn];

void dfs(int u) {
  vis[u] = true;
  FOR(i, 1, n) if (!vis[i] && G[u][i]) dfs(i);
}

int main() {
  while (scanf("%d%d%d", &n, &m, &c) == 3) {
    if (!n) break;
    FOR(i, 1, m) FOR(j, 1, n) {
      int now;
      scanf("%d", &now);
      tab[i][now] = j;
    }
    reset(vis, false);
    reset(G, false);
    FOR(i, 1, n) FOR(j, i + 1, n) {
      int ci = 0, cj = 0;
      FOR(k, 1, m) {
        if (tab[k][i] > tab[k][j]) cj++;
        else ci++;
      }
      if (ci > cj) G[i][j] = true;
      else G[j][i] = true;
    }
    dfs(c);
    bool flag = true;
    FOR(i, 1, n) if (!vis[i]) {
      flag = false;
      break;
    }
    puts(flag ? "yes" : "no");
  }
}
