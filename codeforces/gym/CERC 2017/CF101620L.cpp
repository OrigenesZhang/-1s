#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(int)(a)-1)
#define BUG(x) cout << #x << " = " << x << endl;
#define CON(x) { cout << #x << " = "; for (auto i: x) cout << i << ' '; cout << endl; }
#define pb push_back
#define _1 first
#define _2 second
#define off 2200

int n, sq[4444][4444], tri[8888][8888], x, y, a, ans;
char typ;

int main() {
  cin >> n;
  while (n--) {
    cin >> typ >> x >> y >> a;
    a /= 2;
    if (typ == 'A') {
      sq[x - a + off][y - a + off]++;
      sq[x - a + off][y + a + off]--;
      sq[x + a + off][y - a + off]--;
      sq[x + a + off][y + a + off]++;
    } else {
      int nx = x + y, ny = y - x;
      tri[nx - a + off * 2][ny - a + off * 2]++;
      tri[nx + a + off * 2][ny - a + off * 2]--;
      tri[nx - a + off * 2][ny + a + off * 2]--;
      tri[nx + a + off * 2][ny + a + off * 2]++;
    }
  }

  FOR (i, -2001, 2001) FOR (j, -2001, 2001) {
    sq[off + i][off + j] = sq[off + i - 1][off + j] + sq[off + i][off + j - 1] + sq[off + i][off + j] - sq[off + i - 1][off + j - 1];
    if (sq[off + i][off + j]) {
      ans += 4;
    }
  }

  FOR (i, -4001, 4001) FOR (j, -4001, 4001) {
    tri[off * 2 + i][off * 2 + j] = tri[off * 2 + i - 1][off * 2 + j] + tri[off * 2 + i][off * 2 + j - 1] + tri[off * 2 + i][off * 2 + j] - tri[off * 2 + i - 1][off * 2 + j - 1];
    if (tri[off * 2 + i][off * 2 + j]) {
      if (i % 2 == 0 && j % 2 == 0) {
        y = (i + j) / 2; x = i - y;
        if (!sq[off + x][off + y]) ans++;
        if (!sq[off + x - 1][off + y]) ans++;
      }
      if (i % 2 && j % 2 == 0) {
        y = (i - 1 + j) / 2; x = i - 1 - y;
        if (!sq[off + x][off + y]) ans++;
        if (!sq[off + x][off + y + 1]) ans++;
      }
      if (i % 2 == 0 && j % 2) {
        y = (i + j - 1) / 2; x = i - y;
        if (!sq[off + x - 1][off + y]) ans++;
        if (!sq[off + x - 1][off + y + 1]) ans++;
      }
      if (i % 2 && j % 2) {
        y = (i + j - 2) / 2; x = i - 1 - y;
        if (!sq[off + x][off + y + 1]) ans++;
        if (!sq[off + x - 1][off + y + 1]) ans++;
      }
    }
  }

  printf("%.2f", ans * 1.0 / 4);
}