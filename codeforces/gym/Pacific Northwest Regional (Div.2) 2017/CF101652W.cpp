#include<iostream>
#include<cstring>
using namespace std;

const int N = 30 + 10;

typedef long long LL;
LL n, m, d[N][N], lastb[N], firstr[N];

string s[N];

LL dp(LL col, LL b) {  // b ge
    LL& ans = d[col][b];
    if(ans != -1) return ans;
    if(firstr[col] != -1 && firstr[col] <= b - 1) return ans = 0;
    if(lastb[col] != -1 && lastb[col] > b - 1) return ans = 0;
    if(col == 0) return ans = 1;

    ans = 0;
    for(LL i = b; i <= m; i++) ans += dp(col - 1, i);
    return ans;
}

int main() {
    cin >> m >> n;
    for(LL i = 0; i < m; i++) cin >> s[i];
    memset(d, -1, sizeof(d));
    memset(lastb, -1, sizeof(lastb));
    memset(firstr, -1, sizeof(firstr));

    for(LL i = 0; i < n; i++)
        for(LL j = m - 1; j >= 0; j--)
            if(s[j][i] == 'B') {
                lastb[i] = j;
                break;
            }
    for(LL i = 0; i < n; i++)
        for(LL j = 0; j < m; j++)
            if(s[j][i] == 'R') {
                firstr[i] = j;
                break;
            }

    //for(LL i = 0; i < n; i++)
    //    cout << i << ' ' << firstr[i] << ' ' << lastb[i] << endl;
    //cout << endl;
    /*for(LL i = 0; i < n; i++)
        if(lastb[i] != -1 && firstr[i] != -1 && firstr[i] < lastb[i]) {
            cout << 0 << '\n';
            return 0;
        }*/

    /*for(LL i = 0; i < n; i++)
        for(LL j = 0; j < lastb[i]; j++) {
            d[i][j] = 0;
            if(s[i][j] == 'R') { cout << 0 << '\n'; return 0; }
        }*/

    /*for(LL i = 0; i < n; i++) {
        for(LL j = 0; j <= m; j++) cout << i << ' ' << j << ' ' << dp(i, j) << endl;
        cout << endl;
    }*/

    LL ans = 0;
    for(LL i = 0; i <= m; i++) ans += dp(n - 1, i);
    cout << ans << '\n';
    return 0;
}
