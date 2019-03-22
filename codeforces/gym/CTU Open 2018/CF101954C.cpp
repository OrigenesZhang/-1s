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

int rnk[5], suit[5], rule[22], cp[5];
long long val, nval;
string s;

int parseSuit(char c) {
  if (c == 'S') return 1;
  if (c == 'C') return 2;
  if (c == 'D') return 3;
  if (c == 'H') return 4;
  assert(0);
}

void f(int x) {
  if (nval != val) {
    val = nval;
    rule[x] = 1;
  }
}

void r1() {
  nval = val + 1;
  int cntj = 0;
  REP (i, 5) if (rnk[i] == 11) cntj++;
  nval += cntj * min(10, rnk[0]);
  f(1);
}

void r2() {
  nval = val * 2;
  f(2);
}

void r3() {
  nval = val * 2;
  f(3);
}

void r4() {
  int dif = 0;
  REP (i, 5) {
    if (suit[i] < 3) dif++;
    else dif--;
  }
  nval = val + abs(dif);
  f(4);
}

void r5() {
  nval = val;
  for (long long i = 1; i * i <= val; i++) if (val % i == 0) {
    nval += i;
    if (val / i != i) nval += val / i;
  }
  f(5);
}

void r6() {
  nval = val - 121;
  f(6);
}

void r7() {
  int low = min(10, rnk[0]);
  REP (i, 5) low = min(low, min(10, rnk[i]));
  nval = val + low;
  f(7);
}

void r8() {
  nval = val * -1;
  f(8);
}

void r9() {
  nval = val + 1;
  REP (i, 5) {
    if (rnk[i] == 6) rnk[i] = 9;
    else if (rnk[i] == 9) rnk[i] = 6;
    else if (rnk[i] == 2) rnk[i] = 5;
    else if (rnk[i] == 5) rnk[i] = 2;
  }
  f(9);
}

void r10() {
  int cnta = 0;
  REP (i, 5) if (rnk[i] == 14) cnta++;
  nval = val + 5 * cnta;
  assert(cnta == 1);
  f(10);
}

void r11() {
  nval = val;
  REP (i, 60) if ((1LL << i) & val) nval++;
  f(11);
}

void r12() {
  if (rule[11]) r11();
  else if (rule[10]) r10();
  else if (rule[9]) r9();
  else if (rule[8]) r8();
  else if (rule[7]) r7();
  else if (rule[6]) r6();
  else if (rule[5]) r5();
  else if (rule[4]) r4();
  else if (rule[3]) r3();
  else if (rule[2]) r2();
  else if (rule[1]) r1();
}

void r13() {
  val *= 2;
}

int main() {
  ios::sync_with_stdio(0);
  REP (i, 5) {
    cin >> s;
    if (s.size() == 3) {
      rnk[i] = 10;
      suit[i] = parseSuit(s[2]);
    } else {
      suit[i] = parseSuit(s[1]);
      if (s[0] == 'J') rnk[i] = 11;
      else if (s[0] == 'Q') rnk[i] = 12;
      else if (s[0] == 'K') rnk[i] = 13;
      else if (s[0] == 'A') rnk[i] = 14;
      else rnk[i] = s[0] - '0';
    }
    val += min(10, rnk[i]);
  }

  r1();
  r2();

  bool flag = false;
  FOR (i, 1, 4) {
    bool app = false;
    REP (j, 5) if (suit[j] == i) app = true;
    if (!app) flag = true;
  }
  if (!flag) r3();

  r4();

  if (val % 2 == 0) r5();

  int cnt7 = 0;
  REP (i, 5) if (rnk[i] == 7) cnt7++;
  if (cnt7 == 4) r6();

  if (val >= 0) r7();

  if (val < 0) r8();

  int cntd = 0;
  REP (i, 5) if (suit[i] == 3) cntd++;
  if (cntd >= 3) r9();

  REP (i, 5) cp[i] = rnk[i];
  sort(cp, cp + 5);
  flag = false;
  REP (i, 5) if (cp[i] != 10 + i) flag = true;
  if (!flag) r10();

  int cnt = 0;
  REP (i, 15) if (rule[i]) cnt++;
  if (cnt > 8) r11();

  flag = false;
  REP (i, 5) if (rnk[i] == 2) flag = true;
  if (flag) r12();

  flag = false;
  REP (i, 5) if (rnk[i] == 2) flag = true;
  if (flag) r13();

  cout << val;
}