#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(int)(a)-1)
#define pb push_back
#define _1 first
#define _2 second

int n, k;
string grid[111];

int empty(int r) {
  int res = 0;
  REP (i, 11) if (grid[r][i] == '-') res++;
  return res;
}

bool better(int r1, int r2) {
  int dis1 = min(abs(r1 - 1), min(abs(r1 - n / 2 - 2), abs(r1 - n - 3)));
  int dis2 = min(abs(r2 - 1), min(abs(r2 - n / 2 - 2), abs(r2 - n - 3)));
  return dis1 < dis2 || dis1 == dis2 && r1 < r2;
}

void f(char c) {
  int row = 2;
  if (empty(n / 2 + 3) > empty(row)) row = n / 2 + 3;
  if (!empty(n / 2 + 3) && !empty(2)) {
    FOR (i, 1, n + 3) if (empty(i) > empty(row) || empty(i) == empty(row) && better(i, row)) row = i;
  }
  int ls = 0, rs = 0;
  FOR (i, 1, n + 3) REP (j, 5) if (grid[i][j] == '-') ls++;
  FOR (i, 1, n + 3) FOR (j, 6, 10) if (grid[i][j] == '-') rs++;
  if (grid[row][4] == '-' || grid[row][6] == '-') {
    if (grid[row][4] != '-') grid[row][6] = c;
    else if (grid[row][6] != '-') grid[row][4] = c;
    else if (ls >= rs) grid[row][4] = c;
    else grid[row][6] = c;
    return;
  }
  if (grid[row][2] == '-' || grid[row][8] == '-') {
    if (grid[row][2] != '-') grid[row][8] = c;
    else if (grid[row][8] != '-') grid[row][2] = c;
    else if (ls >= rs) grid[row][2] = c;
    else grid[row][8] = c;
    return;
  }
  if (grid[row][0] == '-' || grid[row][10] == '-') {
    if (grid[row][0] != '-') grid[row][10] = c;
    else if (grid[row][10] != '-') grid[row][0] = c;
    else if (ls >= rs) grid[row][0] = c;
    else grid[row][10] = c;
    return;
  }
  if (grid[row][5] == '-') {
    grid[row][5] = c;
    return;
  }
  if (grid[row][1] == '-' || grid[row][9] == '-') {
    if (grid[row][1] != '-') grid[row][9] = c;
    else if (grid[row][9] != '-') grid[row][1] = c;
    else if (ls >= rs) grid[row][1] = c;
    else grid[row][9] = c;
    return;
  }
  assert(0);
}

int main() {
  cin >> n >> k;
  FOR (i, 1, n + 3) cin >> grid[i];
  REP (i, k) f('a' + i);
  FOR (i, 1, n + 3) cout << grid[i] << endl;
}