#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(int)(a)-1)
#define BUG(x) cout << #x << " = " << x << endl;
#define mod 1000000007

long long t, n, k, ans;

long long expo(long long a, long long b) {
  long long res = 1;
  FORD (i, 30, 0) {
    res = (res * res) % mod;
    if ((1 << i) & b) res = (res * a) % mod;
  }
  return res;
}

int main() {
  cin >> t;
  FOR (cas, 1, t) {
    cout << "Case #" << cas << ": ";
    cin >> n >> k;
    if (k > n) {
      cout << 0 << endl;
      continue;
    }
    ans = expo(2, n) - 1;
    long long tmp = 1;
    FOR (i, 1, k - 1) {
      tmp = (tmp * (1 + n - i)) % mod;
      tmp = (tmp * expo(i, mod - 2)) % mod;
      ans = (ans - tmp) % mod;
    }
    cout << (ans + mod) % mod << endl;
  }
}