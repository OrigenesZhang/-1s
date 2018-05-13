#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 5000 + 10;

int r[N], n, grp[N], start[N], en[N];

long double p[N][100];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cout << fixed;
    cout.precision(10);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> r[i];
    swap(r[1], r[n]);
    sort(r + 1, r + n);
    reverse(r + 1, r + n);

    //for (int i = 1; i <= n; i++) cout << r[i] << endl;

    int pw = 1;
    while (pw <= n) pw *= 2; pw /= 2;

    int cnt = n, cur = 1, tot = 1;
    while (cnt > pw) {
        p[cur][1] = (double)r[cur] / (r[cur] + r[cur + 1]);
        p[cur + 1][1] = (double)r[cur + 1] / (r[cur] + r[cur + 1]);
        grp[cur] = grp[cur + 1] = tot;
        start[tot] = cur; en[tot] = cur + 1;
        tot++;
        cur += 2;
        cnt--;
    }

    for (int i = cur; i <= n; i++) { p[i][1] = 1; grp[i] = tot; start[tot] = en[tot] = i; tot++; }

    //for (int i = 1; i <= n; i++) cout << p[i][1] << endl;
    //for (int i = 1; i <= 4; i++) cout << start[i] << endl;
    //cout << 1 << endl;
    int round = 2;
    while (pw > 1) {
        for (int i = 1; i < pw; i += 2)
            for (int j = start[i]; j <= en[i]; j++)
                for (int k = start[i + 1]; k <= en[i + 1]; k++) {
                    p[j][round] += p[j][round - 1] * p[k][round - 1] * (double)r[j] / (r[j] + r[k]);
                    p[k][round] += p[j][round - 1] * p[k][round - 1] * (double)r[k] / (r[j] + r[k]);
                }
        for (int i = 1; i <= n; i++) grp[i] = (grp[i] + 1) / 2;
        for (int i = 1; i <= pw / 2; i++) { start[i] = start[2 * i - 1]; en[i] = en[i * 2]; }
        round++;
        pw /= 2;
    }

    cout << p[n][round - 1] << '\n';
    return 0;
}
