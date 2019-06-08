#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REP(i, n) FOR(i, 0, (n) - 1)
#define reset(x, y) memset(x, y, sizeof(x))
#define mp(x, y) make_pair(x, y)
#define eb emplace_back
#define _1 first
#define _2 second

using namespace std;
using pii = pair<int, int>;
using ll = long long;

int n;

int main() {
  while (scanf("%d", &n) == 1) {
    map<int, int> p, m;
    FOR(i, 1, n) {
      int x, y;
      scanf("%d%d", &x, &y);
      p[x + y]++;
      m[x - y]++;
    }
    ll nom = 0, den = ll(n) * n;
    for (auto it : p) nom += ll(it._2) * (it._2 - 1);
    for (auto it : m) nom += ll(it._2) * (it._2 - 1);
    printf("%.10lf\n", double(nom) / den);
  }
}