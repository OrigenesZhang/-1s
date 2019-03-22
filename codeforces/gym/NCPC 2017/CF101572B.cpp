#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (long long i = (a); i <= (b); i++)
#define FORD(i,a,b) for (long long i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(long long)(a)-1)
#define reset(a,b) memset(a,b,sizeof(a))
#define all(x) x.begin(), x.end()
#define uni(x) x.erase(unique(all(x)), x.end());
#define BUG(x) cout << #x << " = " << x << endl
#define BUGP(x) cout << #x << " = " << x._1 << ", " << x._2 << endl
#define PR(x,a,b) {cout << #x << " = "; FOR (_,a,b) cout << x[_] << ' '; cout << endl;}
#define CON(x) {cout << #x << " = "; for(auto _i:x) cout << _i << ' '; cout << endl;}
#define mod 1000000007
#define pi acos(-1)
#define eps 1e-8
#define pb push_back
#define sqr(x) (x) * (x)
#define _1 first
#define _2 second
using namespace std;

int fir, oth, n;
string s;
vector<pair<pair<int, int>, string>> v;
vector<string> ans;

int get() {
  int x, y;
  scanf("%d.%d", &x, &y);
  return x * 100 + y;
}

int main() {
  cin >> n;
  v.clear();
  REP (i, n) cin >> s, fir = get(), oth = get(), v.pb({{oth, fir}, s});
  sort(all(v));

  int best = mod;
  FOR (i, 3, v.size() - 1) {
    int cur = v[i]._1._2 + v[0]._1._1 + v[1]._1._1 + v[2]._1._1;
    if (cur < best) {
      best = cur;
      ans.clear();
      ans.pb(v[i]._2);
      REP (j, 3) ans.pb(v[j]._2);
    }
  }
  REP (i, 4) {
    int cur = v[i]._1._2;
    REP (j, 4) if (j != i) cur += v[j]._1._1;
    if (cur < best) {
      best = cur;
      ans.clear();
      ans.pb(v[i]._2);
      REP (j, 4) if (j != i) ans.pb(v[j]._2);
    }
  }

  printf("%d.%02d\n", best / 100, best % 100);
  for (auto s: ans) cout << s << endl;
}