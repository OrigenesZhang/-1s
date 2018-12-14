#include <bits/stdc++.h>
#define pb push_back
using namespace std;

typedef long long LL;
typedef pair<int, int> pii;
const int N = 212345;
const LL INF = LL(1e15);

set<int> id[N * 4];
vector<int> xval;

int n;
vector<int> ans;

struct Node {
    int type, x, y;
};
vector<Node> node;

void update(int o, int l, int r, int ql, int qr, int sym, int num) {
    if (ql <= l && r <= qr) {
        if (sym == 1) id[o].insert(num);
        else id[o].erase(num);
    } else {
        int mid = l + (r - l) / 2;
        if (ql <= mid) update(o * 2, l, mid, ql, qr, sym, num);
        if (qr > mid) update(o * 2 + 1, mid + 1, r, ql, qr, sym, num);
    }
}

void query(int o, int l, int r, int pos) {
    for (auto it = id[o].begin(); it != id[o].end(); it++) ans.pb(*it);
    if (l == r) return;
    int mid = l + (r - l) / 2;
    if (pos <= mid) query(o * 2, l, mid, pos);
    else query(o * 2 + 1, mid + 1, r, pos);
}

bool check(int u, LL x, LL y) {
    LL cx = node[u].x, cy = node[u].y;
    return (cx - x) * (cx - x) + (cy - y) * (cy - y) < cy * cy;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int t, x, y;
        cin >> t >> x >> y;
        node.pb({ t, x, y });
        if (t == 2) xval.pb(x);
    }

    sort(xval.begin(), xval.end());
    xval.erase(unique(xval.begin(), xval.end()), xval.end());

    for (int i = 0; i < n; i++) {
        Node& cur = node[i];
        if (cur.type == 1) {
            int l = upper_bound(xval.begin(), xval.end(), cur.x - cur.y) - xval.begin();
            int r = lower_bound(xval.begin(), xval.end(), cur.x + cur.y) - xval.begin() - 1;
            if (l > r) continue;
            update(1, 0, xval.size() - 1, l, r, 1, i + 1);
        } else {
            ans.clear();
            int pos = lower_bound(xval.begin(), xval.end(), cur.x) - xval.begin();
            query(1, 0, xval.size() - 1, pos);
            int ok = -1;
            for (int u : ans) {
                if (check(u - 1, cur.x, cur.y)) { ok = u; break; }
            }
            cout << ok << '\n';
            if (ok > -1) {
                int x = node[ok - 1].x, y = node[ok - 1].y;
                int l = upper_bound(xval.begin(), xval.end(), x - y) - xval.begin();
                int r = lower_bound(xval.begin(), xval.end(), x + y) - xval.begin() - 1;
                update(1, 0, xval.size() - 1, l, r, -1, ok);
            }
        }
    }
    return 0;
}