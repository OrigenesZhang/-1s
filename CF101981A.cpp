#include <bits/stdc++.h>
using namespace std;

int n, k;

int main() {
  cin >> n >> k;
  if (!n || k == 1 && n % 2 == 0) cout << "Austin";
  else cout << "Adrien";
}