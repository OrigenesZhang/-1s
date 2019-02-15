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

const int maxn = 3123456;

struct Node {
    int val, ch[26];

    Node() {
        val = 0;
        reset(ch, -1);
    }
} trie[maxn];

int cnt = 1;

void insert(const string &s) {
    int n = s.length(), now = 0;
    REP(i, n) {
        int idx = s[i] - 'a';
        if (trie[now].ch[idx] == -1) {
            trie[cnt] = Node();
            trie[now].ch[idx] = cnt++;
        }
        now = trie[now].ch[idx];
        trie[now].val++;
    }
}

int vis[maxn];

string s;

void dfs(int u, int pos, int rem) {
    if (pos == s.length()) {
        vis[u] = 2;
        return;
    }
    if (!vis[u]) vis[u]++;
    if (rem) dfs(u, pos + 1, rem - 1);
    REP(i, 26) if (trie[u].ch[i] != -1) {
            if (s[pos] == i + 'a') dfs(trie[u].ch[i], pos + 1, rem);
            else if (rem) dfs(trie[u].ch[i], pos + 1, rem - 1);
            if (rem) dfs(trie[u].ch[i], pos, rem - 1);
        }
}

int dfs2(int u) {
    if (vis[u] == 2) return trie[u].val;
    int ret = 0;
    REP(i, 26) if (trie[u].ch[i] != -1 && vis[trie[u].ch[i]])
            ret += dfs2(trie[u].ch[i]);
    return ret;
}

void dfs3(int u) {
    REP(i, 26) if (trie[u].ch[i] != -1 && vis[trie[u].ch[i]]) dfs3(trie[u].ch[i]);
    vis[u] = 0;
}

int n, m, edth;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    trie[0] = Node();
    while (n--) {
        cin >> s;
        insert(s);
    }
    cin >> m;
    while (m--) {
        cin >> s >> edth;
        dfs(0, 0, edth);
        cout << dfs2(0) << '\n';
        dfs3(0);
    }
}
