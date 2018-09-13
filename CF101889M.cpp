#include <bits/stdc++.h>
#define push_back pb
#define _1 first
#define _2 second
typedef long long LL;
typedef std::pair<int, int> pii;
using namespace std;

const int N = 612345;
const int MOD = int(1e9) + 7;
const int MUL = 365;

struct Suffix_Array {
    // N: The max length of the string
    int s[N];
    int sa[N], t[N], t2[N], c[N], n;
    // sa: 最终排名情况, c: 基数排序辅助数组
    // O(nlogn)
    // 需要在最后添加一个不会出现且最小的字符，常为$
    void build_sa(int m) {  // m: 可能包含的最大字符值+1
        memset(t, 0, sizeof(t));
        memset(t2, 0, sizeof(t2));
        memset(sa, 0, sizeof(sa));
        int *x = t, *y = t2;  // x: 存储字符的编号, y: 存储第二元的排名情况
        // 基数排序
        for(int i = 0; i < m; i++) c[i] = 0;
        for(int i = 0; i < n; i++) c[x[i] = s[i]]++;
        for(int i = 1; i < m; i++) c[i] += c[i - 1];
        for(int i = n - 1; i >= 0; i--) sa[--c[x[i]]] = i;
        for(int k = 1; k <= n; k <<= 1) {
            int p = 0;
            // 利用sa数组排序第二元
            for(int i = n - k; i < n; i++) y[p++] = i;
            for(int i = 0; i < n; i++)
                if(sa[i] >= k) y[p++] = sa[i] - k;
            // 排序第一元
            for(int i = 0; i < m; i++) c[i] = 0;
            for(int i = 0; i < n; i++) c[x[y[i]]]++;  // 第y[i]个二元组的第一元为x[y[i]]
            for(int i = 0; i < m; i++) c[i] += c[i - 1];
            for(int i = n - 1; i >= 0; i--) sa[--c[x[y[i]]]] = y[i];
            // 根据sa和y重新计算x数组
            swap(x, y);
            p = 1; x[sa[0]] = 0;
            for(int i = 1; i < n; i++)
                x[sa[i]] = y[sa[i - 1]] == y[sa[i]] && y[sa[i - 1] + k] == y[sa[i] + k] ? p - 1 : p++;
            if(p >= n) break;  // 即使倍增也不会改变
            m = p; // 更新可能包含的字符数的最大值
        }
    }

    int rank[N], height[N];
    // 下面计算最长公共前缀LCP。
    // rank[i]: 后缀i在sa数组中的下标, height[i]: sa[i - 1]和sa[i]的LCP
    // O(n)
    void getHeight() {
        int k = 0;
        for(int i = 0; i < n; i++) rank[sa[i]] = i;
        for(int i = 0; i < n - 1; i++) {
            if(k) k--;
            int j = sa[rank[i] - 1];
            while(s[i + k] == s[j + k]) k++;
            height[rank[i]] = k;
        }
    }

};

int n;

Suffix_Array solver;

LL pw[N];

struct cmp {
    bool operator () (const int a, const int b) const {
        return solver.rank[a] > solver.rank[b];
    }
};

priority_queue<int, vector<int>, cmp> pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    int tot = 0;
    for (int i = 0; i < n; i++) {
        int sz;
        cin >> sz;
        tot += sz;
        while (sz--) {
            int x;
            cin >> x;
            solver.s[solver.n++] = x;
        }
        solver.s[solver.n++] = 301;
    }
    solver.s[solver.n++] = 0;
    solver.build_sa(302);
    solver.getHeight();

    pw[0] = 1;
    for (int i = 1; i <= tot; i++) pw[i] = pw[i - 1] * MUL % MOD;

    bool ok = true;
    for (int i = 0; i < solver.n - 1; i++) {
        if (ok) {
            pq.push(i);
            ok = false;
        } else if (solver.s[i] == 301) ok = true;
    }

    LL ans = 0;
    for (int i = tot; i >= 1; i--) {
        int u = pq.top(); pq.pop();
        //cout << solver.s[u] << endl;
        ans = (ans + solver.s[u] * pw[i] % MOD) % MOD;
        if (solver.s[u + 1] != 301) pq.push(u + 1);
    }
    cout << ans << '\n';
    return 0;
}