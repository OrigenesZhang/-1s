#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(int)(a)-1)
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

long long t, n, ans, val, a, b, cur;

int main() {
  ios::sync_with_stdio(0);
  cin >> t;
  FOR (cas, 1, t) {
    cout << "Case #" << cas << ": ";
    cin >> n;
    ans = cur = 0;
    REP (i, n + 1) cin >> val, ans += val;
    REP (i, n) cin >> a >> b, cur = max(cur, b);
    cout << ans + cur << endl;
  }
}