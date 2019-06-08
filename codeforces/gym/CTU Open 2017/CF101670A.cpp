// Bohao
#include <bits/stdc++.h>
using namespace std;

const int N = 1123;

int n, a[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  while (cin >> n) {
    for (int i = 1; i <= n; i++) cin >> a[i];

    if (n == 1) {
      cout << 1 << endl;
      continue;
    }

    int d = a[n] - a[n - 1];
    int idx = n - 1;
    for (int i = n - 2; i >= 1; i--) {
      if (a[i + 1] - a[i] != d) break;
      idx = i;
    }

    cout << idx << endl;
  }
  return 0;
}