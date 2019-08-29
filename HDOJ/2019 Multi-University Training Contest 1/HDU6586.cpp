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
#define uni(x) (x).erase(unique(all(x)), (x).end())
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

const int maxn = 112345;

char s[maxn], ans[maxn];
int n, k;
int L[maxn], R[maxn], f[maxn][26], g[maxn][26], have[26];

bool check(int j, int len) {
  int mx = 0, mn = 0;
  REP(i, 26) {
    if (have[i] + g[j][i] < L[i]) return false;
    mx += have[i] + min(R[i] - have[i], g[j][i]);
    mn += max(L[i] - have[i], 0);
  }
  return mx >= k && mn <= k - len;
}

void solve() {
  n = strlen(s + 1);
  REP(i, 26) scanf("%d%d", L + i, R + i);
  reset(f[n], -1);
  reset(g[n], 0);
  reset(have, 0);
  ROF(i, n - 1, 0) {
    memcpy(f[i], f[i + 1], sizeof(f[i]));
    memcpy(g[i], g[i + 1], sizeof(g[i]));
    f[i][s[i + 1] - 'a'] = i + 1;
    g[i][s[i + 1] - 'a']++;
  }
  int j = 0, len = 0;
  bool good = true;
  while (j <= n && len < k) {
    bool go = false;
    REP(i, 26) if (f[j][i] != -1 && have[i] < R[i]) {
      have[i]++;
      if (check(f[j][i], len + 1)) {
        go = true;
        ans[len++] = i + 'a';
        j = f[j][i];
        break;
      }
      have[i]--;
    }
    if (!go) {
      good = false;
      break;
    }
  }
  ans[len] = '\0';
  puts(good ? ans : "-1");
}

int main() {
  while (scanf("%s%d", s + 1, &k) == 2) solve();
}