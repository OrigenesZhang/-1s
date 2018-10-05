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

int n, ans[100500], val;
pair<int, int> p[100500];

int main() {
  ios::sync_with_stdio(0);
  cin >> n;
  REP (i, n) cin >> val, p[i] = {val, i};
  sort(p, p + n);
  REP (i, n) ans[p[i]._2] = n - i;
  REP (i, n) cout << ans[i] << ' ';
}