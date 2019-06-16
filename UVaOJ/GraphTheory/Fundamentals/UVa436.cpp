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

const int maxn = 35;

int n, m, cs;
double G[maxn][maxn];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  while (cin >> n) {
    if (!n) break;
    map<string, int> tab;
    reset(G, 0);
    FOR(i, 1, n) {
      string s;
      cin >> s;
      tab[s] = i;
    }
    cin >> m;
    while (m--) {
      string su, sv;
      double val;
      cin >> su >> val >> sv;
      int u = tab[su], v = tab[sv];
      G[u][v] = val;
    }
    FOR(k, 1, n) FOR(i, 1, n) FOR(j, 1, n) chkmax(G[i][j], G[i][k] * G[k][j]);
    bool flag = false;
    FOR(i, 1, n) if (G[i][i] > 1) {
      flag = true;
      break;
    }
    cout << "Case " << ++cs << ": " << (flag ? "Yes" : "No") << '\n';
  }
}
