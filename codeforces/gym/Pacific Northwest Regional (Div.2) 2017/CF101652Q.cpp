#include<iostream>
using namespace std;

typedef long long LL;

LL n, f;

int judge(LL u) {
    LL r = (n * 2 - u - 1) * u / 2;
    LL l = r - (n - u);
    if(f <= l) return 1;
    else if(f <= r) return 0;
    else return -1;
}

int main() {
    cin >> n;
    LL tot = n * (n - 1) / 2;
    f = (tot + 1) / 2;
    LL l = 1, r = n + 1;
    while(l < r) {
        LL mid = l + (r - l) / 2;
        int cur = judge(mid);
        if(cur == 0) { cout << mid << '\n'; return 0; }
        else if(cur > 0) r = mid;
        else l = mid + 1;
    }
    //cout << judge(1) << endl;
    return 0;
}
