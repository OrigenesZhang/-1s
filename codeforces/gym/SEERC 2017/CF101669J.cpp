#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REP(i, n) FOR(i, 0, (n) - 1)
typedef long long ll;

const int maxn = 123456;

int a[maxn], n;

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d", a + i);
    sort(a, a + n);
    if (a[n - 1] == 1) {
        puts(n % 3 ? "Win" : "Lose");
        return 0;
    }
    if (n == 1 || a[n - 2] == 1) {
        puts("Win");
        return 0;
    }
    if (n == 2) {
        puts("Lose");
        return 0;
    }
    if (a[n - 3] == 1) {
        int cnt = 0;
        REP(i, n) if (a[i] == 1) cnt++;
        if (cnt % 3 == 0) {
            puts("Lose");
            return 0;
        }
        cnt = 0;
        REP(i, n) if (a[i] == 2) cnt++;
        puts(cnt ? "Win" : "Lose");
        return 0;
    }
    puts("Lose");
    return 0;
}