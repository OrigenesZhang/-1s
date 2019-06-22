#include <bits/stdc++.h>
using namespace std;

const int maxn = 1123456789;
const int sqrtn = 35234;

int N;
int a[21];
int c[21];
bool c_vis[21];
int ares[21][sqrtn + 1234];
int arangeres[21][maxn / sqrtn + 1234][2];
int total = 0;
int c_tot = 0;
vector<int> ranges;

int main() {
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> a[i] >> c[i];
        if (c_vis[c[i]]) {
            if (c[i - 1] != c[i]) {
                cout << 0 << endl;
                return 0;
            }
        } else {
            c_vis[c[i]] = true;
            c_tot++;
        }
    }
    if (c_tot == 1) {
        cout << -1 << endl;
        return 0;
    }

    for (int M = 1; M <= sqrtn; ++M) {
        for (int i = 1; i <= N; ++i) {
            ares[i][M] = (a[i] - 1) / M;
        }
    }
    for (int i = 1; i <= N; ++i) {
        for (int res = 0; res < a[i] / sqrtn; ++res) {
            arangeres[i][res][0] = (a[i] - 1) / (res + 1) + 1;
            arangeres[i][res][1] = res > 0 ? (a[i] - 1) / res : maxn;
            ranges.push_back(arangeres[i][res][0]);
            ranges.push_back(arangeres[i][res][1] + 1);
        }
    }

    for (int M = 1; M <= sqrtn; ++M) {
        bool flag = true;
        for (int i = 2; i <= N; ++i) {
            if (c[i] == c[i - 1]) {
                if (ares[i][M] != ares[i - 1][M]) {
                    flag = false;
                    break;
                }
            } else {
                if (ares[i][M] == ares[i - 1][M]) {
                    flag = false;
                    break;
                }
            }
        }
        if (flag) {
//            cerr << M << endl;
            total++;
        }
    }

//    cerr << "hi" << endl;
    sort(ranges.begin(), ranges.end());
    ranges.erase(unique(ranges.begin(), ranges.end()), ranges.end());
    for (int j = 0; j < int(ranges.size()) - 1; ++j) {
//        cerr << ranges[j] << endl;
        int M_val = ranges[j];
        bool flag = true;
        for (int i = 2; i <= N; ++i) {
            if (c[i] == c[i - 1]) {
                if ((a[i] - 1) / M_val != (a[i - 1] - 1) / M_val) {
                    flag = false;
                    break;
                }
            } else {
                if ((a[i] - 1) / M_val == (a[i - 1] - 1) / M_val) {
                    flag = false;
                    break;
                }
            }
        }
        if (flag) {
            total += (ranges[j + 1] - ranges[j]);
        }
    }

    cout << total << endl;
}