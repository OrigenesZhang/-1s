#include <iostream>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

typedef long long LL;

vector<LL> ans;
set<LL> ok;

int bits(LL val) {
    int ret = 0;
    while (val) {
        ret++;
        val /= 10;
    }
    return ret;
}

LL Conc(LL a, LL b) {
    LL pw = 1;
    while (pw <= b) pw *= 10;
    a = a * pw + b;
    return a;
}

void preprocess() {
    for (LL base = 1; base <= int(1e5); base++) {
        LL up = sqrt(base + 0.5);
        for (LL den = 1; den <= up; den++)
            if (base % (den * den) == 0) {
                for (LL num = den + 1; ; num++) {
                    LL tot = Conc(base, base / den * num);
                    LL cur = base / den / den * num * num;
                    if (bits(tot) + bits(cur) > 15) break;

                    tot = Conc(tot, cur);
                    ok.insert(tot);

                    while (cur % den == 0) {
                        cur = cur / den * num;
                        if (bits(tot) + bits(cur) > 15) break;
                        tot = Conc(tot, cur);
                        ok.insert(tot);
                    }
                }
            }
    }

    for (auto it = ok.begin(); it != ok.end(); it++) ans.push_back(*it);
}

LL solve(LL val) {
    LL l = 0, r = ans.size();
    while (l < r) {
        LL mid = l + (r - l) / 2;
        if (ans[mid] <= val) l = mid + 1;
        else r = mid;
    }
    return l - 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    preprocess();
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        LL a, b;
        cin >> a >> b;
        cout << "Case #" << i << ": ";
        cout << solve(b) - solve(a - 1) << '\n';
    }
    return 0;
}