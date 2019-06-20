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

const int maxn = 212;

vector<int> G[maxn];
int T, V, E, c[maxn];

bool dfs(int u, int col, int &one, int &two) {
  c[u] = col;
  col == 1 ? one++ : two++;
  for (auto v : G[u]) {
    if (c[v] && c[v] == col) return false;
    if (!c[v] && !dfs(v, 3 - col, one, two)) return false;
  }
  return true;
}

int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &V, &E);
    REP(i, V) G[i].clear();
    while (E--) {
      int u, v;
      scanf("%d%d", &u, &v);
      if (u == v) continue;
      G[u].eb(v);
      G[v].eb(u);
    }
    REP(i, V) {
      sort(all(G[i]));
      uni(G[i]);
    }
    fill(c, c + V, 0);
    int ans = 0;
    REP(i, V) if (!c[i]) {
      int one = 0, two = 0;
      if (!dfs(i, 1, one, two)) {
        ans = -1;
        break;
      }
      int now = min(one, two);
      if (!now) now++;
      ans += now;
    }
    printf("%d\n", ans);
  }
}
