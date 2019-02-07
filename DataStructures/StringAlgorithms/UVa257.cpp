// 题意恶心
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

int main() {
    string s;
    while (cin >> s) {
        set<string> pal;
        int n = s.size();
        REP(i, n - 2) if (s[i] == s[i + 2]) {
                pal.insert(s.substr(i, 3));
                if (pal.size() >= 2) {
                    cout << s << '\n';
                    goto label;
                }
            }
        REP(i, n - 3) if (s[i] == s[i + 3] && s[i + 1] == s[i + 2]) {
                if (pal.count(s.substr(i, 3)) || pal.count(s.substr(i + 1, 3))) continue;
                pal.insert(s.substr(i, 4));
                if (pal.size() >= 2) {
                    cout << s << '\n';
                    goto label;
                }
            }
        label:;
    }
}
