#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int N;
int a[1123];
LL total = 0;
int cur = 1;
int res = 0;

int main() {
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> a[i];
    }

    sort(a + 1, a + N + 1);
    while (cur <= N) {
//        cout << cur << endl;
//        cout << total << endl;
        if (a[cur] > total) {
            res++;
            total += a[cur];
        }
        cur = lower_bound(a + cur + 1, a + N + 1, total) - a;
    }

    cout << res << endl;
}