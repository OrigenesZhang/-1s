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

string a, b;
int n;
vector<int> v;

int main() {
  ios::sync_with_stdio(false);
  cin >> a >> b;
  for (auto c: a) if (c == '1') n++;
  for (auto c: b) if (c == '1') n++;
  if (n & 1) {
    cout << -1;
    return 0;
  }


  int ans = mod;
  n = a.size();
  REP (i, n) {
    v.clear();
    REP (j, n) if (a[j] != b[(i + j) % n]) v.pb(j);
    assert(v.size() % 2 == 0);
    int tmp = 0;
    for (int i = 0; i < v.size(); i += 2) tmp += v[i + 1] - v[i];
    tmp = min(tmp, n - tmp);
    ans = min(ans, tmp);
  }
  cout << ans;
}