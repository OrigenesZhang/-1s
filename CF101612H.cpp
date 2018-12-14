#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(int)(a)-1)
#define BUG(x) cout << #x << " = " << x << endl
#define BUGP(x) cout << #x << " = " << x._1 << ' ' << x._2 << endl
#define reset(a,b) memset(a,b,sizeof(a))
#define PR(x,a,b) { cout << #x << " = "; FOR(_,a,b) cout << x[_] << ' '; cout << endl; }
#define CON(x) { cout << #x << " = "; for(auto _i: x) cout << _i << ' '; cout << endl; }
#define all(x) x.begin(), x.end()
#define uni(x) x.erase(unique(all(x)), x.end())
#define mod 1000000007
#define eps 1e-9
#define sqr(x) ((x) * (x))
#define pi acos(-1)
#define pb push_back
#define _1 first
#define _2 second

int n, par[100500], dp[2][100500], ans;
vector<int> child[100500], avai[100500], tot;
vector<pair<int, int>> v;

void dfs(int x) {
  int tmp = 0;
  for (auto i: child[x]) {
    dfs(i);
    dp[0][x] += dp[1][i];
    if (dp[0][i] == dp[1][i]) tmp = 1;
  }
  dp[1][x] = dp[0][x] + tmp;
}

void dfs2(int x, int id) {
  int tmp = -1;
  for (auto i: child[x]) if (dp[0][i] == dp[1][i]) tmp = i;
  if (tmp == -1) avai[id].pb(x);
  for (auto i: child[x]) {
    if (i != tmp) dfs2(i, id);
    else for (auto j: child[i]) dfs2(j, id);
  }
}

int main() {
  freopen("hidden.in", "r", stdin);
  freopen("hidden.out", "w", stdout);
  cin >> n;
  FOR (i, 2, n) cin >> par[i], child[par[i]].pb(i);
  FOR (i, 1, n) if (!par[i]) {
    dfs(i);
    ans += dp[1][i];
    if (dp[1][i] == 1 + dp[0][i]) {
      par[i] = 1;
      dfs2(i, i);
      for (auto j: avai[i]) tot.pb(j);
    } else {
      for (auto j: child[i]) dfs2(j, i);
      if (i != 1) v.pb({avai[i].size(), i});
      else {
        for (auto j: avai[i]) tot.pb(j);
        tot.pb(1);
      }
    }
  }
  sort(all(v));
  reverse(all(v));
  for (auto p: v) {
    int x = p._2;
    if (tot.size()) {
      par[x] = tot.back();
      tot.pop_back();
      ans++;
    } else {
      par[x] = 1;
      tot.pb(x);
    }
    for (auto i: avai[x]) tot.pb(i);
  }

  cout << ans << endl;
  FOR (i, 2, n) cout << max(1, par[i]) << ' ';
}