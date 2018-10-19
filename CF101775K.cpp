#include <iostream>
using namespace std;

const int N = 123456;
typedef long long LL;

LL pos[2], l[N], n;
LL sum[N];

LL my_find(LL val) {
    LL l = 1, r = val;
    while (l < r) {
        LL mid = l + (r - l) / 2;
        if (sum[mid] < val) l = mid + 1;
        else r = mid;
    }
    return l;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int kase = 1; kase <= T; kase++) {
        cin >> pos[0] >> pos[1] >> n;
        for (int i = 1; i <= pos[0]; i++) {
            cin >> l[i];
            sum[i] = sum[i - 1] + l[i];
        }

        while (n) {
            LL major = my_find(pos[0]);
            if (major == pos[0]) {
                pos[1] = pos[0] - sum[major - 1];
                pos[0] = major;
                break;
            } else {
                pos[1] = pos[0] - sum[major - 1];
                pos[0] = major;
                n--;
            }
        }

        cout << "Case #" << kase << ": " << pos[0] << '-' << pos[1] << '\n';
    }
    return 0;
}