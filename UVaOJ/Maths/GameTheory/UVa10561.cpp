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

const int maxn = 213;

char s[maxn];
int sg[maxn], N;

void init() {
    sg[0] = 0;
    sg[1] = sg[2] = sg[3] = 1;
    FOR(i, 4, 200) {
        vector<int> s;
        REP(j, (i + 1) / 2) {
            int now = 0;
            if (j - 2 > 0) now ^= sg[j - 2];
            if (i - j - 3 > 0) now ^= sg[i - j - 3];
            s.pb(now);
        }
        sort(all(s));
        if (s.empty() || s[0]) sg[i] = 0;
        else {
            int n = s.size();
            s.pb(0x3f3f3f3f);
            REP(j, n) if (s[j + 1] > s[j] + 1) {
                    sg[i] = s[j] + 1;
                    break;
                }
        }
    }
}

int main() {
    init();
    scanf("%d", &N);
    while (N--) {
        scanf("%s", s);
        int n = strlen(s);
        vector<int> ans;
        REP(i, n - 2) {
            if (s[i] == 'X' && s[i + 2] == 'X') ans.pb(i + 1);
            if (s[i] == 'X' && s[i + 1] == 'X') ans.pb(i + 2);
            if (s[i + 1] == 'X' && s[i + 2] == 'X') ans.pb(i);
        }
        if (ans.size()) {
            puts("WINNING");
            printf("%d", ans[0] + 1);
            FOR(i, 1, int(ans.size()) - 1) printf(" %d", ans[i] + 1);
            puts("");
            continue;
        }
        vector<int> ps = {-3};
        REP(i, n) if (s[i] == 'X') ps.pb(i);
        ps.pb(n + 2);
        int sum = 0;
        FOR(i, 1, int(ps.size()) - 1)
            if (ps[i] - ps[i - 1] > 5) sum ^= sg[ps[i] - ps[i - 1] - 5];
        if (sum) {
            puts("WINNING");
            int now = 1;
            REP(i, n) {
                if (s[i] == 'X') continue;
                while (i > ps[now]) now++;
                if (i + 2 >= ps[now] || i - 2 <= ps[now - 1]) continue;
                sum ^= sg[ps[now] - ps[now - 1] - 5];
                int cur = 0;
                if (ps[now - 1] + 5 < i) cur ^= sg[i - ps[now - 1]- 5];
                if (i + 5 < ps[now]) cur ^= sg[ps[now] - i - 5];
                sum ^= cur;
                if (!sum) ans.pb(i);
                sum ^= cur;
                sum ^= sg[ps[now] - ps[now - 1] - 5];
            }
            printf("%d", ans[0] + 1);
            FOR(i, 1, int(ans.size()) - 1) printf(" %d", ans[i] + 1);
            puts("");
        } else {
            puts("LOSING\n");
        }
    }
    return 0;
}
