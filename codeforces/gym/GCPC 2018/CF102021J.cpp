#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int N = 312345;

vector<int> num[N * 4];
int a[N][4], n;

bool vis[N];
vector<int> f[N];

int tmp[4];

void change(int id, int st) {
    for (int i = 0; i < 4; i++) tmp[i] = a[id][i];
    for (int i = 0; i < 4; i++) a[id][i] = tmp[(st + i) % 4];
}

vector<int> special;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) cin >> a[i][j];
        int cnt = 0;
        for (int j = 0; j < 4; j++) {
            if (a[i][j] == 0) ++cnt;
            else num[a[i][j]].pb(i);
        }

        if (cnt == 2) num[0].pb(i);
        else if (cnt >= 3) special.pb(i);
    }
    
    int id = 0;
    
    if (!special.empty()) {
        id = special[0];
    } else {
        if (num[0].empty()) {
            cout << "impossible\n";
            return 0;
        }
        id = num[0][0];
    }
    
    int h = 0, w = 0;
    
    for (int i = 0; i < 4; i++) {
        if (a[id][i] == 0 && a[id][(i + 1) % 4] == 0) { change(id, i); break; }
    }


    for (;;) {
        f[0].pb(id);
        ++w;
        int col = a[id][3];
        if (col == 0) break;

        int id2 = num[col][0];
        if (id2 == id) id2 = num[col][1];

        for (int i = 0; i < 4; i++) {
            if (a[id2][i] == col) change(id2, (i - 1 + 4) % 4);
        }
        id = id2;
    }

    //cout << w << endl;

    //for (int it : f[0]) cout << it << endl;

    if (n % w) { cout << "impossible\n"; return 0; }

    h = n / w;

    //cout << w << ' ' << h << endl;

    for (int i = 1; i < h; i++) {
        id = f[i - 1][0];
        int col = a[id][2];
        if (col == 0) { cout << "impossible\n"; return 0; }

        int id2 = num[col][0];
        if (id2 == id) id2 = num[col][1];

        //cout << id2 << endl;

        f[i].pb(id2);
        for (int j = 0; j < 4; j++) {
            if (a[id2][j] == col) { change(id2, j); break; }
        }

        id = id2;
        for (int j = 1; j < w; j++) {
            col = a[id][3];
            if (col == 0) { cout << "impossible\n"; return 0; }

            id2 = num[col][0];
            if (id2 == id) id2 = num[col][1];

            f[i].pb(id2);
            for (int k = 0; k < 4; k++) {
                if (a[id2][k] == col) { change(id2, (k - 1 + 4) % 4); break; }
            }
            id = id2;
        }
    }


//    for (int i = 0; i < h; i++) {
//        for (int j = 0; j < w; j++) cout << f[i][j] << ' ';
//        cout << endl;
//    }

//    for (int i = 0; i < h; i++) {
//        for (int j = 0; j < w; j++) {
//            id = f[i][j];
//            cout << id << ":";
//            for (int k = 0; k < 4; k++) cout << ' ' << a[id][k];
//            cout << endl;
//        }
//    }


//    for (int i = 0; i < h; i++) {
//        for (int j = 0; j < w; j++) cout << f[i][j] << ' ';
//        cout << endl;
//    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            id = f[i][j];
            if (vis[id]) { cout << "impossible\n"; return 0; }
            vis[id] = true;
            if (i == 0 && a[id][0]) { cout << "impossible\n"; return 0; }
            if (j == 0 && a[id][1]) { cout << "impossible\n"; return 0; }
            if (i == h - 1 && a[id][2]) { cout << "impossible\n"; return 0; }
            if (j == w - 1 && a[id][3]) { cout << "impossible\n"; return 0; }

            if (i) {
                int up = f[i - 1][j];
                if (a[up][2] != a[id][0] || a[up][2] == 0 || a[id][0] == 0) { cout << "impossible\n"; return 0; }
            }

            if (j) {
                if (a[id][1] == 0) { cout << "impossible\n"; return 0; }
            }

        }
    }

    cout << h << ' ' << w << '\n';
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) cout << f[i][j] + 1 << ' ';
        cout << '\n';
    }
    return 0;
}