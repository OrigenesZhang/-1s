#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(int)(a)-1)
#define reset(a,b) memset(a, b, sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl;
#define BUGP(x) cout << #x << " = " << x._1 << ", " << x._2 << endl;
#define pb push_back
#define _1 first
#define _2 second
#define PR(x,a,b) { cout << #x << " = "; FOR(_,a,b) cout << x[_] << ' '; cout << endl; }
#define CON(x) { cout << #x << " = "; for (auto i: x) cout << i << ' '; cout << endl; }
#define eps 1e-9
#define sqr(x) ((x) * (x))
#define all(x) x.begin(), x.end()
#define mod 1000000007

int t, n, m, q, trie[16000200], lvl[16000200], cnt, node[2222], k, rnk[2222], val, lca[2222][2222], lead[16000200], par[2222];
pair<int, int> p[2222];
pair<string, int> pp[2222];
string s;
set<int> ans;
vector<int> v[2222];

int get(int x) {
  if (x == par[x]) return x;
  return par[x] = get(par[x]);
}

void merge(int x, int y, int z) {
  for (auto i: v[x]) for (auto j: v[y]) lca[i][j] = lca[j][i] = z;
  if (v[x].size() > v[y].size()) {
    par[y] = x;
    for (auto i: v[y]) v[x].pb(i);
  } else {
    par[x] = y;
    for (auto i: v[x]) v[y].pb(i);
  }
}

void dfs(int x) {
  int l = trie[x], r = trie[x + 1];
  if (l) dfs(l);
  if (r) dfs(r);
  if (l && r) {
    merge(lead[l], lead[r], lvl[x]);
    lead[x] = get(lead[l]);
  } else if (l) {
    lead[x] = lead[l];
  } else if (r) {
    lead[x] = lead[r];
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin >> t;
  FOR (cas, 1, t) {
    cout << "Case #" << cas << ":" << endl;
    cnt = 0;
    reset(trie, 0);
    cin >> n >> m >> q;
    REP (i, n) {
      cin >> s;
      pp[i] = {s, i};
      int cur = 0;
      for (char c: s) {
        int id = c - '0';
        if (!trie[cur + id]) {
          cnt += 2;
          trie[cur + id] = cnt;
          lvl[cnt] = 1 + lvl[cur];
        }
        cur = trie[cur + id];
      }
      node[i] = cur;
    }
    assert(cnt < 16000200);
    sort(pp, pp + n);
    REP (i, n) rnk[pp[i]._2] = i;

    REP (i, n) lead[node[i]] = i, par[i] = i, v[i].clear(), v[i].pb(i);
    dfs(0);

    while (q--) {
      cin >> k;
      REP (i, k) cin >> val, p[i] = {rnk[val], val};
      sort(p, p + k);
      ans.clear();
      REP (i, k - 1) ans.insert(lca[p[i]._2][p[i + 1]._2]);
      cout << ans.size() << ' ';
      for (auto i: ans) cout << i << ' ';
      cout << endl;
    }
  }
}