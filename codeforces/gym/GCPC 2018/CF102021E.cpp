#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

const int N = 11234567;
bool vis[N];

int main() {

    int m = sqrt(10000000 + 0.5);

    vis[1] = true;
    for (int i = 2; i <= m; i++) if (!vis[i]) {
        for (int j = i * i; j <= 10000000; j += i) vis[j] = true;
    }

    int n;
    scanf("%d", &n);
    while (n--) {
        int a = 0, b = 0;
        string s;
        cin >> s;

        int cnt = -1;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '.') cnt = 0;
            else {
                a = a * 10 + s[i] - '0';
                if (cnt > -1) ++cnt;
            }
        }
        if (cnt == -1) cnt = 0;
        for (int i = 0; i < 5 - cnt; i++) a *= 10;

        cin >> s;
        cnt = -1;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '.') cnt = 0;
            else {
                b = b * 10 + s[i] - '0';
                if (cnt > -1) ++cnt;
            }
        }
        if (cnt == -1) cnt = 0;
        for (int i = 0; i < 5 - cnt; i++) b *= 10;

        //cout << a << ' ' << b << endl;

        if (a == b) { cout << 2 << ' ' << 2 << '\n'; continue; }

        int d = __gcd(a, b);
        a /= d; b /= d;

        //cout << a << ' ' << b << endl;


        if (!vis[a] && !vis[b]) cout << a << ' ' << b << '\n';
        else cout << "impossible\n";
    }
    return 0;
}