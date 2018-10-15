include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#define pb push_back
using namespace std;

const int N = 500000 + 10;

int n, id;
vector<int> G[N];
vector<int> num[N];

void dfs(int u, int pa) {
    for (int v : G[u])
        if (v != pa) {
            if (num[u].size() < 2) {
                num[u].pb(++id);
                num[v].pb(id);
            } else {
                num[v].pb(num[u][0]);
            }
            dfs(v, u);
        }
    if (num[u].size() < 2) num[u].pb(++id);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    if (n == 2) {
        cout << 1 << ' ' << 2 << '\n' << 2 << ' ' << 1 << '\n';
        return 0;
    }
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        G[a].pb(b);
        G[b].pb(a);
    }

    dfs(1, 0);
    for (int i = 1; i <= n; i++)
        cout << num[i][0] << ' ' << num[i][1] << '\n';
    return 0;
}