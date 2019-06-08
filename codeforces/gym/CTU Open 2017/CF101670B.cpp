// Bohao
#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int N = 112345;

int n, f, a[N];

bool check_last(double val) {
  double rem = 0;

  for (int i = 1; i < n; i++) {
    rem += val * f;
    if (rem < a[i]) rem = 0;
    else rem -= a[i];
  }

  return rem + val * f >= a[n];
}

bool check_all(double val) {
  double rem = 0;

  for (int i = 1; i <= n; i++) {
    rem += val * f;
    if (rem < a[i]) return false;
    rem -= a[i];
  }

  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cout << fixed;
  cout.precision(8);

  while (cin >> n >> f) {
    for (int i = 1; i <= n; i++) cin >> a[i];

    double l = 0, r = 1e9;
    for (int i = 0; i < 200; i++) {
      double mid = (r + l) / 2;
      if (check_last(mid)) r = mid;
      else l = mid;
    }

    cout << l;

    l = 0, r = 1e9;
    for (int i = 0; i < 200; i++) {
      double mid = (r + l) / 2;
      if (check_all(mid)) r = mid;
      else l = mid;
    }

    cout << ' ' << l << endl;
  }
  return 0;
}