#include <bits/stdc++.h>
using namespace std;

const int N = 112345;
typedef long long LL;

int l, c, n;

int setv[N * 4], cnt[N];

int query(int o, int l, int r, int color) {
    if (setv[o]) {
        if (setv[o] == color) return r - l + 1;
        else return 0;
    } else {
        int mid = l + (r - l) / 2;
        return query(o * 2, l, mid, color) + query(o * 2 + 1, mid + 1, r, color);
    }
}

void push_down(int o) {
    if (setv[o]) {
        setv[o * 2] = setv[o * 2 + 1] = setv[o];
        setv[o] = 0;
    }
}

void my_count(int o, int l, int r) {
    if (setv[o]) cnt[setv[o]] += r - l + 1;
    else {
        int mid = l + (r - l) / 2;
        my_count(o * 2, l, mid);
        my_count(o * 2 + 1, mid + 1, r);
    }
}

void update(int o, int l, int r, int ql, int qr, int color) {
    if (ql <= l && r <= qr) setv[o] = color;
    else {
        push_down(o);
        int mid = l + (r - l) / 2;
        if (ql <= mid) update(o * 2, l, mid, ql, qr, color);
        if (qr > mid) update(o * 2 + 1, mid + 1, r, ql, qr, color);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> l >> c >> n;
    setv[1] = 1;

    for (int i = 0; i < n; i++) {
        int p, x;
        LL a, b;
        cin >> p >> x >> a >> b;
        LL s = query(1, 0, l - 1, p);
        LL m1 = (a + s * s % l) % l;
        LL m2 = (a + (s + b) * (s + b) % l) % l;
        if (m1 > m2) swap(m1, m2);

        update(1, 0, l - 1, (int)m1, (int)m2, x);
    }

    my_count(1, 0, l - 1);
    int maxm = -1;
    for (int i = 1; i <= c; i++) maxm = max(maxm, cnt[i]);
    cout << maxm << '\n';
    return 0;
}