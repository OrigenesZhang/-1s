#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(int)(a)-1)
#define BUG(x) cout << #x << " = " << x << endl
#define PR(x,a,b) { cout << #x << " = "; FOR(_,a,b) cout << x[_] << ' '; cout << endl; }
#define CON(x) { cout << #x << " = "; for (auto i:x) cout << i << ' '; cout << endl; }
#define mod 1000000007
#define eps 1e-8
#define pb push_back
#define _1 first
#define _2 second

long long n, p, x[100500], y[100500], cur1, cur2;

bool ok(int a, int b, int c) {
  return (x[c] - x[b]) * (y[b] - y[a]) == (x[b] - x[a]) * (y[c] - y[b]);
}

void r() {
  cur1 = (cur1 * rand() + 7) % n;
  cur2 = (cur2 * rand() + 11) % n;
}

int main() {
  scanf("%d %d", &n, &p);
  srand(time(NULL));

  REP (i, n) scanf("%d %d", x + i, y + i);
  p = (n * p + 99) / 100;
  cur1 = 17, cur2 = 23;

  if (n <= 2) {
    printf("possible");
    return 0;
  }
  if (n <= 100) {
    REP (i, n) FOR (j, i + 1, n - 1) {
      int cnt = 2;
      REP (k, n) if (i != k && j != k) if (ok(i, j, k)) cnt++;
      if (cnt >= p) {
        printf("possible");
        return 0;
      }
    }
    printf("impossible");
    return 0;
  }

  REP (ii, 300) {
    r();
    while (cur1 == cur2) r();
    int cnt = 2;
    REP (i, n) if (i != cur1 && i != cur2) if (ok(i, cur1, cur2)) cnt++;
    if (cnt >= p) {
      printf("possible");
      return 0;
    }
  }
  printf("impossible");
}