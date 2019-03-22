#include <bits/stdc++.h>
using namespace std;

int a[5], b[5];

int main() {
    for (int i = 0; i < 3; i++) cin >> a[i];
    for (int i = 0; i < 3; i++) cin >> b[i];
    int ans = 0;
    for (int i = 0; i < 3; i++) ans += max(0, b[i] - a[i]);
    cout << ans << '\n';
    return 0;
}