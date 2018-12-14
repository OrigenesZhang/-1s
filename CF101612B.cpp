#include <iostream>
#include <cstring>
using namespace std;

string s;

int up[100], lw[100];

typedef long long LL;

int main() {
    freopen("boolean.in", "r", stdin);
    freopen("boolean.out", "w", stdout);
    cin >> s;

    bool both = false;
    bool neg = false;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '|') {
            neg = false;
        } else if (s[i] == '~') {
            neg ^= 1;
        } else {
            if (isupper(s[i])) {
                int cur = s[i] - 'A';
                if (neg) {
                    if (up[cur] == 1) { up[cur] = 2; both = true; }
                    else if (up[cur] == 0) up[cur] = -1;
                } else {
                    if (up[cur] == -1) { up[cur] = 2; both = true; }
                    else if (up[cur] == 0) up[cur] = 1;
                }
            } else {
                //cout << 1 << endl;
                int cur = s[i] - 'a';
                if (neg) {
                    if (lw[cur] == 1) { lw[cur] = 2; both = true; }
                    else if (lw[cur] == 0) lw[cur] = -1;
                } else {
                    //cout << 1 << endl;
                    if (lw[cur] == -1) { lw[cur] = 2; both = true; }
                    else if (lw[cur] == 0) lw[cur] = 1;
                }
            }
        }
    }

    int app = 0;
    for (int i = 0; i < 26; i++) {
        if (up[i]) app++;
        if (lw[i]) app++;
    }
    //cout << app << endl;

    LL ans = 1;
    for (int i = 1; i <= app; i++) ans *= 2;
    if (!both) ans--;
    cout << ans << '\n';
    fclose(stdout);
    return 0;
}

[close]
