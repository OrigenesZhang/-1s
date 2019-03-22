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

int n, lis[1000006], sieve[10000007], L[1000006], R[1000006], limit, ans[1000006];
vector<int> v;
unordered_map<int, vector<int> > pos;

void f(int prime) {
  v.clear();
  for (int i = prime; i < limit; i += prime) {
    sieve[i] = 1;
    for (auto k: pos[i]) v.pb(k);
  }
  sort(all(v));
  REP (i, v.size()) {
    if (i) L[v[i]] = max(L[v[i]], 1 + v[i - 1]);
    if (i < v.size() - 1) R[v[i]] = min(R[v[i]], v[i + 1] - 1);
  }
}

int solve(int l, int r) {
  int chs = -1;
  for (int pl = l, pr = r; pl <= pr; pl++, pr--) {
    if (L[pl] <= l && R[pl] >= r) {
      chs = pl;
      break;
    }
    if (L[pr] <= l && R[pr] >= r) {
      chs = pr;
      break;
    }
  }
  if (chs == -1) return 0;
  else {
    if (chs > l) {
      int x = solve(l, chs - 1);
      if (!x) return 0;
      ans[x] = chs;
    }
    if (chs < r) {
      int x = solve(chs + 1, r);
      if (!x) return 0;
      ans[x] = chs;
    }
    return chs;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin >> n;
  FOR (i, 1, n) cin >> lis[i], pos[lis[i]].pb(i), L[i] = 1, R[i] = n;
  limit = 10000000;
  f(2);
  f(3);
  f(5);
  for (int i = 6; i < limit; i++) {
    if (!sieve[i + 1] && i + 1 < limit) {
      f(i + 1);
    }
    if (!sieve[i + 5] && i + 5 < limit) {
      f(i + 5);
    }
  }
  if (solve(1, n)) {
    FOR (i, 1, n) cout << ans[i] << ' ';
  } else cout << "impossible";
}
