#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(int)(a)-1)
#define reset(a,b) memset(a,b,sizeof(a))
#define all(x) x.begin(), x.end()
#define uni(x) x.erase(unique(all(x)), x.end());
#define BUG(x) cout << #x << " = " << x << endl
#define BUGP(x) cout << #x << " = " << x._1 << ", " << x._2 << endl
#define PR(x,a,b) {cout << #x << " = "; FOR (_,a,b) cout << x[_] << ' '; cout << endl;}
#define CON(x) {cout << #x << " = "; for(auto _i:x) cout << _i << ' '; cout << endl;}
#define mod 1000000007
#define pi acos(-1)
#define eps 1e-7
#define pb push_back
#define sqr(x) (x) * (x)
#define _1 first
#define _2 second
#define right asdfasd
#define up asd89
#define down aj8
#define left ahh8

int n, l, turn, up, down, left, right, dir, x, y;

int main() {
  ios::sync_with_stdio(0);
  cin >> n;
  REP (i, n) {
    cin >> l >> dir;
    if (turn == 0) {
      up++;
      cout << up - y << ' ';
      y = up;
    } else if (turn == 2) {
      down--;
      cout << y - down << ' ';
      y = down;
    } else if (turn == 1) {
      right++;
      cout << right - x << ' ';
      x = right;
    } else {
      left--;
      cout << x - left << ' ';
      x = left;
    }
    turn = (turn + 4 + dir) % 4;
  }
}
