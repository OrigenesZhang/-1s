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

struct Node {
    string name;
    int money;
    bool operator < (const Node& rhs) const {
        return money > rhs.money;
    }
};

const int N = 10000 + 10;

Node node[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, d, k;
    cin >> n >> d >> k;
    for (int i = 0; i < n; i++) {
        cin >> node[i].name >> node[i].money;
    }
    sort(node, node + n);
    int tot = 0, idx = -1;
    for (int i = 0; i < k; i++) {
        tot += node[i].money;
        if (tot >= d) { idx = i; break; }
    }
    if (idx == -1) cout << "impossible\n";
    else {
        cout << idx + 1 << '\n';
        for (int i = 0; i <= idx; i++) cout << node[i].name << ", YOU ARE FIRED!\n";
    }
    return 0;
}