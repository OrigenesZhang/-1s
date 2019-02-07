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

vector<string> lis;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    while (cin >> s) {
        if (s != "end") {
            lis.eb(s);
            continue;
        }
        while (cin >> s) {
            if (s == "end") {
                cout << '\n';
                lis.clear();
                break;
            }
            string from, to;
            string pref1, suff1, pref2, suff2;
            cin >> from >> to;
            REP(i, from.length()) if (from[i] == '*') {
                    pref1 = from.substr(0, i);
                    suff1 = from.substr(i + 1, from.length() - i - 1);
                    break;
                }
            REP(i, to.length()) if (to[i] == '*') {
                    pref2 = to.substr(0, i);
                    suff2 = to.substr(i + 1, to.length() - i - 1);
                    break;
                }
            cout << "rename " << from << ' ' << to << '\n';
            for (const auto &it : lis) if (it.length() + 1 >= from.length()) {
                    if (it.substr(0, pref1.length()) == pref1 && it.substr(it.length() - suff1.length(), suff1.length()) == suff1)
                        cout << "mv " << it << ' ' << pref2 << it.substr(pref1.length(), it.length() - from.length() + 1) << suff2 << '\n';
                }
        }
    }
}
