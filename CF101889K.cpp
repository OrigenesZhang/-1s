#include <bits/stdc++.h>
#define _1 first
#define _2 second
#define pb push_back
using namespace std;

const int N = 20 + 5;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, 1, 0, -1 };
typedef pair<int, int> P;

int r, c, num_left, num_right;
bool check[N * N * 2];
int match[N * N * 2];
string s[N];

vector<int> G[N * N * 2];

map<P, P> idx;

bool dfs(int u) {
    for (int v : G[u])
        if (!check[v]) {
            check[v] = true;
            if (match[v] == -1 || dfs(match[v])) {
                match[v] = u;
                return true;
            }
        }
    return false;
}

void construct_edges(int cur_r, int cur_c) {
    P index = idx[P(cur_r, cur_c)];
    for (int i = 0; i < 4; i++) {
        int rr = cur_r + dr[i];
        int cc = cur_c + dc[i];
        if (rr < 0 || cc < 0 || rr >= r || cc >= c) continue;

        P index2 = idx[P(rr, cc)];
        if (index._1 == index._2) {
            if (index2._1 == index2._2) G[index._1].pb(index2._1);
            else G[index._1].pb(index2._1), G[index._1].pb(index2._2);
        } else {
            if (index2._1 == index2._2) G[index._1].pb(index2._1), G[index._2].pb(index2._1);
            else G[index._1].pb(index2._2), G[index._2].pb(index2._1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> r >> c;
    for (int i = 0; i < r; i++) cin >> s[i];

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) {
            if ((i + j) % 2) {
                if (s[i][j] == 'o') {
                    idx[P(i, j)] = P(num_left, num_left);
                    num_left++;
                } else {
                    idx[P(i, j)] = P(num_left, num_left + 1);
                    //cout << i << ' ' << j << ' ' << num_left << endl;
                    num_left += 2;
                }
            } else {
                if (s[i][j] == 'o') {
                    idx[P(i, j)] = P(num_right, num_right);
                    num_right++;
                } else {
                    idx[P(i, j)] = P(num_right, num_right + 1);
                    num_right += 2;
                }
            }
        }

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if ((i + j) % 2) construct_edges(i, j);

    //cout << num_left << ' ' << num_right << endl;

    if (num_left != num_right) { cout << "N\n"; return 0; }

    int ans = 0;
    memset(match, -1, sizeof(match));
    for (int i = 0; i < num_left; i++) {
        fill(check, check + num_right, 0);
        if (dfs(i)) ans++;
    }
    //cout << ans << '\n';

    //for (int i = 0; i < 2; i++)
    //   for (int u : G[i]) cout << u << ' ';

    //for (int i = 0; i < num_right; i++) cout << match[i] << endl;

    if (ans == num_left) cout << "Y\n";
    else cout << "N\n";
    return 0;
}