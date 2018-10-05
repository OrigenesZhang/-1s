#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (long long i = (a); i <= (b); i++)
#define FORD(i,a,b) for (long long i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(long long)(a)-1)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl;
#define BUGP(x) cout << #x << " = " << x._1 << ' ' << x._2 << endl;
#define pb push_back
#define _1 first
#define _2 second
#define mod 1000000007
#define wait asfa

long long n, cost[5500], ori;
multiset<long long> v01, v10, v11;
string a, b;

long long calc() {
  long long res = 0, cur = ori;
  for (auto i: v10) {
    cur += i;
    res += cur;
  }
  for (auto i: v01) {
    cur += i;
    res += cur;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(0);
  cin >> n;
  REP (i, n) cin >> cost[i];
  cin >> a >> b;
  REP (i, n) {
    if (a[i] == '0' && b[i] == '1') v01.insert(cost[i]);
    if (a[i] == '1' && b[i] == '1') v11.insert(-cost[i]);
    if (a[i] == '1' && b[i] == '0') v10.insert(-cost[i]);
    if (a[i] == '1') ori += cost[i];
  }

  long long ans = calc();
  while (v11.size()) {
    auto it = v11.begin();
    v01.insert(-*it);
    v10.insert(*it);
    v11.erase(it);
    ans = min(ans, calc());
  }

  cout << ans;
}