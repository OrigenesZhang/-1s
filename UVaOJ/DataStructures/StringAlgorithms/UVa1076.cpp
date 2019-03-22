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

const int sigma_size = 26;
const int maxn = 112 * 26;

int cnt, n, m, cs;
ll dp[30][112][1 << 10];

struct Node {
    vector<int> ch;
    int val, f;

    Node() {
        ch = vector<int>(sigma_size, 0);
        f = val = 0;
    }
} trie[maxn];

void insert(const string &s, int i) {
    int now = 0;
    for (auto ch : s) {
        int idx = ch - 'a';
        if (!trie[now].ch[idx]) {
            trie[cnt] = Node();
            trie[now].ch[idx] = cnt;
            cnt++;
        }
        now = trie[now].ch[idx];
    }
    trie[now].val |= 1 << i;
}

void build() {
    queue<int> q;
    REP(idx, sigma_size) {
        int u = trie[0].ch[idx];
        if (u) q.push(u);
    }
    while (!q.empty()) {
        int r = q.front(); q.pop();
        REP(idx, sigma_size) {
            int u = trie[r].ch[idx];
            if (!u) {
                trie[r].ch[idx] = trie[trie[r].f].ch[idx];
                continue;
            }
            q.push(u);
            int v = trie[r].f;
            while (v && !trie[v].ch[idx]) v = trie[v].f;
            trie[u].f = trie[v].ch[idx];
            trie[u].val |= trie[trie[u].f].val;
        }
    }
}

ll dfs(int pos, int u, int mask) {
    if (pos == n) return mask == (1 << m) - 1;
    if (dp[pos][u][mask] >= 0) return dp[pos][u][mask];
    ll &cur = dp[pos][u][mask];
    cur = 0;
    for (int v : trie[u].ch)
            cur += dfs(pos + 1, v, mask | trie[v].val);
    return cur;
}

void print(int pos, int u, int mask, string now, vector<string> &vec) {
    if (pos == n) {
        if (mask == (1 << m) - 1) vec.eb(now);
        return;
    }
    if (dp[pos][u][mask] <= 0) return;
    REP(i, sigma_size)
            print(pos + 1, trie[u].ch[i], mask | trie[trie[u].ch[i]].val, now + char('a' + i), vec);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    while (cin >> n >> m) {
        if (!n) break;
        cnt = 1;
        trie[0] = Node();
        reset(dp, -1);
        REP(i, m) {
            string s;
            cin >> s;
            insert(s, i);
        }
        build();
        ll ans = dfs(0, 0, 0);
        cout << "Case " << ++cs << ": " << ans << " suspects\n";
        if (ans <= 42) {
            vector<string> now;
            print(0, 0, 0, "", now);
            sort(all(now));
            for (const auto &it : now) cout << it << '\n';
        }
    }
}
