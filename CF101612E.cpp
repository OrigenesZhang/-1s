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

int n, cnt[1100100], val, ans[300500], need[300500];
vector<int> v, vv;

int main() {
  freopen("equal.in", "r", stdin);
  freopen("equal.out", "w", stdout);
  cin >> n;
  FOR (i, 1, n) {
    cin >> val;
    cnt[val]++;
  }
  FOR (i, 1, 1000000) if (cnt[i]) {
    ans[0]++;
    bool flag = false;
    for (int j = i * 2; j <= 1000000; j += i) if (cnt[j]) {
      flag = true;
      break;
    }
    if (flag) v.pb(cnt[i]);
    else vv.pb(cnt[i]);
  }
  reset(need, 55);
  sort(all(v));
  int cur = 0;
  REP (i, v.size()) cur += v[i], need[i + 1] = cur;

  if (vv.size() > 1) {
    sort(all(vv));
    vv[1] += vv[0];
    cur = vv[1];
    FOR (i, 2, vv.size() - 1) v.pb(vv[i]);
    sort(all(v));
    need[1] = min(need[1], cur);
    REP (i, v.size()) cur += v[i], need[i + 2] = min(need[i + 2], cur);
  }

  FOR (i, 1, n) if (need[i] <= n) ans[need[i]] = -1;
  FOR (i, 1, n) ans[i] += ans[i - 1];
  ans[n] = 1;
  FOR (i, 0, n) cout << ans[i] << ' ';
}

[close]
