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

const int maxn = 12;

int T, n;
int s[maxn], deg[maxn], G[maxn][maxn];
bool vis[maxn];


int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d\n", &n);
    reset(s, 0);
    reset(deg, 0);
    reset(G, 0);
    reset(vis, false);
    FOR(i, 1, n) FOR(j, i, n) {
      char op;
      scanf("%c", &op);
      if (op == '+') G[j][i - 1] = 1, deg[i - 1]++;
      else if (op == '-') G[i - 1][j] = 1, deg[j]++;
    }
    queue<int> q;
    REP(i, n + 1) if (!deg[i]) {
      s[i] = 10;
      vis[i] = true;
      q.emplace(i);
    }
    while (!q.empty()) {
      auto u = q.front(); q.pop();
      REP(i, n + 1) if (G[u][i] && !--deg[i] && !vis[i]) {
        vis[i] = true;
        s[i] = s[u] - 1;
        q.emplace(i);
      }
    }
    FOR(i, 1, n) printf("%d%c", s[i] - s[i - 1], i == n ? '\n' : ' ');
  }
}
