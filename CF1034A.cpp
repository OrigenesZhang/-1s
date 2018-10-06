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
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second

const int maxn = 312345;
const int maxa = 15e6;

int n, a[maxn], cnt[maxa + 123], vis[maxa + 123];

int main() {
    scanf("%d", &n);
    int g = 0;
    FOR(i, 1, n) {
        scanf("%d", &a[i]);
        g = __gcd(a[i], g);
    }
    FOR(i, 1, n) a[i] /= g;
    vis[1] = -1;
    FOR(i, 2, maxa) {
        if (vis[i]) continue;
        for (ll j = ll(i) * i; j <= maxa; j += i) if (!vis[j]) vis[j] = i;
        vis[i] = i;
    }
    int ans = 0;
    FOR(i, 1, n) {
        if (a[i] == 1) continue;
        else {
            if (vis[a[i]] == a[i]) cnt[a[i]]++;
            else {
                int now = a[i];
                cnt[vis[now]]++;
                while (now != 1) {
                    if (vis[now] != vis[a[i]]) {
                        cnt[vis[now]]++;
                        a[i] = now;
                    }
                    now /= vis[now];
                }
            }
        }
    }
    FOR(i, 2, maxa) ans = max(cnt[i], ans);
    printf("%d\n", ans ? n - ans : -1);
    return 0;
}
