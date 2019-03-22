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
#define start asfas
#define end jkjkjl

int n, m, start[555], end[555], dur[555], cost[555], fre[555], ini[555], vst[555];
pair<int, int> best[555], ans;
vector<int> from[555], to[555];
set<pair<pair<int, int>, int>> s;

int get(int edge, int aft) {
  if (aft < ini[edge]) return ini[edge];
  else return ini[edge] + fre[edge] * ((aft - ini[edge] + fre[edge]) / fre[edge]);
}

int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  FOR (i, 1, m) cin >> start[i] >> end[i] >> dur[i] >> cost[i] >> fre[i] >> ini[i], best[i] = {mod, mod}, from[start[i]].pb(i), to[end[i]].pb(i);

  for (auto i: from[1]) best[i] = {get(i, 0), 0}, s.insert({best[i], i});

  while (s.size()) {
    auto it = s.begin();
    auto edge = it -> _2;
    s.erase(it);
    if (vst[edge]) continue;
    vst[edge] = 1;

    int timeNow = best[edge]._1 + dur[edge];
    int costNow = best[edge]._2 + cost[edge];

    for (auto i: from[end[edge]]) if (best[i] > make_pair(get(i, timeNow), costNow)) {
      best[i] = {get(i, timeNow), costNow};
      s.insert({best[i], i});
    }
  }

  ans = {mod, mod};
  for (auto edge: to[n]) {
    int timeNow = best[edge]._1 + dur[edge];
    int costNow = best[edge]._2 + cost[edge];
    ans = min(ans, {timeNow, costNow});
  }
  cout << ans._1 << ' ' << ans._2;
}