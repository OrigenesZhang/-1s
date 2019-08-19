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
 
const int maxn = 312345;
 
ll C[maxn];
 
struct Solver {
  int pos[maxn], id[maxn];
  int lo, hi, shift, n;
 
  void init(int n) {
    lo = 1, hi = n, shift = 0;
    this->n = n;
  }
 
  void insert(int x, int i) {
    pos[i] = x;
    id[x] = i;
  }
 
  int query(int i) {
    if (pos[i] <= lo) return lo + shift;
    if (pos[i] >= hi) return hi + shift;
    return pos[i] + shift;
  }
 
  void ml(int k);
 
  void mr(int k);
} row, col;
 
int LL, LR, RL, RR;
bool mark[maxn];
 
void fix(int i) {
  if (mark[i]) return;
  if (row.pos[i] <= row.lo && col.pos[i] <= col.lo) LL++, mark[i] = true;
  else if (row.pos[i] <= row.lo && col.pos[i] >= col.hi) LR++, mark[i] = true;
  else if (row.pos[i] >= row.hi && col.pos[i] <= col.lo) RL++, mark[i] = true;
  else if (row.pos[i] >= row.hi && col.pos[i] >= col.hi) RR++, mark[i] = true;
}
 
void Solver::ml(int k) {
  while (lo < hi && lo + shift - k < 1) fix(id[++lo]);
  if (lo + shift - k < 1) shift = 1 - lo;
  else shift -= k;
}
 
void Solver::mr(int k) {
  while (lo < hi && hi + shift + k > n) fix(id[--hi]);
  if (hi + shift + k > n) shift = n - hi;
  else shift += k;
}
 
ll get() {
  if (row.lo == row.hi && col.lo == col.hi) return C[LL + LR + RL + RR];
  if (row.lo == row.hi) return C[LL + RL] + C[LR + RR];
  if (col.lo == col.hi) return C[LL + LR] + C[RL + RR];
  return C[LL] + C[LR] + C[RL] + C[RR];
}
 
char op[5];
 
void solve() {
  int n, m;
  scanf("%d%d", &n, &m);
  row.init(n); col.init(n);
  FOR(i, 1, n) {
    int x, y;
    scanf("%d%d", &x, &y);
    row.insert(x, i);
    col.insert(y, i);
  }
  LL = LR = RL = RR = 0;
  fill(mark, mark + n + 1, false);
  fix(row.id[1]); fix(row.id[n]);
  fix(col.id[1]); fix(col.id[n]);
  while (m--) {
    scanf("%s", op);
    if (op[0] == '!') printf("%lld\n", get());
    else {
      int k;
      scanf("%d", &k);
      if (op[0] == 'U') row.ml(k);
      else if (op[0] == 'D') row.mr(k);
      else if (op[0] == 'L') col.ml(k);
      else if (op[0] == 'R') col.mr(k);
      else printf("%d %d\n", row.query(k), col.query(k));
    }
  }
}
 
int main() {
  REP(i, maxn) C[i] = ll(i) * (i - 1) / 2;
  int T;
  scanf("%d", &T);
  while (T--) solve();
}