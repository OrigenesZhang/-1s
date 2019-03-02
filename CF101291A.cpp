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

const int maxn = 55;

char s[maxn];
int dp[maxn];

int main() {
  scanf("%s", s + 1);
  int n = strlen(s + 1), ans = 0;
  FOR(i, 1, n) dp[i] = 1;
  FOR(i, 2, n) FOR(j, 1, i - 1) if (s[i] > s[j]) chkmax(dp[i], dp[j] + 1);
  FOR(i, 1, n) chkmax(ans, dp[i]);
  printf("%d", 26 - ans);
}
