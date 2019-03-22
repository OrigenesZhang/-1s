#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define all(x) (x).begin(), (x).end()
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define mp make_pair
#define _1 first
#define _2 second
const double pi = acos(-1);

struct Point {
    ll x, y;

    Point(ll x = 0, ll y = 0) : x(x), y(y) {}

    Point operator+(const Point &rhs) {
        return {x + rhs.x, y + rhs.y};
    }

    Point operator-(const Point &rhs) {
        return {x - rhs.x, y - rhs.y};
    }

    ll operator*(const Point &rhs) {
        return x * rhs.y - y * rhs.x;
    }
};

typedef Point Vector;
int d, theta, N;

ll area2(vector<Point> &pts) {
    ll ret = 0;
    FOR(i, 1, N - 2) ret += (pts[i] - pts[0]) * (pts[i + 1] - pts[0]);
    return abs(ret);
}

ll gcd(ll a, ll b) {
    return !b ? a : gcd(b, a % b);
}

ll onSeg(const Point &a, const Point &b) {
    return gcd(abs(b.x - a.x), abs(b.y - a.y)) - 1;
}

ll inside(vector<Point> &pts) {
    ll a = area2(pts), cnt = N;
    REP(i, N) cnt += onSeg(pts[i], pts[(i + 1) % N]);
    return (a - cnt) / 2 + 1;
}

int main() {
    while (scanf("%d%d%d", &d, &theta, &N) == 3) {
        if (!d) break;
        vector<Point> poly1, poly2;
        REP(i, N) {
            Point p;
            scanf("%lld%lld", &p.x, &p.y);
            poly1.pb(p);
            poly2.pb({p.x - p.y, p.x + p.y});
        }
        ll a = area2(poly1);
        printf("%lld %.0lf\n", inside(poly2) - inside(poly1), sin(theta * pi / 180) * d * d * a / 2);
    }
    return 0;
}
