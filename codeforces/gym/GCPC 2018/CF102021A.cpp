#include <bits/stdc++.h>
#define pb push_back
using namespace std;

using pii = pair<int, int>;

const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };

const int N = 1123;

int f[N][N], tot;  // build map
vector<int> G[N * N];

int fa[N * N][25], dep[N * N];  // LCA

int n, m;
string s[N];

int ID(int r, int c) {
    if (f[r][c]) return f[r][c];
    f[r][c] = ++tot;
    return f[r][c];
}

void dfs(int u, int pa, int depth) {
    dep[u] = depth;
    fa[u][0] = pa;
    for (int v : G[u]) {
        if (v == pa) continue;
        dfs(v, u, depth + 1);
    }
}

void preprocess() {
    for (int j = 1; j < 20; j++) {
        for (int i = 1; i <= tot; i++) {
            int pa = fa[i][j - 1];
            fa[i][j] = fa[pa][j - 1];
        }
    }
}

int LCA(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);

    for (int i = 20; i >= 0; i--) {
        int pa = fa[u][i];
        if (dep[pa] < dep[v]) continue;
        u = pa;
    }


    if (u == v) return u;

    for (int i = 20; i >= 0; i--) {
        if (fa[u][i] == fa[v][i]) continue;
        u = fa[u][i];
        v = fa[v][i];
    }

    return fa[u][0];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    getline(cin, s[0]);

    for (int i = 0; i <= n; i++) getline(cin, s[i]);

    //for (int i = 0; i <= n; i++) cout << s[i] << endl;

    // build:
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int r = i, c = 2 * j - 1;


            if (r > 1) {  // up
                if (s[r - 1][c] == ' ') G[ID(r, j)].pb(ID(r - 1, j));
            }
            if (r < n) {  // down
                if (s[r][c] == ' ') G[ID(r, j)].pb(ID(r + 1, j));
                //if (r == 1 && c == 3) cout << "!" << endl;
            }
            if (j > 1) {  // left
                if (s[r][c - 1] == ' ') G[ID(r, j)].pb(ID(r, j - 1));
            }
            if (j < m) {  // right
                if (s[r][c + 1] == ' ') G[ID(r, j)].pb(ID(r, j + 1));
            }
        }
    }

//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= m; j++) cerr << f[i][j] << ' ';
//        cerr << endl;
//    }

    dfs(1, 0, 1);

    //for (int i = 1; i <= tot; i++) cout << i << ' ' << dep[i] << endl;

    //for (int i = 1; i <= tot; i++) cerr << dep[i] << endl;

    preprocess();

//    for (int i = 1; i <= tot; i++) {
//        cout << i << ":" << endl;
//        for (int j = 0; j < 3; j++) cout << fa[i][j] << ' ';
//        cout << endl;
//    }

    int q;
    cin >> q;
    long long ans = 0;

    int lr = 0, lc = 0;
    for (int i = 0; i < q; i++) {
        int r, c;
        cin >> r >> c;

        if (i) {
            ans += dep[ID(r, c)] + dep[ID(lr, lc)] - dep[LCA(ID(r, c), ID(lr, lc))] * 2;
        }

        lr = r; lc = c;
    }

    cout << ans << '\n';
    return 0;
}