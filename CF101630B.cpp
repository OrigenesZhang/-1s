#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(int)(a)-1)
#define BUG(x) cout << #x << " = " << x << endl;
#define BUGP(x) cout << #x << " = " << x._1 << ' ' << x._2 << endl;
#define pb push_back
#define _1 first
#define _2 second

long long a, b, c, w, h;

bool ok() {
  if (h >= a + a + c + c && w >= c + b + c) return true;
  if (h >= a + b + c && w >= a + b + c + b) return true;
  if (h >= a + c && w >= b * 3 + a + c) return true;
  if (h >= b + a + c + b && w >= a + b + c) return true;
  if (h >= a + c + a + b && w >= c + b + c) return true;
  if (h >= a + c + a + c && w >= a + b + c) return true;
  if (h >= a + b + a + c && w >= c + b + c) return true;
  return false;
}

int main() {
  cin >> a >> b >> c >> w >> h;

  if (ok()) { cout << "Yes"; return 0; }
  swap(b, c); if (ok()) { cout << "Yes"; return 0; }
  swap(a, b); if (ok()) { cout << "Yes"; return 0; }
  swap(b, c); if (ok()) { cout << "Yes"; return 0; }
  swap(a, b); if (ok()) { cout << "Yes"; return 0; }
  swap(b, c); if (ok()) { cout << "Yes"; return 0; }

  swap(w, h);
  if (ok()) { cout << "Yes"; return 0; }
  swap(b, c); if (ok()) { cout << "Yes"; return 0; }
  swap(a, b); if (ok()) { cout << "Yes"; return 0; }
  swap(b, c); if (ok()) { cout << "Yes"; return 0; }
  swap(a, b); if (ok()) { cout << "Yes"; return 0; }
  swap(b, c); if (ok()) { cout << "Yes"; return 0; }

  cout << "No";
}