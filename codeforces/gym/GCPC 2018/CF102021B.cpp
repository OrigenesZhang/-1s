#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-12;
const double PI = acos(-1.0);

struct Point {
    double x, y;
    Point(double x = 0, double y = 0): x(x), y(y) {}
};
int dcmp(double x) {
    if (abs(x) < eps) return 0;
    else return x < 0 ? -1 : 1;
}
using Vector = Point;
Vector operator + (Vector A, Vector B) { return Vector(A.x + B.x, A.y + B.y); }
Vector operator - (Vector A, Vector B) { return Vector(A.x - B.x, A.y - B.y); }
Vector operator * (Vector A, double p) { return Vector(A.x * p, A.y * p); }
Vector operator / (Vector A, double p) { return Vector(A.x / p, A.y / p); }

double Dot(Vector A, Vector B) { return A.x * B.x + A.y * B.y; }
double Length(Vector A) { return sqrt(Dot(A, A)); }
double Length2(Vector A) { return Dot(A, A); }
double polarAngle(Vector v) { return atan2(v.y, v.x); }
Vector Rotate(Vector A, double rad) {
    return Vector(A.x * cos(rad) - A.y * sin(rad), A.x * sin(rad) + A.y * cos(rad));
}

struct Circle {
    Point c;
    double r;
    Circle(Point c = Point(), double r = 0): c(c), r(r) {}
};

int getTangents(Point p, Circle C, vector<Vector> &sol) {
    Vector u = C.c - p;
    double dist = Length(u);
    if (dcmp(dist - C.r) < 0) return 0;
    else if (dcmp(dist - C.r) == 0) {
        sol.push_back(Rotate(u, PI / 2));
    } else {
        double ang = asin(C.r / dist);
        sol.push_back(Rotate(u, ang));
        sol.push_back(Rotate(u, -ang));
    }
}

Point p[2];
Circle c;
double rad[5];
double len[2];

double value(double a, double b) {
    if (dcmp(a) < 0) a += PI * 2;
    if (dcmp(b) < 0) b += PI * 2;

    double l1 = (max(a, b) - min(a, b)) * c.r;
    double l2 = (2 * PI - (max(a, b) - min(a, b))) * c.r;

    return min(l1, l2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < 2; i++) {
        cin >> p[i].x >> p[i].y;
    }

    for (int i = 0; i < 2; i++) {
        cin >> c.c.x >> c.c.y >> c.r;
    }

    for (int i = 0; i < 2; i++) {
        vector<Vector> sol;
        getTangents(p[i], c, sol);
        assert(sol.size() == 2);

        len[i] = sqrt(Length2(p[i] - c.c) - c.r * c.r);
        auto it = sol[0];
        Point tmp = p[i] + it / Length(it) * len[i];
        rad[i * 2] = polarAngle(tmp - c.c);

        it = sol[1];
        tmp = p[i] + it / Length(it) * len[i];
        rad[i * 2 + 1] = polarAngle(tmp - c.c);
    }

    double minm = 1e18;
    for (int i = 0; i < 2; i++) {
        for (int j = 2; j < 4; j++) minm = min(minm, value(rad[i], rad[j]));
    }

    cout << fixed;
    cout.precision(10);
    cout << minm + len[0] + len[1] << '\n';
    return 0;
}