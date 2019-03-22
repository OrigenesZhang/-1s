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

const int N = 200 + 10;

int n, m;
int d[N][N], tot;
map<string, int> idx;

int ID(string& s) {
    if (idx.count(s)) return idx[s];
    else return idx[s] = tot++;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        int idx1 = ID(name);
        for (int j = 0; j < 4; j++) cin >> name;
        int idx2 = ID(name);
        d[idx1][idx2] = 1;
    }

    for (int k = 0; k < tot; k++)
        for (int i = 0; i < tot; i++)
            for (int j = 0; j < tot; j++)
                if (d[i][k] && d[k][j]) d[i][j] = 1;

    for (int i = 0; i < m; i++) {
        string name1, name2;
        cin >> name1;
        for (int j = 0; j < 4; j++) cin >> name2;
        if (!idx.count(name1) || !idx.count(name2)) cout << "Pants on Fire\n";
        else {
            int idx1 = idx[name1];
            int idx2 = idx[name2];
            if (d[idx1][idx2]) cout << "Fact\n";
            else if (d[idx2][idx1]) cout << "Alternative Fact\n";
            else cout << "Pants on Fire\n";
        }
    }
    return 0;
}