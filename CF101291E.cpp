#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

const int maxn = 312;

int n, k, t[maxn];

int main() {
  scanf("%d%d", &n, &k);
  FOR(i, 1, n) scanf("%d", t + i);
  multiset<int> tt;
  FOR(i, 1, k) tt.insert(t[i]);
  ll ans = 0, pre = 0;
  while (!tt.empty()) {
    pre += *tt.begin();
    ans += pre;
    tt.erase(tt.find(*tt.begin()));
    if (k < n) tt.insert(t[++k]);
  }
  printf("%lld", ans);
}