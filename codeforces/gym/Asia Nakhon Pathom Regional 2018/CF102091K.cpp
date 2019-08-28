#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define ROF(i, a, b) for (int i = (a); i >= (b); i--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x)*(x))
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end())
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
void solve() {
    ordered_set<pii> s;
    set<pair<int, pii>> q;
    int E;
    scanf("%d", &E);
    while (E--) {
        int op;
        scanf("%d", &op);
        if (op == 1) {
            int st, en, v;
            scanf("%d%d%d", &st, &v, &en);
            en++;
            s.insert(mp(v, st));
            q.emplace(en, mp(v, st));
        } else {
            int t, k;
            scanf("%d%d", &t, &k);
            while (!q.empty() && q.begin()->_1 <= t) {
                s.erase(q.begin()->_2);
                q.erase(q.begin());
            }
            if (s.size() < k) puts("-1");
            else printf("%d\n", s.find_by_order(k - 1)->_1);
        }
    }
}
 
int main() {
    int T;
    scanf("%d", &T);
    FOR(cs, 1, T) {
        printf("Case %d:\n", cs);
        solve();
    }
}