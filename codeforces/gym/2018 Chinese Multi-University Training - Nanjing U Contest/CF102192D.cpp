#include <bits/stdc++.h>
using namespace std;

const int N = 212;

bool rev;
int h, w, ans[N][N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        cin >> h >> w;

        if (h % 2) {
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                    if (j % 2 == 0) cout << '(';
                    else cout << ')';
                }
                cout << '\n';
            }
            continue;
        }

        if (w % 2) {
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                    if (i % 2 == 0) cout << '(';
                    else cout << ')';
                }
                cout << '\n';
            }
            continue;
        }

        if (h < 6 || w < 6) {
            // even even:
            if (h < w) { swap(h, w); rev = true; }
            else rev = false;

            for (int i = 0; i < h; i++) {
                if (i % 2 == 0) {
                    for (int j = 0; j < w; j++) {
                        if (j < w / 2) ans[i][j] = '(';
                        else ans[i][j] = ')';
                    }
                } else {
                    for (int j = 0; j < w; j++) {
                        if (j % 2 == 0) ans[i][j] = '(';
                        else ans[i][j] = ')';
                    }
                }
            }

            if (!rev) {
                for (int i = 0; i < h; i++) {
                    for (int j = 0; j < w; j++) cout << char(ans[i][j]);
                    cout << '\n';
                }
            } else {
                for (int i = 0; i < w; i++) {
                    for (int j = 0; j < h; j++) cout << char(ans[j][i]);
                    cout << '\n';
                }
            }
        } else {
            for (int i = 0; i < w; i++) cout << '(';
            cout << '\n';
            for (int i = 1; i < h - 1; i++) {
                if (i % 2 == 1) {
                    for (int j = 0; j < w; j++) {
                        if (j % 2 == 0) cout << '(';
                        else cout << ')';
                    }
                } else {
                    cout << '(';
                    for (int j = 1; j < w - 1; j++) {
                        if (j % 2 == 1) cout << '(';
                        else cout << ')';
                    }
                    cout << ')';
                }
                cout << '\n';
            }
            for (int i = 0; i < w; i++) cout << ')';
            cout << '\n';
        }
    }
    return 0;
}