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

const int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int SECS = 24 * 60 * 60;

int gcd(int a, int b) {
    return !b ? a : gcd(b, a % b);
}

void exgcd(ll a, ll b, ll &d, ll &x, ll &y) {
    if (!b) {
        d = a;
        x = 1;
        y = 0;
    } else {
        exgcd(b, a % b, d, y, x);
        y -= x * (a / b);
    }
}

ll fast_pow(ll a, ll p, ll mod) {
    ll ans = 1, b = a;
    while (p) {
        if (p & 1) ans = ans * b % mod;
        b = b * b % mod;
        p >>= 1;
    }
    return ans;
}

int inv(ll a, int mod) {
    ll d, x, y;
    exgcd(a, mod, d, x, y);
    return (x + mod) % mod;
}

// Shank的大步小步定理
int log_mod(int a, int b, int mod) {
    int m, v, e = 1;
    m = int(sqrt(mod));
    v = inv(fast_pow(a, m, mod), mod);
    map<int, int> x;
    x[1] = 0;
    FOR(i, 1, m - 1) {
        e = ll(e) * a % mod;
        if (!x.count(e)) x[e] = i;
    }
    REP(i, m) {
        if (x.count(b)) return i * m + x[b];
        b = ll(b) * v % mod;
    }
    return -1;
}

// 求一个原根
int primitive_root(int mod, int phi) {
    vector<int> fac;
    int n = phi, upp = int(floor(sqrt(n)));
    FOR(i, 2, upp) {
        if (n % i) continue;
        fac.pb(i);
        while (n % i == 0) n /= i;
    }
    if (n > 1) fac.pb(n);
    while (true) {
        int m = rand() % (mod - 2) + 2;
        bool flag = true;
        for (auto it : fac)
            if (fast_pow(m, phi / it, mod) == 1) {
                flag = false;
                break;
            }
        if (flag) return m;
    }
}

// 解方程 a * x == b (mod n)
void linear_mod_equation(vector<ll> &ans, int a, int b, int n) {
    int d = gcd(a, n);
    if (b % d) return;
    a /= d, b /= d;
    int nn = n / d;
    int p = ll(inv(a, nn)) * b % nn;
    REP(i, d) ans.pb((ll(i) * nn + p) % n);
}

inline bool leap_yr(int yr) {
    if (yr % 400 == 0) return true;
    return yr % 4 == 0 && yr % 100;
}

inline bool leap_sec(int yr, int mon) {
    return (yr % 10 == 5 || yr % 10 == 8) && mon == 12;
}

void print_ans(ll x) {
    int yr = 2000;
    while (true) {
        int day = 365 + leap_yr(yr);
        ll sec = ll(day) * SECS + leap_sec(yr, 12);
        if (x < sec) break;
        x -= sec;
        yr++;
    }
    int mon = 1;
    while (true) {
        int day = months[mon - 1];
        if (leap_yr(yr) && mon == 2) day++;
        ll sec = ll(day) * SECS + leap_sec(yr, mon);
        if (x < sec) break;
        x -= sec;
        mon++;
    }
    if (leap_sec(yr, mon) && x == 31 * SECS)
        printf("%d.12.31 23:59:60\n", yr);
    else {
        int day = x / SECS + 1;
        x %= SECS;
        int hr = x / 3600;
        x %= 3600;
        int mnt = x / 60;
        x %= 60;
        printf("%d.%02d.%02d %02d:%02d:%02lld\n", yr, mon, day, hr, mnt, x);
    }
}

int T, p, q, a;
vector<ll> ans;

int main() {
    scanf("%d", &T);
    FOR(cs, 1, T) {
        scanf("%d%d%d", &p, &q, &a);
        ans.clear();
        if (!a) ans = {0};
        else {    // 高次模方程 x ^ q == a (mod p)
            int m = primitive_root(p, p - 1);
            int z = log_mod(m, a, p);
            linear_mod_equation(ans, q, z, p - 1);
            for (auto &it : ans) it = fast_pow(m, it, p);
            sort(all(ans));
        }
        printf("Case #%d:\n", cs);
        if (ans.empty()) puts("Transmission error");
        else for (auto it : ans) print_ans(it);
    }
    return 0;
}
