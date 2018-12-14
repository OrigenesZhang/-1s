#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(int)(a)-1)
#define BUG(x) cout << #x << " = " << x << endl;
#define BUGP(x) cout << #x << " = " << x._1 << ' ' << x._2 << endl;
#define pb push_back
#define _1 first
#define _2 second

int t, n, m, u, v, vst[100500];
vector<int> from[100500], to[100500];
set<pair<int, int>> keep;

void dfs1 (int x) {
  vst[x] = 1;
  for (auto nex: from[x]) if (!vst[nex]) {
    keep.insert({x, nex});
    dfs1(nex);
  }
}

void dfs2 (int x) {
  vst[x] = 1;
  for (auto nex: to[x]) if (!vst[nex]) {
    keep.insert({nex, x});
    dfs2(nex);
  }
}

int main() {
  cin >> t;
  while (t--) {
    cin >> n >> m;
    keep.clear();
    FOR (i, 1, n) from[i].clear(), to[i].clear();
    REP (i, m) {
      cin >> u >> v;
      from[u].pb(v);
      to[v].pb(u);
    }

    FOR (i, 1, n) vst[i] = 0;
    dfs1(1);
    FOR (i, 1, n) vst[i] = 0;
    dfs2(1);
    int need = m - 2 * n;
    FOR (i, 1, n) for (auto nex: from[i]) if (!keep.count({i, nex})) {
      if (need) need--, cout << i << ' ' << nex << endl;
    }
  }
}