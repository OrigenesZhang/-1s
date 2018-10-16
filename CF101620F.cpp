#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef long long LL;

const int N = 12345678;

LL n, p, r;

LL Inv[N];

inline LL inv(LL u, LL p) {
    if (Inv[u]) return Inv[u];
    LL ans = 1;
    LL cur = u;
    LL pw = p - 2;
    while (pw) {
        if (pw & 1) ans = ans * cur % p;
        cur = cur * cur % p;
        pw >>= 1;
    }
    Inv[u] = ans;
    Inv[ans] = u;
    return ans;
}

bool vis[N];
vector<LL> vec;

/*void find_inv() {
    Inv[1] = 1;
    vis[1] = true;

    for (int i = 2; i < p; i++)
        if (!vis[i]) {
            vec.clear();
            LL cur = i;
            while (cur != 1) {
                vis[cur] = true;
                vec.push_back(cur);
                cur = cur * i % p;
            }
            for (int l = 0, r = vec.size() - 1; l <= r; l++, r--) Inv[vec[l]] = vec[r], Inv[vec[r]] = vec[l];
        }
}*/

int main() {
    cin >> n >> p >> r;
    if (r == 0) {
        if (n < p) cout << -1 << ' ' << -1 << '\n';
        else {
            if (p == 2) {
                if (n == 2) cout << -1 << ' ' << -1 << '\n';
                else cout << 3 << ' ' << 1 << '\n';
            } else {
                cout << 2 << ' ' << 1 << '\n';
            }
        }
    } else {
        if (n >= p * 2) cout << -1 << ' ' << -1 << '\n';
        else if (n >= p) {
            LL rest = 1;
            for (int i = 1; i <= n; i++)
                if (i != p) {
                    rest = rest * i % p;
                }
            cout << p << ' ' << r * inv(rest, p) % p << '\n';
        } else {
            LL tot = 1;
            for (int i = 1; i <= n; i++) tot = tot * i % p;
            bool ok = false;
            LL need = inv(tot, p) * r % p;
            //find_inv();
            for (LL i = n; i >= 1; i--) {
                LL cur = i * need % p;
                if (cur < i) { ok = true; cout << i << ' ' << cur << '\n'; break; }
            }
            if (!ok) cout << -1 << ' ' << -1 << '\n';
        }
    }
    return 0;
}