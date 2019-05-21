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

void exgcd(ll a, ll b, ll &x, ll &y) {
  if (!b) {
    x = 1, y = 0;
    return;
  }
  exgcd(b, a % b, y, x);
  y -= (a / b) * x;
}

int main() {
  ll a, b, c, x1, x2, y1, y2;
  cin >> a >> b >> c >> x1 >> x2 >> y1 >> y2;
  c = -c;
  if (c < 0) a = -a, b = -b, c = -c;
  if (a < 0) {
    a = -a;
    swap(x1, x2);
    x1 = -x1, x2 = -x2;
  }
  if (b < 0) {
    b = -b;
    swap(y1, y2);
    y1 = -y1, y2 = -y2;
  }
  if (x1 > x2 || y1 > y2) {
    cout << 0;
    return 0;
  }
  if (!a && !b) {
    cout << (x2 - x1 + 1) * (y2 - y1 + 1) * (c == 0);
    return 0;
  }
  if (!a) {
    ll r = c / b;
    if (c % b == 0 && y1 <= r && r <= y2) cout << x2 - x1 + 1;
    else cout << 0;
    return 0;
  }
  if (!b) {
    ll r = c / a;
    if (c % a == 0 && x1 <= r && r <= x2) cout << y2 - y1 + 1;
    else cout << 0;
    return 0;
  }
  ll x, y, d = __gcd(a, b);
  if (c % d) {
    cout << 0;
    return 0;
  }
  a /= d, b /= d, c /= d;
  exgcd(a, b, x, y);
  x *= c, y *= c;
  ll lo = max(ceil(double(x1 - x) / b), ceil(double(y - y2) / a));
  ll hi = min(floor(double(x2 - x) / b), floor(double(y - y1) / a));
  cout << (hi - lo + 1) * (lo <= hi);
}