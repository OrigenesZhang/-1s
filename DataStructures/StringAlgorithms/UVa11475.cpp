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

const int maxn = 112345;

int n, f[maxn];
string s, t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    while (cin >> t) {
        s = t;
        reverse(all(t));
        n = s.length();
        f[0] = f[1] = 0;
        FOR(i, 1, n - 1) {
            int j = f[i];
            while (j && t[i] != t[j]) j = f[j];
            f[i + 1] = t[i] == t[j] ? j + 1 : 0;
        }
        int j = 0;
        REP(i, n) {
            while (j && s[i] != t[j]) j = f[j];
            if (s[i] == t[j]) j++;
            if (i == n - 1)
                cout << s << t.substr(j, n) << '\n';
        }
    }
}
