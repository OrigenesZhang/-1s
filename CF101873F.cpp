#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define mp make_pair
#define _1 first
#define _2 second

const int Maxnode = 3123;

vector<int> G[Maxnode];

int num_left, num_right, num_edge, match[Maxnode];
bool check[Maxnode];

bool dfs(int u) {
    //check[u] = true;
    for (int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        if (!check[v]) {
            check[v] = true;
            if (match[v] == -1 || dfs(match[v])) {
                match[v] = u;
                //match[u] = v;
                return true;
            }
        }
    }
    return false;
}

int hungarian() {
    int ans = 0;
    memset(match, -1, sizeof(match));
    for (int u = 0; u < num_left; u++) {
        fill(check, check + num_right, false);
        if (dfs(u)) ans++;
    }
    return ans;
}

int solve(int idx) {
    G[num_left - 2].clear();
    G[num_left - 1].clear();
    for (int i = 0; i < num_right; i++)
        if (match[i] == num_left - 1 || match[i] == num_left - 2)
            match[i] = -1;
    G[num_left - 2] = G[num_left - 1] =  G[idx];

    int ans = 0;
    for (int u = num_left - 2; u < num_left; u++) {
        fill(check, check + num_right, false);
        if (dfs(u)) ans++;
    }
    return ans;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> num_left >> num_right >> num_edge;
    for (int i = 0; i < num_edge; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        G[x].push_back(y);
    }

    int tot = hungarian();
    //cout << tot << endl;
    int ans = tot;

    num_left += 2;
    for (int i = 0; i < num_left - 2; i++) {
        ans = max(ans, tot + solve(i));
    }
    cout << ans << '\n';
    return 0;
}