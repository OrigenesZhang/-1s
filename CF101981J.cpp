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

int n, k, sieve[1100100], val;
long long ans;
vector<int> contain[1100100], id[1100100], pri;

int main() {
  ios::sync_with_stdio(0);
  FOR (i, 2, 1000000) if (!sieve[i]) {
    for (int j = i + i; j <= 1000000; j += i) sieve[j] = 1, contain[j].pb(i);
    contain[i].pb(i);
    pri.pb(i);
  }
  cin >> n;
  FOR (i, 1, n) {
    cin >> val;
    for (auto prime: contain[val]) id[prime].pb(i);
  }

  for (auto prime: pri) if (id[prime].size()) {
    ans += (long long)n * (n + 1) / 2;
    long long cur = 0;
    for (auto i: id[prime]) {
      ans -= (i - cur - 1) * (i - cur) / 2;
      cur = i;
    }
    ans -= (n - cur) * (n - cur + 1) / 2;
  }

  cout << ans;
}