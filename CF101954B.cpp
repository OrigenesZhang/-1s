#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(int)(a)-1)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl;
#define PR(x,a,b) { cout << #x << " = "; FOR(_,a,b) cout << x[_] << ' '; cout << endl; }
#define CON(x) { cout << #x << " = "; for (auto i: x) cout << i << ' '; cout << endl; }
#define all(x) x.begin(), x.end()
#define mod 1000000007
#define sqr(x) ((x) * (x))
#define pb push_back
#define _1 first
#define _2 second

int n, q, dis[5555][5555], x, y, dx[] = {1, 1, 1, 0, -1, -1, -1, 0}, dy[] = {1, 0, -1, -1, -1, 0, 1, 1};
queue<int> qx, qy;

int main() {
  ios::sync_with_stdio(0);
  cin >> n >> q;
  REP (i, n) {
    cin >> x >> y;
    dis[x][y] = 1;
    qx.push(x); qy.push(y);
  }

  while (qx.size()) {
    x = qx.front(); qx.pop();
    y = qy.front(); qy.pop();
    REP (d, 8) {
      int nx = x + dx[d];
      int ny = y + dy[d];
      if (nx >= 0 && ny >= 0 && nx <= 5000 && ny <= 5000 && !dis[nx][ny]) {
        dis[nx][ny] = 1 + dis[x][y];
        qx.push(nx); qy.push(ny);
      }
    }
  }

  while (q--) {
    cin >> x >> y;
    cout << dis[x][y] - 1 << endl;
  }
}