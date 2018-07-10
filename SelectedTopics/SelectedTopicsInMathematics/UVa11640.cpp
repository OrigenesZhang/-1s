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

const ll MOD = 786433;
const int maxn = 55;

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
        REP(i, s1 + s2 - 1) ans[i] = ll(round(a[i].real())) % MOD;
        return ans;
    }
}

int T, N, Q, L;
vector<ll> rec[maxn];
int p, l, u, c[maxn];

inline void upd(ll &a, ll b) {
    a = (a + b) % MOD;
}

void dp(int idx) {
    ll mem[2][10][11];
    int cur = 0, nxt = 1;
    memset(mem, 0, sizeof(mem));
    REP(i, p) mem[cur][i][1] = 1;
    l ? rec[idx].pb(0) : rec[idx].pb(1);
    FOR(pos, 1, u) {
        if (l > pos) rec[idx].pb(0);
        else {
            ll ans = 0;
            REP(clr, p) FOR(len, 1, c[clr])upd(ans, mem[cur][clr][len]);
            rec[idx].pb(ans);
        }
        memset(mem[nxt], 0, sizeof(mem[nxt]));
        REP(clr, p) {
            FOR(len, 1, c[clr]) {
                if (len != c[clr]) upd(mem[nxt][clr][len + 1], mem[cur][clr][len]);
                REP(cc, p) {
                    if (cc == clr) continue;
                    upd(mem[nxt][cc][1], mem[cur][clr][len]);
                }
            }
        }
        cur ^= 1;
        nxt ^= 1;
    }
}

using namespace FFT;

int main() {
    scanf("%d", &T);
    FOR(cs, 1, T) {
        scanf("%d", &N);
        REP(i, N) {
            rec[i].clear();
            scanf("%d%d%d", &p, &l, &u);
            REP(j, p) scanf("%d", &c[j]);
            dp(i);
        }
        vector<ll> ans = {1};
        REP(i, N) ans = ans * rec[i];
        scanf("%d", &Q);
        printf("Case #%d:\n", cs);
        FOR(q, 1, Q) {
            scanf("%d", &L);
            if (L >= ans.size()) printf("Query %d: 0\n", q);
            else printf("Query %d: %lld\n", q, ans[L]);
        }
        puts("");
    }
    return 0;
}
