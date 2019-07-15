#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
using namespace std;
 
const int maxn = 2123;
 
int m, n, W, H;
int w[maxn], d[maxn];
vector<int> ans[maxn];
 
struct Node {
  int id, s, t, w;
 
  Node (int id, int s, int t, int w) : id(id), s(s), t(t), w(w) {}
 
  bool operator < (const Node &rhs) const {
    if (s != rhs.s) return s > rhs.s;
    return w < rhs.w;
  }
};
 
int main() {
  scanf("%d%d%d%d", &m, &n, &W, &H);
  FOR(i, 1, m) scanf("%d", w + i);
  FOR(i, 1, n) scanf("%d", d + i);
  priority_queue<Node> q;
  priority_queue<int, vector<int>, greater<>> p;
  FOR(i, 1, m) q.emplace(i, 0, 0, w[i]);
  bool ok = true;
  int cnt = 0;
  vector<Node> v;
  FOR(i, 1, n) {
    while (!p.empty() && p.top() < i) p.pop();
    int sz = p.size();
    if (d[i] < sz) {
      ok = false;
      break;
    }
    if (d[i] == sz) continue;
    while (!q.empty()) {
      auto now = q.top();
      if (now.s > i) break;
      v.emplace_back(now); q.pop();
    }
    sort(v.begin(), v.end(), [] (const Node &a, const Node &b) { return a.w < b.w; });
    while (p.size() < d[i]) {
      if (v.empty()) {
        ok = false;
        break;
      }
      auto now = v.back(); v.pop_back();
      now.s = i; ans[now.id].emplace_back(i);
      now.s += W; p.emplace(now.s - 1);
      now.s += H; now.w -= min(W, n - i + 1);
      if (now.w) q.emplace(now);
      else cnt++;
    }
    if (p.size() != d[i]) ok = false;
    if (!ok) break;
  }
  if (cnt != m) ok = false;
  if (ok) {
    puts("1");
    FOR(i, 1, m) {
      for (auto j : ans[i]) printf("%d ", j);
      puts("");
    }
  } else puts("-1");
}
/*
 * 4 9 2 1
4 4 6 2
1 3 2 1 2 1 1 3 2
 */