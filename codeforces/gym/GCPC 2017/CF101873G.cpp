#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define mp make_pair
#define _1 first
#define _2 second

const int maxn = 123456;

struct Point {
    ll x, y;

    ll operator * (const Point & rhs) {
        return x * rhs.y - y * rhs.x;
    }

    Point operator - (const Point & rhs) {
        return {x - rhs.x, y - rhs.y};
    }

    void read() {
        scanf("%lld%lld", &x, &y);
    }
};

Point poly[maxn];
int n;

ll area2() {
    Point &o = poly[0];
    ll ret = 0;
    FOR(i, 1, n - 1) {
        ret += (poly[i] - o) * (poly[i + 1] - poly[0]);
    }
    return abs(ret);
}

ll gcd(ll a, ll b) {
    return !b ? a : gcd(b, a % b);
}

ll border() {
    ll ret = 0;
    REP(i, n) ret += gcd(abs(poly[i + 1].y - poly[i].y), abs(poly[i + 1].x - poly[i].x));
    return ret;
}

int main() {
    scanf("%d", &n);
    REP(i, n) poly[i].read();
    poly[n] = poly[0];
//    cerr << area2() << ' ' << border() << endl;
    printf("%lld\n", (area2() - border() + 2) / 2);
    return 0;
}