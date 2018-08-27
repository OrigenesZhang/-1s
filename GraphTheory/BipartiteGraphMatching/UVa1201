// 拆点建图
// 将DAG上点u拆成一个X集的u'和一个Y集的u"
// 若对于DAG上的点u和v 存在边e(u->v) 则在u'和v"间加一条无向边
// 最小路径覆盖 = 新建二分图X集的点数 - 最大匹配

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define sqr(x) ((x) * (x))
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define mp make_pair
#define _1 first
#define _2 second

const int maxn = 512;

vector<int> G[2 * maxn];
int num_left;
int check[2 * maxn], match[2 * maxn], pre[2 * maxn];

int hungarian() {
    int ans = 0;
    reset(check, -1);
    reset(match, -1);
    REP(i, num_left) {
        queue<int> q;
        q.push(i);
        pre[i] = -1;
        while (!q.empty() && match[i] == -1) {
            int u = q.front(); q.pop();
            for (int v : G[u]) {
                if (match[i] != -1) break;
                if (check[v] != i) {
                    check[v] = i;
                    if (match[v] != -1) {
                        q.push(match[v]);
                        pre[match[v]] = u;
                    } else {
                        int d = u, e = v;
                        while (d != -1) {
                            int t = match[d];
                            match[d] = e;
                            match[e] = d;
                            d = pre[d];
                            e = t;
                        }
                    }
                }
            }
        }
        if (match[i] != -1) ans++;
    }
    return ans;
}

inline int dist(pii a, pii b) {
    return abs(a._1 - b._1) + abs(a._2 - b._2);
}

int T, e[maxn];
pii pos[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &num_left);
        REP(i, num_left) {
            G[i].clear();
            G[i + maxn].clear();
            int t, hh, mm;
            scanf("%d:%d", &hh, &mm);
            t = hh * 60 + mm;
            pii p1, p2;
            scanf("%d%d%d%d", &p1._1, &p1._2, &p2._1, &p2._2);
            e[i] = t + dist(p1, p2);
            REP(j, i) if (e[j] + dist(pos[j], p1) < t) {
                    G[j].pb(i + maxn);
                    G[i + maxn].pb(j);
                }
            pos[i] = p2;
        }
        printf("%d\n", num_left - hungarian());
    }
    return 0;
}
