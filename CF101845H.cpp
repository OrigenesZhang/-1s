#include <bits/stdc++.h>
using namespace std;

int n;

char s[][10] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

int solve(int num) {
    if (num % 4) return 365;
    if (num % 400 == 0) return 366;
    if (num % 100 == 0) return 365;
    else return 366;
}

int main() {
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++) ans = (ans + solve(i + 1867)) % 7;
    //cout << solve(1868) << ' ' << 1868 % 4 << endl;
    cout << s[ans] << '\n';
    return 0;
}