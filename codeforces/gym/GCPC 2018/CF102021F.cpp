#include <bits/stdc++.h>

using namespace std;

int n;
int m;
vector<int> fibo;
int idx[100000];

int main() {
    fibo.push_back(1);
    fibo.push_back(2);
    int cur = 2;
    while (true) {
        int next_val = fibo[cur - 1] + fibo[cur - 2];
        if (next_val <= 1000000) {
            fibo.push_back(next_val);
            cur++;
        } else {
            break;
        }
    }

    memset(idx, -1, sizeof(idx));
    bool flag = true;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> m;
        int search_res = lower_bound(fibo.begin(), fibo.end(), m) - fibo.begin();
        if (fibo[search_res] == m) {
            if (m == 1) {
                if (idx[0] != -1) {
                    cout << idx[0] << " " << i << endl;
                    flag = false;
                    break;
                } else {
                    idx[0] = i;
                }
            } else {
                idx[search_res] = i;
                if (idx[search_res - 1] != -1) {
                    cout << idx[search_res - 1] << " " << i << endl;
                    flag = false;
                    break;
                } else if (idx[search_res + 1] != -1) {
                    cout << i << " " << idx[search_res + 1] << endl;
                    flag = false;
                    break;
                }
            }
        }
    }

    if (flag) {
        cout << "impossible" << endl;
    }
}