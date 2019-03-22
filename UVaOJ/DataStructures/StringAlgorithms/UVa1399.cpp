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

const int maxn = 51234;

int T, n, s, cnt, in[maxn], dp[maxn], pre[maxn], clk;
pii ans;
bool flag;

struct Node {
    vector<int> ch;
    int val, f, last;

    Node() {
        ch = vector<int>(n, -1);
        f = last = val = 0;
    }
} trie[maxn];

void insert(const string &s) {
    int now = 0;
    for (auto ch : s) {
        int idx = ch - 'A';
        if (trie[now].ch[idx] == -1) {
            trie[cnt] = Node();
            trie[now].ch[idx] = cnt;
            cnt++;
        }
        now = trie[now].ch[idx];
    }
    trie[now].val++;
}

void build() {
    queue<int> q;
    REP(idx, n) {
        int u = trie[0].ch[idx];
        if (u != -1) q.push(u);
    }
    while (!q.empty()) {
        int r = q.front(); q.pop();
        REP(idx, n) {
            int u = trie[r].ch[idx];
            if (u == -1) {
                trie[r].ch[idx] = trie[trie[r].f].ch[idx];
                continue;
            }
            q.push(u);
            int v = trie[r].f;
            while (v && trie[v].ch[idx] == -1) v = trie[v].f;
            trie[u].f = trie[v].ch[idx];
            trie[u].last = trie[trie[u].f].val ? trie[u].f : trie[trie[u].f].last;
        }
    }
}

void dfs(int u) {
    in[u] = ++clk;
    for (int v : trie[u].ch) {
        if (v == -1 || in[v] > 0) {
            flag = true;
            return;
        }
        if (in[v] || trie[v].val) continue;
        dfs(v);
        if (flag) return;
    }
    in[u] = -1;
}

void go(int u) {
    ROF(i, n - 1, 0) {
        int v = trie[u].ch[i];
        if (trie[v].val) continue;
        if (dp[u] + 1 > dp[v]) {
            dp[v] = dp[u] + 1;
            pre[v] = u;
            if (dp[v] > ans._1) ans = mp(dp[v], v);
            go(v);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> T;
    while (T--) {
        cin >> n >> s;
        cnt = 1;
        trie[0] = Node();
        REP(i, s) {
            string now;
            cin >> now;
            insert(now);
        }
        build();
        reset(in, 0);
        flag = clk = 0;
        dfs(0);
        if (flag) {
            cout << "No" << '\n';
            continue;
        }
        reset(dp, 0);
        reset(pre, -1);
        ans = mp(0, -1);
        go(0);
        if (!ans._1) {
            cout << "No" << '\n';
            continue;
        }
        string out;
        int now = pre[ans._2], nxt = ans._2;
        while (nxt) {
            REP(i, n) if (trie[now].ch[i] == nxt) {
                    out += i + 'A';
                    break;
                }
            nxt = now;
            now = pre[now];
        }
        reverse(all(out));
        cout << out << '\n';
    }
}
