#include <bits/stdc++.h>
using namespace std;

const int N = 212;
const int BASE = 100000;

struct Node {
  int x;
  int t;
};

int n, a[N], d[BASE * 2][2];

void init() {
  memset(d, -1, sizeof(d));
  d[BASE][0] = 0;
  queue<Node> q;
  q.push({ BASE, 0 });

  while (!q.empty()) {
    Node u = q.front(); q.pop();
    //cout << u.x << ' ' << u.t << endl;

    for (int i = 1; i <= n; i++) {
      Node v{u.x + a[i] * ((u.t & 1) ? -1 : 1), u.t + 1};
      if (v.x < 0 || v.x >= BASE * 2) break;
      if (d[v.x][v.t & 1] > -1) continue;

      d[v.x][v.t & 1] = v.t;
      q.push(v);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  //for (int i = 50; i <= 10000; i += 50) cout << i << endl;

  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + n + 1);

  init();

  //cout << "DONE" << endl;

  int q;
  cin >> q;
  while (q--) {
    int s, t;
    cin >> s >> t;
    if ((s & 1) != (t & 1)) { cout << -1 << '\n'; continue; }

    int x = t / 2 - s / 2, y = (t + s) / 2;

    if (d[BASE + x][0] == -1 && d[BASE + y][1] == -1) cout << -1 << '\n';
    else if (d[BASE + x][0] == -1 || d[BASE + y][1] == -1) {
      cout << max(d[BASE + x][0], d[BASE + y][1]) << '\n';
    } else {
      cout << min(d[BASE + x][0], d[BASE + y][1]) << '\n';
    }
  }

  return 0;
}
/*
4
1 2 4 7
10
2 3
5 6
6 0
3 7
10 3
7 6
5 5
2 10
4 10
10 10
 */