#include<iostream>
#include<cstring>
#include<cctype>
#include<cstdlib>
using namespace std;

const int N = 50;
int n, a[N][N];
string s[N];
bool vis[N];

int main() {
    while(cin >> n) {
        for (int i = 0; i < n; i++) cin >> s[i];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                if (isdigit(s[i][j])) a[i][j] = s[i][j] - '0';
                else a[i][j] = s[i][j] - 'A' + 10;
            }

        /*for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) cout << a[i][j] << ' ';
            cout << endl;
        }*/

        for (int i = 0; i < n; i++) {
            memset(vis, false, sizeof(vis));
            for (int j = 0; j < n; j++) {
                if (vis[a[i][j]]) {
                    cout << "No\n";
                    goto label;
                }
                vis[a[i][j]] = true;
            }
        }

        for (int j = 0; j < n; j++) {
            memset(vis, false, sizeof(vis));
            for (int i = 0; i < n; i++) {
                if (vis[a[i][j]]) {
                    cout << "No\n";
                    goto label;
                }
                vis[a[i][j]] = true;
            }
        }

        for (int i = 1; i < n; i++) {
            if (a[0][i] < a[0][i - 1]) {
                cout << "Not Reduced\n";
                goto label;
            }
            if (a[i][0] < a[i - 1][0]) {
                cout << "Not Reduced\n";
                goto label;
            }
        }
        cout << "Reduced\n";
        label:;
    }
    return 0;
}
