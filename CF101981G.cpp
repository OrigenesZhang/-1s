#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(int)(a)-1)
#define BUG(x) cout << #x << " = " << x << endl;
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

long long t, n;

long long inv(long long x) {
  long long res = 1;
  FORD (i, 30, 0) {
    res = (res * res) % mod;
    if ((1 << i) & (mod - 2)) res = (res * x) % mod;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(0);
  scanf("%d", &t);
  long long inv24 = inv(24);
  while (t--) {
    scanf("%d", &n);
    long long res = (inv24 * n) % mod;
    FOR (i, 1, 3) res = (res * (n + i)) % mod;
    printf("%d\n", res);
  }
}

[close]
