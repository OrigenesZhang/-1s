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

const int maxn = 123456;

struct State {
    int id, p, t;
    bool operator < (const State &rhs) const {
        if (p != rhs.p) return p < rhs.p;
        if (t != rhs.t) return t > rhs.t;
        return id < rhs.id;
    }
};

int solved[maxn], penalty[maxn];
int n, m;
set<State> s;

inline bool better(int t1, int t2) {
    if (solved[t1] != solved[t2]) return solved[t1] > solved[t2];
    return penalty[t1] < penalty[t2];
}

inline bool equal(int t1, int t2) {
    return solved[t1] == solved[t2] && penalty[t1] == penalty[t2];
}

int main() {
    scanf("%d%d", &n, &m);
    REP(i, m) {
        int nowt, nowp;
        scanf("%d%d", &nowt, &nowp);
        if (s.find({nowt, solved[nowt], penalty[nowt]}) != s.end()) {
            s.erase({nowt, solved[nowt], penalty[nowt]});
        }
        solved[nowt]++;
        penalty[nowt] += nowp;
        if (nowt != 1) {
            State cur = {nowt, solved[nowt], penalty[nowt]};
            if (better(nowt, 1)) {
                s.insert(cur);
                printf("%d\n", int(s.size()) + 1);
                continue;
            }
        }
        while (!s.empty()) {
            int curId = s.begin()->id;
            if (better(1, curId) || equal(1, curId)) s.erase(s.begin());
            else break;
        }
        printf("%d\n", int(s.size()) + 1);
    }
    return 0;
}