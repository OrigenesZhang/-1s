#include <bits/stdc++.h>
using namespace std;

using LL = long long;

LL a, b, c, d;

int main() {
    cin >> a >> b >> c >> d;

    vector<pair<int, int>> p;

    LL ans = 0;
    for (int i = 1; i < 999; i++) {
        for (int j = 1; j <= 999 - i; j++) {
            if (__gcd(i, j) != 1) continue;

            LL l = max(1ll, max((a + i - 1) / i, (c + j - 1) / j));
            LL r = min(b / i, d / j);

            if (r < l) continue;

            //cerr << i << ' ' << j << ' ' << l << ' ' << r << endl;
            ans += r - l + 1;
        }
    }

    //sort(p.begin(), p.end());
    //for (auto it : p) cout << it.first << ' ' << it.second << endl;

    cout << ans << '\n';
    return 0;
}