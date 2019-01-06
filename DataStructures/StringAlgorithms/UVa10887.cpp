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

const int maxn = 1512;

string s[maxn], t;

int T, n, m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> T;
    FOR(cs, 1, T) {
        cin >> n >> m;
        cin.ignore();
        unordered_set<string> mem;
        REP(i, n) getline(cin, s[i]);
        REP(i, m) {
            getline(cin, t);
            REP(j, n) mem.insert(s[j] + t);
        }
        cout << "Case " << cs << ": " << mem.size() << '\n';
    }
}
