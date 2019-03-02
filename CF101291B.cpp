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

int b[15], p[15], n, m;
set<ll> lis, ans;

void dfs(int i, ll l, ll r) {
  if (i > m) return;
  if (l == r) lis.insert(r + l);
  dfs(i + 1, l + p[i + 1], r);
  dfs(i + 1, l, r + p[i + 1]);
  dfs(i + 1, l, r);
}

int main() {
  scanf("%d%d", &n, &m);
  FOR(i, 1, n) scanf("%d", b + i);
  FOR(i, 1, m) scanf("%d", p + i);
  dfs(0, 0, 0);
  FOR(i, 1, n) for (auto it : lis) ans.insert(it + b[i]);
  for (auto it : ans) printf("%lld\n", it);
}