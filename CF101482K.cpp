#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(int)(a)-1)
#define BUG(x) cout << #x << " = " << x << endl
#define PR(x,a,b) { cout << #x << " = "; FOR(_,a,b) cout << x[_] << ' '; cout << endl; }
#define CON(x) { cout << #x << " = "; for (auto i:x) cout << i << ' '; cout << endl; }
#define mod 1000000007
#define eps 1e-8
#define pb push_back
#define _1 first
#define _2 second

long long n, len, t, pos[2222], ans[10100100], mi, ma, tot;
multiset<long long> s;

long long gcd(long long a, long long b) {
  return b ? gcd(b, a % b) : a;
}

int main() {
  cin >> n >> len >> t;
  REP (i, n) cin >> pos[i];

  REP (i, n) if (!ans[pos[i]]) {
    long long cur = pos[i], tmp = 0;
    REP (j, n) s.insert(pos[j]);
    while (s.size()) {
      auto it = s.lower_bound(cur);
      if (it == s.end()) it = s.begin();
      auto nex = *it;
      s.erase(it);
      tmp += (nex + len - cur) % len + t;
      cur = (nex + t) % len;
    }
    ans[pos[i]] = tmp;
  }

  REP (i, n) {
    int cur = (pos[i] + len - 1) % len;
    while (!ans[cur]) {
      ans[cur] = ans[(cur + 1) % len] + 1;
      cur = (cur + len - 1) % len;
    }
  }

  mi = ma = ans[0];
  REP (i, len) mi = min(mi, ans[i]), ma = max(ma, ans[i]), tot += ans[i];
  long long z = gcd(tot, len);
  tot /= z;
  len /= z;
  cout << mi << endl << ma << endl << tot << '/' << len;
}