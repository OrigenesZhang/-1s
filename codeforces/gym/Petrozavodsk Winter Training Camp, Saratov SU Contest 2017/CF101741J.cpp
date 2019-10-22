#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define ROF(i, a, b) for (int i = (a); i >= (b); --i)
#define REP(i, a) FOR(i, 0, int(a) - 1)
#define reset(a, b) memset(a, b, sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define pb push_back
#define _1 first
#define _2 second
#define mp make_pair

#define all(x) (x).begin(), (x).end()
#define uni(x) x.erase(unique(all(x)), x.end())
#define sqr(x) ((x) * (x))
using LL = long long;
using pii = pair<int, int>;

const int N = 212345;
const int MOD = int(1e9) + 7;

int n, m, a[N], num;
LL ans[N], f[N][21];

void solve(int l, int r, vector<pair<int, pii>> &q) {
  if (l == r) {
    for (auto &it : q) ans[it._1] = 1 + (a[l] == 0);
    return;
  }

  int mid = l + (r - l) / 2;
  reset(f[mid], 0);
  reset(f[mid + 1], 0);
  f[mid][a[mid]] = 1;
  f[mid][0] += 1;
  f[mid + 1][a[mid + 1]] = 1;
  f[mid + 1][0] += 1;

  for (int i = mid - 1; i >= l; --i) {
    reset(f[i], 0);
    for (int j = 0; j < m; ++j) {
      f[i][j] = (f[i][j] + f[i + 1][j]) % MOD;
      f[i][(j + a[i]) % m] = (f[i][(j + a[i]) % m] + f[i + 1][j]) % MOD;
    }
  }
  for (int i = mid + 2; i <= r; ++i) {
    reset(f[i], 0);
    for (int j = 0; j < m; ++j) {
      f[i][j] = (f[i][j] + f[i - 1][j]) % MOD;
      f[i][(j + a[i]) % m] = (f[i][(j + a[i]) % m] + f[i - 1][j]) % MOD;
    }
  }

  vector<pair<int, pii>> ql, qr;
  for (auto &it : q) {
    if (it._2._2 <= mid) ql.pb(it);
    else if (it._2._1 > mid) qr.pb(it);
    else {
      //cout << l << ' ' << r << endl;
      for (int i = 0; i < m; ++i) {
        ans[it._1] = (ans[it._1] + f[it._2._1][i] * f[it._2._2][(m - i) % m]) % MOD;
        //cout << i << ' ' << f[it._2._1][i] << ' ' << f[it._2._2][(m - i) % m] << endl;
      }
    }
  }
  solve(l, mid, ql);
  solve(mid + 1, r, qr);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    a[i] %= m;
  }
  cin >> num;
  vector<pair<int, pii>> q;
  for (int i = 0; i < num; ++i) {
    int l, r;
    cin >> l >> r;
    q.pb(mp(i, mp(l, r)));
  }

  solve(1, n, q);
  for (int i = 0; i < num; ++i) cout << ans[i] << '\n';
  return 0;
}