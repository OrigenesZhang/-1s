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

struct Node {
    int ch[10], val;

    Node() {
        val = 0;
        reset(ch, -1);
    }
};

map<string, int> lis;
map<int, string> rlis;
vector<Node> trie;

void dfs(int u, int id) {
    REP(i, 10) {
        if (trie[u].ch[i] == -1) {
            trie[u].ch[i] = trie.size();
            trie.eb();
            trie[trie[u].ch[i]].val = id;
        } else if (trie[trie[u].ch[i]].val) continue;
        else dfs(trie[u].ch[i], id);
    }
}

int dfs2(int u) {
    if (trie[u].val) return trie[u].val;
    REP(i, 10) if (trie[u].ch[i] == -1) return 0;
    int ret = 0;
    REP(i, 10) {
        if (trie[trie[u].ch[i]].val) {
            if (!ret) ret = trie[trie[u].ch[i]].val;
            else if (trie[trie[u].ch[i]].val != ret) return 0;
        }
        int now = dfs2(trie[u].ch[i]);
        if (!now) return 0;
        if (!ret) ret = now;
        else if (ret != now) return 0;
    }
    assert(ret);
    trie[u].val = ret;
    return ret;
}

void insert(const string &s, int id) {
    int now = 0, n = s.length();
    bool flag = false;
    REP(i, n) {
        int idx = s[i] - '0';
        if (trie[now].ch[idx] == -1) {
            trie[now].ch[idx] = trie.size();
            trie.eb();
            flag = true;
        } else flag = false;
        now = trie[now].ch[idx];
        if (trie[now].val) return;
    }
    if (flag) trie[now].val = id;
    else dfs(now, id);
    REP(i, 10) if (trie[0].ch[i] != -1) dfs2(trie[0].ch[i]);
}

void insert(vector<Node> &trie, const string &s, int pos) {
    int now = 0, n = s.length();
    REP(i, n) {
        int idx = s[i] - '0';
        if (trie[now].ch[idx] == -1) {
            trie[now].ch[idx] = trie.size();
            trie.eb();
        }
        now = trie[now].ch[idx];
        if (i >= pos) trie[now].val -= 100;
    }
    if (n - 1 < pos) trie[now].val++;
}

void go(const vector<Node> &trie, vector<string> &ops) {
    string pref;
    int now = 0;
    while (true) {
        int fi = 11, se = -1;
        REP(i, 10) if (trie[now].ch[i] != -1) {
                fi = min(fi, i);
                se = max(se, i);
            }
        assert(fi < 10 && se > -1);
        if (fi == se) {
            if (trie[trie[now].ch[fi]].val == 2 || trie[trie[now].ch[fi]].val == -99) {
                ops.eb(pref + char('0' + fi));
                return;
            }
            pref += char('0' + fi);
            now = trie[now].ch[fi];
        } else {
            FOR(i, fi + 1, se - 1) ops.eb(pref + char('0' + i));
            string s1, s2;
            int pre = now;
            while (!trie[trie[now].ch[fi]].val) {
                s1 += char('0' + fi);
                now = trie[now].ch[fi];
                REP(i, 10) if (trie[now].ch[i] != -1) {
                        fi = i;
                        break;
                    }
                if (trie[trie[now].ch[fi]].val == -100) {
                    ops.eb(pref + s1);
                    goto label;
                }
                FOR(i, fi + 1, 9) ops.eb(pref + s1 + char('0' + i));
            }
            ops.eb(pref + s1 + char('0' + fi));
            label:
            now = pre;
            while (!trie[trie[now].ch[se]].val) {
                s2 += char('0' + se);
                now = trie[now].ch[se];
                REP(i, 10) if (trie[now].ch[i] != -1) {
                        se = i;
                        break;
                    }
                if (trie[trie[now].ch[se]].val == -100) {
                    ops.eb(pref + s2);
                    return;
                }
                REP(i, se) ops.eb(pref + s2 + char('0' + i));
            }
            ops.eb(pref + s2 + char('0' + se));
            return;
        }
    }
}

void parse(string &a, const string &bb, vector<string> &ops) {
    string b = a;
    int n = a.length();
    REP(i, bb.length())
        b[n - i - 1] = bb[bb.length() - 1 - i];
    while (!a.empty() && a.back() == '0' && !b.empty() && b.back() == '9') a.pop_back(), b.pop_back();
    if (a.empty()) a = "0", b = "9";
    n = a.length();
    int pos[2] = {n + 5, n + 5};
    bool en[2] = {true, true};
    ROF(i, n - 1, 1) {
        if (a[i] == '0' && en[0]) pos[0] = i;
        else en[0] = false;
        if (b[i] == '9' && en[1]) pos[1] = i;
        else en[1] = false;
    }
    vector<Node> t(1, Node());
    insert(t, a, pos[0]);
    insert(t, b, pos[1]);
    go(t, ops);
}

void print(int u, string pref, vector<pair<string, int>> &ans) {
    REP(i, 10) if (trie[u].ch[i] != -1) {
            int v = trie[u].ch[i];
            if (trie[v].val) {
                if (trie[v].val == -1) continue;
                ans.eb(pref + char('0' + i), trie[v].val);
            } else print(v, pref + char('0' + i), ans);
        }
}

int n, T;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    while (cin >> n) {
        if (T++) cout << '\n';
        lis["invalid"] = -1;
        rlis[-1] = "invalid";
        trie = vector<Node>(1, Node());
        while (n--) {
            string a, b, buff;
            cin >> a >> buff >> b;
            cin >> buff;
            vector<string> ops;
            parse(a, b, ops);
            if (!lis.count(buff)) {
                lis[buff] = lis.size() + 1;
                rlis[lis.size() + 1] = buff;
            }
            for (const auto &now : ops) insert(now, lis[buff]);
        }
        vector<pair<string, int>> ans;
        print(0, "", ans);
        cout << ans.size() << '\n';
        for (const auto &it : ans) cout << it._1 << ' ' << rlis[it._2] << '\n';
    }
}
