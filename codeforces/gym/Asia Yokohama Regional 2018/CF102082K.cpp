#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REP(i, n) FOR(i, 0, (n) - 1)
#define ROF(i, a, b) for (int i = (a); i >= (b); i--)
#define eb emplace_back
#define _1 first
#define _2 second
#define all(x) x.begin(), x.end()
typedef pair<int, int> pii;
 
vector<int> a, b, now;
int ans, n;
 
bool check(int st, int v, const vector<int> &cur) {
  int ret = (v > a[st]), j = cur.size() - 1;
  bool f = false;
  FOR(i, st + 1, n - 1) {
    if (cur[j] == v && !f) {
      f = true;
      j--;
    }
    if (cur[j] > a[i]) j--, ret++;
  }
  return ret == ans;
}
 
int main() {
  scanf("%d", &n);
  a.resize(n), b.resize(n);
  for (auto &x : a) scanf("%d", &x);
  for (auto &x : b) scanf("%d", &x);
  now = a;
  sort(all(a), greater<>());
  sort(all(b));
  multiset<int> que;
  for (auto x : b) que.emplace(x);
  REP(i, n) {
    auto it = que.end();
    it--;
    if (*it > a[i]) ans++;
    else it = que.begin();
    que.erase(it);
  }
  REP(i, n) {
    copy(all(now), a.begin());
    sort(a.begin() + i + 1, a.end(), greater<>());
    int lo = upper_bound(all(b), a[i]) - b.begin() - 1, hi = b.size() - 1;
    while (lo < hi) {
      int mi = lo + hi + 1 >> 1;
      if (check(i, b[mi], b)) lo = mi;
      else hi = mi - 1;
    }
    if (check(i, b[hi], b)) {
      if (b[hi] > a[i]) ans--;
      printf("%d ", b[hi]);
      b.erase(b.begin() + hi);
    } else {
      lo = 0, hi = upper_bound(all(b), a[i]) - b.begin() - 1;
      while (lo < hi) {
        int mi = lo + hi + 1 >> 1;
        if (check(i, b[mi], b)) lo = mi;
        else hi = mi - 1;
      }
      printf("%d ", b[hi]);
      b.erase(b.begin() + lo);
    }
  }
}