// 这破题脑子有坑...
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

struct Frac {

    ll nom, den;

    Frac() {
        nom = 0;
        den = 1;
    }

    Frac(ll nom, ll den) {
        this->nom = nom;
        this->den = den;
        deal();
    }

    void deal() {
        ll d = __gcd(nom, den);
        nom /= d;
        den /= d;
        if (den < 0) {
            nom = -nom;
            den = -den;
        }
    }

    Frac operator+(Frac rhs) {
        Frac ans;
        ans.nom = nom * rhs.den + den * rhs.nom;
        ans.den = den * rhs.den;
        ans.deal();
        return ans;
    }

    Frac operator-(Frac rhs) {
        Frac ans;
        ans.nom = nom * rhs.den - den * rhs.nom;
        ans.den = den * rhs.den;
        ans.deal();
        return ans;
    }

    Frac operator*(Frac rhs) {
        Frac ans;
        ans.nom = nom * rhs.nom;
        ans.den = den * rhs.den;
        ans.deal();
        return ans;
    }

    Frac operator/(Frac rhs) {
        Frac ans;
        ans.nom = nom * rhs.den;
        ans.den = den * rhs.nom;
        ans.deal();
        return ans;
    }

    void operator+=(Frac rhs) { *this = *this + rhs; }

    void operator+=(ll rhs) { *this = *this + Frac(rhs, 1); }

    void operator-=(Frac rhs) { *this = *this - rhs; }

    void operator*=(Frac rhs) { *this = *this * rhs; }

    void operator/=(Frac rhs) { *this = *this / rhs; }

    bool operator>(Frac rhs) { return nom * rhs.den > den * rhs.nom; }

    bool operator==(Frac rhs) { return nom * rhs.den == den * rhs.nom; }

    bool operator<(Frac rhs) { return !(*this < rhs && *this == rhs); }

    bool operator>=(Frac rhs) { return !(*this < rhs); }

    bool operator<=(Frac rhs) { return !(*this > rhs); }

    bool operator!=(Frac rhs) { return !(*this == rhs); }

    bool operator!=(ll rhs) { return *this != Frac(rhs, 1); }

    void operator=(ll rhs) {
        this->nom = rhs;
        this->den = 1;
    }
};

int T, sig, n;
char s[15];
int f[15];
Frac A[15][15];

void solve() {
    REP(i, n + 1) {
        int r;
        for (r = i; r <= n; r++) if (A[r][i] != 0) break;
        FOR(j, i, n + 1) swap(A[i][j], A[r][j]);
        ROF(j, n + 1, i + 1) A[i][j] /= A[i][i];
        A[i][i] = 1;
        REP(j, n + 1) {
            if (i == j) continue;
            if (A[j][i] != 0) {
                ROF(k, n + 1, i + 1) A[j][k] -= A[j][i] * A[i][k];
                A[j][i] = 0;
            }
        }
    }
    A[0][n + 1] /= A[0][0];
}

int main() {
    scanf("%d", &T);
    FOR(cs, 1, T) {
        scanf("%d%s", &sig, s + 1);
        n = strlen(s + 1);
        FOR(i, 1, n) s[i] -= 'A';
        f[0] = f[1] = 0;
        int j = 0;
        FOR(i, 2, n) {
            while (j && s[i] != s[j + 1]) j = f[j];
            if (s[i] == s[j + 1]) j++;
            f[i] = j;
        }
        REP(i, n + 1) REP(j, n + 2) A[i][j] = 0;
        REP(i, n) {
            A[i][n + 1] = 1;
            A[i][i] = 1;
            REP(j, sig) {
                if (s[i + 1] == j) {
                    A[i][i + 1] += {-1, sig};
                    continue;
                }
                int now = i;
                bool flag = true;
                while (now) {
                    now = f[now];
                    if (s[now + 1] == j) {
                        flag = false;
                        A[i][now + 1] += {-1, sig};
                        break;
                    }
                }
                if (flag) A[i][0] += {-1, sig};
            }
        }
        A[n][n] = 1;
        solve();
        printf("Case %d:\n%lld\n", cs, A[0][n + 1].nom);
        if (cs != T) puts("");
    }
}
