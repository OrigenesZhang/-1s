#include <bits/stdc++.h>
using namespace std;

using LL = long long;

LL qpow(LL u, int pw) {
    LL ans = 1;
    while (pw) {
        if (pw & 1) ans *= u;
        u *= u;
        pw >>= 1;
    }
    return ans;
}

int main() {
    LL n;
    cin >> n;

    for (int i = 2; i <= 60; i++) {
        LL sum = 0;
        for (int j = 1; ; j++) {
            sum += qpow(j, i);
            if (sum == n) { cout << i + 1 << ' ' << j << '\n'; return 0; }
            if (sum > n) break;
        }
    }

    cout << "impossible\n";
    return 0;
}