#include <bits/stdc++.h>
using namespace std;

int n, g;
int d[61];
double res = -1.0;
bool f[61][61][1501];

int main() {
    cin >> n >> g;
    for (int i = 1; i <= n; ++i) {
        cin >> d[i];
    }

    f[0][0][0] = true;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= i; ++j) {
            for (int k = 0; k <= 1500; ++k) {
                f[i][j][k] = f[i - 1][j][k];
                if (k >= d[i] && j) {
                    f[i][j][k] |= f[i - 1][j - 1][k - d[i]];
                }
            }
        }
    }

    for (int j = 1; j <= n; ++j) {
        for (int k = g - 10; k <= 1500; ++k) {
            if (f[n][j][k]) {
                if (k + 10 - g >= 0 && 5 * (j + 1) >= (k + 10 - g)) {
                    res = max(res, (k + 10 - g) / (j + 1.0));
                }
            }
        }
    }

    if (res > - 0.5) {
        printf("%.10lf", res);
    } else {
        cout << "impossible" << endl;
    }
}