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

int n, c, download[555], store[555], d[555], s[555], dp[555][10004], prei[555][10004], prej[555][10004], tran[555];
vector<pair<int, int> > v;
vector<int> ans;

int main() {
  ios::sync_with_stdio(0);
  cin >> n >> c;
  REP (i, n) cin >> d[i] >> s[i], v.pb({s[i] - max(d[i], s[i]), i});
  sort(all(v));
  REP (i, n) download[i + 1] = d[v[i]._2], store[i + 1] = s[v[i]._2], tran[i + 1] = v[i]._2 + 1;
  FOR (i, 1, n) FOR (j, 1, c) {
    dp[i][j] = dp[i][j - 1];
    prei[i][j] = i;
    prej[i][j] = j - 1;
    if (dp[i - 1][j] > dp[i][j]) dp[i][j] = dp[i - 1][j], prei[i][j] = i - 1, prej[i][j] = j;
    if (j >= store[i]) {
      int pre = j - store[i];
      if (pre + max(download[i], store[i]) > c) continue;
      if (dp[i - 1][pre] + 1 > dp[i][j]) {
        dp[i][j] = dp[i - 1][pre] + 1;
        prei[i][j] = i - 1;
        prej[i][j] = pre;
      }
    }
  }
  int curi = n, curj = c;
  while (curi > 0) {
    int nexi = prei[curi][curj];
    int nexj = prej[curi][curj];
    if (curi - nexi == 1 && dp[curi][curj] == 1 + dp[nexi][nexj]) ans.pb(curi);
    curi = nexi;
    curj = nexj;
  }
  reverse(all(ans));
  cout << ans.size() << endl;
  for (auto i: ans) cout << tran[i] << ' ';
}
