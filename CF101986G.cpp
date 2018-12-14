#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(int)(a)-1)
#define BUG(x) cout << #x << " = " << x << endl
#define BUGP(x) cout << #x << " = " << x._1 << ' ' << x._2 << endl
#define reset(a,b) memset(a,b,sizeof(a))
#define PR(x,a,b) { cout << #x << " = "; FOR(_,a,b) cout << x[_] << ' '; cout << endl; }
#define CON(x) { cout << #x << " = "; for(auto _i: x) cout << _i << ' '; cout << endl; }
#define all(x) x.begin(), x.end()
#define uni(x) x.erase(unique(all(x)), x.end())
#define mod 1000000007
#define eps 1e-9
#define sqr(x) ((x) * (x))
#define pi acos(-1)
#define pb push_back
#define _1 first
#define _2 second

string s;
int angle, l;

char f() {
  double alpha = (angle - 30) * pi / 180;
  char a = 'A', b = s[0], c = s[1], d = 'B' + 'C' + 'D' - b - c;
  double dx = l * sin(alpha);
  double dy = l * cos(alpha);
  dy /= sqrt(3);
  while (dy >= 2) dy -= 2;
  while (dx >= 2) dx -= 2;
  while (dx < 0) dx += 2;

  if (dy <= 0.5) {
    if (dx <= 0.5) {
      if (dx < dy) return d;
      else return b;
    } else if (dx <= 1) {
      if (dx - 0.5 + dy < 0.5) return b;
      else return a;
    } else if (dx <= 1.5) {
      if (dx - 1 < dy) return a;
      else return c;
    } else {
      if (dx - 1.5 + dy < 0.5) return c;
      else return d;
    }
  } else if (dy <= 1) {
    if (dx <= 0.5) {
      if (dx + dy - 0.5 < 0.5) return a;
      else return b;
    } else if (dx <= 1) {
      if (dx - 0.5 < dy - 0.5) return b;
      else return d;
    } else if (dx <= 1.5) {
      if (dx - 1 + dy - 0.5 < 0.5) return d;
      else return c;
    } else {
      if (dx - 1.5 < dy - 0.5) return c;
      else return a;
    }
  } else if (dy <= 1.5) {
    if (dx <= 0.5) {
      if (dx < dy - 1) return a;
      else return c;
    } else if (dx <= 1) {
      if (dx - 0.5 + dy - 1 < 0.5) return c;
      else return d;
    } else if (dx <= 1.5) {
      if (dx - 1 < dy - 1) return d;
      else return b;
    } else {
      if (dx - 1.5 + dy - 1 < 0.5) return b;
      else return a;
    }
  } else {
    if (dx <= 0.5) {
      if (dx + dy - 1.5 < 0.5) return d;
      else return c;
    } else if (dx <= 1) {
      if (dx - 0.5 < dy - 1.5) return c;
      else return a;
    } else if (dx <= 1.5) {
      if (dx - 1 + dy - 1.5 < 0.5) return a;
      else return b;
    } else {
      if (dx - 1.5 < dy - 1.5) return b;
      else return d;
    }
  }
}

int main() {
  cin >> s >> angle >> l;
  char c = f();
  cin >> s >> angle >> l;
  char cc = f();
  if (c == cc) cout << "YES";
  else cout << "NO";
}