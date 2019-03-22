#include <iostream>
#include <cstring>
using namespace std;

typedef long long LL;

const LL INF = LL(1e9);

LL n;

LL tot;

int main() {
    freopen("intel.in", "r", stdin);
    freopen("intel.out", "w", stdout);

    cin >> n;

    LL x0, y0;
    LL x, y, x2, y2;
    cin >> x >> y;
    LL x_min = x, x_max = x, y_min = y, y_max = y;
    x0 = x; y0 = y;
    for (LL i = 1; i < n; i++) {
        cin >> x2 >> y2;
        tot += abs(x - x2) + abs(y - y2);
        x_min = min(x_min, x2);
        y_min = min(y_min, y2);
        x_max = max(x_max, x2);
        y_max = max(y_max, y2);
        x = x2; y = y2;
    }

    tot += abs(x - x0) + abs(y - y0);

    //cout << tot << ' ' << 2 * (x_max - x_min + y_max - y_min) << '\n';

    cout << tot - 2 * (x_max - x_min + y_max - y_min);
    return 0;
}