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
#define wait asdf

long long n, t, h[100500], pre[100500], wait[100500];

int main() {
  cin >> n >> t;
  FOR (i, 1, n) cin >> h[i], pre[i] = pre[i - 1] + h[i], wait[i] = max(h[i], wait[i - 1]);
  FOR (i, 1, n) {
    if (t < pre[i - 1] + h[i]) cout << 1 << endl;
    else {
      cout << (t - pre[i - 1] - h[i]) / wait[i] + 2 << endl;
    }
  }
}