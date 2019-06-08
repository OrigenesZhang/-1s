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

const int maxn = 112345;

int pre[maxn], lowlink[maxn], sccno[maxn], in[maxn], out[maxn];
int dfs_clk, scc_cnt, n, m;
bool vis[maxn], matched[maxn];
vector<int> G[maxn], adj[maxn];
stack<int> s;

void dfs(int u) {
  pre[u] = lowlink[u] = ++dfs_clk;
  s.emplace(u);
  for (auto v : G[u]) {
    if (!pre[v]) {
      dfs(v);
      chkmin(lowlink[u], lowlink[v]);
    } else if (sccno[v] == -1) chkmin(lowlink[u], pre[v]);
  }
  if (lowlink[u] == pre[u]) {
    while (true) {
      int x = s.top(); s.pop();
      sccno[x] = scc_cnt;
      if (x == u) break;
    }
    scc_cnt++;
  }
}

void find_scc() {
  dfs_clk = scc_cnt = 0;
  fill(sccno, sccno + n, -1);
  fill(pre, pre + n, 0);
  REP(i, n) if (!pre[i]) dfs(i);
}

int dfs2(int u) {
  if (vis[u]) return -1;
  vis[u] = true;
  if (!out[u]) return u;
  for (auto v : adj[u]) {
    int now = dfs2(v);
    if (now != -1) return now;
  }
  return -1;
}

int main() {
  while (scanf("%d%d", &n, &m) == 2) {
    REP(i, n) G[i].clear();
    while (!s.empty()) s.pop();
    vector<pii> edges;
    while (m--) {
      int u, v;
      scanf("%d%d", &u, &v);
      u--, v--;
      edges.eb(u, v);
      G[u].eb(v);
    }
    find_scc();
    if (scc_cnt == 1) {
      puts("0");
      continue;
    }
    REP(i, scc_cnt) adj[i].clear();
    vector<int> rep(scc_cnt, -1);
    fill(in, in + scc_cnt, 0);
    fill(out, out + scc_cnt, 0);
    for (auto it : edges) {
      int u = sccno[it._1], v = sccno[it._2];
      if (u != v) {
        adj[u].eb(v);
        in[v]++, out[u]++;
      }
    }
    REP(i, n) if (rep[sccno[i]] == -1) rep[sccno[i]] = i;
    vector<int> sources, sinks;
    REP(i, scc_cnt) {
      if (!in[i]) sources.eb(i);
      else if (!out[i]) sinks.eb(i);
    }
    bool rev = false;
    if (sources.size() > sinks.size()) {
      rev = true;
      REP(i, scc_cnt) swap(in[i], out[i]);
      swap(sources, sinks);
      REP(i, scc_cnt) adj[i].clear();
      for (auto it : edges) {
        int u = sccno[it._1], v = sccno[it._2];
        if (u != v) adj[v].eb(u);
      }
    }
    fill(vis, vis + scc_cnt, false);
    fill(matched, matched + scc_cnt, false);
    vector<pii> lis;
    for (auto u : sources) {
      int v = dfs2(u);
      if (v != -1) {
        lis.eb(u, v);
        matched[u] = matched[v] = true;
      }
    }
    int have = lis.size(), diff = sinks.size() - sources.size();
    vector<int> rems, remt;
    for (auto it : sources) if (!matched[it]) rems.eb(it);
    for (auto it : sinks) if (!matched[it]) remt.eb(it);
    vector<pii> ans;
    if (!diff) {
      REP(i, have - 1) ans.eb(lis[i]._2, lis[i + 1]._1);
      REP(i, int(rems.size())) ans.eb(remt[i], rems[i]);
      ans.eb(lis.back()._2, lis.front()._1);
    } else {
      REP(i, have - 1) ans.eb(lis[i]._2, lis[i + 1]._1);
      REP(i, int(rems.size())) ans.eb(remt[i], rems[i]);
      ans.eb(lis.back()._2, remt[rems.size()]);
      FOR(i, int(rems.size()), int(remt.size()) - 2) ans.eb(remt[i], remt[i + 1]);
      ans.eb(remt.back(), lis.front()._1);
    }
    printf("%d\n", int(ans.size()));
    for (auto it : ans) {
      if (rev) printf("%d %d\n", rep[it._2] + 1, rep[it._1] + 1);
      else printf("%d %d\n", rep[it._1] + 1, rep[it._2] + 1);
    }
  }
}

/*
 5 6
 1 2
 2 3
 3 1
 2 4
 4 5
 5 4

 4 3
 2 1
 3 1
 4 1

 6 5
 1 4
 1 5
 1 6
 2 4
 3 4

 */