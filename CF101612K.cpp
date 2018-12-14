#include <iostream>
using namespace std;

const int N = 100 + 10;

int h, w, n;
char ans[N][N];

void print(int r, int c) {
    for (int i = 1; i <= h; i++)
        for (int j = 1; j <= w; j++) ans[i][j] = '.';
    int cur = 2, tot = 0;
    while (tot < r - 1) {
        for (int j = 1; j <= w; j++) ans[cur][j] = '#';
        cur += 2;
        tot++;
    }

    cur = 2; tot = 0;
    while (tot < c - 1) {
        for (int j = 1; j <= h; j++) ans[j][cur] = '#';
        cur += 2;
        tot++;
    }

    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) cout << ans[i][j];
        cout << '\n';
    }
}

int main() {
    freopen("kotlin.in", "r", stdin);
    freopen("kotlin.out", "w", stdout);
    cin >> h >> w >> n;

    int hh = (h + 1) / 2;
    int ww = (w + 1) / 2;

    for (int i = 1; i <= hh; i++)
        if (n % i == 0) {
            int j = n / i;
            if (j <= ww) { print(i, j); return 0; }
        }
    cout << "Impossible\n";
    fclose(stdout);
    return 0;
}