#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int i2 = 5e8 + 4;

int main() {
    vector<int> cnt(3);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int a;
        scanf("%d", &a);
        cnt[a - 1]++;
    }
    cerr << cnt[0] << ' ' << cnt[1] << ' ' << cnt[2];
    if (cnt[0] + cnt[1] * 2 + cnt[2] * 3 != 2 * n - 2 || cnt[0] != cnt[2] + 2) {
        puts("0");
        return 0;
    }
    long long ans = 1;
    for (int i = 1; i <= n - 2; i++) ans = ans * i % MOD;
    for (int i = 1; i <= cnt[2]; i++) ans = ans * i2 % MOD;
    printf("%lld", ans);
}