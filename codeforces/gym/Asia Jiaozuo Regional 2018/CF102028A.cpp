#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int T;
    cin >> T;
 
    while (T--) {
        int cnt = 0;
        for (int i = 0; i < 4; i++) {
            int x;
            cin >> x;
            if (x) ++cnt;
        }
 
        if (cnt == 0) cout << "Typically Otaku" << endl;
        else if (cnt == 1) cout << "Eye-opener" << endl;
        else if (cnt == 2) cout << "Young Traveller" << endl;
        else if (cnt == 3) cout << "Excellent Traveller" << endl;
        else cout << "Contemporary Xu Xiake" << endl;
    }
    return 0;
}