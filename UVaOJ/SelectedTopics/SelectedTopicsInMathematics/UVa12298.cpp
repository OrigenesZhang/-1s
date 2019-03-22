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

namespace FFT {
    typedef complex<double> cd;
    const double PI = acos(-1);
    
    // Cooley-Tukey's FFT iterative
    void fft(vector<cd> &a, bool inv = false) {
        int n = a.size();
        // in-place bit reversal
        for (int i = 0, j = 0; i < n; i++) {
            if (j > i) swap(a[i], a[j]);
            int k = n;
            while (j & (k >>= 1)) j &= ~k;
            j |= k;
        }
        double pi = inv ? -PI : PI;
        for (int step = 1; step < n; step <<= 1) {
            double alpha = pi / step;
            // 蝴蝶操作枚举下标
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

    // 多项式乘法
    vector<double> operator*(const vector<double> &v1, const vector<double> &v2) {
        int s1 = v1.size(), s2 = v2.size(), s = 2;
        while (s < s1 + s2) s <<= 1;
        vector<cd> a(s, 0), b(s, 0);
        REP(i, s1) a[i] = v1[i];
        REP(i, s2) b[i] = v2[i];
        fft(a);
        fft(b);
        REP(i, s) a[i] *= b[i];
        fft(a, true);
        vector<double> ans(s1 + s2 - 1);
        REP(i, s1 + s2 - 1) ans[i] = a[i].real();
        return ans;
    }
}

using namespace FFT;

const int maxn = 51234;

bool comp[maxn], lost[4][maxn];
int a, b, c;

void init(int n) {
    int upp = sqrt(n + 0.5);
    memset(comp, false, sizeof(comp));
    FOR(i, 2, upp) if (!comp[i])
            for (int j = i * i; j <= n; j += i) comp[j] = true;
}

inline int idx(char ch) {
    switch (ch) {
        case 'S':
            return 0;
        case 'H':
            return 1;
        case 'C':
            return 2;
        default:
            return 3;
    }
}

int main() {
    init(50000);
    while (scanf("%d%d%d", &a, &b, &c) == 3) {
        if (!a) break;
        memset(lost, false, sizeof(lost));
        REP(i, c) {
            int d;
            char s;
            scanf("%d%c", &d, &s);
            lost[idx(s)][d] = true;
        }
        vector<double> ans(1, 1), poly;
        REP(s, 4) {
            poly.clear();
            poly.resize(b + 1, 0);
            FOR(i, 4, b) if (comp[i] && !lost[s][i]) poly[i] = 1;
            ans = ans * poly;
            ans.resize(b + 1);
        }
        FOR(i, a, b) printf("%.0lf\n", fabs(ans[i]));
        puts("");
    }
    return 0;
}
