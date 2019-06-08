// Bohao
#include <bits/stdc++.h>
using namespace std;

const int N = 1123;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  char c;
  int n;

  while (cin >> n >> c) {
    if (c == 'K') {
      if (n == 1) cout << 1 << endl;
      else cout << 4 << endl;
    } else if (c == 'N') {
      if (n == 1 || n == 2) cout << 1 << endl;
      else cout << 2 << endl;
    } else cout << n << endl;
  }
  return 0;
}