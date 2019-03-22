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

const int maxn = 123;

int T, N, sg[3][3][maxn];
bool vis[3][3][maxn];
char txt[maxn];

int dfs(int s, int e, int l) {
    if (vis[s][e][l]) return sg[s][e][l];
    int &ret = sg[s][e][l];
    vis[s][e][l] = true;
    if (!l) return ret = 0;
    set<int> mex;
    FOR(i, 1, l) {
        FOR(now, 1, 2) {
            if (i == 1 && s == now) continue;
            if (i == l && e == now) continue;
            mex.insert(dfs(s, now, i - 1) ^ dfs(now, e, l - i));
        }
    }
    int p = -1;
    for (auto it : mex) {
        if (it > p + 1) return ret = p + 1;
        p = it;
    }
    return ret = p + 1;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%s", txt);
        int s = 0, e = 0, sum = 0, r = 0, cnt = 0;
        N = strlen(txt);
        REP(i, N) {
            if (txt[i] == '.') cnt++;
            else {
                e = txt[i] == 'O' ? 1 : 2;
                sum ^= dfs(s, e, cnt);
                s = e;
                cnt = 0;
                r++;
            }
        }
        sum ^= dfs(s, 0, cnt);
        if (r & 1) sum = !sum;
        puts(sum ? "Possible." : "Impossible.");
    }
    return 0;
}
