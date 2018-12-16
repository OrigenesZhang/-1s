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

const int maxn = 50000 * 200 + 123;

struct Node {
    int ch[2], val;

    Node() {
        reset(ch, -1);
        val = 0;
    }
} trie[maxn];

int dep[maxn], cnt, ans;

void insert(const string &s) {
    int now = 0;
    for (auto ch : s) {
        int idx = ch - '0';
        if (trie[now].ch[idx] == -1) {
            trie[cnt] = Node();
            trie[now].ch[idx] = cnt;
            dep[cnt] = dep[now] + 1;
            cnt++;
        }
        now = trie[now].ch[idx];
        trie[now].val++;
    }
}

void dfs(int u) {
    ans = max(ans, dep[u] * trie[u].val);
    for (int v : trie[u].ch) if (v != -1) dfs(v);
}

int T, n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> T;
    while (T--) {
        cin >> n;
        trie[0] = Node();
        ans = dep[0] = 0;
        cnt = 1;
        string s;
        REP(i, n) {
            cin >> s;
            insert(s);
        }
        dfs(0);
        cout << ans << '\n';
    }
}
