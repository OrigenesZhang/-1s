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

const int maxn = 55;

char mat[maxn][maxn];
int n, m;

int main() {
  scanf("%d%d", &n, &m);
  FOR(i, 1, n) scanf("%s", mat[i] + 1);
  FOR(i, 1, m) {
    int en = n;
    ROF(j, n, 1) {
      if (mat[j][i] == '#') en = j - 1;
      else if (mat[j][i] == 'o')
        ROF(k, en, j + 1) if (mat[k][i] == '.') {
            swap(mat[k][i], mat[j][i]);
            break;
          }
    }
  }
  FOR(i, 1, n) printf("%s\n", mat[i] + 1);
}