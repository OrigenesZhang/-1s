// 好坑 输入有空格所以要getline读
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
    while (getline(cin, s)) {
        int n = s.length(), ans = 123;
        FOR(k, 1, n) {
            set<string> lis;
            REP(i, n - k + 1) {
                lis.insert(s.substr(i, k));
                if (lis.size() > k + 1) {
                    ans = min(ans, i + k);
                    break;
                }
            }
        }
        if (ans > n) cout << "YES" << '\n';
        else cout << "NO:" << ans << '\n';
    }
}
