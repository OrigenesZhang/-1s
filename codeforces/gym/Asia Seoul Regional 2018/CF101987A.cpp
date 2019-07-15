#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
 
const int N = 212345;
 
int maxv[N * 4], addv[N * 4];
pii rec[N];
int n;
vector<int> cor;
vector<pair<int, pii>> node;
 
int query(int o, int l, int r, int ql, int qr) {
  //cout << o << ' ' << l << ' ' << r << ' ' << ql << ' ' << qr << endl;
  if (ql <= l && r <= qr) return maxv[o];
  int mid = l + (r - l) / 2;
  int ret = 0;
  if (ql <= mid) ret = query(o * 2, l, mid, ql, qr);
  if (qr > mid) ret = max(ret, query(o * 2 + 1, mid + 1, r, ql, qr));
  return ret + addv[o];
}
 
void add(int o, int l, int r, int ql, int qr, int val) {
  if (ql <= l && r <= qr) {
    addv[o] += val;
    maxv[o] += val;
    return;
  }
  int mid = l + (r - l) / 2;
  if (ql <= mid) add(o * 2, l, mid, ql, qr, val);
  if (qr > mid) add(o * 2 + 1, mid + 1, r, ql, qr, val);
  maxv[o] = max(maxv[o * 2], maxv[o * 2 + 1]) + addv[o];
}
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
 
  cin >> n;
  for (int i = 0; i < n; i++) {
    int ux, uy, vx, vy;
    cin >> ux >> uy >> vx >> vy;
    rec[i] = { vy, uy };
    cor.push_back(uy);
    cor.push_back(vy);
    node.push_back({ vy, { 0, i }});
    node.push_back({ uy, { 1, i }});
  }
 
  sort(cor.begin(), cor.end());
  cor.erase(unique(cor.begin(), cor.end()), cor.end());
  int sz = cor.size() - 1;
 
 
  for (int i = 0; i < n; i++) {
    int l = lower_bound(cor.begin(), cor.end(), rec[i].first) - cor.begin();
    int r = lower_bound(cor.begin(), cor.end(), rec[i].second) - cor.begin();
    add(1, 0, sz, l, r, 1);
  }
 
  int ans = 0, cnt = 0;
 
  sort(node.begin(), node.end());
 
 
  for (auto it : node) {
    if (it.second.first == 0) {
      ++cnt;
      int id = it.second.second;
      //cout << "   " << id << ' ' << rec[id].first << ' ' << rec[id].second << endl;
      int l = lower_bound(cor.begin(), cor.end(), rec[id].first) - cor.begin();
      int r = lower_bound(cor.begin(), cor.end(), rec[id].second) - cor.begin();
      add(1, 0, sz, l, r, -1);
      ans = max(ans, cnt + maxv[1]);
      //cout << "******" << endl;
      //cout << l << ' ' << r << endl;
      //cout << cnt << ' ' << maxv[1] << endl;
    } else --cnt;
  }
 
  cout << ans << '\n';
  return 0;
}