#include <bits/stdc++.h>
using namespace std;
 
const int maxn = 512345;
 
int tab[maxn];
int r, s, p, ans;
 
int main() {
  scanf("%d%d%d", &r, &s, &p);
  for (int i = 0; i < p; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    x = r - x + 1;
    y = y > s ? y - s : s - y + 1;
    tab[i] = x + y;
  }
  sort(tab, tab + p);
  for (int i = 0; i < p; i++) ans = max(ans, tab[i] + p - i - 1);
  printf("%d", ans);
}
/*
5 2 7
1 1
1 2
1 3
2 3
2 4
4 4
5 2
 
500 500 16
1 1
 1 2
 1 999
 1 1000
 2 1
 2 2
 2 999
 2 1000
 3 1
 3 2
 3 999
 3 1000
 499 500
 499 501
 499 999
 499 1000
*/