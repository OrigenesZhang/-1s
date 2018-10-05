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

int n, m, par[100500], edge[100500], k, val, ans, rnk[100500];

int get(int x) {
  if (x == par[x]) return x;
  return par[x] = get(par[x]);
}

void merge(int x, int y) {
  x = get(x);
  y = get(y);
  if (rnk[x] > rnk[y]) par[y] = x;
  else par[x] = y;
  if (rnk[x] == rnk[y]) rnk[y]++;
}

int main() {
  ios::sync_with_stdio(0);
  cin >> m >> n;
  FOR (i, 1, m) par[i] = i;
  FOR (i, 1, m) {
    cin >> k;
    while (k--) {
      cin >> val;
      if (!edge[val]) edge[val] = i;
      else {
        int x = edge[val];
        int y = i;
        if (get(x) != get(y)) ans++, merge(x, y);
      }
    }
  }
  cout << ans;
}