#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL, LL> pll;

const int N = 112345;

struct Node {
    LL b, f, d;
    bool operator < (const Node& rhs) const {
        return b < rhs.b || (b == rhs.b && f > rhs.f);
    }
};

Node node[N];

int n;

LL val[N];

map<LL, LL> to_small;

LL c[N];

int lowbit(LL x) { return x & (-x); }

LL maxm(LL x) {
    LL ans = 0;
    while (x) {
        ans = max(ans, c[x]);
        x -= lowbit(x);
    }
    return ans;
}

void update(LL x, LL d) {
    while (x <= n) {
        c[x] = max(c[x], d);
        x += lowbit(x);
    }
}

set<pll> pic;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> node[i].b >> node[i].f >> node[i].d;

    sort(node, node + n);
    int sz = 0;
    for (int i = 1; i < n; i++) {
        if (node[i].b == node[i - 1].b && node[i].f == node[i - 1].f) node[sz].d += node[i].d;
        else node[++sz] = node[i];
    }
    sz++;

    for (int i = 0; i < sz; i++) val[i] = node[i].f;
    sort(val, val + sz);
    int val_sz = unique(val, val + sz) - val;
    for (int i = 0; i < val_sz; i++) to_small[val[i]] = i + 1;
    for (int i = 0; i < sz; i++) node[i].f = to_small[node[i].f];

    LL ans = 0;
    for (int i = 0; i < sz; i++) {
        LL cur = maxm(node[i].f - 1);
        ans = max(ans, cur + node[i].d);
        update(node[i].f, cur + node[i].d);
    }
    cout << ans << '\n';

    //LL ans = 0;
    /*for (int i = 0; i < sz; i++) {
        pll cur = pll(node[i].f, 0);
        LL val = node[i].d;
        auto it = pic.upper_bound(cur);
        if (it != pic.begin()) {
            it--;
            val += it->second;
            //ans = max(ans, val);
        }

        for (;;) {
            it = pic.upper_bound(cur);
            if (it == pic.end()) break;
            if (it->second <= val) pic.erase(it);
            else break;
        }

        it = pic.upper_bound(cur);
        if (it == pic.end() || it->first > node[i].f) pic.insert({ node[i].f, val });
    }
    //cout << ans << '\n';
    auto it = pic.end();
    cout << (--it)->second << '\n';
    return 0;*/
}