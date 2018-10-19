#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(int)(a)-1)
#define reset(a,b) memset(a, b, sizeof(a))
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

long long t, n, lis[200500];

int main() {
  ios::sync_with_stdio(0);
  cin >> t;
  FOR (cas, 1, t) {
    cout << "Case #" << cas << ": ";
    reset(lis, 0);
    cin >> n;
    FOR (i, 1, n) cin >> lis[i];
    n++;
    FORD (i, n, 1) lis[i] -= lis[i - 1];
    int pt = 4;
    long long cur = 0;
    FOR (i, 1, n) {
      if (lis[i] > 0) cur += lis[i];
      while (pt - i < 3) pt++;
      while (cur > 0 && pt <= n) {
        if (lis[pt] >= 0) {
          pt++;
          continue;
        }
        if (cur + lis[pt] <= 0) lis[pt] += cur, cur = 0;
        else cur += lis[pt], lis[pt] = 0, pt++;
      }
    }
    bool flag = false;
    FOR (i, 1, n) if (lis[i] < 0) flag = true;
    if (flag || cur > 0) cout << "No" << endl;
    else cout << "Yes" << endl;
  }
}

[close]
