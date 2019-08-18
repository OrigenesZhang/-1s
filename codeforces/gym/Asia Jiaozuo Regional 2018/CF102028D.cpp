#include <bits/stdc++.h>
using namespace std;
 
const double PI = acos(-1.0);
 
double a, b, r, d;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
 
    cout << fixed;
    cout.precision(12);
 
    while (T--) {
        cin >> a >> b >> r >> d;
        double tmp = atan(b / (a + r));
        if (tmp <= PI * d / 180) cout << sqrt((a + r) * (a + r) + b * b) - r << endl;
        else cout << sqrt((a + r) * (a + r) + b * b) * cos(tmp - PI * d / 180) - r << endl;
    }
 
    return 0;
}