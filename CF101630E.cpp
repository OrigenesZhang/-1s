#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define pb push_back

int n, cnt, val;
multiset<int> s;
vector<int> ans;

int main() {
  cin >> n;
  while (n--) {
    cin >> val;
    if (val < 0) {
      val = -val;
      if (s.count(val)) {
        s.erase(s.find(val));
      } else if (cnt) {
        cnt--;
        ans.pb(val);
      } else {
        cout << "No";
        return 0;
      }
    } else if (val > 0) {
      s.insert(val);
    } else cnt++;
  }
  while (cnt--) ans.pb(1);
  cout << "Yes" << endl;
  for (auto i: ans) cout << i << ' ';
}