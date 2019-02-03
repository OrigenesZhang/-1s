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

const int maxn = 1123456;

struct Node {
    int ch[26];

    Node() {
        reset(ch, -1);
    }
} trie[maxn];

int pos[maxn], cnt, clk, dep[maxn], in[maxn], st[maxn << 1][21];

void insert(int id, const string &s) {
    int now = 0;
    for (auto ch : s) {
        int idx = ch - 'a';
        if (trie[now].ch[idx] == -1) {
            trie[cnt] = Node();
            trie[now].ch[idx] = cnt;
            dep[cnt] = dep[now] + 1;
            cnt++;
        }
        now = trie[now].ch[idx];
    }
    pos[id] = now;
}

void dfs(int u) {
    in[u] = ++clk;
    st[clk][0] = u;
    for (int v : trie[u].ch) if (v != -1) {
            dfs(v);
            st[++clk][0] = u;
        }
}

void rmq_init() {
    FOR(i, 1, clk) FOR(j, 1, 20) {
            st[i][j] = st[i][j - 1];
            int val = i - (1 << j - 1);
            if (val > 0 && dep[st[val][j - 1]] < dep[st[i][j]])
                st[i][j] = st[val][j - 1];
        }
}

int rmq(int l, int r) {
    int val = floor(log(r - l + 1) / log(2));
    int u = st[l + (1 << val) - 1][val], v = st[r][val];
    return dep[u] < dep[v] ? u : v;
}

int lca(int u, int v) {
    if (in[u] > in[v]) swap(u, v);
    return rmq(in[u], in[v]);
}

int T, n, q;
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> T;
    FOR(cs, 1, T) {
        cin >> n;
        trie[0] = Node();
        cnt = 1;
        clk = dep[0] = 0;
        FOR(i, 1, n) {
            cin >> s;
            insert(i, s);
        }
        dfs(0);
        rmq_init();
        cin >> q;
        cout << "Case " << cs << ":\n";
        while (q--) {
            int u, v;
            cin >> u >> v;
            cout << dep[lca(pos[u], pos[v])] << '\n';
        }
    }
}
