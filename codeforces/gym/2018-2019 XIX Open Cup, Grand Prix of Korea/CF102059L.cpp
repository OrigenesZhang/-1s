#include <bits/stdc++.h>
using namespace std;

const int N = 112345;

int n;
int a[N], f[N][2];
int ans[N][2];

void solve(int x) {
    int cur = 1;
    int arr = 0, bad = 0;
    while (cur <= n) {
        ++arr;
        int val = max(f[cur][0], f[cur][1]);
        if (val >= x || cur + val > n) cur += val;
        else {
            bad += min(x, n - cur + 1) - val;
            cur += x;
        }
    }

    ans[x][0] = arr;
    ans[x][1] = bad;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    f[n][0] = f[n][1] = 1;
    for (int i = n - 1; i >= 1; i--) {
        if (a[i] <= a[i + 1]) {
            f[i][0] = f[i + 1][0] + 1;
            f[i][1] = 1;
        } else {
            f[i][0] = 1;
            f[i][1] = f[i + 1][1] + 1;
        }
    }

    for (int i = 1; i <= n; i++) solve(i);

    int q;
    cin >> q;

    while (q--) {
        int x;
        cin >> x;
        cout << ans[x][0] << ' ' << ans[x][1] << '\n';
    }
    return 0;
}