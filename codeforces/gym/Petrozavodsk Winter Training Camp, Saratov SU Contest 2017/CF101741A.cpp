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

#define all(x) (x).begin(), (x).end()
#define uni(x) x.erase(unique(all(x)), x.end())
#define sqr(x) ((x) * (x))
using LL = long long;

const int N = 512345;

int a[N], b[N], c[N];
int na, nb, nc, d;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  while (cin >> d >> na >> nb >> nc) {
    for (int i = 0; i < na; ++i) cin >> a[i];
    for (int i = 0; i < nb; ++i) cin >> b[i];
    for (int i = 0; i < nc; ++i) cin >> c[i];

    //1:
    LL ans = 0;
    for (int i = 0; i < na; ++i) {
      int numb = upper_bound(b, b + nb, a[i] + d) - upper_bound(b, b + nb, a[i] - 1);
      int numc = upper_bound(c, c + nc, a[i] + d) - upper_bound(c, c + nc, a[i] - 1);
      ans += LL(numb) * numc;
    }

    //2:
    for (int i = 0; i < nb; ++i) {
      int numa = upper_bound(a, a + na, b[i] + d) - upper_bound(a, a + na, b[i]);
      int numc = upper_bound(c, c + nc, b[i] + d) - upper_bound(c, c + nc, b[i] - 1);
      ans += LL(numa) * numc;
    }

    for (int i = 0; i < nc; ++i) {
      int numa = upper_bound(a, a + na, c[i] + d) - upper_bound(a, a + na, c[i]);
      int numb = upper_bound(b, b + nb, c[i] + d) - upper_bound(b, b + nb, c[i]);
      ans += LL(numa) * numb;
    }

    cout << ans << '\n';
  }
  return 0;
}