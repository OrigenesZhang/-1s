#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second

const int maxn = 1123456;

char s[maxn];
int f[maxn];

int main() {
    while (scanf("%s", s) && s[0] != '.') {
        int n = strlen(s);
        f[0] = f[1] = 0;
        FOR(i, 1, n - 1) {
            int j = f[i];
            while (j && s[i] != s[j]) j = f[j];
            f[i + 1] = s[i] == s[j] ? j + 1 : 0;
        }
        printf("%d\n", n / (n - f[n]));
    }
}
