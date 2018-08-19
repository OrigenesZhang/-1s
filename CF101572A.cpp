#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 500000 + 10;
const double INF = 1e12;

int a, b, t, r, n;
LL l, pos[N];
double d[N];
bool vis[N];

double cal_time(LL lef, LL rig) {
    if (rig - lef <= t * a) return double(rig - lef) / a;
    else if (rig - lef <= t * a + r * b) return t + double(rig - lef - t * a) / b;
    else return t + r + double(rig - lef - t * a - r * b) / a;
}

int next_chosen[N];

double dp(int u) {
    if (vis[u]) return d[u];
    double& ans = d[u];
    ans = cal_time(pos[u], l);
    vis[u] = true;
    LL dis = pos[u] + t * a + r * b;

    int next_idx = upper_bound(pos, pos + n, dis) - pos - 1;
    if (pos[next_idx] - pos[u] >= t * a) //ans = min(ans, dp(next_idx) + cal_time(pos[u], pos[next_idx]));
        if (dp(next_idx) + cal_time(pos[u], pos[next_idx]) < ans) {
            ans = dp(next_idx) + cal_time(pos[u], pos[next_idx]);
            next_chosen[u] = next_idx;
        }
    next_idx++;
    if (next_idx < n) //ans = min(ans, dp(next_idx) + cal_time(pos[u], pos[next_idx]));
        if (dp(next_idx) + cal_time(pos[u], pos[next_idx]) < ans) {
            ans = dp(next_idx) + cal_time(pos[u], pos[next_idx]);
            next_chosen[u] = next_idx;
        }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> l >> a >> b >> t >> r;
    cin >> n;
    if (n == 0) { cout << 0 << '\n'; return 0; }
    for (int i = 0; i < n; i++) cin >> pos[i];
    dp(0);
    vector<int> idx;
    int cur = 0;
    while (next_chosen[cur]) {
        cur = next_chosen[cur];
        idx.push_back(cur);
    }
    cout << idx.size() + 1 << '\n';
    cout << 0;
    for (int u : idx) cout << ' ' << u;
    cout << '\n';
    return 0;
}