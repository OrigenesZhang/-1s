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
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second

namespace FFT {
    typedef complex<double> cd;
    const double PI = acos(-1);

    void fft(vector<cd> &a, bool inv = false) {
        int n = a.size();
        for (int i = 0, j = 0; i < n; i++) {
            if (j > i) swap(a[i], a[j]);
            int k = n;
            while (j & (k >>= 1)) j &= ~k;
            j |= k;
        }
        double pi = inv ? -PI : PI;
        for (int step = 1; step < n; step <<= 1) {
            double alpha = pi / step;
            REP(k, step) {
                cd omegak = exp(cd(0, alpha * k));
                for (int ek = k; ek < n; ek += step << 1) {
                    int ok = ek + step;
                    cd t = omegak * a[ok];
                    a[ok] = a[ek] - t;
                    a[ek] += t;
                }
            }
        }
        if (inv) REP(i, n) a[i] /= n;
    }

    vector<ll> operator*(const vector<ll> &v1, const vector<ll> &v2) {
        int s1 = v1.size(), s2 = v2.size(), s = 2;
        while (s < s1 + s2) s <<= 1;
        vector<cd> a(s, 0), b(s, 0);
        REP(i, s1) a[i] = v1[i];
        REP(i, s2) b[i] = v2[i];
        fft(a);
        fft(b);
        REP(i, s) a[i] *= b[i];
        fft(a, true);
        vector<ll> ans(s1 + s2 - 1);
        REP(i, s1 + s2 - 1) ans[i] = ll(round(a[i].real()));
        return ans;
    }
}

using namespace FFT;

const int maxn = 512345;
char s[maxn], t[maxn];

int main() {
    scanf("%s%s", s, t);
    int m = strlen(s), n = strlen(t);
    reverse(t, t + n);
    vector<ll> a[4], b[4];
    REP(i, 4) {
        a[i].resize(m);
        b[i].resize(n);
    }
    map<char, int> mmap;
    mmap['A'] = 0; mmap['C'] = 1;
    mmap['G'] = 2; mmap['T'] = 3;
    REP(i, m) a[mmap[s[i]]][i]++;
    REP(i, n) b[mmap[t[i]]][i]++;
    vector<ll> tot(n + m - 1);
    REP(i, 4) {
        auto now = a[i] * b[i];
        REP(j, n + m - 1) tot[j] += now[j];
    }
    ll mmin = 1e15;
    FOR(i, n - 1, m - 1) mmin = min(mmin, n - tot[i]);
    printf("%lld\n", mmin);
    return 0;
}
