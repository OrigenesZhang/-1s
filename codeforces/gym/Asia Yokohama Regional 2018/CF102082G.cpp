#include <bits/stdc++.h>
using namespace std;
 
const int N = 112345;
 
int c[N];
 
int n, a[N];
vector<int> vec[N];
 
int lowbit(int x) { return x & (-x); }
 
void add(int pos) {
  while (pos <= n) {
    c[pos] += 1;
    pos += lowbit(pos);
  }
}
 
int sum(int pos) {
  int ans = 0;
  while (pos) {
    ans += c[pos];
    pos -= lowbit(pos);
  }
  return ans;
}
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
 
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    vec[x].push_back(i);
  }
 
 
  long long ans = 0;
  for (int i = 1; i <= 100000; i++) {
    for (auto it : vec[i]) add(it);
    for (auto it : vec[i]) {
      ans += min(it - sum(it), n - it - (sum(n) - sum(it)));
    }
  }
 
  cout << ans << '\n';
  return 0;
}