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

const int maxn = 112345;

int k, r, n;
bool vis[maxn];

int main() {
  scanf("%d%d%d", &n, &k, &r);
  REP(i, k) {
    int p;
    scanf("%d", &p);
    vis[p] = true;
  }
  int cnt = 0, ans = 0;
  FOR(i, 1, r - 1) cnt += vis[i];
  FOR(i, r, n) {
    cnt -= vis[i - r];
    cnt += vis[i];
    ROF(j, i, 1) {
      if (cnt >= 2) break;
      if (vis[j]) continue;
      vis[j] = true;
      cnt++, ans++;
    }
  }
  printf("%d", ans);
}