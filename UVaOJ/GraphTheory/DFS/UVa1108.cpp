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

const int maxn = 51234;

int cs, n, m, clk, bcc_cnt;
int bccno[maxn], in[maxn];
bool cut[maxn];
vector<int> G[maxn], bcc[maxn];
stack<pii> s;

int dfs(int u, int par) {
  int lowu = in[u] = ++clk, ch = 0;
  for (auto v : G[u]) {
    if (!in[v]) {
      s.emplace(u, v);
      ch++;
      int lowv = dfs(v, u);
      chkmin(lowu, lowv);
      if (lowv >= in[u]) {
        cut[u] = true;
        bcc[++bcc_cnt].clear();
        pii e;
        do {
          e = s.top(); s.pop();
          if (bccno[e._1] != bcc_cnt) {
            bcc[bcc_cnt].eb(e._1);
            bccno[e._1] = bcc_cnt;
          }
          if (bccno[e._2] != bcc_cnt) {
            bcc[bcc_cnt].eb(e._2);
            bccno[e._2] = bcc_cnt;
          }
        } while (e._1 != u || e._2 != v);
      }
    } else if (in[v] < in[u] && v != par) {
      s.emplace(u, v);
      chkmin(lowu, in[v]);
    }
  }
  if (par == -1 && ch == 1) cut[u] = false;
  return lowu;
}

int main() {
  while (scanf("%d", &m) == 1) {
    if (!m) break;
    n = 0;
    FOR(i, 1, m + 1) G[i].clear();
    FOR(i, 1, m) {
      int u, v;
      scanf("%d%d", &u, &v);
      G[u].eb(v);
      G[v].eb(u);
      chkmax(n, max(u, v));
    }
    clk = bcc_cnt = 0;
    reset(bccno, 0);
    reset(in, 0);
    reset(cut, false);
    dfs(1, -1);
    printf("Case %d: ", ++cs);
    if (bcc_cnt == 1) {
      printf("2 %lld\n", ll(n) * (n - 1) / 2);
      continue;
    }
    int need = 0;
    ll way = 1;
    FOR(i, 1, bcc_cnt) {
      int no = 0;
      for (auto it : bcc[i]) if (cut[it]) no++;
      if (no == 1) {
        need++;
        way *= bcc[i].size() - no;
      }
    }
    printf("%d %lld\n", need, way);
  }
}
