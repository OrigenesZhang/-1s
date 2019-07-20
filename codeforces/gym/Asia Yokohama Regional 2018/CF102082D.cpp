#include <bits/stdc++.h>
using namespace std;
 
const int N = 4123;
const int INF = int(1e9);
 
string s[2];
int nex[2][N][2];
int f[N][N];
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
 
  cin >> s[0] >> s[1];
  int n = s[0].length(), m = s[1].length();
 
  nex[0][n][0] = nex[0][n][1] = n;
  nex[1][m][0] = nex[1][m][1] = m;
 
  for (int i = n - 1; i >= 0; i--) {
    nex[0][i][0] = nex[0][i + 1][0];
    nex[0][i][1] = nex[0][i + 1][1];
    if (s[0][i] == '0') nex[0][i][0] = i;
    else nex[0][i][1] = i;
  }
 
  for (int i = m - 1; i >= 0; i--) {
    nex[1][i][0] = nex[1][i + 1][0];
    nex[1][i][1] = nex[1][i + 1][1];
    if (s[1][i] == '0') nex[1][i][0] = i;
    else nex[1][i][1] = i;
  }
 
  f[n][m] = 1;
 
  for (int i = n; i >= 0; i--) {
    for (int j = m; j >= 0; j--) {
      if (i == n && j == m) continue;
      f[i][j] = INF;
      if (nex[0][i][0] == n && nex[1][j][0] == m) {
        f[i][j] = 1;
      } else {
        f[i][j] = min(f[i][j], f[min(n, nex[0][i][0] + 1)][min(m, nex[1][j][0] + 1)] + 1);
      }
 
      if (nex[0][i][1] == n && nex[1][j][1] == m) {
        f[i][j] = 1;
      } else {
        f[i][j] = min(f[i][j], f[min(n, nex[0][i][1] + 1)][min(m, nex[1][j][1] + 1)] + 1);
      }
    }
  }
 
 
  int i = 0, j = 0;
  for (int k = 0; k < f[0][0]; k++) {
    int val1 = 0, val2 = 0;
    if (nex[0][i][0] == n && nex[1][j][0] == m) {
      val1 = 1;
    } else {
      val1 = f[min(n, nex[0][i][0] + 1)][min(m, nex[1][j][0] + 1)] + 1;
    }
 
    if (nex[0][i][1] == n && nex[1][j][1] == m) {
      val2 = 1;
    } else {
      val2 = f[min(n, nex[0][i][1] + 1)][min(m, nex[1][j][1] + 1)] + 1;
    }
 
    if (val1 <= val2) {
      cout << 0;
      i = min(n, nex[0][i][0] + 1);
      j = min(m, nex[1][j][0] + 1);
    } else {
      cout << 1;
      i = min(n, nex[0][i][1] + 1);
      j = min(m, nex[1][j][1] + 1);
    }
  }
 
  cout << '\n';
  return 0;
}
 
/*
 0101
 1100001
 
 101010101
 010101010
 
 11111111
 00000000
 */