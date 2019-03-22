#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(int)(a)-1)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl;
#define PR(x,a,b) { cout << #x << " = "; FOR(_,a,b) cout << x[_] << ' '; cout << endl; }
#define CON(x) { cout << #x << " = "; for (auto i: x) cout << i << ' '; cout << endl; }
#define all(x) x.begin(), x.end()
#define mod 1000000007
#define sqr(x) ((x) * (x))
#define pb push_back
#define _1 first
#define _2 second

int n, k, seg[2500500], rnk[500500];
string s;
pair<pair<int, int>, int> p[500500];

void put(int x, int l, int r, int ll, int rr) {
  if (r < ll || l > rr) return;
  if (l >= ll && r <= rr) {
    seg[x] = r - l + 1;
    return;
  }
  int mid = (l + r) / 2;
  put(x * 2, l, mid, ll, rr);
  put(x * 2 + 1, mid + 1, r, ll, rr);
  seg[x] = max(seg[x], seg[x * 2] + seg[x * 2 + 1]);
}

bool mark(int x) {
  if (x + k - 1 <= n) put(1, 1, n, x, x + k - 1);
  else put(1, 1, n, x, n), put(1, 1, n, 1, x + k - 1 - n);
  return seg[1] == n;
}

int main() {
  ios::sync_with_stdio(0);
  cin >> n >> k >> s;

  REP (i, n) rnk[i] = s[i] - 'a';
  int len = 1;

  FOR (ii, 1, 20) {
    REP (i, n) p[i] = {{rnk[i], rnk[(i + len) % n]}, i};
    sort(p, p + n);
    int cnt = 0;
    REP (i, n) {
      if (i && p[i]._1 != p[i - 1]._1) cnt++;
      rnk[p[i]._2] = cnt;
    }
    len *= 2;
  }

  REP (i, n) {
    int id = p[i]._2;
    if (mark(id + 1)) {
      REP (j, k) {
        cout << s[id];
        id = (id + 1) % n;
      }
      return 0;
    }
  }
  assert(0);
}
