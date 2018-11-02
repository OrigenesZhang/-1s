#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(int)(a)-1)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl;
#define pb push_back

string s[3];

bool f1() {
  return s[1][1] == 'o';
}

bool f2() {
  return s[0][0] == 'o' && s[2][2] == 'o' || s[0][2] == 'o' && s[2][0] == 'o';
  //return s[0][1] == 'o' && s[2][1] == 'o' || s[1][0] == 'o' && s[1][2] == 'o';
}

bool f3() {
  return s[0][0] == 'o' && s[1][1] == 'o' && s[2][2] == 'o' ||
    s[0][2] == 'o' && s[1][1] == 'o' && s[2][0] == 'o';
}

bool f4() {
  return s[0][0] == 'o' && s[2][2] == 'o' && s[0][2] == 'o' && s[2][0] == 'o';
}

bool f5() {
  return f4() && s[1][1] == 'o';
}

bool f6() {
  bool flag = false;
  REP (i, 3) if (s[i][1] == 'o') flag = true;
  if (!flag) return true;
  flag = false;
  REP (i, 3) if (s[1][i] == 'o') flag = true;
  return !flag;
}

int main() {
  REP (i, 3) cin >> s[i];
  int cnt = 0;
  REP (i, 3) REP (j, 3) if (s[i][j] == 'o') cnt++;
  if (cnt == 1 && f1()) cout << 1;
  else if (cnt == 2 && f2()) cout << 2;
  else if (cnt == 3 && f3()) cout << 3;
  else if (cnt == 4 && f4()) cout << 4;
  else if (cnt == 5 && f5()) cout << 5;
  else if (cnt == 6 && f6()) cout << 6;
  else cout << "unknown";
}