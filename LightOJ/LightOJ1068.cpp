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

const int maxk = 85;
const int maxp = 11;

struct State {
    int pos, num, sum, flag;
};

bool vis[maxp][maxk][maxk][2];
int dp[maxp][maxk][maxk][2], K, tot;

int bfs(const int *upp) {
    if (upp[0] == -1)
        return 1;
    reset(vis, 0);
    queue<State> q;
    REP(i, upp[0]) {
        vis[0][i % K][i % K][1] = true;
        dp[0][i % K][i % K][1] = 1;
        q.push({0, i % K, i % K, 1});
    }
    vis[0][upp[0] % K][upp[0] % K][0] = true;
    dp[0][upp[0] % K][upp[0] % K][0] = 1;
    q.push({0, upp[0] % K, upp[0] % K, 0});
    while (!q.empty()) {
        State u = q.front();
        q.pop();
        int pos = u.pos, num = u.num, sum = u.sum, flag = u.flag;
        if (upp[pos + 1] == -1) break;
        if (flag) {
            REP(i, 10) {
                if (vis[pos + 1][(num * 10 + i) % K][(sum + i) % K][1])
                    dp[pos + 1][(num * 10 + i) % K][(sum + i) % K][1] += dp[pos][num][sum][1];
                else {
                    vis[pos + 1][(num * 10 + i) % K][(sum + i) % K][1] = true;
                    dp[pos + 1][(num * 10 + i) % K][(sum + i) % K][1] = dp[pos][num][sum][1];
                    q.push({pos + 1, (num * 10 + i) % K, (sum + i) % K, 1});
                }
            }
        } else {
            REP(i, upp[pos + 1]) {
                if (vis[pos + 1][(num * 10 + i) % K][(sum + i) % K][1])
                    dp[pos + 1][(num * 10 + i) % K][(sum + i) % K][1] += dp[pos][num][sum][0];
                else {
                    vis[pos + 1][(num * 10 + i) % K][(sum + i) % K][1] = true;
                    dp[pos + 1][(num * 10 + i) % K][(sum + i) % K][1] = dp[pos][num][sum][0];
                    q.push({pos + 1, (num * 10 + i) % K, (sum + i) % K, 1});
                }
            }
            if (vis[pos + 1][(num * 10 + upp[pos + 1]) % K][(sum + upp[pos + 1]) % K][0])
                dp[pos + 1][(num * 10 + upp[pos + 1]) % K][(sum + upp[pos + 1]) % K][0] += dp[pos][num][sum][0];
            else {
                vis[pos + 1][(num * 10 + upp[pos + 1]) % K][(sum + upp[pos + 1]) % K][0] = true;
                dp[pos + 1][(num * 10 + upp[pos + 1]) % K][(sum + upp[pos + 1]) % K][0] = dp[pos][num][sum][0];
                q.push({pos + 1, (num * 10 + upp[pos + 1]) % K, (sum + upp[pos + 1]) % K, 0});
            }
        }
    }
    if (!vis[tot][0][0][0]) dp[tot][0][0][0] = 0;
    if (!vis[tot][0][0][1]) dp[tot][0][0][1] = 0;
    return dp[tot][0][0][0] + dp[tot][0][0][1];
}

int conv(int num, int *a) {
    int cnt = 0;
    while (num) {
        a[cnt++] = num % 10;
        num /= 10;
    }
    REP(i, cnt / 2) swap(a[i], a[cnt - i - 1]);
    return cnt;
}

int T, A, B;

int main() {
    scanf("%d", &T);
    FOR(cs, 1, T) {
        scanf("%d%d%d", &A, &B, &K);
        printf("Case %d: ", cs);
        if (K > 82) {
            puts("0");
            continue;
        }
        reset(vis, 0);
        int upp[15];
        reset(upp, -1);
        tot = conv(B, upp) - 1;
        int ans = bfs(upp);
        reset(upp, -1);
        tot = conv(A - 1, upp) - 1;
        ans -= bfs(upp);
        printf("%d\n", ans);
    }
    return 0;
}
