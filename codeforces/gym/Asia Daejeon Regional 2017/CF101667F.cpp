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

long long n, m;

pair<long long, long long> solve(long long n, long long m) {
  if (n == 1) return {1, 1};
  long long q = sqr(n / 2);
  if (m <= q) {
    auto p = solve(n / 2, q + 1 - m);
    return {p._2, n / 2 + 1 - p._1};
  } else if (m <= 2 * q) {
    auto p = solve(n / 2, m - q);
    return {p._1, p._2 + n / 2};
  } else if (m <= 3 * q) {
    auto p = solve(n / 2, m - 2 * q);
    return {p._1 + n / 2, p._2 + n / 2};
  } else {
    auto p = solve(n / 2, 4 * q + 1 - m);
    return {n + 1 - p._2, p._1};
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin >> n >> m;
  auto p = solve(n, m);
  cout << p._1 << ' ' << p._2;
}
