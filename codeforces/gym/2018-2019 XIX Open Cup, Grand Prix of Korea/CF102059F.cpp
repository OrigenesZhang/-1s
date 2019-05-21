#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using pii = pair<int, int>;

int cur;
map<LL, int> id;
vector<pii> ans;

int dfs(LL u) {
    if (id.count(u)) return id[u];
    if (u == 1) {
        id[u] = ++cur;
        ans.push_back({ -1, -1 });
        return id[u];
    }
    LL l, r;
    if (u % 2 == 1) l = dfs(u / 2 + 1);
    else l = dfs(u / 2);
    r = dfs(u / 2);

    id[u] = ++cur;
    //cerr << u << ' ' << id[u] << endl;
    ans.push_back({ l, r });
    return id[u];
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        LL n;
        cin >> n;
        cur = -1;
        ans.clear();
        id.clear();
        dfs(n);

        cout << ans.size() << '\n';
        for (auto it : ans) cout << it.first << ' ' << it.second << '\n';
        cout << ans.size() - 1 << '\n';
    }
    return 0;
}