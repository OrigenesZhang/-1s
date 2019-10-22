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

const int M1 = 998244353;
const int M2 = 1e9 + 7;
const int B1 = 131;
const int B2 = 233;
const int maxn = 112345;

inline int add(int a, int b, int M) {
  a += b;
  if (a >= M) a -= M;
  return a;
}

inline int mul(int a, int b, int M) {
  return ll(a) * b % M;
}

int n, q;
char s[maxn], t[maxn];
int p1[maxn], p2[maxn], f1[maxn], f2[maxn], g1[maxn], g2[maxn], len[maxn];
bool vis[maxn];
set<pii> h[maxn];
map<pii, int> ans[maxn];

inline pii query(int l, int r) {
  return {add(f1[r], M1 - mul(f1[l - 1], p1[r - l + 1], M1), M1), add(f2[r], M2 - mul(f2[l - 1], p2[r - l + 1], M2), M2)};
}

void solve(int m) {
  vis[m] = true;
  vector<pair<pii, int>> now(n - m + 1);
  FOR(i, m, n) now[i - m] = {query(i - m + 1, i), i};
  sort(all(now));
  int tot = now.size();
  int j;
  for (int i = 0; i < tot; i = j) {
    j = i;
    while (j < tot && now[i]._1 == now[j]._1) j++;
    if (!h[m].count(now[i]._1)) continue;
    int last = -n, cur = 0;
    FOR(k, i, j - 1) if (now[k]._2 - last >= m) {
      cur++;
      last = now[k]._2;
    }
    ans[m][now[i]._1] = cur;
  }
}

int solve(int m, int h1, int h2) {
  if (!vis[m]) solve(m);
  return ans[m][mp(h1, h2)];
}

int main() {
  scanf("%d%d", &n, &q);
  scanf("%s", s + 1);
  p1[0] = p2[0] = 1;
  FOR(i, 1, n) {
    p1[i] = mul(p1[i - 1], B1, M1);
    p2[i] = mul(p2[i - 1], B2, M2);
  }
  FOR(i, 1, n) {
    f1[i] = add(mul(f1[i - 1], B1, M1), s[i] - 'a', M1);
    f2[i] = add(mul(f2[i - 1], B2, M2), s[i] - 'a', M2);
  }
  FOR(i, 1, q) {
    scanf("%s", t + 1);
    len[i] = strlen(t + 1);
    FOR(j, 1, len[i]) {
      g1[i] = add(mul(g1[i], B1, M1), t[j] - 'a', M1);
      g2[i] = add(mul(g2[i], B2, M2), t[j] - 'a', M2);
    }
    h[len[i]].emplace(g1[i], g2[i]);
  }
  FOR(i, 1, q) printf("%d\n", solve(len[i], g1[i], g2[i]));
}