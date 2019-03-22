// 默认栈好小
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

const int maxn = 41234;
const int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool vis[maxn];
int sg[maxn], T;

inline int enc(int y, int m, int d) {
    return d + m * 31 + y * 31 * 12;
}

int dfs(int y, int m, int d) {
    int h_code = enc(y, m, d);
    if (vis[h_code]) return sg[h_code];
    vis[h_code] = true;
    int &ret = sg[h_code];
    set<int> mex;
    if (m != 1) {
        if (d + 1 < days[m]) mex.insert(dfs(y, m, d + 1));
        else if (m != 11) {
            mex.insert(dfs(y, m + 1, 0));
        } else {
            mex.insert(dfs(y + 1, 0, 0));
        }
    } else {
        if (y % 4 || y == 0) {
            if (d < 27) mex.insert(dfs(y, m, d + 1));
            else mex.insert(dfs(y, m + 1, 0));
        } else {
            if (d < 28) mex.insert(dfs(y, m, d + 1));
            else mex.insert(dfs(y, m + 1, 0));
        }
    }
    if (m) {
        if (m == 11) {
            mex.insert(dfs(y + 1, 0, d));
        } else {
            if (d < days[m + 1]) mex.insert(dfs(y, m + 1, d));
        }
    } else {
        if (y % 4 || y == 0) {
            if (d < 28) mex.insert(dfs(y, m + 1, d));
        } else {
            if (d < 29) mex.insert(dfs(y, m + 1, d));
        }
    }
    int p = -1;
    for (int it : mex) {
        if (it > p + 1) return ret = p + 1;
        p = it;
    }
    return ret = p + 1;
}

int main() {
    vis[enc(101, 10, 3)] = true;
    int now = 1;
    ROF(d, 2, 0) {
        vis[enc(101, 10, d)] = true;
        sg[enc(101, 10, d)] = now;
        now ^= 1;
    }
    ROF(d, 30, 4) {
        vis[enc(101, 9, d)] = true;
        sg[enc(101, 9, d)] = now;
        now ^= 1;
    }
    scanf("%d", &T);
    while (T--) {
        int y, m, d;
        scanf("%d%d%d", &y, &m, &d);
        y -= 1900;
        m--;
        d--;
        puts(dfs(y, m, d) ? "YES" : "NO");
    }
    return 0;
}
