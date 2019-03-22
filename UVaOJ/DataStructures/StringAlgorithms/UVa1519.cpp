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

const int maxn = 412345;

struct Node {
    int ch[26];

    Node() {
        reset(ch, -1);
    }
} trie[2][maxn];

int cnt[2][26], tot[2];
bool vis[26];

void insert(bool suf, const string &s) {
    int now = 0;
    bool en = false;
    for (auto ch : s) {
        int idx = ch - 'a';
        if (trie[suf][now].ch[idx] == -1) {
            trie[suf][tot[suf]] = Node();
            trie[suf][now].ch[idx] = tot[suf];
            tot[suf]++;
            if (en) cnt[suf][idx]++;
        }
        now = trie[suf][now].ch[idx];
        en = true;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    while (cin >> n) {
        tot[0] = tot[1] = 1;
        reset(cnt, 0);
        reset(vis, false);
        trie[0][0] = Node();
        trie[1][0] = Node();
        while (n--) {
            string s;
            cin >> s;
            if (s.length() == 1) vis[s[0] - 'a'] = true;
            insert(false, s);
            reverse(all(s));
            insert(true, s);
        }
        ll ans = ll(tot[0] - 1) * (tot[1] - 1);
        REP(i, 26) ans = ans + vis[i] - ll(cnt[0][i]) * cnt[1][i];
        cout << ans << '\n';
    }
}
