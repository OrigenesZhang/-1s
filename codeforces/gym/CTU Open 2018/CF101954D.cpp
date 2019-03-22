#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#define REP(i, n) for (int i = 0; i < (n); i++)
using namespace std;

const int max_node = 300 + 10;
const int sigma_size = 2;

struct Trie {
    int ch[max_node][sigma_size], val[max_node], sz;
    void init() { sz = 1; memset(ch[0], 0, sizeof(ch[0])); }

    int idx(char c) { return c - '0'; }

    void insert(string& s, int v) {
        int u = 0, n = s.length();
        for (int i = 0; i < n; i++) {
            int c = idx(s[i]);
            if (!ch[u][c]) {
                memset(ch[sz], 0, sizeof(ch[sz]));
                val[sz] = 0;
                ch[u][c] = sz++;
            }
            u = ch[u][c];
        }
        val[u] = v;
    }

    int f[max_node], last[max_node];
    void getfail() {
        queue<int> q;
        f[0] = 0;
        for (int c = 0; c < sigma_size; c++) {
            int u = ch[0][c];
            if (u) { f[u] = 0; q.push(u); last[u] = 0; }
        }

        while (!q.empty()) {
            int r = q.front(); q.pop();
            for (int c = 0; c < sigma_size; c++) {
                int u = ch[r][c];
                if (!u) { ch[r][c] = ch[f[r]][c]; continue; }

                q.push(u);
                int v = f[r];
                f[u] = ch[v][c];
                last[u] = val[f[u]] ? f[u] : last[f[u]];
            }
        }
    }
};

Trie solver;

struct Matrix {
    vector< vector<double> > mat;
    int n, m;
    Matrix(int n = 0, int m = 0): n(n), m(m) {
        mat.resize(n);
        REP (i, n) {
            mat[i].resize(m);
            REP (j, m) mat[i][j] = 0;
        }
    }

    void guessElimination() {
        REP (i, n) {
            for (int u = i; u < n; u++) {
                if (mat[u][i]) {
                    if (u != i) {
                        REP(j, m) swap(mat[i][j], mat[u][j]);
                    }
                    break;
                }
            }
            if (!mat[i][i]) continue;
            for (int u = i + 1; u < n; u++) if (mat[u][i]) {
                    /*double xui = mat[u][i];
                    for (int j = i; j < m; j++) {
                        mat[u][j] = mat[u][j] * mat[i][i] - mat[i][j] * xui;
                    }*/
                    double coe = mat[u][i] / mat[i][i];
                    for (int j = i; j < m; j++) mat[u][j] -= coe * mat[i][j];
                }
        }

        for (int i = n - 1; i >= 0; i--) {
            double cur = mat[i][n];
            for (int j = i + 1; j < n; j++) cur -= mat[i][j] * mat[j][n];
            cur /= mat[i][i];
            mat[i][n] = cur;
        }
    }
};

bool vis[max_node];

void dfs(int u, Matrix& m) {
    if (vis[u]) return;
    vis[u] = true;
    if (solver.val[u]) { m.mat[u][u] = 1; m.mat[u][solver.sz] = 0; }
    else {
        m.mat[u][u] = 1;
        m.mat[u][solver.ch[u][0]] += -0.5;
        m.mat[u][solver.ch[u][1]] += -0.5;
        m.mat[u][solver.sz] = 1;
    }
    dfs(solver.ch[u][0], m);
    dfs(solver.ch[u][1], m);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solver.init();
    int n, b;
    cin >> n >> b;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < s.length(); j++) {
            if (s[j] == 'H') s[j] = '0';
            else s[j] = '1';
        }

        solver.insert(s, 1);
    }

    solver.getfail();
    cout << fixed;
    cout.precision(10);
    Matrix m(solver.sz, solver.sz + 1);
    dfs(0, m);
    m.guessElimination();
    cout << m.mat[0][solver.sz] << '\n';
    return 0;
}
