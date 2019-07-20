#include <bits/stdc++.h>
 
using namespace std;
 
const int maxn = 5123;
 
int n, ans = 2;
int v[maxn], f[maxn][maxn];
 
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", v + i);
  sort(v, v + n);
  for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) f[i][j] = 2;
  for (int i = 0; i < n; i++) {
    int j = i - 1, k = i + 1;
    while (j >= 0 && k < n) {
      if (v[j] + v[k] == v[i] * 2) {
        f[i][k] = f[j][i] + 1;
        ans = max(ans, f[i][k]);
        j--, k++;
      } else v[j] + v[k] < 2 * v[i] ? k++ : j--;
    }
  }
  printf("%d", ans);
}
/*
6
0 1 3 5 6 9
 
7
1 4 7 3 2 6 5
 
5
1 2 4 8 16
 */