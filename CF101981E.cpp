#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(int)(a)-1)
#define BUG(x) cout << #x << " = " << x << endl;
#define BUGP(x) cout << #x << " = " << x._1 << ' ' << x._2 << endl;
#define PR(x,a,b) { cout << #x << " = "; FOR(_,a,b) cout << x[_] << ' '; cout << endl; }
#define CON(x) { cout << #x << " = "; for(auto _i: x) cout << _i << ' '; cout << endl; }
#define all(x) x.begin(), x.end()
#define mod 1000000007
#define eps 1e-9
#define sqr(x) ((x) * (x))
#define pi acos(-1)
#define reset(a,b) memset(a, b, sizeof(a))
#define pb push_back
#define _1 first
#define _2 second

int n, k;
string s;
vector<pair<char, int>> v, vv;

int main() {
  ios::sync_with_stdio(0);
  cin >> n >> k >> s;
  for (char c: s) {
    if (v.size() && v.back()._1 == c) {
      auto p = v.back();
      v.pop_back();
      v.pb({p._1, p._2 + 1});
    } else v.pb({c, 1});
    if (v.back()._2 == k) v.pop_back();
  }
  cin >> s;
  for (char c: s) {
    if (vv.size() && vv.back()._1 == c) {
      auto p = vv.back();
      vv.pop_back();
      vv.pb({p._1, p._2 + 1});
    } else vv.pb({c, 1});
    if (vv.back()._2 == k) vv.pop_back();
  }
  if (v == vv) cout << "Yes";
  else cout << "No";
}