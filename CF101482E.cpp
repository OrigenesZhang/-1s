#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;

int n;
double p, s, v;


double f(double c) {
    return pow(log2(n), c * sqrt(2)) * n / (p * 1e9) + s * (1 + 1 / c) / v;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> p >> s >> v;
    double l = 0, r = 100;
    for (int i = 0; i < 100; i++) {
        double one = l + (r - l) / 3;
        double two = l + (r - l) / 3 * 2;
        if (f(one) < f(two)) r = two;
        else l = one;
    }

    cout << fixed;
    cout.precision(10);
    cout << f(l) << ' ' << l << '\n';
    return 0;
}