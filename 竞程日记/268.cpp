#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int main() {
  int n, k, x, y, dir = 0;
  scanf("%d%d%d%d", &n, &x, &y, &k);
  while (k--) {
    char op[5];
    int mv;
    scanf("%s%d", op, &mv);
    if (op[0] == 'W') {
      x += mv * dx[dir];
      y += mv * dy[dir];
      chkmax(x, 0);
      chkmax(y, 0);
      chkmin(x, n - 1);
      chkmin(y, n - 1);
    } else if (op[0] == 'L') {
      dir = (dir + mv) % 4;
    } else {
      dir = ((dir - mv) % 4 + 4) % 4;
    }
  }
  printf("(%d, %d)", x, y);
}