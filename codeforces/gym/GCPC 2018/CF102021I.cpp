#include <bits/stdc++.h>

using namespace std;

const int maxn = 1123;

int n, ans;
int h[maxn], v[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", h + i);
    for (int i = 1; i <= n; i++) scanf("%d", v + i);
    if (h[1] > v[1]) {
        puts("0");
        return 0;
    }
    h[n + 1] = 1;
    int diff = v[1] - h[1];
    for (int i = 2; i <= n + 1; i++) {
        h[i] += diff;
        if (h[i] == v[i]) continue;
        printf("%d", diff + (v[i] > h[i]));
        return 0;
    }
}