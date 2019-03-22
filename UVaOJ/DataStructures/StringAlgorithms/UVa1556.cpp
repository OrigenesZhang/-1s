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

const int maxn = 41234;

int n, cnt;

struct Node {
    int dep;
    map<int, int> ch;

    Node() {
        dep = 0;
        ch.clear();
    }
} trie[maxn];

map<string, int> lis;
map<int, string> rlis;

void insert(const vector<string> &s) {
    int now = 0;
    for (const auto& cur : s) {
        if (!lis.count(cur)) {
            lis[cur] = lis.size();
            rlis[lis[cur]] = cur;
        }
        int idx = lis[cur];
        if (!trie[now].ch.count(idx)) {
            trie[now].ch[idx] = cnt;
            trie[cnt] = Node();
            cnt++;
        }
        trie[trie[now].ch[idx]].dep = trie[now].dep + 1;
        now = trie[now].ch[idx];
    }
}

vector<string> parse(const string& str) {
    int len = str.length(), pre = 0, now = 0;
    vector<string> ret;
    while (pre + now < len) {
        if (str[pre + now] == '\\') {
            auto tmp = str.substr(pre, now);
            ret.eb(str.substr(pre, now));
            pre = pre + now + 1;
            now = 0;
        } else now++;
    }
    ret.eb(str.substr(pre, now));
    return ret;
}

void dfs(int u) {
    vector<pii> tmp;
    for (auto now : trie[u].ch) tmp.eb(now);
    sort(all(tmp), [](pii a, pii b) { return rlis[a._1] < rlis[b._1]; });
    for (auto now : tmp) {
        REP(i, trie[u].dep) cout << ' ';
        cout << rlis[now._1] << '\n';
        dfs(now._2);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    while (cin >> n) {
        lis.clear();
        cnt = 1;
        trie[0] = Node();
        FOR(i, 1, n) {
            string s;
            cin >> s;
            insert(parse(s));
        }
        dfs(0);
        cout << '\n';
    }
}
