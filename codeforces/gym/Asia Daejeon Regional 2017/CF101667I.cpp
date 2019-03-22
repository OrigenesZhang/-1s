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
#define y1 asdfasd
#define y0 ajajaj

int n, val, kmp[2000006];
vector<int> lis;

int main() {
  ios::sync_with_stdio(0);
  cin >> n;
  REP (i, n) cin >> val, lis.pb(val);
  reverse(all(lis));
  REP (i, n) lis.pb(-1);
  kmp[0] = -1;
  kmp[1] = 0;
  int cur = 0;
  FOR (i, 2, lis.size()) {
    while (cur != -1 && lis[i - 1] != -1 && lis[i - 1] != lis[cur]) cur = kmp[cur];
    kmp[i] = ++cur;
  }
  int k = n - 1, p = 1;
  FOR (i, 1, n * 2) {
    int period = i - kmp[i];
    int newk = max(0, n - i);
    int newp = period;
    if (newk + newp < k + p || newk + newp == k + p && newp < p) k = newk, p = newp;
  }
  cout << k << ' ' << p;
}
