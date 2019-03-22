#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second

typedef pair<double, double> Point;

Point p1, p2, o;
inline double dist(Point p1, Point p2) {
    return sqrt(sqr(p1._1 - p2._1) + sqr(p1._2 - p2._2));
}

int main() {
    cin >> o._1 >> o._2 >> p1._1 >> p1._2 >> p2._1 >> p2._2;
    double ans = 1e15;
    ans = min(dist(o, p1), ans);
    ans = min(dist(o, p2), ans);
    ans = min(dist(o, mp(p1._1, p2._2)), ans);
    ans = min(dist(o, mp(p2._1, p1._2)), ans);
    if (o._1 > p1._1 - 0.5 && o._1 < p2._1 + 0.5) {
        ans = min(ans, abs(p1._2 - o._2));
        ans = min(ans, abs(p2._2 - o._2));
    }
    if (o._2 > p1._2 - 0.5 && o._2 < p2._2 + 0.5) {
        ans = min(ans, abs(p1._1 - o._1));
        ans = min(ans, abs(p2._1 - o._1));
    }
    printf("%.3lf\n", ans);
}