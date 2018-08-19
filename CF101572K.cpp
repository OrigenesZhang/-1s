#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define all(x) (x).begin(), (x).end()
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define mp make_pair
#define _1 first
#define _2 second

const int N = 100000 + 10;

int a[5], b[5];

int s[5], n, c[N];

struct Node {
    int val, idx1, idx2;
    bool operator < (const Node& rhs) const {
        return val < rhs.val || (val == rhs.val && idx1 < rhs.idx1);
    }
} node[100];

bool check(int val) {
    b[0] = a[0]; b[1] = a[1]; b[2] = a[2];

    for (int i = 0; i < n; i++) {
        bool ok = false;
        for (int j = 0; j < 6; j++)
            if (node[j].val * c[i] >= val) {
                if (node[j].idx1 == node[j].idx2 && b[node[j].idx1] >= 2) { b[node[j].idx1] -= 2; ok = true; break; }
                else if (node[j].idx1 != node[j].idx2 && b[node[j].idx1] >= 1 && b[node[j].idx2] >= 1) { b[node[j].idx1]--; b[node[j].idx2]--; ok = true; break; }
            }
        if (!ok) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> a[0] >> a[1] >> a[2];
    cin >> s[0] >> s[1] >> s[2];
    n = (a[0] + a[1] + a[2]) / 2;
    for (int i = 0; i < n; i++) cin >> c[i];
    sort(c, c + n);
    reverse(c, c + n);

    int cnt = 0;
    for (int i = 0; i < 3; i++)
        for (int j = i; j < 3; j++) {
            node[cnt].val = s[i] + s[j];
            node[cnt].idx1 = i;
            node[cnt++].idx2 = j;
        }
    sort(node, node + cnt);

    int l = 1, r = int(1e9);

    while (l < r) {
        int mid = l + (r - l) / 2;
        if (check(mid)) l = mid + 1;
        else r = mid;
    }
    cout << l - 1 << '\n';
    return 0;
}