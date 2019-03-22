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

bool flag;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string p;
    vector<string> lis;
    while (getline(cin, p)) {
        int n = p.length(), pre = 0, cnt = 1;
        string pref, suf;
        lis.clear();
        REP(i, n) {
            if (p[i] == '*') {
                lis.eb(p.substr(pre, i - pre));
                cnt++;
                while (i < n && p[i] == '*') i++;
                pre = i;
                i--;
                continue;
            }
        }
        if (pre != n) suf = p.substr(pre, n - pre);
        if (!lis.empty()) {
            pref = lis.front();
            lis.erase(lis.begin());
        }
        string s;
        vector<string> ans;
        if (cnt <= 2) assert(lis.empty());
        else assert(lis.size());
        while (getline(cin, s)) {
            if (s.empty()) break;
            if (s.length() < pref.length() + suf.length()) continue;
            if (s.substr(0, pref.length()) != pref || s.substr(s.length() - suf.length(), suf.length()) != suf) continue;
            if (cnt == 1) {
                if (s.length() == pref.length() + suf.length()) ans.eb(s);
                continue;
            } else if (cnt == 2) {
                ans.eb(s);
                continue;
            }
            string tmp = s.substr(pref.length(), s.length() - pref.length() - suf.length());
            int cur = 0;
            REP(i, int(tmp.length())) {
                if (tmp.length() - i < lis[cur].length()) break;
                if (tmp.substr(i, lis[cur].length()) == lis[cur]) {
                    cur++;
                    if (cur == lis.size()) break;
                }
            }
            if (cur == lis.size()) ans.eb(s);
        }
        if (ans.size()) {
            if (flag) cout << '\n';
            else flag = true;
            cout << "MATCHES FOR THE PATTERN: " << p << '\n';
            for (const auto &it : ans) cout << it << '\n';
        }
    }
}
