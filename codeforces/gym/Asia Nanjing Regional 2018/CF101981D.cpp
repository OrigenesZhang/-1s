#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
#define pb push_back
using namespace std;

struct Node {
    double x, y, z;
};

const int N = 100 + 10;
Node node[N];
int n;

double dist(Node a, Node b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z);
}

double f(double x, double y, double z) {
    double maxm = 0;
    for (int i = 0; i < n; i++) maxm = max(maxm, dist({ x, y, z }, node[i]));
    return maxm;
}

double x, y, z;

double fxy(double xval, double yval) {
    double l = -100000, r = 100000;
    for (int i = 0; i < 60; i++) {
        double mid1 = l + (r - l) / 3;
        double mid2 = r - (r - l) / 3;
        if (f(xval, yval, mid1) < f(xval, yval, mid2)) r = mid2;
        else l = mid1;

        //cout << mid1 << ' ' << mid2 << f(x)
    }
    z = l;
    return f(xval, yval, z);
}

double fx(double xval) {
    double l = -100000, r = 100000;
    for (int i = 0; i < 60; i++) {
        double mid1 = l + (r - l) / 3;
        double mid2 = r - (r - l) / 3;
        if (fxy(xval, mid1) < fxy(xval, mid2)) r = mid2;
        else l = mid1;
        //break;
    }
    y = l;
    return fxy(xval, y);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> node[i].x >> node[i].y >> node[i].z;

    double l = -100000, r = 100000;
    for (int i = 0; i < 60; i++) {
        double mid1 = l + (r - l) / 3;
        double mid2 = r - (r - l) / 3;
        if (fx(mid1) < fx(mid2)) {
            r = mid2;
        } else {
            l = mid1;
        }
    }
    x = l;
    fx(x);


    cout << fixed;
    cout.precision(10);
    cout << sqrt(f(x, y, z)) << '\n';
    return 0;
}