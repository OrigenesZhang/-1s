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

int k, n, val, cnt[1111];
pair<int, int> p[1111];

bool ok() {
  FOR (i, 2, k) if (p[i]._1 != p[1]._1) return false;
  return true;
}

int main() {
  cin >> k >> n;
  REP (i, n) cin >> val, cnt[val]++;
  FOR (i, 1, k) p[i] = {cnt[i], i};
  sort(p + 1, p + 1 + k);
  p[1]._1 += 1;
  if (ok()) {
    cout << "+" << p[1]._2;
    return 0;
  }
  p[k]._1 -= 1;
  if (ok()) {
    cout << "-" << p[k]._2 << " +" << p[1]._2;
    return 0;
  }
  p[1]._1 -= 1;
  if (ok()) {
    cout << "-" << p[k]._2;
  } else cout << "*";
}