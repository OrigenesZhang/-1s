#include <bits/stdc++.h>

using namespace std;

int T, n;
int sqr[3][3];
int idx;
char rot;

void Crotate(int x, int y) {
    int temp = sqr[x][y];
    sqr[x][y] = sqr[x + 1][y];
    sqr[x + 1][y] = sqr[x + 1][y + 1];
    sqr[x + 1][y + 1] = sqr[x][y + 1];
    sqr[x][y + 1] = temp;
}

void Rrotate(int x, int y) {
    int temp = sqr[x][y];
    sqr[x][y] = sqr[x][y + 1];
    sqr[x][y + 1] = sqr[x + 1][y + 1];
    sqr[x + 1][y + 1] = sqr[x + 1][y];
    sqr[x + 1][y] = temp;
}

int main() {
    cin >> T;
    for (int kase = 0; kase < T; ++kase) {
        cin >> n;
        int three_digit;
        for (int i = 0; i < 3; ++i) {
            cin >> three_digit;
            sqr[i][2] = three_digit % 10;
            sqr[i][1] = (three_digit / 10) % 10;
            sqr[i][0] = three_digit / 100;
        }

//        for (int i = 0; i < 3; ++i) {
//            for (int j = 0; j < 3; ++j) {
//                cout << sqr[i][j];
//            }
//            cout << endl;
//        }

        for (int num = 0; num < n; ++num) {
            cin >> idx >> rot;
            if (rot == 'C') {
                if (idx == 1) {
                    Crotate(0, 0);
                } else if (idx == 2) {
                    Crotate(0, 1);
                } else if (idx == 3) {
                    Crotate(1, 0);
                } else if (idx == 4) {
                    Crotate(1, 1);
                }
            } else if (rot == 'R') {
                if (idx == 1) {
                    Rrotate(0, 0);
                } else if (idx == 2) {
                    Rrotate(0, 1);
                } else if (idx == 3) {
                    Rrotate(1, 0);
                } else if (idx == 4) {
                    Rrotate(1, 1);
                }
            }
//            for (int i = 0; i < 3; ++i) {
//                for (int j = 0; j < 3; ++j) {
//                    cout << sqr[i][j];
//                }
//                cout << endl;
//            }
        }

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                cout << sqr[i][j];
            }
            cout << endl;
        }
    }
}