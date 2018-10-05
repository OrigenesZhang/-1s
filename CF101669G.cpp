#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

struct Node {
    LL a, t;
    bool operator < (const Node& rhs) const {
        return a > rhs.a;
    }
};

const int N = 11234;

Node node[N];
int n;

LL a[N], t[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> t[i];
        node[i] = { a[i], t[i] };
    }

    sort(node, node + n);
    double v = 0, dis = 0, v_a = 0;
    for (int i = 0; i < n; i++) {
        dis += v * node[i].t + 0.5 * double(node[i].a) * double(node[i].t) * double(node[i].t);
        v += double(node[i].a) * double(node[i].t);
        dis -= v_a * t[i] + 0.5 * double(a[i]) * double(t[i]) * double(t[i]);
        v_a += double(a[i]) * double(t[i]);
    }

    cout << fixed;
    cout.precision(1);
    cout << dis << '\n';
    return 0;
}