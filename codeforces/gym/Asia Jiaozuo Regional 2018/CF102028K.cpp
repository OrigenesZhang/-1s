#include <bits/stdc++.h>
using namespace std;
using LL = unsigned long long;
 
const int N = 112345;
const LL x = 37;
 
map<LL, int> my_hash[N];
LL h[N], pw[N];
int d[N][20];
int n, m, q;
string s;
vector<int> G[N];
int max_len;
char ch[N];
 
void dfs(int u, LL val, int dep) {
    max_len = max(max_len, dep);
    val = val * x + unsigned(ch[u] - 'a' + 3);
    //cout << u << ' ' << val << endl;
    my_hash[dep][val] = u;
    for (auto it : G[u]) dfs(it, val, dep + 1);
}
 
LL get_hash(int l, int r) {
    LL ans = h[r];
    int len = r - l + 1;
    if (l) ans -= h[l - 1] * pw[len];
    return ans;
}
 
int main() {
    ch[0] = 'a' - 3;
    pw[0] = 1;
    for (int i = 1; i <= 100000; i++) pw[i] = pw[i - 1] * x;
 
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m >> q;
        for (int i = 1; i <= n; i++) {
            int f;
            cin >> f >> ch[i];
            G[f].push_back(i);
        }
 
        cin >> s;
 
        // get hash:
        dfs(0, 0, 0);
        h[0] = s[0] - 'a' + 3;
        for (int i = 1; i < m; i++) h[i] = h[i - 1] * x + unsigned(s[i] - 'a' + 3);
 
        //for (int i = 0; i < m; i++) cout << h[i] << endl;
 
        // get d[i][0]:
        for (int i = 0; i < m; i++) {
            int l = i, r = m;
            while (l < r) {
                int mid = (l + r) >> 1;
                int len = mid - i + 1;
                LL cur_hash = get_hash(i, mid);
                if (my_hash[len].count(cur_hash)) l = mid + 1;
                else r = mid;
            }
            d[i][0] = min(l + 1, m);
        }
 
        //for (int i = 0; i < m; i++) cout << d[i][0] << endl;
 
        for (int i = 0; i < 18; i++) d[m][i] = m;
 
        // get d:
        for (int len = 1; len < 18; len++) {
            for (int i = 0; i < m; i++) {
                d[i][len] = d[d[i][len - 1]][len - 1];
            }
        }
 
        // get ans:
        while (q--) {
            int l, r;
            cin >> l >> r;
            --l; --r;
            int cur = l, cnt = 0;
 
            for (int len = 17; len >= 0; len--) {
                if (d[cur][len] <= r) {
                    cnt += (1 << len);
                    cur = d[cur][len];
                }
            }
 
            LL cur_hash = get_hash(cur, r);
            int len = r - cur + 1;
            if (my_hash[len].count(cur_hash)) {
                cout << cnt << ' ' << my_hash[len][cur_hash] << '\n';
            } else {
                cout << cnt + 1 << ' ' << 0 << '\n';
            }
        }
 
        for (int i = 0; i <= max_len; i++) my_hash[i].clear();
        for (int i = 0; i <= n; i++) G[i].clear();
        max_len = 0;
    }
    return 0;
}