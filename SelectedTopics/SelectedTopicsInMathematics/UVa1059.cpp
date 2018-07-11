// 好烦
// 觉得这个输入不保证不共线属于没有意义地增加代码难度
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

const int maxn = 1234;

int gcd(int a, int b) {
    return !b ? a : gcd(b, a % b);
}

struct Point {
    int x, y;

    ll operator*(const Point &rhs) {
        return ll(x) * rhs.y - ll(y) * rhs.x;
    }
} pts[maxn];

ll onSeg(const Point &a, const Point &b) {
    return gcd(abs(b.x - a.x), abs(b.y - a.y));
}

ll cal(ll M, ll a2, ll b) {
    ll x = M * (M + 1) >> 1, y = a2 * (M << 1 | 1) - b * 3;
    x & 1 ? y >>= 1 : x >>= 1;
    x % 3 ? y /= 3 : x /= 3;
    return M + x * y;
}

int N, M, cs = 1;
bool vis[maxn];

int main() {
    while (scanf("%d%d", &N, &M) == 2) {
        if (!N) break;
        REP(i, N) scanf("%d%d", &pts[i].x, &pts[i].y);
        memset(vis, false, sizeof(vis));
        REP(i, N) {
            int p1 = (i - 1 + N) % N, p2 = (i + 1) % N;
            if (ll(pts[i].y - pts[p1].y) * (pts[p2].x - pts[p1].x) ==
                ll(pts[i].x - pts[p1].x) * (pts[p2].y - pts[p1].y))
                vis[i] = true;
        }
        int n = 0;
        REP(i, N) if (!vis[i]) pts[n++] = pts[i];
        N = n;
        int scale = 0;
        FOR(i, 1, N - 1) {
            pts[i].x -= pts[0].x;
            pts[i].y -= pts[0].y;
            int d = gcd(abs(pts[i].x), abs(pts[i].y));
            scale = gcd(scale, d);
        }
        pts[0] = {0, 0};
        FOR(i, 1, N - 1) {
            pts[i].x /= scale;
            pts[i].y /= scale;
        }
        ll a2 = 0, b = 0;
        FOR(i, 1, N - 2) a2 += pts[i] * pts[i + 1];
        a2 = abs(a2);
        REP(i, N) b += onSeg(pts[i], pts[(i + 1) % N]);
        printf("Case %d: %lld\n", cs++, N > 2 ? cal(M, a2, b) : 0);
    }
    return 0;
}
