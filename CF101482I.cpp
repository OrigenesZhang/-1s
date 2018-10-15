#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
#define pb push_back
using namespace std;

const int N = 15;

typedef long long LL;

int n;
LL l, d[N][N];
LL val[3500][5050];
int id[1 << N];
int id_cnt;

int count(int mask) {
    int ans = 0;
    while (mask) {
        ans += mask & 1;
        mask >>= 1;
    }
    return ans;
}

vector<int> first, second;
set<LL> s[N][N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> l;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> d[i][j];

    if (n == 2) {
        if (d[0][1] * 2 == l) cout << "possible\n";
        else cout << "impossible\n";
        return 0;
    }

    if (n == 3) {
        if (d[0][1] + d[0][2] + d[1][2] == l) cout << "possible\n";
        else cout << "impossible\n";
        return 0;
    }

    n--;
    int all = (1 << n) - 1;
    int half = (n + 1) / 2;

    // preprocess:
    for (int mask = 0; mask <= all; mask++) {
        int cnt = count(mask);
        if (cnt == half || cnt == n - half) {
            id[mask] = id_cnt++;
            int tot = 0;
            vector<int> vec;
            for (int i = 0; i < n; i++)
                if ((1 << i) & mask) vec.pb(i);
            sort(vec.begin(), vec.end());
            do {
                LL sum = 0;
                for (int i = 0; i < vec.size() - 1; i++) sum += d[vec[i]][vec[i + 1]];
                val[id[mask]][tot++] = sum;
            } while (next_permutation(vec.begin(), vec.end()));
        }
    }



    for (int mask = 0; mask <= all; mask++) {
        if (count(mask) != half) continue;
        first.clear();
        second.clear();
        for (int i = 0; i < n; i++) {
            if ((1 << i) & mask) first.pb(i);
            else second.pb(i);
        }

        sort(first.begin(), first.end());
        sort(second.begin(), second.end());

        for (int u : first)
            for (int v : first) s[u][v].clear();
        int cur = 0;
        do {
            LL tot = val[id[mask]][cur++];
            int head = first[0];
            int tail = first[first.size() - 1];
            s[head][tail].insert(tot);
        } while (next_permutation(first.begin(), first.end()));

        cur = 0;
        do {
            LL tot = val[id[all - mask]][cur++];
            int head = second[0];
            int tail = second[second.size() - 1];
            for (int u : first)
                for (int v : first)
                    if (u != v) {
                        LL now = l - d[n][u] - d[n][head] - d[v][tail] - tot;
                        if (s[u][v].count(now)) { cout << "possible\n"; return 0; }
                    }
        } while (next_permutation(second.begin(), second.end()));
    }

    cout << "impossible\n";
    return 0;
}