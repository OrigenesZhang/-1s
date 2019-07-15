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
 
const int maxn = 25;
 
ll go(int s, int a, int b, int c) {
  ll ret = 0;
  vector<pii> w{mp(a, 0), mp(b, 1), mp(c, 2)};
  sort(all(w));
  do {
    ret += w[0]._1 * w[0]._1 * w[1]._1;
    ret += w[0]._1 * w[1]._1 * w[1]._1;
    ret += (s - w[0]._1 - w[1]._1) * w[0]._1 * w[1]._1 * 2;
  } while (next_permutation(all((w))));
  return ret;
}
 
int id[maxn];
pair<ll, ll> val[maxn];
 
int main() {
  int n;
  scanf("%d", &n);
  FOR(i, 1, n) {
    id[i] = i;
    int s, a, b, c;
    scanf("%d%d%d%d", &s, &a, &b, &c);
    val[i] = {go(s, a, b, c), s * s * s};
  }
  sort(id + 1, id + n + 1, [](auto a, auto b) {
    ll va = val[a]._1 * val[b]._2, vb = val[b]._1 * val[a]._2;
    return va == vb ? a < b : va < vb;
  });
  FOR(i, 1, n) printf("%d ", id[i]);
}