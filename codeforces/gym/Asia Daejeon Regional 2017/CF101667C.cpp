#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(int)(a)-1)
#define reset(a,b) memset(a,b,sizeof(a))
#define all(x) x.begin(), x.end()
#define uni(x) x.erase(unique(all(x)), x.end());
#define BUG(x) cout << #x << " = " << x << endl
#define BUGP(x) cout << #x << " = " << x._1 << ", " << x._2 << endl
#define PR(x,a,b) {cout << #x << " = "; FOR (_,a,b) cout << x[_] << ' '; cout << endl;}
#define CON(x) {cout << #x << " = "; for(auto _i:x) cout << _i << ' '; cout << endl;}
#define mod 1000000007
#define pi acos(-1)
#define eps 1e-7
#define pb push_back
#define sqr(x) (x) * (x)
#define _1 first
#define _2 second

int n, m, u, v, deg[100005], ans, dp[100005];
vector<int> adj[100005];
vector<pair<int, int> > nodes;

int main() {
  ios::sync_with_stdio(0);
  cin >> n >> m;
  while (m--) {
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
    deg[v]++;
    deg[u]++;
  }
  REP (i, n) nodes.pb({deg[i], i});
  sort(all(nodes));
  for (auto p: nodes) {
    v = p._2;
    dp[v] = 1;
    for (int pre: adj[v]) if (deg[pre] < deg[v]) dp[v] = max(dp[v], 1 + dp[pre]);
    ans = max(ans, dp[v]);
  }
  cout << ans;
}
