#include<iostream>
using namespace std;

const int N = 123456;

int f[N], d[N];
// f: R - B; d: B - R
string s;

int main() {
    cin >> s;
    for(int i = s.length() - 1; i >= 0; i--)
        if(s[i] == 'R') {
            f[i] = max(1, f[i + 1] + 1);
            d[i] = max(-1, d[i + 1] - 1);
        } else {
            f[i] = max(-1, f[i + 1] - 1);
            d[i] = max(1, d[i + 1] + 1);
        }

    int maxf = -1, curf = -1, maxd = -1, curd = -1;
    for(int i = 0; i < s.length(); i++) {
        if(f[i] > maxf) { maxf = f[i]; curf = i; }
        if(d[i] > maxd) { maxd = d[i]; curd = i; }
    }

    if(maxf > maxd || (maxf == maxd && curf < curd)) {
        int l = curf, diff = 0, r = curf;
        for(int i = l; i < s.length(); i++) {
            if(s[i] == 'R') diff++;
            else diff--;
            if(diff == maxf) { r = i; break; }
        }
        cout << l + 1 << ' ' << r + 1 << '\n';
    } else if(maxf < maxd || (maxf == maxd && curf > curd)) {
        int l = curd, diff = 0, r = curd;
        for(int i = l; i < s.length(); i++) {
            if(s[i] == 'B') diff++;
            else diff--;
            if(diff == maxd) { r = i; break; }
        }
        cout << l + 1 << ' ' << r + 1 << '\n';
    }

    return 0;
}
