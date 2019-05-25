#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int l = 0, r = 1000000000;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        r = min(r, x);
        l = x - l;
        r = x - r;
        swap(l, r);
        //cout << l << ' ' << r << endl;
    }

    cout << max(r - l + 1, 0) << '\n';
    return 0;
}