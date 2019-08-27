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

const int maxn = 1123;
const int maxr = 105;
const int MOD = 888888887;

bool vis[maxn][maxr][maxr][2];
int dp[maxn][maxr][maxr][2], len, a, need = -1, k;
char b[maxn], l[maxn], r[maxn];

inline int add(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}

int dfs(int pos, int rem, int cnt, bool small) {
  if (pos == len + 1) return !rem && cnt == need;
  if (vis[pos][rem][cnt][small]) return dp[pos][rem][cnt][small];
  vis[pos][rem][cnt][small] = true;
  int &ret = dp[pos][rem][cnt][small];
  ret = 0;
  if (small) {
    ret = add(ret, dfs(pos + 1, rem * 10 % a, cnt, true));
    if (cnt < need) ret = add(ret, dfs(pos + 1, (rem * 10 + 1) % a, cnt + 1, true));
    FOR(d, 2, 9) ret = add(ret, dfs(pos + 1, (rem * 10 + d) % a, cnt, true));
  } else {
    ret = add(ret, dfs(pos + 1, rem * 10 % a, cnt, b[pos] > 0));
    if (cnt < need && b[pos] >= 1) ret = add(ret, dfs(pos + 1, (rem * 10 + 1) % a, cnt + 1, b[pos] != 1));
    FOR(d, 2, b[pos] - 1) ret = add(ret, dfs(pos + 1, (rem * 10 + d) % a, cnt, true));
    if (b[pos] >= 2) ret = add(ret, dfs(pos + 1, (rem * 10 + b[pos]) % a, cnt, false));
  }
  return ret;
}

int solve(char *now) {
  len = strlen(now + 1);
  FOR(i, 1, len) b[i] = now[i] - '0';
  reset(vis, 0);
  return dfs(1, 0, 0, false);
}

bool check(char *now) {
  len = strlen(now + 1);
  FOR(i, 1, len) b[i] = now[i] - '0';
  int rem = 0, cnt = 0;
  FOR(i, 1, len) {
    cnt += b[i] == 1;
    rem = (rem * 10 + b[i]) % a;
  }
  return !rem && cnt == need;
}

int main() {
  scanf("%s%s%d%d", l + 1, r + 1, &a, &k);
  FOR(i, 2, 100) if (i * (i - 1) == 2 * k) {
      need = i;
      break;
    }
  if (need == -1) {
    puts("0");
    return 0;
  }
  assert(need <= 100);
  printf("%d", add(add(solve(r), MOD - solve(l)), check(l)));
}
